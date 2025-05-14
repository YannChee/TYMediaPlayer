//
//  TTVideoEngine.h
//  Pods
//
//  Created by guikunzhi on 16/12/2.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TTVideoEngineNetClient.h"
#import "TTVideoEngineModelDef.h"
#import "TTVideoEnginePlayItem.h"
#import "TTVideoEngineVideoInfo.h"
#import "TTVideoEngineModel.h"
#import "TTVideoEngineAVPlayerItemAccessLog.h"
#import "TTVideoEnginePlayerDefine.h"
#import "TTVideoEnginePublicProtocol.h"
#import "TTVideoEngineUtil.h"
#import "TTVideoEngineStrategyABRConfig.h"
#import "IVCNetworkSpeedPredictor.h"
#import "IVCABRModule.h"
#if __has_include(<TTPlayerSDK/TTAVPlayerLoadControlInterface.h>)
#import <TTPlayerSDK/TTAVPlayerLoadControlInterface.h>
#else
#import "TTAVPlayerLoadControlInterface.h"
#endif

@class TTStreamInfo;
@class TTAVTraitObject;
@class TTAVPlayerMaskInfoInterface;

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
FOUNDATION_EXPORT const NSNotificationName TTVideoEngineAudioDeviceNotification;

/**
 * @locale zh
 * @hidden
 * @type keytype
 */
/**
 * @locale en
 * @type keytype
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineCustomInfoKey) {
    TTVideoEngineCustomInfoKey_PlaySessionID_NSString,
    TTVideoEngineCustomInfoKey_VVData_Dic, // custom vv bury data, cover keys in oneplay
};

/**
 * @locale zh
 * @hidden
 */
extern NSString *kTTVideoEngineUserClickedUI;

/**
 * @locale zh
 * @hidden
 */
typedef void* _Nullable (*DrmCreater)(int drmType);


/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief video engine data source。
 */
/**
 * @locale en
 * @type callback
 * @brief Video engine data source.
 * @hidden 
 */
@protocol TTVideoEngineDataSource <NSObject>

@optional
- (nullable NSString *)apiForFetcher __attribute__((deprecated));

- (nullable NSString *)apiForFetcher:(TTVideoEnginePlayAPIVersion)apiVersion;

- (TTVideoEngineNetworkType)networkType;

/// Custom cache file path.
- (NSString *)cacheFilePathUsingMediaDataLoader:(NSString *)videoId infoModel:(TTVideoEngineURLInfo *)infoModel;

/// The key from TTVideoEngineKeys.h
- (nullable NSDictionary<NSString *, id> *)appInfo;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 过期 URL 刷新完成 block。
 * @param newUrl 新 URL。
 * @param expireTimeInMS 新 URL 的过期时间。精度为毫秒的 Unix 时间戳。
 */
typedef void(^TTVideoURLRefreshCompleteBlock)(NSString *newUrl, NSString *expireTimeInMS);
/**
 * @locale zh
 * @type keytype
 * @brief 过期 URL 刷新失败 block。
 * @param error 失败原因。
 */
typedef void(^TTVideoURLRefreshErrorBlock)(NSError *error);
/**
 * @locale zh
 * @type keytype
 * @brief 过期 URL 取消刷新 block。
 */
typedef void(^TTVideoURLRefreshCancelBlock)(void);

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief URL 地址过期自动刷新协议。
 */
/**
 * @locale en
 * @type callback
 * @brief Protocol for Automatic Refresh of Expired URL Addresses.
 * @hidden
 */
@protocol TTVideoURLRefreshFetcher <NSObject>

/**
 * @locale zh
 * @type callback
 * @brief 请求新的播放 URL 地址回调。
 * @param cacheKey 缓存 Key。播放地址的唯一标识。
 * @param oldUrl 已过期的旧 URL 地址。
 * @param complateBlock 请求成功 block
 * @param errorBlock 请求错误 block
 * @param cancelBlock 请求取消 block
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for requesting a new playback URL.
 * @param cacheKey Cache Key. The unique identifier for the playback URL.
 * @param oldUrl Expired old URL address.
 * @param complateBlock Request Success Block
 * @param errorBlock Request Error Block
 * @param cancelBlock Request to Cancel Block
 */
- (void)refreshNewUrls:(NSString * _Nonnull)cacheKey
                oldUrl:(NSString * _Nonnull)oldUrl
         complateBlock:(TTVideoURLRefreshCompleteBlock)complateBlock
            errorBlock:(TTVideoURLRefreshErrorBlock)errorBlock
           cancelBlock:(TTVideoURLRefreshCancelBlock)cancelBlock;

/**
 * @locale zh
 * @type api
 * @brief 取消请求新的播放 URL 地址回调。
 */
/**
 * @locale en
 * @brief Cancel the request for the new playback URL callback.
 * @type api
 */
- (void)cancel;

@end

@class TTVideoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 播放状态相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief TTVideoEngine Delegate
 */
@protocol TTVideoEngineDelegate <NSObject>

@optional

/**
 * @locale zh
 * @type callback
 * @brief 播放状态改变回调。
 * @notes 播放状态发生变化时 SDK 会触发此回调。
 * @list 播放回调
 * @order 0
 * @param videoEngine `videoEngine` 对象。
 * @param playbackState 当前播放状态，详见 [TTVideoEnginePlaybackState](803941#TTVideoEnginePlaybackState) 。
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 0
 * @brief Playback status change callback.
 * @param videoEngine `videoEngine` object.
 * @param playbackState The current playback state. For more details, see [TTVideoEnginePlaybackState](ios-player-sdk-type-definitions#TTVideoEnginePlaybackState).
 * @notes The SDK triggers this callback when the playback state changes.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine playbackStateDidChanged:(TTVideoEnginePlaybackState)playbackState;

/**
 * @locale zh
 * @type callback
 * @brief 加载状态改变回调。
 * @notes 内部加载状态发生变化时 SDK 会触发此回调。您可以根据此回调显示或者隐藏 loading 视图。
 * @list 播放回调
 * @order 1
 * @param videoEngine `videoEngine` 对象。
 * @param loadState 当前加载状态，详见 [TTVideoEngineLoadState](803941#TTVideoEngineLoadState) 。
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 1
 * @brief Callback for load state changes.
 * @param videoEngine The `videoEngine` object.
 * @param loadState The current load state, see [TTVideoEngineLoadState](ios-player-sdk-type-definitions#TTVideoEngineLoadState) for details.
 * @notes The SDK triggers this callback when the internal loading state changes. This callback allows showing or hiding the loading view accordingly.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine loadStateDidChanged:(TTVideoEngineLoadState)loadState;

/**
 * @locale zh
 * @type callback
 * @brief 加载状态改变回调。
 * @notes 内部加载状态发生变化时 SDK 会触发此回调。您可以根据此回调显示或者隐藏 loading 视图。
 * @param videoEngine `videoEngine` 对象。
 * @param loadState 当前加载状态，详见 [TTVideoEngineLoadState](803941#TTVideoEngineLoadState) 。
 * @param extraInfo 额外信息：<br>
 *        - `TTVideoEngineBufferStartAction:@(TTVideoEngineStallActionNone)`: 导致出现卡顿的动作，详见 [TTVideoEngineStallAction](803941#TTVideoEngineStallAction) 。<br>
 *        - `TTVideoEngineBufferStartReason:@(TTVideoEngineStallReasonNetwork)`: 导致出现卡顿的具体原因，详见 [TTVideoEngineStallReason](803941#TTVideoEngineStallReason) 。
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for load status change.
 * @param videoEngine The `videoEngine` object.
 * @param loadState Current loading state, see [TTVideoEngineLoadState](ios-player-sdk-type-definitions#TTVideoEngineLoadState) for details.
 * @param extraInfo extra info：<br>
 *        - `TTVideoEngineBufferStartAction:@(TTVideoEngineStallActionNone)`<br>
 *        - `TTVideoEngineBufferStartReason:@(TTVideoEngineStallReasonNetwork)` 。
 * @notes The SDK triggers this callback when the internal loading state changes. This callback can be used to show or hide the loading view.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine
loadStateDidChanged:(TTVideoEngineLoadState)loadState
              extra:(nullable NSDictionary<NSString *,id> *)extraInfo;

/**
 * @locale zh
 * @type callback
 * @brief 获取到视频信息回调。
 * @notes 使用 Video ID 播放视频时，此回调返回视频信息，包含所有档位清晰度的 `urls` 信息。
 * @list 播放回调
 * @order 2
 * @param videoEngine `videoEngine` 对象。
 * @param videoModel 服务端返回视频播放的详细信息。
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 2
 * @brief Callback for retrieving video information.
 * @param videoEngine The `videoEngine` object.
 * @param videoModel video info
 * @notes When playing a video using the Video ID, this callback returns video information, including `urls` for all resolution levels.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine fetchedVideoModel:(TTVideoEngineModel *)videoModel;

/**
 * @locale zh
 * @type callback
 * @brief 获取播放信息数组的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param urlInfos 视频所有档位分辨率的 URL 信息。
 * @notes 播放 Vid 视频源时，此回调返回视频所有档位分辨率。
 * @list 播放回调
 * @order 3
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 3
 * @brief Callback for retrieving the playback information array.
 * @param videoEngine The `videoEngine` object.
 * @param urlInfos URL information for all resolution levels of the video.
 * @notes This callback returns all the resolution levels of the video when playing a Vid source.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine usingUrlInfos:(NSArray<TTVideoEngineURLInfo *> *)urlInfos;

/**
 * @locale zh
 * @type callback
 * @brief 显示视频首帧回调。
 * @param videoEngine `videoEngine` 对象。
 * @notes 您可以根据该回调隐藏封面图，显示视频画面。
 * @list 播放回调
 * @order 5
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for displaying the first frame of the video.
 * @param videoEngine `videoEngine` object.
 * @notes You can hide the cover image and display the video screen based on the callback.
 * @list 播放回调
 */
- (void)videoEngineReadyToDisPlay:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 播放器各模块准备完成、可以播放回调。
 * @param videoEngine `videoEngine` 对象。
 * @list 播放回调
 * @order 4
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 4
 * @brief Callback for when all modules of the player are ready and playback can commence.
 * @param videoEngine The `videoEngine` object.
 */
- (void)videoEnginePrepared:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 视频加载完成、开始播放回调。
 * @param videoEngine `videoEngine` 对象。
 * @notes 该回调必须调用 `[videoEngine play]` 后才会触发。
 * @list 播放回调
 * @order 6
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for video load completion and start of playback.
 * @param videoEngine `videoEngine` object.
 * @notes This callback is triggered only after `[videoEngine play]` is called.
 * @list 播放回调
 */
- (void)videoEngineReadyToPlay:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 音频渲染完成回调。
 * @param videoEngine `videoEngine` 对象。
 * @list 播放回调
 * @order 7
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for audio rendering completion.
 * @param videoEngine The `videoEngine` object.
 * @list 播放回调
 */
- (void)videoEngineAudioRendered:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief SDK 内部发生错误、开启重试的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param error 内部错误信息。
 * @notes 此回调表示 SDK 内部发生错误，即将重试，而非最终播放失败。
 */
/**
 * @locale en
 * @type callback
 * @brief The callback for internal SDK errors and retry initiation.
 * @param videoEngine videoEngine instance
 * @param error error info。
 * @notes This callback indicates that an error has occurred within the SDK and a retry is imminent, rather than a final playback failure.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine retryForError:(NSError *)error;

/**
 * @locale zh
 * @type callback
 * @brief 主备 URL 切换回调。SDK 切换到备用 URL 回调此方法。
 * @param videoEngine `videoEngine` 对象。
 * @param url 当前备用 URL 地址
 * @param cacheKey URL 的缓存 Key
 * @param index 当前备用 URL 在 URL 列表中的索引
 */
/**
 * @locale en
 * @type api
 * @brief Callback for primary to backup URL switch. The SDK calls this method when switching to the backup URL.
 * @param videoEngine videoengine
 * @param url Current Backup URL Address
 * @param cacheKey cache key
 * @param index Index of the current backup URL in the URL list
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine fallbackUrlChanged:(NSString *)url cacheKey:(NSString *)cacheKey index:(NSInteger)index;

/**
 * @locale zh
 * @type callback
 * @brief 非 seek 操作引起的卡顿回调。
 * @param videoEngine `videoEngine` 对象。
 * @list 播放回调
 * @order 8
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 8
 * @brief video engine stalled not because of seek
 * @param videoEngine videoengine
 */
- (void)videoEngineStalledExcludeSeek:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 预加载命中回调。
 * @param videoEngine `videoEngine` 对象。
 * @param key 视频缓存的唯一标识符。
 * @param cacheSize 命中缓存视频的大小。
 * @notes 如果您使用预加载功能，通过 `cacheSize` 是否大于 0 可以判断当此播放是否命中了预加载。
 */
/**
 * @locale en
 * @type callback
 * @brief Using media loader,the size of hit cache.
 * @param videoEngine videoengine
 * @param key The task key of using media loader
 * @param cacheSize hit cache size
 * @notes If using the preloading feature, whether the current playback hits the preload can be determined by checking if `cacheSize` is greater than 0.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine mdlKey:(NSString *)key hitCacheSze:(NSInteger)cacheSize;

/**
 * @locale zh
 * @type callback
 * @brief 字幕预加载命中回调。
 * @param videoEngine `videoEngine` 对象。
 * @param key 字幕缓存的唯一标识符。
 * @param cacheSize 命中缓存大小。
 * @notes 如果您使用字幕预加载功能，通过 `cacheSize` 是否大于 0 可以判断当此播放是否命中字幕预加载。
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for subtitle pre - loading hit
 * @param videoEngine videoengine
 * @param key The unique identifier of subtitle cache.
 * @param cacheSize hit cache size
 * @notes If using the subtitle preloading feature, whether the current playback hits the preload can be determined by checking if `cacheSize` is greater than 0.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine subtitleKey:(NSString *)key subtitleHitCacheSize:(NSInteger)cacheSize;

/**
 * @locale zh
 * @type callback
 * @brief 音视频设备打开的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param streamType 音频流类型，详见 [TTVideoEngineStreamType](803941#TTVideoEngineStreamType) 。
 */
/**
 * @locale en
 * @type callback
 * @brief video engine play device opened
 * @param videoEngine videoengine
 * @param streamType stream type 0 for video 1 for audio
 */
- (void)videoEngineDeviceOpened:(TTVideoEngine *)videoEngine streamType:(TTVideoEngineStreamType)streamType;

/**
 * @locale zh
 * @type callback
 * @brief 当前 playview 从父 view 移除前的回调。如果 playview 被移除，页面将展示黑屏。
 * @param videoEngine `videoEngine` 对象。
 */
/**
 * @locale en
 * @type callback
 * @brief This will be called before videoEngine remove the old view. After view removed, the screen shows black.
 * @param videoEngine videoengine
 */
- (void)videoEngineBeforeViewRemove:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 播放内核音视频流 outlet 暂停回调。
 * @param videoEngine `videoEngine` 对象。
 * @param streamType 区分音频流类型，详见 [TTVideoEngineStreamType](803941#TTVideoEngineStreamType) 。
 */
/**
 * @locale en
 * @hidden
 * @type callback
 * @brief outlet paused
 * @param videoEngine videoengine
 * @param streamType stream type 0 for video 1 for audio
 */
- (void)videoEngineOutleterPaused:(TTVideoEngine *)videoEngine streamType:(TTVideoEngineStreamType)streamType;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 音视频 outlet 同步状态的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param type 同步状态，详见 [TTVideoEngineAVOutsyncType](803941#TTVideoEngineAVOutsyncType) 。
 * @param extraInfo 额外信息。
 */
/**
 * @locale en
 * @hidden
 * @type callback
 * @brief video engine AV outsync state change
 * @param videoEngine videoengine
 * @param type av out sync type
 * @param extraInfo extra info。
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine avOutsyncStateDidChanged:(TTVideoEngineAVOutsyncType)type extraInfo:(nullable NSDictionary *)extraInfo;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief no av render 同步状态的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param type 同步状态，详见 [TTVideoEngineNOVARenderStateType](803941#TTVideoEngineNOVARenderStateType) 。
 * @param extraInfo 额外信息。
 */
/**
 * @locale en
 * @hidden
 * @type callback
 * @brief video engine no av render state change
 * @param videoEngine videoengine
 * @param type no av render state type
 * @param extraInfo extra info。
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine noVARenderStateDidChange:(TTVideoEngineNOVARenderStateType)type extraInfo:(nullable NSDictionary *)extraInfo;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief video engine media info switching with info id completed
 * @param videoEngine `videoEngine` 对象。
 * @param infoId player info id
 */
/**
 * @locale en
 * @hidden
 * @type callback
 * @brief video engine media info switching with info id completed
 * @param videoEngine videoengine
 * @param infoId player info id
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine switchMediaInfoCompleted:(NSInteger)infoId;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief video engine detect bad av interlaced issue
 * @param videoEngine `videoEngine` 对象。
 * @param info `KeyIsMaxSamplePosBackDiff` info
 */
/**
 * @locale en
 * @brief The video engine detects bad AV interlaced issue.
 * @param videoEngine `videoEngine` object.
 * @param info `KeyIsMaxSamplePosBackDiff` information
 * @hidden (iOS)
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onAVBadInterlaced:(nullable NSDictionary *)info;

/**
 * @locale zh
 * @type callback
 * @brief 返回本地加密时间戳回调。
 * @param videoEngine `videoEngine` 对象。
 * @return 该回调用于私有 DRM 加密。您需要通过返回值将本地加密时间戳传给 SDK。
 */
/**
 * @locale en
 * @type callback
 * @brief for evideo
 * @param videoEngine videoEngine
 * @return the encrypted local time stamp maintained by application layer.
 */
- (nullable NSString *)videoEngineGetEncryptedLocalTime:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief crosstalk happen, more than one ttvideoengine are playing for a while
 * @param videoEngine `videoEngine` 对象。
 * @param info info
 */
/**
 * @locale en
 * @brief Crosstalk occurs when multiple ttvideoengine instances play simultaneously for a while.
 * @param videoEngine `videoEngine` object.
 * @param info info
 * @hidden (iOS)
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine crosstalkHappen:(nullable NSDictionary *)info;

@required

/**
 * @locale zh
 * @type callback
 * @brief 播放停止回调。
 * @param videoEngine `videoEngine` 对象。
 * @notes 如果您调用了 `stop` 方法，执行完毕 SDK 触发此回调。
 * @list 播放回调
 * @order 9
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 9
 * @brief Callback for playback stop.
 * @param videoEngine videoEngine
 * @notes If the `stop` method is called, the SDK triggers this callback upon completion.
 */
- (void)videoEngineUserStopped:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 播放结束回调。
 * @param videoEngine `videoEngine` 对象。
 * @param error 错误信息。<br>
 *        * `error` 为空表示正常结束播放。<br>
 *        * `error` 不为空表示播放失败，`error` 对应具体的错误信息。
 * @list 播放回调
 * @order 10
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 10
 * @brief video engine finished
 * @param videoEngine The `videoEngine` object.
 * @param error Error Message.<br/>
 *        * An empty `error` indicates normal playback completion.<br/>
 *        * A non-empty `error` indicates playback failure, with `error` containing specific error information.
 */
- (void)videoEngineDidFinish:(TTVideoEngine *)videoEngine error:(nullable NSError *)error;

/**
 * @locale zh
 * @type callback
 * @brief 异常播放结束回调。
 * @param videoEngine `videoEngine` 对象。
 * @param status Video ID 播放获取播放信息异常状态码。
 */
/**
 * @locale en
 * @type callback
 * @brief Callback for abnormal playback termination.
 * @param videoEngine The `videoEngine` object.
 * @param status Exception status code for fetching playback information by Video ID.
 */
- (void)videoEngineDidFinish:(TTVideoEngine *)videoEngine videoStatusException:(NSInteger)status;

/**
 * @locale zh
 * @type callback
 * @brief 播放器实例销毁回调。
 * @param videoEngine `videoEngine` 对象。
 * @notes 如果您调用了 `closeAysnc`, 执行完毕 SDK 触发此回调。
 * @list 播放回调
 * @order 11
 */
/**
 * @locale en
 * @type callback
 * @list 播放回调
 * @order 11
 * @brief Callback for player instance destruction.
 * @param videoEngine The `videoEngine` object.
 * @notes If `closeAysnc` is called, the SDK triggers this callback upon completion.
 */
- (void)videoEngineCloseAysncFinish:(TTVideoEngine *)videoEngine;

@end

/**
 * @locale zh
 * @type callback
 * @brief 分辨率相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief Callbacks related to resolution.
 */
@protocol TTVideoEngineResolutionDelegate <NSObject>

@optional
/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 分辨率自动降级回调。
 * @param videoEngine `videoEngine` 对象。
 */
/**
 * @locale en
 * @brief Callback for automatic resolution downgrade.
 * @param videoEngine `videoEngine` object.
 * @hidden (iOS)
 */
- (void)suggestReduceResolution:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type callback
 * @brief 视频码率发生变化回调。
 * @param videoEngine `videoEngine` 对象。
 * @param resolution 当前视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param bitrate 当前视频码率。
 */
/**
 * @locale en
 * @brief Callback for changes in video bitrate.
 * @param videoEngine The `videoEngine` object.
 * @param resolution Current video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @param bitrate Current video bitrate.
 */
- (void)videoBitrateDidChange:(TTVideoEngine *)videoEngine resolution:(TTVideoEngineResolutionType)resolution bitrate:(NSInteger)bitrate;

/**
 * @locale zh
 * @type callback
 * @brief 视频分辨率发生变化回调。
 * @param videoEngine `videoEngine` 对象。
 * @param videoWidth 当前视频宽。
 * @param videoHeight 当前视频高。
 */
/**
 * @locale en
 * @brief Callback for video resolution change.
 * @param videoEngine The `videoEngine` object.
 * @param videoWidth Current video width.
 * @param videoHeight Current video height.
 */
- (void)videoSizeDidChange:(TTVideoEngine *)videoEngine videoWidth:(NSInteger)videoWidth videoHeight:(NSInteger)videoHeight;

@end

/**
 * @locale zh
 * @type callback
 * @brief ABR 相关回调
 */
/**
 * @locale en
 * @type callback
 * @brief Callbacks Related to ABR
 */
@protocol TTVideoEngineABRDelegate <NSObject>

@optional

/**
 * @locale zh
 * @type api
 * @brief 获取 ABR 配置回调
 * @param videoEngine egnine 实例
 * @return 返回 ABR 配置实例
 */
- (TTVideoEngineStrategyABRConfig *)videoEngineAbrConfig:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type api
 * @brief ABR 当前选择档位回调
 * @param videoEngine egnine 实例
 * @param resolution 当前选择档位
 */
- (void)videoEngineAbrSelectResolution:(TTVideoEngine *)videoEngine resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @type api
 * @brief ABR 当前选择档位回调
 * @param videoEngine egnine 实例
 * @param resolution 将要切换 abr 选择档位的回调
 */
- (void)videoEngineAbrWillSelectResolution:(TTVideoEngine *)videoEngine resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @type api
 * @brief ABR 当前选择档位回调
 * @param videoEngine egnine 实例
 * @param resolution 切换 abr 选择档位完成回调
 */
- (void)videoEngineAbrEndSelectResolution:(TTVideoEngine *)videoEngine resolution:(TTVideoEngineResolutionType)resolution;

@end

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 测速相关回调
 */
/**
 * @locale en
 * @type callback
 * @brief Callback Related to Speed Test
 * @hidden 
 */
@protocol TTVideoEngineNetworkPredictorDelegate <NSObject>

@optional
- (void)predictorSpeedNetworkChanged:(float)speed timestamp:(int64_t)timestamp;

@end

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief VR 相关回调
 */
/**
 * @locale en
 * @type callback
 * @brief VR Related Callbacks
 * @hidden 
 */
@protocol TTVideoEngineVRDelegate <NSObject>

@optional
- (void)didUpdateVRHeadPoseWithYaw:(CGFloat)yaw pitch:(CGFloat)pitch roll:(CGFloat)roll;

@end

@protocol TTVideoEngineEventLoggerProtocol;
@class TTVideoEngineNetworkSpeedPredictorConfigModel;

@protocol TTVideoEngineGearStrategyDelegate;
@class TTVideoEngineGearContext;
@class TTStreamInfo;

/**
 * @locale zh
 * @type api
 * @brief 播放引擎。`TTVideoEngine` 为点播 SDK 的核心对象，提供播放核心接口。
 * @pos 1
 */
/**
 * @locale en
 * @brief Playback engine. `TTVideoEngine` is the core object of the Player SDK, providing key playback interfaces.
 * @pos 1
 * @type api
 */
@interface TTVideoEngine : NSObject

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineDataSource> dataSource;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineDelegate> delegate;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineResolutionDelegate> resolutionDelegate;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineABRDelegate> abrDelegate;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineNetworkPredictorDelegate> networkPredictorDelegate;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<TTVideoEngineVRDelegate> videoVRDelegate;
/**
 * @locale zh
 * @hidden
 * @brief Set resourceLoaderDelegate for system player. FairPlay Drm with thirdparty KSM can use this delegate to transfer ckc
 */
/**
 * @locale en
 * @brief Set resourceLoaderDelegate for the system player. FairPlay DRM with third-party KSM can use this delegate to transfer CKC.
 * @hidden (iOS)
 */
@property (nonatomic, nullable, weak) id<AVAssetResourceLoaderDelegate> resourceLoaderDelegate;

/**
 * @locale zh
 * @brief 设置 URL 过期时请求新的播放地址的回调。
 */
/**
 * @locale en
 * @brief Set a callback to request a new playback URL when the current one expires.
 */
@property (nonatomic, nullable, weak) id<TTVideoURLRefreshFetcher> urlRefreshFetcher;

/**
 * @locale zh
 * @brief 设置播放倍速，默认为 1，取值范围为 (0,3]。
 */
/**
 * @locale en
 * @brief Set the playback speed, default is 1, with a range of (0,3].
 */
@property (nonatomic, assign) CGFloat playbackSpeed;

/**
 * @locale zh
 * @hidden
 * @brief 调节音量。建议使用系统音量方法进行调节。
 */
/**
 * @locale en
 * @hidden
 * @brief Playback volume
 */
@property (nonatomic, assign) CGFloat volume;

/**
 * @locale zh
 * @brief 设置是否静音：<br>
 *        - YES: 静音。<br>
 *        - NO:（默认）没有静音。
 */
/**
 * @locale en
 * @brief Set mute status:<br/>
 *        - YES: Muted.
 *        - NO: (default) Not muted.
 */
@property (nonatomic, assign) BOOL muted;

/**
 * @locale zh
 * @brief 设置是否开启纯音频播放模式： <br>
 *        - YES: 开启。<br>
 *        - NO:（默认）关闭。
 */
/**
 * @locale en
 * @brief Set whether to enable pure audio playback mode:<br/>
 *        - YES: Enabled.
 *        - NO: (default) Disabled.
 */
@property (nonatomic, assign) BOOL radioMode;

/**
 * @locale zh
 * @brief 设置是否开启硬件解码： <br>
 *        - YES: 开启。<br>
 *        - NO: 关闭。<br>
 *        SDK 默认开启硬件解码。
 */
/**
 * @locale en
 * @brief Configure whether to enable hardware decoding:<br/>
 *        - YES: Enabled.
 *        - NO: Disabled.
 *        The SDK enables hardware decoding by default.
 */
@property (nonatomic, assign) BOOL hardwareDecode;

/**
 * @locale zh
 * @brief 设置是否开启循环播放： <br>
 *        - YES: 开启。<br>
 *        - NO:（默认）关闭。
 */
/**
 * @locale en
 * @brief Set whether to enable loop:<br/>
 *        - YES: Enabled.
 *        - NO: (default) Disabled.
 */
@property (nonatomic, assign) BOOL looping;

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL cacheEnable;

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL supportBarrageMask;

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, nullable, strong) id<TTVideoEngineNetClient> netClient;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property (nonatomic, assign, readonly) BOOL isOwnPlayer;

/**
 * @locale zh
 * @brief 播放器的显示视图。
 */
/**
 * @locale en
 * @brief The display view of the player.
 */
@property (nonatomic, strong, readonly) UIView *playerView;

/**
 * @locale zh
 * @brief 当前播放时间，单位为秒。
 */
/**
 * @locale en
 * @brief The current playback time, in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval currentPlaybackTime;
/**
 * @locale zh
 * @brief 视频总时长，单位为秒。
 */
/**
 * @locale en
 * @brief The total video duration in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;
/**
 * @locale zh
 * @brief 当前可播放时长，即缓存进度，单位为秒。
 */
/**
 * @locale en
 * @brief The current playable duration, which is the buffer progress, is measured in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;
/**
 * @locale zh
 * @brief 已观看总时长，单位为秒。
 */
/**
 * @locale en
 * @brief Total duration watched, in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval durationWatched;
/**
 * @locale zh
 * @brief 当前播放器状态，详见 [TTVideoEngineState](803941#TTVideoEngineState) 。
 */
/**
 * @locale en
 * @brief Current player status, see [TTVideoEngineState](ios-player-sdk-type-definitions#TTVideoEngineState) for details.
 */
@property (nonatomic, assign, readonly) TTVideoEngineState state;
/**
 * @locale zh
 * @brief 当前播放状态，详见 [TTVideoEnginePlaybackState](803941#TTVideoEnginePlaybackState) 。
 */
/**
 * @locale en
 * @brief The current playback state. See [TTVideoEnginePlaybackState](ios-player-sdk-type-definitions#TTVideoEnginePlaybackState) for details.
 */
@property (nonatomic, assign, readonly) TTVideoEnginePlaybackState playbackState;
/**
 * @locale zh
 * @brief 当前播放器加载状态，详见 [TTVideoEngineLoadState](803941#TTVideoEngineLoadState) 。
 */
/**
 * @locale en
 * @brief Current player load state, see [TTVideoEngineLoadState](ios-player-sdk-type-definitions#TTVideoEngineLoadState) for details.
 */
@property (nonatomic, assign, readonly) TTVideoEngineLoadState loadState;
/**
 * @locale zh
 * @brief 播放器卡顿原因，详见 [TTVideoEngineStallReason](803941#TTVideoEngineStallReason) 。
 */
/**
 * @locale en
 * @brief The reasons for player stuttering can be found in [TTVideoEngineStallReason](ios-player-sdk-type-definitions#TTVideoEngineStallReason).
 */
@property (nonatomic, assign, readonly) TTVideoEngineStallReason stallReason;
/**
 * @locale zh
 * @hidden
 * @brief 详见 TTVideoEngineAVPlayerItemAccessLog 。
 */
/**
 * @locale en
 * @brief See TTVideoEngineAVPlayerItemAccessLog for details.
 * @hidden (iOS)
 */
@property (nonatomic, strong, readonly) TTVideoEngineAVPlayerItemAccessLog *accessLog;
/**
 * @locale zh
 * @hidden
 * @brief 播放器Ready之后是否开始播放
 */
/**
 * @locale en
 * @hidden
 * @brief If pause called return NO
 */
@property (nonatomic, assign, readonly) BOOL shouldPlay;
/**
 * @locale zh
 * @hidden
 * @brief 开启自动切换档位
 */
/**
 * @locale en
 * @hidden
 * @brief if enable resolution will gained from service recommendation
 */
@property (nonatomic, assign, readonly) BOOL autoModeEnabled;
/**
 * @locale zh
 * @brief 当前视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief The current video resolution. For more details, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 */
@property (nonatomic, assign, readonly) TTVideoEngineResolutionType currentResolution;
/**
 * @locale zh
 * @hidden
 * @brief 当前播放分辨率的字符串描述
 */
/**
 * @locale en
 * @hidden
 * @brief Current qualityDesc
 */
@property (nonatomic, copy, nullable) NSString *currentQualityDesc;

/**
 * @locale zh
 * @hidden
 * @brief 用于开发期间调适 debug view，展示部分debug 信息
 */
/**
 * @locale en
 * @brief Used for debugging during development, displaying specific debug information.
 * @hidden (iOS)
 */
@property (nonatomic, strong, nullable, readonly) UIView *debugInfoView;

/**
 * @locale zh
 * @hidden
 * @brief load control interface
 */
/**
 * @locale en
 * @brief load control interface
 * @hidden (iOS)
 */
@property (nonatomic, strong, nullable) id<TTAVPlayerLoadControlInterface> loadControl;

/**
 * @locale zh
 * @hidden
 * @brief 设置支持画中画模式
 * @notes this feature only support on sys ver > iOS 14.0 default is NO , if your player will on a  PictureInPicture wrapper  at sometime , you can set this YES
 if set this YES , playerView will check if itSelf  on a PictureInPicture wrapper or not , if the result is true , the player can still play on background  app mode ,
 so this prop is just a config that determin if  playerView should check or not , this prop cannot determin if the player can still play on background  app mode
 Only condition
 */
/**
 * @locale en
 * @brief Enable Picture-in-Picture Mode
 * @notes this feature only supports on sys ver > iOS 14.0. The default is NO. If the player will be in a PictureInPicture wrapper at some time, set this to YES. If set to YES, the playerView will check if it is in a PictureInPicture wrapper. If true, the player can still play in background app mode. Hence, this prop is just a config that determines if playerView should check or not. This prop cannot determine if the player can still play in background app mode. Only condition
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL supportPictureInPictureMode API_AVAILABLE(ios(14.0));

/**
 * @locale zh
 * @hidden
 * @brief 记录播放器当前操作 Action.
 */
/**
 * @locale en
 * @brief Record the current operation action of the player.
 * @hidden (iOS)
 */
@property (nonatomic, assign, readonly) TTVideoEngineUserAction lastUserAction;

/**
 * @locale zh
 * @hidden
 * @brief 播放器是否Close完成
 */
/**
 * @locale en
 * @brief Whether the player has completed Close
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL engineCloseIsDone;
/**
 * @locale zh
 * @hidden
 * @brief 当前播放实例是否从 EnginePool 中获取
 */
/**
 * @locale en
 * @brief Whether the current playback instance is obtained from the EnginePool
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL isGetFromEnginePool;

/**
 * @locale zh
 * @hidden
 * @brief 记录分辨率的枚举和字符串描述对应关系
 * @notes
 * {
 *      @"360p":@(TTVideoEngineResolutionTypeSD),
 *      @"480p":@(TTVideoEngineResolutionTypeHD),
 *      @"720p":@(TTVideoEngineResolutionTypeFullHD),
 *      @"1080p":@(TTVideoEngineResolutionType1080P),
 *      @"2k":@(TTVideoEngineResolutionType2K),
 *      @"4k":@(TTVideoEngineResolutionType4K),
 *      @"hdr":@(TTVideoEngineResolutionTypeHDR),
 *      @"240p hdr":@(TTVideoEngineResolutionTypeHDR_240P),
 *      @"360p hdr":@(TTVideoEngineResolutionTypeHDR_360P),
 *      @"480p hdr":@(TTVideoEngineResolutionTypeHDR_480P),
 *      @"540p hdr":@(TTVideoEngineResolutionTypeHDR_540P),
 *      @"720p hdr":@(TTVideoEngineResolutionTypeHDR_720P),
 *      @"1080p hdr":@(TTVideoEngineResolutionTypeHDR_1080P),
 *      @"2k hdr":@(TTVideoEngineResolutionTypeHDR_2K),
 *      @"4k hdr":@(TTVideoEngineResolutionTypeHDR_4K)
 * };
 */
/**
 * @locale en
 * @brief Record the mapping between resolution enums and their string descriptions.
 * @notes
 * {
 *      @"360p":@(TTVideoEngineResolutionTypeSD),
 *      @"480p":@(TTVideoEngineResolutionTypeHD),
 *      @"720p":@(TTVideoEngineResolutionTypeFullHD),
 *      @"1080p":@(TTVideoEngineResolutionType1080P),
 *      @"2k":@(TTVideoEngineResolutionType2K),
 *      @"4k":@(TTVideoEngineResolutionType4K),
 *      @"hdr":@(TTVideoEngineResolutionTypeHDR),
 *      @"240p hdr":@(TTVideoEngineResolutionTypeHDR_240P),
 *      @"360p hdr":@(TTVideoEngineResolutionTypeHDR_360P),
 *      @"480p hdr":@(TTVideoEngineResolutionTypeHDR_480P),
 *      @"540p hdr":@(TTVideoEngineResolutionTypeHDR_540P),
 *      @"720p hdr":@(TTVideoEngineResolutionTypeHDR_720P),
 *      @"1080p hdr":@(TTVideoEngineResolutionTypeHDR_1080P),
 *      @"2k hdr":@(TTVideoEngineResolutionTypeHDR_2K),
 *      @"4k hdr":@(TTVideoEngineResolutionTypeHDR_4K)
 * };
 * @hidden (iOS)
 */
@property (nonatomic, nullable, strong) NSDictionary<NSString *, NSNumber *> *resolutionMap;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 激活视频显示 Render，SDK内部处理，业务无需手动调用
 */
/**
 * @locale en
 * @brief Activate video rendering. This is handled internally by the SDK, so manual invocation by the application is not required.
 * @hidden (iOS)
 */
+ (void)startOpenGLESActivity;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 暂未对外开放设置-开启测速
 * @param type 测速算法
 * @param configModel 算法预测模型配置对象
 */
/**
 * @locale en
 * @brief Settings not yet open to the public - Enable Speed Test
 * @param type Speed Measurement Algorithm
 * @param configModel Configuration Object for Algorithm Prediction Model
 * @hidden (iOS)
 */
+ (void)startSpeedPredictor:(NetworkPredictAlgoType)type congifModel:(TTVideoEngineNetworkSpeedPredictorConfigModel *)configModel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 暂未对外开放设置-设置默认ABR算法
 * @param algoType 算法类型
 */
/**
 * @locale en
 * @brief Settings not yet open to the public - Set default ABR algorithm
 * @param algoType Algorithm Type
 * @hidden (iOS)
 */
+ (void)setDefaultABRAlgorithm:(ABRPredictAlgoType)algoType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 暂未对外开放设置-设置默认ABR Flow算法
 * @param algoType 算法类型
 */
/**
 * @locale en
 * @brief Settings not yet available for public use - set default ABR Flow algorithm
 * @param algoType Algorithm Type
 * @hidden (iOS)
 */
+ (void)setDefaultABRFlowAlgoType:(ABRFlowAlgoType)algoType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 暂未对外开放设置-设置默认ABR Flow算法
 * @param algoType 算法类型
 */
/**
 * @locale en
 * @brief Currently not open to the public - Set default ABR Flow algorithm
 * @param algoType Algorithm Type
 * @hidden (iOS)
 */
+ (void)setDefaultOnceSelectAlgoType:(ABROnceAlgoType)algoType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 停止视频显示 Render，SDK内部处理，业务无需手动调用
 */
/**
 * @locale en
 * @brief Stop video rendering; handled internally by the SDK, no manual call needed from the business side
 * @hidden (iOS)
 */
+ (void)stopOpenGLESActivity;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 暂未对外开放
 * @param message message
 */
/**
 * @locale en
 * @brief Not yet available to the public.
 * @param message message
 * @hidden (iOS)
 */
+ (void)sendCustomMessage:(nullable NSDictionary *)message;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 开启日志，已过时
 * @param enabled 开启日志
 */
/**
 * @locale en
 * @brief Enable logging, deprecated
 * @param enabled Enable Logging
 * @hidden (iOS)
 */
+ (void)setLogEnabled:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("Please use setLogFlag:");

/**
 * @locale zh
 * @type api
 * @brief 设置 SDK 输出 log 模块。
 * @notes <br>
 * - 建议 debug 模式下设置为 `TTVideoEngineLogFlagDefault`，release 模式下设置为 `TTVideoEngineLogFlagNone`。
 * - 如果你在 debug 模式下开启了日志输出，一定要在发版本前检查是否关闭了日志输出。
 * @param flag 输出 log 模块，详见 [TTVideoEngineLogFlag](803941#TTVideoEngineLogFlag) 。
 */
/**
 * @locale en
 * @brief Set the SDK output log module.
 * @notes <br>
 *        - It is recommended to set to `TTVideoEngineLogFlagDefault` in debug mode and `TTVideoEngineLogFlagNone` in release mode.
 *        - If logging is enabled in debug mode, ensure to check and disable logging before releasing the version.
 * @param flag Output log module, see [TTVideoEngineLogFlag](ios-player-sdk-type-definitions#TTVideoEngineLogFlag) for details.
 */
+ (void)setLogFlag:(TTVideoEngineLogFlag)flag;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置控制台日志回调
 * @param logDelegate 回调实例
 */
/**
 * @locale en
 * @brief Set Console Log Callback
 * @param logDelegate Callback Instance
 * @hidden (iOS)
 */
+ (void)setLogDelegate:(nullable id<TTVideoEngineLogDelegate>)logDelegate;

/**
 * @locale zh
 * @type api
 * @brief 判断当前设备是否支持 Metal 渲染。
 * @return 是否支持 Metal 渲染：<br>
 *         - YES: 支持。<br>
 *         - NO: 不支持。
 */
/**
 * @locale en
 * @brief Check if the current device supports Metal rendering.
 */
+ (BOOL)isSupportMetal;

/**
 * @locale zh
 * @type api
 * @brief 判断当前设备是否支持 H.266。
 * @notes H.266 使用软解，相对比较耗性能，中高端以上机型支持开启 H.266。
 * @return 当前设备是否支持 H.266：
 *         - YES: 支持。
 *         - NO: 不支持。
 */
+ (BOOL)isSupportH266;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 忽略音频阻断
 * @param ignore 是否忽略
 */
/**
 * @locale en
 * @brief Ignore audio blocking
 * @param ignore Ignore or Not
 * @hidden (iOS)
 */
+ (void)setIgnoreAudioInterruption:(BOOL)ignore;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置使用DNS优先级，默认使用 HTTPDNS
 * @param isFirst 是否 HTTPDNS 优先
 */
/**
 * @locale en
 * @brief Set DNS priority, default to HTTPDNS.
 * @param isFirst Whether HTTPDNS is Preferred
 * @hidden (iOS)
 */
+ (void)setHTTPDNSFirst:(BOOL)isFirst;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取是否使用 HTTPDNS
 * @return 返回是否使用 HTTPDNS <br>
 *         - YES: 支持。<br>
 *         - NO: 不支持。
 */
/**
 * @locale en
 * @brief Get whether HTTPDNS is used
 * @hidden (iOS)
 */
+ (BOOL)getHTTPDNSFirst;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set the quality infos
 * @param qualityInfos quality infos
 */
/**
 * @locale en
 * @brief set the quality information
 * @param qualityInfos quality information
 * @hidden (iOS)
 */
+ (void)setQualityInfos:(NSArray *)qualityInfos;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get quality infos
 * @return quality infos
 */
/**
 * @locale en
 * @brief retrieve quality information
 * @hidden (iOS)
 */
+ (NSArray *)getQualityInfos;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set the main dns and backup dns
 */
/**
 * @locale en
 * @brief set the main DNS and backup DNS
 * @hidden (iOS)
 */
+ (void)setDNSType:(TTVideoEngineDnsType)mainDns backupDns:(TTVideoEngineDnsType)backupDns;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get dns type
 * @return dns type
 */
/**
 * @locale en
 * @brief Get DNS Type
 * @hidden (iOS)
 */
+ (NSArray *)getDNSType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set global http dns server IP address
 * @param serverIP server ip
 */
/**
 * @locale en
 * @brief Set the global HTTP DNS server IP address
 * @param serverIP server IP
 * @hidden (iOS)
 */
+ (void)setHTTPDNSServerIP:(NSString *)serverIP;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set global delegate to get extrainfo form player
 * @param protocol protocol
 */
/**
 * @locale en
 * @brief Set the global delegate to get extra info from the player
 * @param protocol protocol
 * @hidden (iOS)
 */
+ (void)configExtraInfoProtocol:(nullable id<TTVideoEngineExtraInfoProtocol>)protocol;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (void)configureAppInfo:(NSDictionary<NSString *, id>*)config;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (void)setStackSizeOptimized:(BOOL)optimized;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief config thread wait timeout, such as 1000ms, default is 0(wait forever)
 * @param timeout 过期时间
 */
/**
 * @locale en
 * @brief Configure thread wait timeout, such as 1000ms. Default is 0 (wait forever).
 * @param timeout Expiration Time
 * @hidden (iOS)
 */
+ (void)configThreadWaitMilliSeconds:(int)timeout;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取 DRM 加密视频的本地时间戳，该时间戳跟当前设备绑定。
 * @param timestamp 时间戳
 * @return 返回加密视频本地时间戳
 */
/**
 * @locale en
 * @brief Retrieve the local timestamp of the DRM-encrypted video, which is bound to the current device.
 * @param timestamp timestamp
 * @hidden (iOS)
 */
+ (nullable NSString *)encryptTimestamp:(NSInteger)timestamp;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取 TTVideoEngine 生成的 app_session_id
 * @return 返回 TTVideoEngine app_session_id
 * @notes 获取时机在 configureAppInfo 之后，否则会返回 nil
 */
/**
 * @locale en
 * @brief Retrieve the app_session_id generated by TTVideoEngine
 * @notes Should be accessed after configureAppInfo; otherwise, nil will be returned.
 * @hidden (iOS)
 */
+ (nullable NSString *)getAppSessionID;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 为后处理特效设置全局参数，或者做全局行为如模型资源下载
 */
/**
 * @locale en
 * @brief Set global parameters for post-processing effects or perform global actions such as downloading model resources.
 * @hidden (iOS)
 */
+ (void)setEffect:(NSDictionary *)param;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief OPEN API 是否强制使用 HTTPS
 */
/**
 * @locale en
 * @brief Is HTTPS mandatory for OPEN API?
 * @hidden (iOS)
 */
@property (nonatomic, assign, class) BOOL useHttpsForApiFetch;

/**
 * @locale zh
 * @type api
 * @brief 初始化播放器实例。
 * @param isOwnPlayer 是否使用自研播放器 <br>
 *         - `YES`: 火山自研播放器。
 *         - `NO`: 系统播放器。
 * @return 调用成功后，返回播放器实例。
 * @notes 强烈建议初始化时设置为 `YES` 使用火山自研播放器。如使用系统播放器，您将无法使用预加载、本地缓存等功能。
 * @list 播放
 * @order 0
 */
/**
 * @locale en
 * @brief Initialize the player instance.
 * @notes It is strongly recommended to set it to `YES` to use the Volcengine custom player during initialization. If the system player is used, preloading and local caching functionalities will be unavailable.
 * @param isOwnPlayer Whether to use the BytePlus player<br/>
 *        - `YES`: The BytePlus player.
 *        - `NO`: System player.
 * @list 播放
 */
- (instancetype)initWithOwnPlayer:(BOOL)isOwnPlayer;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 初始化播放器实例。
 * @param type 播放器类型，支持初始化系统播放器或自研播放器，
 * @notes 如果使用该方法初始化，除一些特别场景（例如商业DRM-Fairplay），强烈建议初始化时设置为 TTVideoEnginePlayerTypeVanGuard 使用火山自研播放器。
 * @return 调用成功后，返回播放器实例。
 */
/**
 * @locale en
 * @brief Initialize the player instance.
 * @notes When initializing using this method, it is strongly recommended to set TTVideoEnginePlayerTypeVanGuard to use the proprietary Volcano player, except in special scenarios (e.g., commercial DRM-Fairplay).
 * @param type Player types: supports initializing the system player or a self-developed player.
 * @hidden (iOS)
 */
- (instancetype)initWithType:(TTVideoEnginePlayerType)type;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放鉴权 token。
 * @param auth 播放鉴权 token。
 */
/**
 * @locale en
 * @brief Set the playback authentication token.
 * @param auth Playback authorization token.
 * @hidden (iOS)
 */
- (void)setPlayAuthToken:(NSString *)auth;


/**
 * @locale zh
 * @type api
 * @brief 设置字幕鉴权 token。
 * @param auth 字幕鉴权 token。
 */
/**
 * @locale en
 * @brief Set the subtitle authentication token.
 * @param auth The subtitle authentication token.
 */
- (void)setSubtitleAuthToken:(NSString *)auth;

/**
 * @locale zh
 * @type api
 * @brief 设置播放器请求自定义 header 字段。
 * @param value 键值 value。
 * @param key 键值 key。
 */
/**
 * @locale en
 * @brief Set the custom header field for player requests.
 * @param value Key-value pair value.
 * @param key Key-value pair key.
 */
- (void)setCustomHeaderValue:(NSString *)value forKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置视频 ID。
 * @param videoID 视频 ID。
 */
/**
 * @locale en
 * @brief Set the video ID.
 * @param videoID Video ID.
 * @hidden (iOS)
 */
- (void)setVideoID:(NSString *)videoID DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置视频 ID。
 * @param videoID 视频 ID。
 * @param strategy 编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
 */
/**
 * @locale en
 * @brief Set the video ID.
 * @param videoID Video ID.
 * @param strategy Codec strategies, see [TTVideoEngineCodecStrategy](ios-player-sdk-type-definitions#TTVideoEngineCodecStrategy) for details.
 * @hidden (iOS)
 */
- (void)setVideoID:(NSString *)videoID codecStrategy:(TTVideoEngineCodecStrategy)strategy;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置直播 ID
 * @param liveID 直播 ID
 */
/**
 * @locale en
 * @brief Set Live ID
 * @param liveID Live Stream ID
 * @hidden (iOS)
 */
- (void)setLiveID:(NSString *)liveID;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 * @param playItem 播放源。
 */
/**
 * @locale en
 * @brief Set the playback source.
 * @param playItem Playback source.
 * @hidden (iOS)
 */
- (void)setPlayItem:(TTVideoEnginePlayItem *)playItem DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 * @param videoInfo 播放源。
 */
/**
 * @locale en
 * @brief Set the playback source.
 * @param videoInfo Playback source.
 * @hidden (iOS)
 */
- (void)setVideoInfo:(TTVideoEngineVideoInfo *)videoInfo DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 * @param videoModel 播放源。
 */
/**
 * @locale en
 * @brief Set the playback source.
 * @param videoModel Playback source.
 * @hidden (iOS)
 */
- (void)setVideoModel:(TTVideoEngineModel *)videoModel DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置预加载源。
 * @param preloaderItem 预加载源。
 */
/**
 * @locale en
 * @brief Set the preloading source.
 * @param preloaderItem Preload source.
 * @hidden (iOS)
 */
- (void)setPreloaderItem:(TTAVPreloaderItem *)preloaderItem;

/**
 * @locale zh
 * @type api
 * @brief 设置本地视频源。
 * @param url 本地视频地址，例如 `file://xxx.xx`。
 * @notes 您可调用此方法将本地资源的地址设置给播放器。
 */
/**
 * @locale en
 * @brief Set up the local video source.
 * @notes You can call this method to set the local resource address for the player.
 * @param url Local video URL, such as `file://xxx.xx`.
 */
- (void)setLocalURL:(NSString *)url;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 通过 FileHanle 播放。
 * @param fileHandle 文件句柄。
 * @param offset 偏移量。
 * @param contentLength 文件长度。
 */
/**
 * @locale en
 * @brief Play through FileHandle.
 * @param fileHandle File handle.
 * @param offset Offset.
 * @param contentLength File length.
 * @hidden (iOS)
 */
- (void)setFileHandle:(NSFileHandle *)fileHandle offset:(long)offset contentLength:(long)contentLength;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 使用指定URL地址播放。
 * @param url 播放地址。
 */
/**
 * @locale en
 * @brief Play using the specified URL address.
 * @param url Playback URL.
 * @hidden (iOS)
 */
- (void)setDirectPlayURL:(NSString *)url DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 使用指定URL地址+cache进行播放
 * @param url 播放地址。
 * @param cacheFilePath 缓存文件路径。
 */
/**
 * @locale en
 * @brief Play using the specified URL address and cache
 * @param url Playback URL.
 * @param cacheFilePath Cache file path.
 * @hidden (iOS)
 */
- (void)setDirectPlayURL:(NSString *)url cacheFile:(nullable NSString* )cacheFilePath DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置内存数据源播放源。
 * @param datasource 播放源。
 */
/**
 * @locale en
 * @brief Set memory data source for playback.
 * @param datasource Playback source.
 * @hidden (iOS)
 */
- (void)setMemoryDataSource:(id<MemoryDataSourceProtocol>) datasource;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置系统播放器的播放源。
 * @param playerItem 播放源。
 */
/**
 * @locale en
 * @brief Set the playback source for the system player.
 * @param playerItem Playback source.
 * @hidden (iOS)
 */
- (void)setAVPlayerItem:(AVPlayerItem *)playerItem;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源，支持Backup播放源。
 * @param urls 播放源。
 */
/**
 * @locale en
 * @brief Set the playback source, supporting Backup playback source.
 * @param urls Playback source.
 * @hidden (iOS)
 */
- (void)setDirectPlayURLs:(NSArray<NSString *> *)urls DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置数据加载 group id
 * @notes 业务无需设置。
 * @param groupid group id
 */
/**
 * @locale en
 * @brief Set Data Loading Group ID
 * @notes No configuration is required for the service.
 * @param groupid group id
 * @hidden (iOS)
 */
- (void)setMDLGroupID:(NSString*)groupid;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置自定义的埋点信息。
 * @notes 业务无需设置。
 * @param key 埋点key。
 * @param value 埋点value。
 */
/**
 * @locale en
 * @brief Set custom event tracking information.
 * @notes Business configuration is not required.
 * @param key Tracking key.
 * @param value Tracking value.
 * @hidden (iOS)
 */
- (void)setCustomInfo:(TTVideoEngineCustomInfoKey)key value:(id)value;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置 Mask 头长度。
 * @notes 业务无需设置。
 * @param maskHeadLen mask 头长度。
 */
/**
 * @locale en
 * @brief Set Mask header length.
 * @notes No business configuration is required.
 * @param maskHeadLen Length of the mask header.
 * @hidden (iOS)
 */
- (void)setMaskHeadLen:(NSInteger)maskHeadLen;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置蒙版弹幕 URL。
 * @param url 蒙版弹幕 URL。
 */
/**
 * @locale en
 * @brief Set Mask Danmaku URL.
 * @param url Masked barrage URL.
 * @hidden (iOS)
 */
- (void)setBarrageMaskURL:(NSString *)url;

/**
 * @locale zh
 * @type api
 * @brief 设置蒙版弹幕 URL。
 * @param url 蒙版弹幕 URL。
 * @param fileHash 文件的唯一标识，建议使用文件 hash 值或 URL MD5 值。
 */
/**
 * @locale en
 * @brief Set masked barrage URL.
 * @param url Masked bullet URL.
 * @param fileHash The unique identifier for the file is recommended to be the file hash value or the URL MD5 value.
 */
- (void)setBarrageMaskURL:(NSString *)url fileHash:(nullable NSString *)fileHash;

/**
 * @locale zh
 * @type api
 * @brief 准备播放。
 * @notes 该方法适用于预渲染策略。您设置播放源后，需要调用此方法，播放器会渲染第一帧，但不会马上播放。
 * @list 播放
 * @order 2
 */
/**
 * @locale en
 * @brief Ready to play.
 * @notes This method is suitable for prerendering strategies. After setting the playback source, calling this method will render the first frame, but it will not start playing immediately.
 * @list 播放
 */
- (void)prepareToPlay;

/**
 * @locale zh
 * @type api
 * @brief 开始播放。
 * @list 播放
 * @order 3
 */
/**
 * @locale en
 * @brief Start playing.
 * @list 播放
 */
- (void)play;

/**
 * @locale zh
 * @type api
 * @brief 暂停播放。
 * @list 播放
 * @order 4
 */
/**
 * @locale en
 * @brief Pause playback.
 * @list 播放
 */
- (void)pause;

/**
 * @locale zh
 * @type api
 * @brief 暂停播放。
 * @param async 是否异步暂停。
 */
/**
 * @locale en
 * @brief Pause playback.
 * @param async Indicates whether asynchronous suspension is enabled.
 */
- (void)pause:(BOOL)async;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 异步暂停，避免阻塞主线程。
 */
/**
 * @locale en
 * @brief Asynchronous suspension to avoid blocking the main thread.
 * @hidden (iOS)
 */
- (void)pauseAsync NS_DEPRECATED(2_0,2_0,2_0,2_0,"use pause:");

/**
 * @locale zh
 * @type api
 * @brief 停止播放。
 * @list 播放
 * @order 5
 */
/**
 * @locale en
 * @brief Stop playback.
 * @list 播放
 * @order 5
 */
- (void)stop;

/**
 * @locale zh
 * @type api
 * @brief 关闭销毁播放器。
 * @notes 销毁播放器实例后，不能再调用任何方法。您可以将 `engine` 实例设置为 `nil`，防止再次调用。
 */
/**
 * @locale en
 * @brief Close and destroy the player.
 * @notes After destroying the player instance, calling any methods is no longer possible. You can set the `engine` instance to `nil` to prevent any further calls.
 */
- (void)close;

/**
 * @locale zh
 * @type api
 * @brief 异步关闭销毁播放器。
 * @notes  <br>
 *       - 此方法异步销毁播放器实例，不影响主线程。<br>
 *       - 异步关闭有助于避免视频上下滑动中造成 UI 卡顿。<br>
 *       - 销毁播放器实例后，不能再调用任何方法。您可以将 `engine` 实例设置为 `nil`，防止再次调用。
 * @list 播放
 * @order 6
 */
/**
 * @locale en
 * @brief Asynchronously close and destroy the player.
 * @list 播放
 * @order 6
 * @notes <br>
 *        - This method asynchronously destroys the player instance without affecting the main thread.<br>
 *        - Asynchronous closing helps avoid UI stuttering when scrolling the video up and down.<br>
 *        - After destroying the player instance, no methods can be called anymore. You can set the `engine` instance to `nil` to prevent further calls.
 */
-(void)closeAysnc;

/**
 * @locale zh
 * @type api
 * @brief 跳转至指定时间戳位置播放。
 * @param currentPlaybackTime 指定位置。
 * @param finised 跳转完成回调。
 * @notes 您可以调用此方法实现拖拽进度条到指定时间开始播放的功能。
 */
/**
 * @locale en
 * @brief Seek to the specified timestamp and play.
 * @notes You can use this method to enable dragging the progress bar to start playback from a specified time.
 * @param currentPlaybackTime Specify the location.
 * @param finised Callback after successful navigation.
 */
- (void)setCurrentPlaybackTime:(NSTimeInterval)currentPlaybackTime
                      complete:(void(^)(BOOL success))finised;

/**
 * @locale zh
 * @type api
 * @brief 跳转至指定时间戳位置播放。
 * @param currentPlaybackTime 指定位置。
 * @param finised 跳转完成回调。
 * @param renderComplete 渲染完成回调。
 * @notes 您可以调用此方法实现拖拽进度条到指定时间开始播放的功能。
 * @list 播放
 * @order 7
 */
/**
 * @locale en
 * @list 播放
 * @order 7
 * @brief Jump to a specified timestamp for playback.
 * @notes You can call this method to implement the functionality of dragging the progress bar to start playback at a specified time.
 * @param currentPlaybackTime Specify the location.
 * @param finised Callback after navigation is complete.
 * @param renderComplete Callback upon render completion.
 */
- (void)setCurrentPlaybackTime:(NSTimeInterval)currentPlaybackTime
                      complete:(void(^)(BOOL success))finised
                renderComplete:(void(^)(void)) renderComplete;

/**
 * @locale zh
 * @type api
 * @brief 内部封装 NSTimer 定时器，方便您在 block 回调中更新播放进度。
 * @param interval 回调时间间隔，单位为秒。
 * @param queue 指定线程队列。
 * @param block 回调。
 */
/**
 * @locale en
 * @brief Encapsulates NSTimer internally, allowing updating of playback progress conveniently within the block callback.
 * @param interval Callback interval, measured in seconds.
 * @param queue Specify the thread queue.
 * @param block Callback.
 */
- (void)addPeriodicTimeObserverForInterval:(NSTimeInterval)interval
                                     queue:(dispatch_queue_t)queue
                                usingBlock:(void (^)(void))block;

/**
 * @locale zh
 * @type api
 * @brief 与 `addPeriodicTimeObserverForInterval:queue:usingBlock` 配对使用。
 * @notes 播放器销毁后切记一定要调用该方法，否则可能产生内存泄漏。
 */
/**
 * @locale en
 * @brief Use in conjunction with `addPeriodicTimeObserverForInterval:queue:usingBlock`.
 * @notes After the player is destroyed, make sure to call this method, otherwise memory leaks may occur.
 */
- (void)removeTimeObserver;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 内部封装 NSTimer 定时器，block 回调下载速度。
 * @param interval 回调时间间隔，单位为秒。
 * @param queue 指定线程队列。
 * @param block 回调。
 */
/**
 * @locale en
 * @brief Encapsulates NSTimer internally, with a block callback for download speed.
 * @param interval Callback interval, in seconds.
 * @param queue Specify the thread queue.
 * @param block Callback.
 * @hidden (iOS)
 */
- (void)addSpeedTimeObserverForInterval:(NSTimeInterval)interval
                                  queue:(dispatch_queue_t)queue
                             usingBlock:(void (^)(long long speed))block;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 与 `addSpeedTimeObserverForInterval:queue:usingBlock` 配对使用。
 * @notes 播放器销毁后切记一定要调用该方法，否则可能产生内存泄漏。
 */
/**
 * @locale en
 * @brief Use in conjunction with `addSpeedTimeObserverForInterval:queue:usingBlock`.
 * @notes After destroying the player, make sure to call this method; otherwise, memory leaks may occur.
 * @hidden (iOS)
 */
- (void)removeSpeedTimeObserver;

/**
 * @locale zh
 * @type api
 * @brief 播放 Vid 视频源时，获取所有分辨率的值。
 * @return 返回所有分辨率值数组。
 */
/**
 * @locale en
 * @brief When playing Vid video sources, obtain the values of all resolutions.
 */
- (nullable NSArray<NSNumber *> *)supportedResolutionTypes;

/**
 * @locale zh
 * @type api
 * @brief 播放 Vid 视频源时，获取所有分辨率的描述。
 * @return 返回所有分辨率描述数组。
 */
/**
 * @locale en
 * @brief Get descriptions of all resolutions when playing Vid video sources.
 */
- (nullable NSArray<NSString *> *)supportedQualityInfos;

/**
 * @locale zh
 * @type api
 * @brief 设置起播分辨率或者切换分辨率。
 * @return 方法调用结果：<br>
 *         - YES: 成功。<br>
 *         - NO: 失败。
 * @notes 您可在播放前调用此方法预设分辨率，也可在播放中调用此方法切换分辨率。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief Set the initial resolution or switch the resolution.
 * @notes This method can be called to preset the resolution before playback or to switch the resolution during playback.
 * @param resolution Video resolution. For details, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 */
- (BOOL)configResolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置起播或者切换分辨率。
 * @return 方法调用结果：<br>
 *         - YES: 成功。<br>
 *         - NO: 失败。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param map 扩展参数。
 */
/**
 * @locale en
 * @brief Set up initial playback or switch resolution.
 * @param resolution The video resolution can be found in [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 * @param map Extension Parameters.
 * @hidden (iOS)
 */
- (BOOL)configResolution:(TTVideoEngineResolutionType)resolution params:(nullable NSDictionary *)map;

/**
 * @locale zh
 * @type api
 * @brief 设置起播或者切换分辨率。
 * @return 方法调用结果：<br>
 *         - YES: 成功。<br>
 *         - NO: 失败。
 * @notes 您可在播放前调用此方法预设分辨率，也可在播放中调用此方法切换分辨率。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param completion 切换分辨率完成回调。
 */
/**
 * @locale en
 * @brief Set the initial resolution or switch the resolution.
 * @notes You can call this method to preset the resolution before playback, or use it to switch the resolution during playback.
 * @param resolution Video resolution. See [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @param completion Callback after switching resolution.
 */
- (void)configResolution:(TTVideoEngineResolutionType)resolution
              completion:(void(^)(BOOL success, TTVideoEngineResolutionType completeResolution))completion;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置起播分辨率。
 * @param resolution 分辨率，详见 TTVideoEngineResolutionType{@link #TTVideoEngineResolutionType}
 * @param map 扩展参数
 * @param completion 切换分辨率完成回调。
 */
/**
 * @locale en
 * @brief Set the initial playback resolution.
 * @param resolution resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details
 * @param map Extended Parameters
 * @param completion Callback after switching resolution.
 * @hidden (iOS)
 */
- (void)configResolution:(TTVideoEngineResolutionType)resolution params:(NSDictionary *)map
completion:(void(^)(BOOL success, TTVideoEngineResolutionType completeResolution))completion;

/**
 * @locale zh
 * @type api
 * @brief 设置起播或者切换分辨率。
 * @return 方法调用结果：<br>
 *         - YES: 成功。<br>
 *         - NO: 失败。
 * @notes 您可在播放前调用此方法预设分辨率，也可在播放中调用此方法切换分辨率。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param completion 切换分辨率完成回调，如果出现错误，回调中将携带错误信息。
 */
/**
 * @locale en
 * @brief Set the initial resolution or switch the resolution.
 * @notes You can call this method to preset the resolution before playback, or use it to switch the resolution during playback.
 * @param resolution Video resolution. See [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @param completion Callback after switching resolution, if an error occurs, the callback will contain the error information.
 */
- (void)configResolution:(TTVideoEngineResolutionType)resolution
          withCompletion:(void(^)(BOOL success, NSError* __nullable err, TTVideoEngineResolutionType completeResolution))completion;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置起播分辨率。
 * @param resolution 分辨率，详见 TTVideoEngineResolutionType{@link #TTVideoEngineResolutionType}
 * @param map 扩展参数
 * @param completion 切换分辨率完成回调，如果出现错误，回调中将携带错误信息。
 */
/**
 * @locale en
 * @brief Set the initial playback resolution.
 * @param resolution resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details
 * @param map Extended Parameters
 * @param completion Callback after switching resolution, if an error occurs, the callback will contain the error information.
 * @hidden (iOS)
 */
- (void)configResolution:(TTVideoEngineResolutionType)resolution params:(NSDictionary *)map
          withCompletion:(void(^)(BOOL success, NSError* __nullable err, TTVideoEngineResolutionType completeResolution))completion;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置Gear代理。
 * @notes 业务无需设置。
 * @param delegate 回调，详见 TTVideoEngineGearStrategyDelegate{@link #TTVideoEngineGearStrategyDelegate}。
 * @param userData user data。
 */
/**
 * @locale en
 * @brief Set Gear agent.
 * @notes No configuration required for the service.
 * @param delegate Callback, see TTVideoEngineGearStrategyDelegate for details
 * @param userData user data.
 * @hidden (iOS)
 */
- (void)setGearStrategyDelegate:(id<TTVideoEngineGearStrategyDelegate>)delegate userData:(nullable id)userData;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取当前预加载源。
 * @return 预加载源。
 */
/**
 * @locale en
 * @brief Retrieve the current preload source.
 * @hidden (iOS)
 */
- (nullable TTAVPreloaderItem*)getCurPreloaderItem;

/**
 * @locale zh
 * @type api
 * @brief 获取指定分辨率的视频大小，单位为 byte。
 * @return 视频大小，单位为 byte。
 * @param type 分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief Get the size of the video with the specified resolution, measured in bytes.
 * @param type The resolution. For more details, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 */
- (NSInteger)videoSizeForType:(TTVideoEngineResolutionType)type;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 清空 playview。
 * @notes 业务无需调用。
 */
/**
 * @locale en
 * @brief Clear playview.
 * @notes No need for the business to call.
 * @hidden (iOS)
 */
- (void)clearScreen NS_DEPRECATED(2_0,2_0,2_0,2_0,"Don't use it, not supportted any more!");

/**
 * @locale zh
 * @type api
 * @brief 获取当前渲染 CVPixelBufferRef。
 * @return 返回当前渲染 CVPixelBufferRef。
 * @notes 您可以通过该方法实现自定义渲染。
 */
/**
 * @locale en
 * @brief Obtain the current rendered CVPixelBufferRef.
 * @notes You can achieve custom rendering through this method.
 */
- (nullable CVPixelBufferRef)copyPixelBuffer;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置DrmCreater。
 * @notes 业务无需设置。
 * @param drmCreater drmCreater。
 */
/**
 * @locale en
 * @brief Set DrmCreater.
 * @notes No configuration is needed for the service.
 * @param drmCreater drmCreater.
 * @hidden (iOS)
 */
- (void)setDrmCreater:(nullable DrmCreater)drmCreater;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置 fairplay 播放信息。
 * @param data fairplay 证书。
 * @param id fairplay id
 * @param url 请求 fairplay license 地址。
 */
/**
 * @locale en
 * @brief Set FairPlay playback information.
 * @param data fairplay certificate.
 * @param id fairplay ID
 * @param url Request the FairPlay license URL.
 * @hidden (iOS)
 */
- (void)setFpsCertificateData:(NSData*)data fpsId:(NSInteger)id fpsLicenseUrl:(NSString*)url;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 判断当前播放是否为 DASH 视频源。
 * @return 是否为 DASH 视频源：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @brief Check whether the current playback is a DASH video source.
 * @hidden (iOS)
 */
- (BOOL)isDashSource;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 判断当前播放是否为 BASH 视频源。
 * @return 是否为 BASH 视频源：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @brief Check whether the current playback is from a BASH video source.
 * @hidden (iOS)
 */
- (BOOL)isBashSource;

/** return support HDR */
/**
 * @locale zh
 * @type api
 * @brief 判断当前设备是否支持 HDR 播放。
 * @return 是否支持 HDR：<br>
 *         - YES: 支持。<br>
 *         - NO: 不支持。
 * @notes SDK 内部有支持 HDR 播放的设备白名单。SDK 会检查当前设备是否在白名单中，以确定当前设备是否支持 HDR 播放。
 */
/**
 * @locale en
 * @brief Check if the current device supports HDR playback.
 * @notes The SDK contains a list of devices that support HDR playback. The SDK checks whether the current device is on the list to determine if it supports HDR playback.
 */
- (BOOL)isSupportHDR;

/**
 * @locale zh
 * @type api
 * @brief 判断当前设备是否支持超分。
 * @return 是否支持超分：<br>
 *         - YES: 支持。<br>
 *         - NO: 不支持。
 * @notes SDK 内部有支持超分的设备白名单。SDK 会检查当前设备是否在白名单中，以确定当前设备是否支持超分。
 */
/**
 * @locale en
 * @brief Check whether the current device supports super-resolution.
 * @notes The SDK contains a list of devices that support super-resolution. The SDK checks if the current device is on the list to determine if it supports super-resolution.
 */
- (BOOL)isSupportSR;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取mem播放地址。
 * @notes 业务无需设置。
 * @param infos 播放源；
 * @return 返回mem播放地址。
 */
/**
 * @locale en
 * @brief Get the mem playback address.
 * @notes Business does not require any configuration.
 * @param infos Playback source
 * @hidden (iOS)
 */
- (NSString *)getDubbedMemUrl:(NSArray<TTVideoEngineURLInfo *> *)infos;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置effect参数。
 * @notes 业务无需设置。
 * @param effectParam effect餐素。
 */
/**
 * @locale en
 * @brief Set the effect parameter.
 * @notes No configuration required for business operations.
 * @param effectParam effect meal.
 * @hidden (iOS)
 */
- (void)setEffect:(NSDictionary *)effectParam;

/**
 * @locale zh
 * @type api
 * @brief 设置您自行实现的 `TTVideoEngineFFmpegProtocol` 协议对象，用于支持私有 FFmpeg 加密协议。
 * @param obj 您自行实现的 `TTVideoEngineFFmpegProtocol` 协议的对象。
 */
/**
 * @locale en
 * @brief Set your custom implementation of the `TTVideoEngineFFmpegProtocol` protocol object to support private FFmpeg encryption protocols.
 * @param obj An object of the self-implemented `TTVideoEngineFFmpegProtocol` protocol.
 */
- (void)setFFmpegProtocol:(id<TTVideoEngineFFmpegProtocol>) obj;

/**
 * @locale zh
 * @type api
 * @brief 截屏。
 * @param completion 截屏完成回调。
 */
/**
 * @locale en
 * @brief Take a screenshot.
 * @param completion Screenshot completed callback.
 */
- (void)snapshot:(void(^)(UIImage *))completion;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取视频源数据流流信息。
 * @return 返回视频源数据流流信息。
 */
/**
 * @locale en
 * @brief Retrieve video stream source information.
 * @hidden (iOS)
 */
- (NSArray<TTStreamInfo*> *_Nullable)getStreamInfo;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置公司 ID，用于埋点上报分析。
 * @notes 业务无需设置。
 * @param companyID 公司 ID
 */
/**
 * @locale en
 * @brief Set the company ID for event reporting and analysis.
 * @notes No configuration is required for the service.
 * @param companyID Company ID
 * @hidden (iOS)
 */
- (void)setCustomCompanyID:(nullable NSString *)companyID;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 重置Processor，播放器重用时、播放器重用前和播放器停止后调用此函数。
 */
/**
 * @locale en
 * @brief Reset the Processor. Call this function when reusing the player, before reusing the player, and after stopping the player.
 * @hidden (iOS)
 */
- (void)resetPlayerVideoProcessor;

@end

/**
 * @locale zh
 * @hidden
 */
NS_ASSUME_NONNULL_END

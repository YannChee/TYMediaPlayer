//
//  TTVideoEngine+Strategy.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/15.
//

#import "TTVideoEngine.h"
#import "TTVideoEngineMediaSource.h"
#import "TTVideoEngine+Preload.h"
#import "TTVideoEngineStrategyPreloadConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineVidSource;
@class TTVideoEngineUrlSource;

/**
 * @locale zh
 * @type keytype
 * @brief 播放器策略类型。SDK 支持多种策略，可以单个开启使用，也可以组合使用。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player strategy types. The SDK supports multiple strategies that can be used individually or in combination.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineStrategyType) {

    /**
     * @locale zh
     * @brief 默认值，不开启任何策略。
     */
    TTVideoEngineStrategyTypeNone      = 1 << 0,

    /**
     * @locale zh
     * @brief 通用策略，SDK 内部默认开启。
     */
    TTVideoEngineStrategyTypeCommon    = 1 << 1,

    /**
     * @locale zh
     * @brief 预加载策略。
     */
    TTVideoEngineStrategyTypePreload   = 1 << 2,

    /**
     * @locale zh
     * @brief 预渲染策略。
     */
    TTVideoEngineStrategyTypePreRender = 1 << 3,
};
 
/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 策略场景 - 短视频场景策略
 */
FOUNDATION_EXTERN NSString * const TTVEngineStrategySceneSmallVideo;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 策略场景 - 中视频场景策略
 */
FOUNDATION_EXTERN NSString * const TTVEngineStrategySceneShortVideo;

#pragma mark - Engine Preload Item

/**
 * @locale zh
 * @type keytype
 * @brief DirectUrl 视频源预加载 item。
 */
/**
 * @locale en
 * @type keytype
 * @brief Preload item for DirectUrl video source.
 */
@interface TTVideoEnginePreloaderURLItem (PreloadItem)

/**
 * @locale zh
 * @type api
 * @brief 构造一个 DirectUrl 播放源预加载 Item 实例。
 * @return 返回 DirectUrl 播放源预加载 Item 实例。
 * @param source DirectUrl 播放源信息 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 * @param preloadSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 */
/**
 * @locale en
 * @brief Construct a DirectUrl playback source preload Item instance.
 * @type api
 * @param source DirectUrl playback source information [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource).
 * @param preloadSize Preload data size, unit: byte. For example, 800 * 1024 represents preloading 800k data.
 */
+ (nullable instancetype)urlItemWithVideoSource:(id<TTVideoEngineMediaSource>)source preloadSize:(NSInteger)preloadSize;

@end

/**
 * @locale zh
 * @type keytype
 * @brief VID 视频源预加载 item。
 */
/**
 * @locale en
 * @type keytype
 * @brief VID video source preload item.
 */
@interface TTVideoEnginePreloaderVidItem (PreloadItem)


/**
 * @locale zh
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例。
 * @return 返回 Vid 播放源预加载 Item 实例。
 * @param source Vid 播放源。
 * @param preloadSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 */
/**
 * @locale en
 * @brief Create a Vid play source preloading Item instance.
 * @type api
 * @param source Vid playback source.
 * @param preloadSize The size of preloaded data, in bytes. For instance, 800 * 1024 indicates preloading 800k of data.
 */
+ (nullable instancetype)vidItemWithVideoSource:(id<TTVideoEngineMediaSource>)source preloadSize:(NSInteger)preloadSize;

@end


/**
 * @locale zh
 * @type keytype
 * @brief VideoModel 视频源预加载 item。
 */
/**
 * @locale en
 * @type keytype
 * @brief VideoModel video source preloading item.
 */
@interface TTVideoEnginePreloaderVideoModelItem (PreloadItem)

/**
 * @locale zh
 * @type api
 * @brief 构建一个 VideoModel 播放源预加载 Item 实例。
 * @return 返回 VideoModel 播放源预加载 Item 实例。
 * @param source VideoModel 播放源。
 * @param preloadSize 预加载数据大小，例如 800 * 1024 代表预加载 800k 数据。
 * @param params 扩展参数，您无需设置。
 */
/**
 * @locale en
 * @brief Construct a VideoModel playback source preload Item instance.
 * @type api
 * @param source VideoModel playback source.
 * @param preloadSize The size of preloaded data, for example, 800 * 1024 represents preloading 800k of data.
 * @param params Extended parameters, no configuration required.
 */
+ (nullable instancetype)videoModelItemWithVideoSource:(id<TTVideoEngineMediaSource>)source preloadSize:(NSInteger)preloadSize params:(nullable NSDictionary *)params;

@end

#pragma mark - Engine Play Source

/**
 * @locale zh
 * @type api
 * @brief 播放源相关接口。
 * @pos 8
 */
/**
 * @locale en
 * @brief APIs Related to Playback Sources.
 * @pos 8
 * @type api
 */
@interface TTVideoEngine (PlaySouce)

/**
 * @locale zh
 * @type api
 * @brief 设置播放源。
 * @list 播放
 * @order 1
 * @param source 播放源，支持以下类型：<br>
 *        - 如果使用 Vid 视频源，可设为 [TTVideoEngineVidSource](803941#TTVideoEngineVidSource) 。<br>
 *        - 如果使用 DirectUrl 视频源，可设为 [TTVideoEngineUrlSource](803941#TTVideoEngineUrlSource) 。
 */
/**
 * @locale en
 * @list 播放
 * @order 1
 * @brief Set the playback source.
 * @param source Playback sources support the following types:<br>
 *        - For Vid video sources, set [TTVideoEngineVidSource](ios-player-sdk-type-definitions#TTVideoEngineVidSource).<br>
 *        - For DirectUrl video sources, set [TTVideoEngineUrlSource](ios-player-sdk-type-definitions#TTVideoEngineUrlSource).
 */
- (void)setVideoEngineVideoSource:(id<TTVideoEngineMediaSource>)source;

/**
 * @locale zh
 * @type api
 * @brief 获取当前 `TTVideoEngine` 对象唯一标识。
 * @return 返回当前 `TTVideoEngine` 对象唯一标识，即 `TTVideoEngineMediaSource` 对象的 `uniqueId` 属性。
 * @list 预加载和预渲染策略
 * @order 7
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 7
 * @brief Obtain the unique identifier of the current `TTVideoEngine` object.
 * @return Returns the unique identifier of the current `TTVideoEngine` object, which is the `uniqueId` attribute of the `TTVideoEngineMediaSource` object.
 */
- (NSString *)getVideoEngineStrategyUniqueId;

@end

#pragma mark - Engine Strategy

/**
 * @locale zh
 * @type api
 * @brief 策略相关接口。
 * @pos 2
 */
/**
 * @locale en
 * @brief Interfaces related to strategy.
 * @pos 2
 * @type api
 */
@interface TTVideoEngine (EngineStrategy)

/**
 * @locale zh
 * @type api
 * @brief 开启策略。SDK 支持预加载和预渲染策略。
 * @list 预加载和预渲染策略
 * @order 0
 * @param strategyType 策略类型，详见 [TTVideoEngineStrategyType](803941#TTVideoEngineStrategyType) 。
 * @param scene 使用场景。SDK 策略搭配场景使用，可达到不同场景最佳实践。支持以下场景：<br>
 *              - `TTVEngineStrategySceneSmallVideo`: 短视频场景，类似抖音的 Feed 页。
 *              - `TTVEngineStrategySceneShortVideo`: 中视频场景，类似西瓜的 Feed 页。
 * @return 预渲染策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 * @notes <br>
 * - 建议在进入页面后开启策略。
 * - 关于预加载和预渲染策略的具体使用方法，详见 [iOS 短视频场景](https://www.volcengine.com/docs/4/101200)。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 0
 * @brief Enable strategy. The SDK supports preloading and prerendering strategies.
 * @notes <br>
 *        - It is recommended to enable the strategy after entering the page.
 *        - For detailed usage of preloading and prerendering strategies, refer to [iOS Short Video Scenario](https://www.volcengine.com/docs/4/101200).
 * @param strategyType Strategy type, see [TTVideoEngineStrategyType](ios-player-sdk-type-definitions#TTVideoEngineStrategyType).
 * @param scene Usage Scenarios. The SDK strategy can be paired with different scenarios to achieve best practices for each. Supported scenarios include:<br>
 *        - `TTVEngineStrategySceneSmallVideo`: Short video scenario, akin to the Feed page of Douyin.
 *        - `TTVEngineStrategySceneShortVideo`: Mid-length video scenario, similar to the Feed page of Xigua.
 */
+ (BOOL)enableEngineStrategy:(TTVideoEngineStrategyType)strategyType scene:(NSString *)scene;

/** 
 * @locale zh
 * @type api
 * @brief 开启预渲染策略。
 * @param scene 使用场景。SDK 策略搭配场景使用，可达到不同场景最佳实践。支持以下场景：<br/>
 *        - `TTVEngineStrategySceneSmallVideo`: 短视频场景，类似抖音的 Feed 页。
 *        - `TTVEngineStrategySceneShortVideo`: 中视频场景，类似西瓜的 Feed 页。
 * @list 预加载和预渲染策略
 * @return 预渲染策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @brief Enable pre-rendering strategy.
 * @param scene Usage Scenarios. SDK strategy can be used in combination with different scenarios to achieve best practices. The following scenarios are supported:<br>
 *        - `TTVEngineStrategySceneSmallVideo`: Short video scenario, similar to the feed page of TikTok.
 *        - `TTVEngineStrategySceneShortVideo`: Medium video scenario, similar to the feed page of Xigua.
 */
+ (BOOL)enableEnginePreRenderStrategy:(NSString *)scene;

/**
 * @locale zh
 * @brief 开启预加载策略。
 * @param scene 使用场景。SDK 策略搭配场景使用，可达到不同场景最佳实践。支持以下场景：<br/>
 *        - `TTVEngineStrategySceneSmallVideo`: 短视频场景，类似抖音的 Feed 页。
 *        - `TTVEngineStrategySceneShortVideo`: 中视频场景，类似西瓜的 Feed 页。
 * @list 预加载和预渲染策略
 * @return 预加载策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @brief Enable preloading strategy.
 * @param scene Usage Scenarios. The SDK strategy can be used in combination with different scenarios to achieve best practices for each. The following scenarios are supported:<br>
 *        - `TTVEngineStrategySceneSmallVideo`: Short video scenario, similar to the feed page of Douyin.
 *        - `TTVEngineStrategySceneShortVideo`: Medium video scenario, similar to the feed page of Xigua.
 */
+ (BOOL)enableEnginePreloadStrategy:(NSString *)scene;

/**
 * @locale zh
 * @brief 开启预加载策略并自定义预加载策略配置。
 * @param preloadConfig 预加载策略配置，详见 [TTVideoEngineStrategyPreloadConfig](803941#TTVideoEngineStrategyType)。
 * @param scene 使用场景。SDK 策略搭配场景使用，可达到不同场景最佳实践。支持以下场景：<br/>
 *        - `TTVEngineStrategySceneSmallVideo`: 短视频场景，类似抖音的 Feed 页。
 *        - `TTVEngineStrategySceneShortVideo`: 中视频场景，类似西瓜的 Feed 页。
 * @list 预加载和预渲染策略
 * @return 预加载策略是否开启成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @brief Enable preloading strategy and customize preloading strategy configuration.
 * @param preloadConfig The preload strategy configuration can be found in [TTVideoEngineStrategyPreloadConfig](ios-player-sdk-type-definitions#TTVideoEngineStrategyType).
 * @param scene Usage Scenarios. By combining SDK strategies with scenarios, optimal practices can be achieved for different situations. The following scenarios are supported:<br>
 *        - `TTVEngineStrategySceneSmallVideo`: Short video scenarios, similar to the Feed page of Douyin.
 *        - `TTVEngineStrategySceneShortVideo`: Medium video scenarios, similar to the Feed page of Xigua.
 */
+ (BOOL)enableEnginePreloadStrategy:(TTVideoEngineStrategyPreloadConfig *)preloadConfig scene:(NSString *)scene;

/**
 * @locale zh
 * @type api
 * @brief 清除所有策略，释放资源。
 * @notes 在退出当前页面或切换到其他页面时调用此方法。
 * @list 预加载和预渲染策略
 * @order 6
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 6
 * @brief Clear all policies and release resources.
 * @notes Call this method when exiting the current page or switching to another page.
 */
+ (void)clearAllEngineStrategy;

@end

#pragma mark - Preload|PreRender videoSource

/**
 * @locale zh
 * @type api
 * @brief 预加载和预渲染策略相关接口
 * @pos 3
 */
/**
 * @locale en
 * @brief Interfaces related to preloading and prerendering strategies
 * @pos 3
 * @type api
 */
@interface TTVideoEngine (EngineStrategySource)

/**
 * @locale zh
 * @type api
 * @brief 设置当前页面播放源列表。
 * @notes <br>
 * - 该方法用于预加载或预渲染策略。<br>
 * - 调用该方法会重置当前的播放源列表，用于首次设置播放源或在刷新页面以显示新数据时使用。
 * @list 预加载和预渲染策略
 * @order 1
 * @param videoSources 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 1
 * @brief Set the playback source list for the current page.
 * @notes <br>
 *        - This method is used for preloading or prerendering strategies.<br>
 *        - Calling this method will reset the current playback source list, which is used for initial setup of playback sources or when refreshing the page to display new data.
 * @param videoSources Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 */
+ (void)setStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources;

/**
 * @locale zh
 * @type api
 * @brief 添加播放源数据到当前播放源列表。
 * @notes <br>
 * - 该方法用于预加载或预渲染策略。<br>
 * - 该方法适用于加载更多数据的业务场景。
 * @list 预加载和预渲染策略
 * @order 2
 * @param videoSources 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 2
 * @brief Add playback source data to the current playback source list.
 * @notes <br>
 *        - This method is used for preloading or prerendering strategies.<br>
 *        - This method is suitable for business scenarios requiring the loading of additional data.
 * @param videoSources Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 */
+ (void)addStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置当前页面播放源列表。
 * @notes <br>
 * - 该方法用于预加载或预渲染策略。<br>
 * - 调用该方法会重置当前的播放源列表，用于首次设置播放源或在刷新页面以显示新数据时使用。
 * @param videoSources 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 * @param codecStrategy 编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
 */
/**
 * @locale en
 * @brief Set the playback source list for the current page.
 * @notes <br>
 *        - This method is used for preloading or prerendering strategies.<br>
 *        - Invoking this method will reset the current playlist and is used for setting the playlist for the first time or refreshing the page to display new data.
 * @param videoSources Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 * @param codecStrategy Codec strategy, see [TTVideoEngineCodecStrategy](ios-player-sdk-type-definitions#TTVideoEngineCodecStrategy) for details.
 * @hidden (iOS)
 */
+ (void)setStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources codecStrategy:(TTVideoEngineCodecStrategy)codecStrategy;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加播放源数据到当前播放源列表。
 * @notes 该方法适用于加载更多数据的业务场景。
 * @param videoSources 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 * @param codecStrategy 编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
 */
/**
 * @locale en
 * @brief Add playback source data to the current playback source list.
 * @notes This method is suitable for scenarios involving loading more data.
 * @param videoSources Playback source, refer to [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 * @param codecStrategy Encoding and decoding strategy, see [TTVideoEngineCodecStrategy](ios-player-sdk-type-definitions#TTVideoEngineCodecStrategy) for details.
 * @hidden (iOS)
 */
+ (void)addStrategyVideoSources:(NSArray<id<TTVideoEngineMediaSource>> *)videoSources codecStrategy:(TTVideoEngineCodecStrategy)codecStrategy;

@end

#pragma mark - Preload Strategy

/**
 * @locale zh
 * @type api
 * @brief 自定义预加载相关接口。
 * @pos 5
 */
/**
 * @locale en
 * @brief Custom Preloading Related Interfaces.
 * @pos 5
 * @type api
 */
@interface TTVideoEngine (EngineStrategyPreload)

/**
 * @locale zh
 * @type api
 * @brief 开始执行预加载策略。
 * @param startIndex 预加载开始位置。
 */
/**
 * @locale en
 * @brief Start executing the preloading strategy.
 * @param startIndex Start position for preloading.
 */
+ (void)startEnginePreloadStrategyWithIndex:(NSInteger)startIndex;

@end

#pragma mark - PreRender Strategy

/**
 * @locale zh
 * @type callback
 * @brief 预渲染策略相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief Callbacks Related to Pre-rendering Strategy.
 */
@protocol TTVideoEnginePreRenderDelegate <NSObject>

@optional
/**
 * @locale zh
 * @type api
 * @brief 业务层创建预渲染`TTVideoEngine` 对象。
 * @param source 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @brief The business layer creates a pre-rendered TTVideoEngine object.
 * @param source Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 */
- (TTVideoEngine * _Nullable)createPreRenderEngine:(id<TTVideoEngineMediaSource>)source;

/**
 * @locale zh
 * @type callback
 * @brief 预渲染 `TTVideoEngine` 实例将要渲染回调。
 * @notes 此回调的触发时机在 `[videoEngine setVideoEngineVideoSource:]` 设置播放源之前。您可在此回调中设置字幕。
 * @param videoEngine `videoEngine` 对象。
 * @param source 播放源
 */
/**
 * @locale en
 * @brief Callback for pre-rendering `TTVideoEngine` instance prior to rendering.
 * @type api
 * @notes The timing of this callback is before setting the playback source with `[videoEngine setVideoEngineVideoSource:]`. Subtitles can be set in this callback.
 * @param videoEngine The `videoEngine` object.
 * @param source play source
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine willPreRenderSource:(id<TTVideoEngineMediaSource>)source;

/**
 * @locale zh
 * @type callback
 * @brief 预渲染 `TTVideoEngine` 实例将要播放回调。
 * @list 预加载和预渲染策略回调
 * @order 0
 * @notes 此回调的触发时机在 `[videoEngine prepareToPlay]` 播放之前，您可在此回调中设置大部分播放参数，例如显示模式、填充模式、起播时间、超分等。
 * @param videoEngine `videoEngine` 对象。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略回调
 * @order 0
 * @brief Callback for the pre-rendering of the `TTVideoEngine` instance before playback.
 * @type api
 * @notes The callback is triggered before `[videoEngine prepareToPlay]` is called. In this callback, most playback parameters can be set, such as display mode, fill mode, start time, and super-resolution.
 * @param videoEngine The `videoEngine` object.
 */
- (void)videoEngineWillPrepare:(TTVideoEngine *)videoEngine;

@end

/**
 * @locale zh
 * @type api
 * @brief 预渲染相关方法。
 * @pos 4
 */
/**
 * @locale en
 * @brief Methods related to pre-rendering.
 * @pos 4
 * @type api
 */
@interface TTVideoEngine (EngineStrategyPreRender)

/**
 * @locale zh
 * @type api
 * @brief 设置预渲染策略的代理。
 * @list 预加载和预渲染策略
 * @order 3
 * @param delegate 预渲染策略的代理对象，详见 [TTVideoEnginePreRenderDelegate](518261#TTVideoEnginePreRenderDelegate) 。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 3
 * @brief Set the proxy for the pre-rendering strategy.
 * @param delegate The proxy object for the pre-rendering strategy. For more details, see [TTVideoEnginePreRenderDelegate](ios-player-sdk-callbacks#TTVideoEnginePreRenderDelegate).
 */
+ (void)setPreRenderVideoEngineDelegate:(id<TTVideoEnginePreRenderDelegate>)delegate;

/**
 * @locale zh
 * @type api
 * @brief 通过播放源获取预渲染 `TTVideoEngine` 对象。
 * @return 返回预渲染 `TTVideoEngine` 对象实例。
 * @param source 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @brief Get a pre-rendered `TTVideoEngine` object through the playback source.
 * @param source Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 */
+ (TTVideoEngine * _Nullable)getPreRenderVideoEngineWithVideoSource:(id<TTVideoEngineMediaSource>)source;

/**
 * @locale zh
 * @type api
 * @brief 通过播放源获取预渲染 `TTVideoEngine` 对象播放器视图。
 * @return 返回预渲染 `TTVideoEngine` 对象播放器视图。
 * @notes 您通过 `TTVideoEngine` 对象播放器视图是否为 `nil` 判断预渲染是否完成。
 * @list 预加载和预渲染策略
 * @order 4
 * @param source 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 4
 * @brief Obtain the pre-rendered `TTVideoEngine` player view through the playback source.
 * @notes Check whether pre-rendering is complete by checking if the player view of the `TTVideoEngine` object is `nil`.
 * @param source Playback source, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource) for details.
 */
+ (UIView * _Nullable)getPreRenderFinishedPlayerViewWithVideoSource:(id<TTVideoEngineMediaSource>)source;

/**
 * @locale zh
 * @type api
 * @brief 通过播放源获取预渲染 `TTVideoEngine` 对象。
 * @return 返回预渲染 `TTVideoEngine` 对象。
 * @notes 您可通过 `TTVideoEngine` 对象是否为 `nil` 判断预渲染是否完成。
 * @list 预加载和预渲染策略
 * @order 5
 * @param source 播放源，详见 [TTVideoEngineMediaSource](803941#TTVideoEngineMediaSource) 。
 */
/**
 * @locale en
 * @list 预加载和预渲染策略
 * @order 5
 * @brief Obtain a pre-rendered `TTVideoEngine` object through the playback source.
 * @notes You can determine whether the pre-rendering is complete by checking if the `TTVideoEngine` object is `nil`.
 * @param source For playback source details, see [TTVideoEngineMediaSource](ios-player-sdk-type-definitions#TTVideoEngineMediaSource).
 */
+ (TTVideoEngine * _Nullable)getPreRenderFinishedVideoEngineWithVideoSource:(id<TTVideoEngineMediaSource>)source;

@end

NS_ASSUME_NONNULL_END

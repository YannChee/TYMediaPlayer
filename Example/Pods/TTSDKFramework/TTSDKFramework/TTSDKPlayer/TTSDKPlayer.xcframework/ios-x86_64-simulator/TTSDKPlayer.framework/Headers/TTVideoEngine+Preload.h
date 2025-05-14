//
//  TTVideoEngine+Preload.h
//  TTVideoEngine
//
//  Created by 黄清 on 2018/11/28.
//

#import "TTVideoEngine.h"
#import "TTVideoEngineUtil.h"
#import "TTVideoEngineLoadProgress.h"
#import "TTVideoEngine+AutoRes.h"
#import "TTVideoEngine+SubTitle.h"

NS_ASSUME_NONNULL_BEGIN

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
typedef NS_ENUM(NSInteger, TTMDLGETValueType) {
    TTMDLGetChecksumInfo    =  624,
};

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
typedef NS_ENUM(NSInteger, TTCMPreConnectRunMode) {
    TTCMPreConnectRunModeLimit,
    TTCMPreConnectRunModeFull,
};

/**
 * @locale zh
 * @hidden
 * @brief Default priority, will enque task from the back.
 */
FOUNDATION_EXTERN const NSInteger TTVideoEnginePrloadPriorityDefault;

/**
 * @locale zh
 * @hidden
 * @brief Default priority, will exec when no other play/preload task
 */
FOUNDATION_EXTERN const NSInteger TTVideoEnginePrloadPriorityIDLE;

/**
 * @locale zh
 * @hidden
 * @brief High priority, will enque task from the front.
 */
FOUNDATION_EXTERN const NSInteger TTVideoEnginePrloadPriorityHigh;

/**
 * @locale zh
 * @hidden
 * @brief Highest priority, will enque task from the front ,and only be canceled by the key.
 */
FOUNDATION_EXTERN const NSInteger TTVideoEnginePrloadPriorityHighest;

/**
 * @locale zh
 * @hidden
 */
typedef NSString *_Nullable(^TTVideoEngineReturnStringBlock)(TTVideoEnginePlayAPIVersion apiVersion, NSString *vid);
/**
 * @locale zh
 * @hidden
 * @brief 下载速度回调
 */
typedef void (^TTVideoEngineSpeedInfoBlock)(int64_t timeIntervalMs, int64_t size, NSString *type, NSString *key,  NSString *_Nullable info, NSDictionary * _Nullable extraDic);


@class AVMDLDataLoaderConfigure;
@class TTVideoEngineLocalServerCDNLog;
@class TTVideoEngineLocalServerTaskInfo;
@class TTVideoEngineLocalServerConfigure;
@class TTVideoEngineLocalServerCacheInfo;
@class TTVideoEnginePreloaderVideoModelItem;
@class TTVideoEnginePreloaderURLItem;
@class TTVideoEngineLoadProgress;
@class TTVideoEngineUrlSource;
@class TTVideoEngineDirectURLItem;
@class TTVideoEnginePreloaderSubtitleItem;

@protocol TTVideoEngineInternalDelegate;

/**
 * @locale zh
 * @type keytype
 * @brief 该协议描述使用外部自定义 DNS 解析 DataSource。
 */
/**
 * @locale en
 * @type keytype
 * @brief This protocol describe the deteil of extern DNS Parser's result.
 */
@protocol TTVideoEngineExternDNSParserDataSource<NSObject>

@required
/**
 * @locale zh
 * @brief 解析的域名。
 */
/**
 * @locale en
 * @type api
 * @brief host name
 */
- (NSString *)hostName;

/**
 * @locale zh
 * @brief 域名解析出的 IP 列表。
 */
/**
 * @locale en
 * @type api
 * @brief IP list of host name.
 */
- (NSArray *)ipList;

/**
 * @locale zh
 * @brief 解析过期时间，单位：秒。
 */
/**
 * @locale en
 * @type api
 * @brief The effective duration of this result. (unit: second)
 */
- (NSInteger)ttl;

@end

/**
 * @locale zh
 * @type callback
 * @brief 该协议描述使用外部 DNS 解析 Delegate。
 */
/**
 * @locale en
 * @type callback
 * @brief This protocol provide the origin parm of DNS entry.
 */
@protocol TTVideoEngineExternDNSParserDelegate<NSObject>

@required

/**
 * @locale zh
 * @type callback
 * @brief 提供需要被解析的 URL。
 * @param urlString 需要被解析的 URL。
 */
/**
 * @locale en
 * @type api
 * @brief Provide the url which you want to parse.
 * @param urlString The URL that needs to be parsed.
 */
- (void)setUrl:(NSString *)urlString;

@end

@class TTVideoEngineMasterPlaylist;

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 预加载相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief Callbacks related to preloading.
 * @hidden 
 */
@protocol TTVideoEnginePreloadDelegate <NSObject>

@optional
/// Api for fetch video model by vid;
- (NSString *)apiStringForVid:(NSString *)videoId resolution:(TTVideoEngineResolutionType)resolution DEPRECATED_MSG_ATTRIBUTE("see TTVideoEnginePreloaderVidItem");
/// Authentication for fetch video model by vid;
- (nullable NSString *)authStringForVid:(NSString *)videoId resolution:(TTVideoEngineResolutionType)resolution DEPRECATED_MSG_ATTRIBUTE("see TTVideoEnginePreloaderVidItem");

/// Local server, An error occurred.
- (void)preloaderErrorForVid:(nullable NSString *)vid errorType:(TTVideoEngineDataLoaderErrorType)errorType error:(NSError *)error;
/// Local server, Log update.
/// ⚠️ Called in an asynchronous thread, Serial queue.
- (void)localServerLogUpdate:(NSDictionary *)logInfo;
/// Local server, Test speed.
/// ⚠️ Called in an asynchronous thread, Serial queue.
- (void)localServerTestSpeedInfo:(NSTimeInterval)timeInternalMs size:(NSInteger)sizeByte;
/// Local server, task progress.
/// ⚠️ Called in an asynchronous thread, Serial queue.
- (void)localServerTaskProgress:(TTVideoEngineLocalServerTaskInfo *)taskInfo;
/// Local server, getstring value by key.
/// ⚠️ Called in an asynchronous thread.
- (NSString *)localServerGetStringBykey:(NSString *)key code:(NSInteger)code type:(NSInteger)type;
/// cdn log
- (void)localServerCDNLog:(NSDictionary *)log;
/// load progress
/// ⚠️ Called in an asynchronous thread, Serial queue.
- (void)mediaLoaderLoadProgress:(TTVideoEngineLoadProgress *)loadProgress;

- (NSDictionary*)localServerGetCustomHttpHeader:(NSString *)url;

- (void)onMultiNetworkSwitch:(NSString*) targetNetwork currentNetwork:(NSString *)currentNetwork;

- (void)onTaskOpenWithInfo:(NSDictionary *)info;

@optional
- (void)reportDownloadStatus:(NSInteger)downloadStatus;
- (int)indexOfVariantOnPreloadMasterPlaylist:(TTVideoEngineMasterPlaylist *)masterPlaylist;
- (int)indexOfRendtionOnPreloadMasterPlaylist:(TTVideoEngineMasterPlaylist *)masterPlaylist;

@end


/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 预加载相关回调，支持设置多个 Listerner
 */
/**
 * @locale en
 * @type callback
 * @brief Callbacks related to preloading, supporting multiple listeners.
 * @hidden 
 */
@protocol TTVideoEnginePreloadListener <NSObject>
/// ⚠️ Called in an asynchronous thread, Serial queue.
- (void)onTestSpeedInfo:(NSTimeInterval)timeInternalMs size:(NSInteger)sizeByte;
/// report header log
- (void)onResponseHeadersLog:(NSString * _Nonnull)info;
@end

/**
 * @locale zh
 * @type api
 * @brief 播放器引擎。
 */
/**
 * @locale en
 * @brief Player Engine.
 * @type api
 */
@interface TTVideoEngine()

/**
 * @locale zh
 * @hidden
 * @brief Local server switch.
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief Local server switch.
 */
@property(nonatomic, assign) BOOL proxyServerEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL medialoaderEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL medialoaderNativeEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL medialoaderProtocolRegistered;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL hlsproxyProtocolRegistered;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) NSInteger medialoaderCdnType;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) NSInteger mediaLoaderPcdnTimerInterval;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL firstNativeMdlEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) NSInteger netSpeedUpdateInterval;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, nullable, weak) id<TTVideoEngineInternalDelegate>internalDelegate;

@end

@class TTVideoEnginePreloaderVidItem;
@class TTVideoEngineMultiEncodingUrlSource;
@class TTVideoEngineCopyCacheItem;

/**
 * @locale zh
 * @type api
 * @brief 自定义预加载和本地播放缓存相关接口。
 * @pos 7
 */
/**
 * @locale en
 * @brief Custom preloading and local playback caching related APIs.
 * @pos 7
 * @type api
 */
@interface TTVideoEngine (Preload)

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放地址。
 * @param url 播放地址
 * @param key 缓存key
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set play url
 * @param url url
 * @param key cache key
 */
- (void)ls_setDirectURL:(NSString *)url key:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放地址，支持backup地址。
 * @param urls 主备URL数组。
 * @param key 缓存key
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set play url, support backup url
 * @param urls urls info
 * @param key cache key
 */
- (void)ls_setDirectURLs:(NSArray<NSString *> *)urls key:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源
 * @param urlSource 播放源。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set url source model
 * @param urlSource url source
 */
- (void)ls_setDirectURLSource:(TTVideoEngineUrlSource *)urlSource DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放地址。
 * @param urlSource 播放源。
 * @param strategy 播放策略。
 */
/**
 * @locale en
 * @brief Set the playback URL.
 * @param urlSource Playback source.
 * @param strategy Playback Strategy.
 * @hidden (iOS)
 */
- (void)ls_setMultiEncodingUrlSource:(TTVideoEngineMultiEncodingUrlSource *)urlSource withCodecStrategy:(TTVideoEngineCodecStrategy)strategy DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set url
 */
- (void)ls_setDirectURL:(NSString *)url key:(NSString *)key videoId:(nullable NSString *)videoId extraInfo:(nullable NSString *)extraInfo DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");;
/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set url
 */
- (void)ls_setDirectURLs:(NSArray<NSString *> *)urls key:(NSString *)key videoId:(nullable NSString *)videoId extraInfo:(nullable NSString *)extraInfo DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置播放源。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set url item
 */
- (void)ls_setDirectURLItem:(TTVideoEngineDirectURLItem *)urlItem DEPRECATED_MSG_ATTRIBUTE("use setVideoEngineVideoSource:");;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置group id。
 * @notes 业务无需设置。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set MDL groupID, use to correlate play event and preload event
 * @notes No business settings required.
 */
- (void)ls_setGroupID:(NSString*)groupid;


/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief MDL播放相关的option key
 */
/**
 * @locale en
 * @hidden for internal use only
 * @type keytype
 * @brief MDL option key
 */
typedef NS_ENUM(NSInteger, MdlKeyPlayInfo) {
    MdlKeyPlayInfoRenderStart = 6230,
    MdlKeyPlayInfoPlayingPos  = 6231,
    MdlKeyPlayInfoLoadPercent = 6232,
    MdlKeyPlayInfoBufferingStart = 6233,
    MdlKeyPlayInfoBufferingEnd = 6234,
    MdlKeyPlayInfoCurrentBuffer = 6235,
    MdlKeyPlayInfoSeekAction = 6236,
};

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置 trace id。
 * @notes 业务无需设置。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief set trace id
 * @notes No configuration needed for business operations.
 */
- (void)ls_setPlayInfo:(NSInteger)key Traceid:(NSString *)traceId Value:(int64_t)value;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置下载速度回调。
 * @param block 回调。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Set the download speed callback.
 * @param block callback function
 */
- (void)setSpeedPredictBlock:(nullable TTVideoEngineSpeedInfoBlock)block;

#pragma mark - Module Manager

/**
 * @locale zh
 * @type api
 * @brief 数据加载模块配置，详见 [TTVideoEngineLocalServerConfigure](803941#TTVideoEngineLocalServerConfigure) 。
 */
/**
 * @locale en
 * @type api
 * @brief MDL config，详见 [TTVideoEngineLocalServerConfigure]。
 */
+ (TTVideoEngineLocalServerConfigure *)ls_localServerConfigure;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 配置 Video ID 预加载获取视频信息的最大并发数。
 * @param number Video ID 预加载获取视频信息的最大并发数，最大 4 个。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief se vid to preload data or use vid to play video through a local proxy server, need to get media information through vid. Fetch video info, control the max concurrent number.
 * @param number concurrent number, [0~4] Default:4
 */
+ (void)ls_setMaxConcurrentNumber:(NSInteger)number;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置预加载相关回调
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Use vid to preload data or use vid to play video through a local proxy server,
 * need to provide the necessary information to get the media data,
 *  so you need to set up the delegate
 */
+ (void)ls_setPreloadDelegate:(nullable id<TTVideoEnginePreloadDelegate>)delegate;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载监听回调。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief add preload listener
 */
+ (void)ls_addPreloadListener:(nonnull id<TTVideoEnginePreloadListener>)listener;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 移除预加载监听回调。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief remove preload listener
 */
+ (void)ls_removePreloadListener:(nonnull id<TTVideoEnginePreloadListener>)listener;

/**
 * @locale zh
 * @type api
 * @brief 设置自定义 DNS 解析对象。
 * @param parser 实现 `<TTVideoEngineExternDNSParserDataSource, TTVideoEngineExternDNSParserDelegate>` 协议的解析实例。
 * @notes 使用自定义 DNS 解析，务必在 `[TTSDKManager startWithConfiguration:configuration]` 前调用。
 */
/**
 * @locale en
 * @type api
 * @brief Set a custom DNS resolver object.
 * @param parser Implementing  `<TTVideoEngineExternDNSParserDataSource, TTVideoEngineExternDNSParserDelegate>` protocol。
 * @notes You should call this method before MDL call ls_start.
 */
+ (void)ls_setCustomDNSParser:(nonnull id<TTVideoEngineExternDNSParserDataSource, TTVideoEngineExternDNSParserDelegate>)parser;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 启动播放器数据加载模块。
 * @notes SDK 初始化时会自动启动数据加载模块，您无需调用该方法。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief start mdl
 * @notes The mdl is automatically started when the SDK is initialized. You do not need to call this method.
 */
+ (void)ls_start;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 判断播放器数据加载模块是否启动成功。
 * @return 数据加载模块是否启动成功：<br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @brief Check whether the player data loading module has started successfully.
 * @hidden (iOS)
 */
+ (BOOL)ls_isStarted;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取 Native MDL Handle
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Get medialoader native handle for player
 */
+ (void*)ls_getNativeMedialoaderHandle;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 关闭播放器数据加载模块（MDL）
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief close mdl
 */
+ (void)ls_close;

#pragma mark - Task Manager

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Use vid to preload data or use vid to play video through a local proxy server,
 * internally, ls_startTaskByKey: is called.
 */
/**
 * @locale en
 * @brief Fetching DNS Resolution Refresh Methods
 * @hidden (iOS)
 */
+ (void)ls_addTask:(NSString *)key vidItem:(TTVideoEnginePreloaderVidItem *)vidItem DEPRECATED_MSG_ATTRIBUTE("Please use ls_addTaskWithVidItem:");

/**
 * @locale zh
 * @type api
 * @brief 添加 DirectUrl 播放源预加载任务。
 * @param urlItem DirectUrl 播放源预加载任务。
 * @list 自定义预加载
 * @order 0
 */
/**
 * @locale en
 * @list 自定义预加载
 * @order 0
 * @type api
 * @brief Add a DirectUrl playback source preload task.
 * @param urlItem DirectUrl playback source preloading task.
 */
+ (void)ls_addTaskWithURLItem:(TTVideoEnginePreloaderURLItem *)urlItem;

/**
 * @locale zh
 * @type api
 * @brief 添加 Vid 播放源预加载任务。
 * @param vidItem DirectUrl 播放源预加载任务。
 * @list 自定义预加载
 * @order 1
 */
/**
 * @locale en
 * @type api
 * @list 自定义预加载
 * @order 1
 * @brief Add Vid source preload tasks.
 * @param urlItem vid preload item。
 * @param vidItem DirectUrl playback source preloading task.
 */
+ (void)ls_addTaskWithVidItem:(TTVideoEnginePreloaderVidItem *)vidItem;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加 VideoModel 播放源预加载任务。
 * @param videoModelItem VideoModel 播放源预加载任务。
 */
/**
 * @locale en
 * @type api
 * @brief Preload with video-model
 * @param videoModelItem VideoModel playback source preloading task.
 * @hidden (iOS)
 */
+ (void)ls_addTaskWithVideoModelItem:(TTVideoEnginePreloaderVideoModelItem *)videoModelItem;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加字幕预加载任务。
 * @param subtitleItem 字幕源。
 */
/**
 * @locale en
 * @type api
 * @brief Preload with subtitle-model.
 * @param subtitleItem subtitle-model preload item。
 * @hidden (iOS)
 */
+ (void)ls_addTaskWithSubtitleItem:(TTVideoEnginePreloaderSubtitleItem *)subtitleItem;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务。
 * @param infoModel 预加载源。
 * @param type 预加载清晰度。
 * @param preloadSize 预加载大小。
 */
/**
 * @locale en
 * @type api
 * @brief preload videoModle
 * @param infoModel video model
 * @param type resolution
 * @param preloadSize preload size
 * @hidden (iOS)
 */
+ (void)ls_addTask:(TTVideoEngineModel *)infoModel resolution:(TTVideoEngineResolutionType)type preloadSize:(NSInteger)preloadSize;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务。
 * @param infoModel 预加载源。
 * @param type  预加载清晰度。
 * @param preloadSize 预加载大小。
 * @param filePath 预加载缓存路径。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief preload videoModle, custom cache file path.
 * @param infoModel video model
 * @param type  resolution
 * @param preloadSize preload size
 * @param filePath Custom cache file path.
 */
+ (void)ls_addTask:(TTVideoEngineModel *)infoModel resolution:(TTVideoEngineResolutionType)type preloadSize:(NSInteger)preloadSize filePath:(nullable NSString *(^)(TTVideoEngineURLInfo *urlInfo))filePath;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务。
 * @param infoModel 预加载源。
 * @param type  预加载清晰度。
 * @param params 扩展参数。
 * @param preloadSize 预加载大小。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief preload videoModle, custom cache file path.
 * @param infoModel video model
 * @param type  resolution
 * @param preloadSize preload size
 * @param params extend params
 */
+ (void)ls_addTask:(TTVideoEngineModel *)infoModel resolution:(TTVideoEngineResolutionType)type params:(nullable NSDictionary *)params preloadSize:(NSInteger)preloadSize;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (void)ls_copyCache:(TTVideoEngineCopyCacheItem *)copyCacheItem;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务
 * @param key 预加载key
 * @param videoId 视频 id
 * @param preSize 缓存大小
 * @param url 视频地址
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief add preload task
 * @param key key The unique identity of media. filehash is a good choice.
 * @param videoId video id
 * @param preSize preload size
 * @param url url
 */
+ (void)ls_addTask:(NSString *)key vid:(nullable NSString *)videoId preSize:(NSInteger)preSize url:(NSString *)url;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务
 * @param url 视频地址
 * @param videoId 视频 id
 * @param preSize 缓存大小
 * @param filePath 预加载缓存路径。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief add preload task
 * @param url url
 * @param videoId video id
 * @param preSize preload size
 * @param filePath custom cache file path.
 */
+ (void)ls_addTaskForUrl:(NSString *)url vid:(nullable NSString *)videoId preSize:(NSInteger)preSize filePath:(NSString *)filePath;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务，支持主备地址
 * @param key 预加载key
 * @param videoId 视频 id
 * @param preSize 缓存大小
 * @param urls 视频地址，主备地址
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief add preload task, support backup url
 * @param key key The unique identity of media. filehash is a good choice.
 * @param videoId video id
 * @param preSize preload size
 * @param urls urls info
 */
+ (void)ls_addTask:(NSString *)key vid:(nullable NSString *)videoId preSize:(NSInteger)preSize urls:(NSArray<NSString *> *)urls;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 添加预加载任务，支持主备地址
 * @param url 视频地址，主备地址
 * @param videoId 视频 id
 * @param preSize 缓存大小
 * @param filePath 预加载缓存路径。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief add preload task, support backup url
 * @param urls urls info
 * @param videoId video id
 * @param preSize preload size
 * @param filePath custom cache file path.
 */
+ (void)ls_addTaskForUrls:(NSArray<NSString *> *)urls vid:(nullable NSString *)videoId preSize:(NSInteger)preSize filePath:(NSString *)filePath;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置预链接url。
 * @param url 视频地址。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief pre connect by url
 * @param url url
 */
+ (void)ls_preConnectUrl:(NSString *)url;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (BOOL)switchToDefaultNetwork;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (BOOL)switchToCellularNetwork;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief suspend socket check
 */
/**
 * @locale en
 * @brief suspend socket check
 * @hidden (iOS)
 */
+ (void)suspendSocketCheck;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief resume socket check
 */
/**
 * @locale en
 * @brief resume socket check
 * @hidden (iOS)
 */
+ (void)resumeSocketCheck;

/**
 * @locale zh
 * @hidden
 * @brief custom preload strategy.
 */
/**
 * @locale en
 * @brief custom preload strategy.
 * @hidden (iOS)
 */
@property (nonatomic, assign, class) TTVideoEnginePrelaodStrategy preloadStrategy;

/**
 * @locale zh
 * @type api
 * @brief 根据缓存 key 取消预加载任务。
 * @param key 缓存 key，即 DirectUrl 播放源预加载任务的唯一标识。
 * @list 自定义预加载
 * @order 2
 */
/**
 * @locale en
 * @type api
 * @list 自定义预加载
 * @order 2
 * @brief Cancel the preloading task based on the cache key.
 * @param key The cache key is the unique identifier for the DirectUrl playback source preloading task.
 */
+ (void)ls_cancelTaskByKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief cancel task by file path.
 * @param custom cache file path.
 */
/**
 * @locale en
 * @brief Cancel a task by file path.
 * @hidden (iOS)
 */
+ (void)ls_cancelTaskByFilePath:(NSString *)filePath;

/**
 * @locale zh
 * @type api
 * @brief 根据视频 ID 取消预加载任务。
 * @param vid 视频 ID。
 * @list 自定义预加载
 * @order 3
 */
/**
 * @locale en
 * @type api
 * @list 自定义预加载
 * @order 3
 * @brief Cancel the preload task based on the video ID.
 * @param vid Video ID.
 */
+ (void)ls_cancelTaskByVideoId:(NSString *)vid;

/**
 * @locale zh
 * @type api
 * @brief 取消所有预加载任务。
 * @list 自定义预加载
 * @order 4
 */
/**
 * @locale en
 * @type api
 * @list 自定义预加载
 * @order 4
 * @brief Cancel all preloading tasks.
 */
+ (void)ls_cancelAllTasks;

/**
 * @locale zh
 * @type api
 * @brief 取消所有空闲预加载任务。
 * @list 自定义预加载
 * @order 5
 */
/**
 * @locale en
 * @type api
 * @list 自定义预加载
 * @order 5
 * @brief Cancel all idle preloading tasks.
 */
+ (void)ls_cancelAllIdlePreloadTasks;

#pragma mark - Cache Manager

/**
 * @locale zh
 * @type api
 * @brief 删除所有数据加载模块的缓存数据。
 * @notes 为优化实际播放体验，调用该方法并不会删除所有缓存数据，而是会按照 Least Recently Used (LRU) 算法保留最近播放的 10 条左右数据。
 */
/**
 * @locale en
 * @type api
 * @brief Clear the cache data of all data loading modules.
 * @notes To optimize the actual playback experience, invoking this method will not delete all cached data. Instead, it will retain the most recently played 10 items or so using the Least Recently Used (LRU) algorithm.
 */
+ (void)ls_clearAllCaches;

/**
 * @locale zh
 * @type api
 * @brief 删除所有数据加载模块的缓存数据。
 * @param force 是否强制删除所有数据加载模块缓存数据。<br>
 *         - YES: 删除所有缓存数据。<br>
 *         - NO: 同调用 `ls_clearAllCaches` 方法一致，不全部删除所有缓存数据，而是会按照 Least Recently Used (LRU) 算法保留最近播放的 10 条左右数据，从而优化实际播放体验。
 */
/**
 * @locale en
 * @type api
 * @brief Delete all cached data from data loading modules.
 * @param force Whether to forcibly delete all cached data of data loading modules.<br>
 *        - YES: Delete all cached data.<br>
 *        - NO: Similar to calling the `ls_clearAllCaches` method, it will not delete all cached data. Instead, it will retain the most recently played approximately 10 items according to the Least Recently Used (LRU) algorithm, thereby optimizing the actual playback experience.
 */
+ (void)ls_clearAllCaches:(BOOL)force;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取 `ls_clearAllCaches`  删除缓存数据大小，单位：byte
 * @return 删除缓存数据大小。
 */
/**
 * @locale en
 * @type api
 * @brief get the clear size by ls_clearAllCaches.
 * @hidden (iOS)
 * @return clear size (byte)
 */
+ (int64_t)ls_getClearSizeByClearAll;

/**
 * @locale zh
 * @type api
 * @brief 根据缓存 key 删除数据加载模块的缓存数据。
 * @param key 数据加载模块中缓存数据的唯一标识。
 */
/**
 * @locale em
 * @type api
 * @brief Remove the file disk cache by key.
 * @param key cache key.
 */

/**
 * @locale en
 * @brief Delete the cache data of the data loading module based on the cache key.
 * @param key The unique identifier for cached data in the data loading module.
 */
+ (void)ls_removeFileCacheByKey:(NSString *)key;

/**
 * @locale zh
 * @type api
 * @brief 获取数据加载模块缓存数据总大小，单位：byte。
 * @return 数据加载模块缓存数据总大小。
 */
/**
 * @locale en
 * @type api
 * @brief Retrieve the total size of cached data in the data loading module, measured in bytes.
 * @return Total size of cached data in the data loading module.
 */
+ (int64_t)ls_getAllCacheSize;

/**
 * @locale zh
 * @type api
 * @brief 异步获取数据加载模块缓存数据总大小，单位：byte。
 * @param block 异步回调。
 */
/**
 * @locale en
 * @type api
 * @brief Asynchronously retrieves the total size of cached data in the data loading module, in bytes.
 * @param block Asynchronous callback.
 */
+ (void)ls_getAllCacheSizeWithCompletion:(void(^)(int64_t cacheSize))block;

/**
 * @locale zh
 * @type api
 * @brief 根据缓存 key 获取缓存数据的大小。
 * @param key 数据加载模块中缓存数据的唯一标识。
 * @return 返回缓存数据的大小，单位：byte。
 */
/**
 * @locale en
 * @type api
 * @brief Get the size of cached data based on the cache key.
 * @param key The unique identifier for cached data in the data loading module.
 * @return Returns the size of the cached data in bytes.
 */
+ (int64_t)ls_getCacheSizeByKey:(NSString *)key;

/**
 * @locale zh
 * @type api
 * @brief 根据缓存 key 异步获取缓存数据的大小，单位：byte。
 * @param key 数据加载模块中缓存数据的唯一标识。
 * @param result 异步回调。
 */
/**
 * @locale en
 * @type api
 * @brief Get the size of the cached data asynchronously based on the cache key. Unit: byte.
 * @param key The unique identifier for cached data in the data loading module.
 * @param result Asynchronous callback.
 */
+ (void)ls_getCacheSizeByKey:(NSString *)key result:(void(^)(int64_t size))result;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取指定filePath的缓存大小。
 * @param filePath 本地缓存路径。
 * @return 返回缓存大小。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief get the cache size by file path
 * @param filePath Custom cache file path.
 * @return cache size (byte).
 */
+ (int64_t)ls_getCacheSizeByFilePath:(NSString *)filePath;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 异步获取指定filePath的缓存大小。
 * @param filePath 本地缓存路径。
 * @param result 回调。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief get the cache size by file path asynchronously
 * @param filePath Custom cache file path.
 * @param result callback
 */
+ (void)ls_getCacheSizeByFilePath:(NSString *)filePath result:(void(^)(int64_t size))result;


/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取本地缓存大小。
 * @param infoModel 视频源。
 * @param resolution 清晰度
 * @return 返回缓存大小。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief get the cache size by video model and resolution
 * @param infoModel video model
 * @param resolution resolution
 * @return cache size (byte).
 */
+ (int64_t)ls_getCacheFileSize:(TTVideoEngineModel *)infoModel resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 异步获取本地缓存大小。
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief get the cache size by video model and resolution asynchronously
 * @param infoModel video model
 * @param resolution resolution
 * @param result callback
 */
+ (void)ls_getCacheFileSize:(TTVideoEngineModel *)infoModel resolution:(TTVideoEngineResolutionType)resolution result:(void(^)(int64_t size))result;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Get cache size by read file list struct in memory,
 * may return 0 when init file list not finish at background thread.
 * @param key cache key
 */
/**
 * @locale en
 * @brief Get cache size by reading file list structure in memory, may return 0 if file list initialization is not finished in the background thread.
 * @param key cache key
 * @hidden (iOS)
 */
+ (int64_t)ls_tryQuickGetCacheSizeByKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief quick query cache,can replace ls_tryQuickGetCacheSizeByKey, do not fallbackt to read file
 * @param key cache key
 */
/**
 * @locale en
 * @brief quick query cache can replace ls_tryQuickGetCacheSizeByKey; do not fall back to read file
 * @param key cache key
 * @hidden (iOS)
 */
+ (int64_t)ls_tryQuickQueryCacheSizeByKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get io write error.
 * @param traceId trace id
 */
/**
 * @locale en
 * @brief Received an I/O write error.
 * @param traceId trace id
 * @hidden (iOS)
 */
+ (int)ls_getIoWriteError:(NSString *)traceId;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief clean local cache by dir
 * @param dirpath path
 * @param force force clean
 */
/**
 * @locale en
 * @brief clean local cache by directory
 * @param dirpath path
 * @param force force clean
 * @hidden (iOS)
 */
+ (void)ls_cleanSpecifiedCacheDir:(NSString *)dirpath force:(NSInteger)force;

/**
 * @locale zh
 * @type api
 * @brief 根据缓存 key 获取缓存数据详细信息，详见 [TTVideoEngineLocalServerCacheInfo](803941#TTVideoEngineLocalServerCacheInfo) 。
 * @param key 数据加载模块中缓存数据唯一标识。
 */
/**
 * @locale en
 * @type api
 * @brief Retrieve detailed cache data information based on the cache key. For more details, see [TTVideoEngineLocalServerCacheInfo](ios-player-sdk-type-definitions#TTVideoEngineLocalServerCacheInfo).
 * @param key Unique identifier for cached data in the data loading module.
 */
+ (nullable TTVideoEngineLocalServerCacheInfo *)ls_getCacheFileInfoByKey:(NSString *)key;

#pragma mark - DNS Setting

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Get cache info by file path
 * @param filePath 自定义缓存文件路径。
 */
/**
 * @locale en
 * @brief Retrieve cache information by file path
 * @param filePath Customize cache file path.
 * @hidden (iOS)
 */
+ (nullable TTVideoEngineLocalServerCacheInfo *)ls_getCacheFileInfoByFilePath:(NSString *)filePath;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Set dns ttl
 */
/**
 * @locale en
 * @brief Set DNS TTL
 * @hidden (iOS)
 */
+ (void)ls_DNSTTL:(NSInteger)ttl;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get dns ttl
 */
/**
 * @locale en
 * @brief get DNS TTL
 * @hidden (iOS)
 */
+ (NSInteger)ls_getDNSTTL;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (float)ls_getNetspeed;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 配置 DNS 解析类型
 * @param mainType dns 主解析类型，默认 local.
 * @param backupType dns 备解析类型，默认 local.
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Configure DNS parse type
 * @param mainType main dns parser type, default is local.
 * @param backupType backup dns parser type, default is local.
 */
+ (void)ls_mainDNSParseType:(TTVideoEngineDnsType)mainType backup:(TTVideoEngineDnsType)backupType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get main dns parse type
 */
/**
 * @locale en
 * @brief Retrieve main DNS parse type
 * @hidden (iOS)
 */
+ (TTVideoEngineDnsType)ls_getMainDNSParseType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get backup dns parse type
 */
/**
 * @locale en
 * @brief Fetch backup DNS parse type
 * @hidden (iOS)
 */
+ (TTVideoEngineDnsType)ls_getBackupDNSParseType;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 开启HTTPDNS服务，该服务为付费服务，具体可咨询技术支持。
 * @param accountID 账号ID
 * @param key key
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief this method will start bytedance httpdns service without anyother method
 * @param accountID account id
 * @param key key
 */
+ (void)ls_startByteDanceHttpDnsWithAccountID:(NSString *)accountID key:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief The time of backup parser wait.
 * @param second default is 0.0f, The unit is seconds.
 */
/**
 * @locale en
 * @brief The duration for which the backup parser waits.
 * @param second The default is 0.0f. The unit is seconds.
 * @hidden (iOS)
 */
+ (void)ls_backupDNSParserWaitTime:(double)second;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get the time of backup parser wait.
 */
/**
 * @locale en
 * @brief Retrieve the duration of backup parser wait time.
 * @hidden (iOS)
 */
+ (double)ls_getBackupDNSParserWaitTime;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set the method of dns resolution
 * @param parallel mainDns and backupDns start at the same moment and default is 0
 */
/**
 * @locale en
 * @brief Set the method of DNS resolution
 * @param parallel mainDns and backupDns start at the same moment and default is 0
 * @hidden (iOS)
 */
+ (void)ls_setDNSParallel:(NSInteger)parallel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get the method of dns resolution
 */
/**
 * @locale en
 * @brief get the method of dns resolution
 * @hidden (iOS)
 */
+ (NSInteger)ls_getDNSParallel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief set the refresh method of dns resolution
 * @param refresh dns resolution refresh by iteself
 */
/**
 * @locale en
 * @brief Set the refresh method of DNS resolution
 * @param refresh DNS resolution refreshes by itself
 * @hidden (iOS)
 */
+ (void)ls_setDNSRefresh:(NSInteger)refresh;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取DNS解析的刷新方法
 * @return whether dns resolution refresh by itself
 */
/**
 * @locale en
 * @brief Methods to Refresh DNS Resolution
 * @hidden (iOS)
 */
+ (NSInteger)ls_getDNSRefresh;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Clear all dns cache.
 */
/**
 * @locale en
 * @brief Clear all DNS cache.
 * @hidden (iOS)
 */
+ (void)ls_clearAllDNSCache;

#pragma mark - AutoTrim

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief disable auto-trim mechanism for video key.
 */
/**
 * @locale en
 * @brief Disable the auto-trim mechanism for video keys.
 * @hidden (iOS)
 */
+ (void)ls_disableAutoTrimForKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief enable auto-trim mechanism for video key.
 */
/**
 * @locale en
 * @brief Enable auto-trim mechanism for video key.
 * @hidden (iOS)
 */
+ (void)ls_enableAutoTrimForKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief get cdnlog by filekey.
 * @return cdn log
 */
/**
 * @locale en
 * @brief Retrieve CDN log by file key.
 * @hidden (iOS)
 */
+ (NSDictionary*)ls_getCDNLog:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (void)ls_setNetClient:(id<TTVideoEngineNetClient>)netClient;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (void)ls_setNetClientV1:(id<TTVideoEngineNetClient>(^)(void))getNetClient;

/**
 * @locale zh
 * @hidden
 * @type api
 */
/**
 * @locale en
 * @hidden (iOS)
 */
+ (int64_t)ls_getDownloadCountByVid:(NSString *)vid;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 生成子 URL 缓存键
 * @param key  url cache key
 * @param subUrl  sub url cdn url
 * @return cache key of sub url
 */
/**
 * @locale en
 * @brief Generating Sub-URL Cache Key
 * @param key URL cache key
 * @param subUrl sub URL cdn URL
 * @hidden (iOS)
 */
+ (NSString*)ls_generateKey:(NSString *)key subUrl:(NSString *)subUrl;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief generate mdl proxy url
 * @return mdl proxy url
 */
/**
 * @locale en
 * @brief generate mdl proxy URL
 * @hidden (iOS)
 */
+ (NSString *)ls_proxyUrl:(NSString *)key url:(NSString *)url;


@end

#pragma mark - Private Method

/**
 * @locale zh
 * @hidden for internal use only
 * @type callback
 * @brief local server delegate
 */
/**
 * @locale en
 * @type callback
 * @brief local server delegate
 * @hidden 
 */
@protocol TTVideoEngineLocalServerToEngineProtocol <NSObject>

- (void)updateCacheProgress:(NSString *)key flag:(NSInteger)flag observer:(id)observer progress:(CGFloat)progress;

@end

/**
 * @locale zh
 * @hidden for internal use only
 * @type api
 * @brief TTVideoEngine Preload-Private
 */
/**
 * @locale en
 * @brief TTVideoEngine Preload-Private
 * @type api
 * @hidden 
 */
@interface TTVideoEngine(PreloadPrivate)
- (NSString*)_ls_proxyUrl:(NSString *)key rawKey:(NSString *)rawKey urls:(NSArray<NSString *> *)urls extraInfo:(nullable NSString *)extra filePath:(nullable NSString *)filePath;

- (NSString*)_ls_proxyUrl:(TTVideoEngineDirectURLItem *)urlItem;

- (void)_ls_logProxyUrl:(NSString *)proxyUrl;
- (void)_ls_addTask:(nullable NSString *)videoId
                key:(NSString *)key
         resolution:(TTVideoEngineResolutionType)type
           proxyUrl:(NSString *)proxyUrl
      decryptionKey:(nullable NSString *)decryptionKey
               info:(TTVideoEngineURLInfo *)info
               urls:(NSArray *)urls;
+ (NSString *)_ls_getMDLVersion;
- (NSString*)_ls_getMDLPlayLog:(NSString *)traceId;
- (void)_ls_removePlayTaskByKeys:(NSArray *)keys;
- (void)_registerMdlProtocolHandle;
- (BOOL)firstNativeRegister;
- (void)_registerHLSProxyProtocolHandle;
+ (void)_ls_addObserver:(__weak id)observer forKey:(NSString *)key;
+ (void)_ls_removeObserver:(__weak id)observer forKeys:(NSArray *)keys;
+ (nullable NSString *)_ls_keyFromFilePath:(NSString *)filePath;
+ (void)_ls_forceRemoveFileCacheByKey:(NSString *)key;
+ (NSInteger)_ls_getPreloadTaskNumber;
- (BOOL) _removeThirdPartyProtocolHead: (NSMutableArray<NSString *> *)urls;
- (NSString *) _addThirdPartyProtocolHead:(NSString *)url;
- (nullable NSString *) _ls_getPreloadTraceId:(NSString *)rawKey;
- (void) _ls_resetPreloadTraceId:(NSString *)rawKey;
@end

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 使用 URL 播放源对象
 */
/**
 * @locale en
 * @brief Using URL Playback Source Object
 * @type api
 * @hidden 
 */
@interface TTVideoEngineDirectURLItem : NSObject

/// Cache-key.
@property (nonatomic, copy, nullable) NSString *key;
@property (nonatomic, copy, nullable) NSArray<NSString *> *urls;

/// Optional
@property (nonatomic, copy, nullable) NSString *videoId;
/// Custom cache file path.
@property (nonatomic, copy, nullable) NSString *cacheFilePath;
/// cdn url expired time stamp, unix epoch second.
@property (nonatomic, assign) NSInteger urlExpiredTime;

+ (nullable instancetype)urlItem:(NSString *)key
                            urls:(NSArray<NSString *> *)urls
                  urlExpiredTime:(NSInteger) urlExpiredTime;

@end

@interface TTVideoEnginePreloaderItem : NSObject

/**
 * @locale zh
 * @hidden
 * @brief preload task started
 * @notes   info @{@"index": @(index), @"url": url}
 */
/**
 * @locale en
 * @brief preload task started
 * @type api
 * @hidden
 * @notes info \@{index: \\\@(index), \\\@url: url}
 */
@property (nonatomic, copy, nullable) void(^preloadDidStart)(NSDictionary *_Nullable info);

/**
 * @locale zh
 * @hidden
 * @brief preload task progress
 */
/**
 * @locale en
 * @hidden
 * @brief preload task progress
 * @type api
 */
@property (nonatomic, copy, nullable) void(^preloadProgress)(TTVideoEngineLoadProgress *progress);

/**
 * @locale zh
 * @hidden
 * @brief preload task end call back.
 */
/**
 * @locale en
 * @hidden
 * @brief Callback when the preload task ends.
 * @type api
 */
@property (nonatomic, copy, nullable) void(^preloadEnd)(TTVideoEngineLocalServerTaskInfo *_Nullable info, NSError *_Nullable error);

/**
 * @locale zh
 * @hidden
 * @brief preload task cancel call back.
 */
/**
 * @locale en
 * @hidden
 * @brief Callback for cancelling preload task.
 * @type api
 */
@property (nonatomic, copy, nullable) void(^preloadCanceled)(void);

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 取消预加载
 */
/**
 * @locale en
 * @hidden
 * @brief cancel the preload task
 * @type api
 */
- (void)cancel;

@end

/**
 * @locale zh
 * @type keytype
 * @brief DirectUrl 播放源预加载信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Preloading information for DirectUrl streaming source.
 */
@interface TTVideoEnginePreloaderURLItem : TTVideoEnginePreloaderItem
/**
 * @locale zh
 * @brief （必需）设置预加载任务唯一标识。建议使用 URL MD5 值作为 key。如果使用 URL MD5 值作为 key，需要注意某些 URL 可能会包含时间戳或签名等信息，在使用之前需要将这些可变部分去除，以保证使用的是不变的 URL 的 MD5 值。
 */
/**
 * @locale en
 * @brief (Mandatory) Set a unique identifier for the preload task. It's recommended to use the URL's MD5 value as the key. If using the URL's MD5 value as the key, be aware that some URLs may contain information like timestamps or signatures. These variable parts should be removed before use to ensure the MD5 value of a constant URL is used.
 */
@property (nonatomic, copy, nullable) NSString *key;
/**
 * @locale zh
 * @brief （必需）设置预加载视频源的 URL。支持主备 URL。
 */
/**
 * @locale en
 * @brief (Mandatory) Set the preloaded video source URL. Both primary and backup URLs are supported.
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *urls;
/**
 * @locale zh
 * @brief （必需）视频的唯一标识，必须与视频源一一对应。可以是您自己的视频管理系统中的视频唯一标识，也可以跟 `key` 赋值一样。
 */
/**
 * @locale en
 * @brief (Required) The unique identifier for the video, which must correspond to the video source one-to-one. This can be the unique identifier from your own video management system, or it can be the same value as `key`.
 */
@property (nonatomic, copy, nullable) NSString *videoId;
/**
 * @locale zh
 * @brief 指定缓存路径。SDK 有默认缓存路径，不建议您单独设置。
 */
/**
 * @locale en
 * @brief Specify the cache path. The SDK has a default cache path, and it is not recommended to set it separately.
 */
@property (nonatomic, copy, nullable) NSString *cacheFilePath;
/**
 * @locale zh
 * @brief 设置预加载数据大小，例如 800 * 1024 代表预加载 800k 数据。
 */
/**
 * @locale en
 * @brief Set the size of preloaded data. For example, 800 * 1024 represents preloading 800k of data.
 */
@property (nonatomic, assign) NSInteger preloadSize;
/**
 * @locale zh
 * @brief 预加载优先级，默认为 `TTVideoEnginePrloadPriorityDefault`。
 */
/**
 * @locale en
 * @brief The preloading priority defaults to `TTVideoEnginePrloadPriorityDefault`.
 */
@property (nonatomic, assign) NSInteger priorityLevel;

/**
 * @locale zh
 * @hidden
 * @brief 标记预加载主分类。
 */
/**
 * @locale en
 * @hidden
 * @brief Mark the preload main category.
 */
@property (nonatomic, copy) NSString *tag;
/**
 * @locale zh
 * @hidden
 * @brief 标记预加载二级分类。
 */
/**
 * @locale en
 * @hidden
 * @brief Mark preloading for secondary category.
 */
@property (nonatomic, copy) NSString *subTag;

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, copy) NSString *groupId;

/**
 * @locale zh
 * @hidden
 * @brief url 过期时间
 */
/**
 * @locale en
 * @hidden
 * @brief URL expiration time
 */
@property (nonatomic, assign) NSInteger urlExpiredTime;

/**
 * @locale zh
 * @hidden
 * @brief additional footer size for moov at end of file
 */
/**
 * @locale en
 * @hidden
 * @brief extra footer size for moov at the end of the file
 */
@property (nonatomic, assign) NSInteger preloadFooterSize;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Set custom header
 */
/**
 * @locale en
 * @hidden
 * @brief Set custom header
 * @type api
 */
- (void)setCustomHeaderValue:(NSString *)value forKey:(NSString *)key;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构造一个 DirectUrl 播放源预加载 Item 实例。
 * @param key 预加载任务的唯一标识。建议使用 URL MD5 值作为 key。如果使用 URL MD5 值作为 key，需要注意某些 URL 可能会包含时间戳或签名等信息，在使用之前需要将这些可变部分去除，以保证使用的是不变的 URL 的 MD5 值。
 * @param videoId 视频的唯一标识，必须与视频源一一对应。可以是您自己的视频管理系统中的视频唯一标识，也可以跟 `key` 赋值一样。
 * @param preloadSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param urls 预加载 URL。支持主备 URL。
 * @return 返回 DirectUrl 播放源预加载 Item 实例。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct an instance of DirectUrl Play Source Preload Item.
 * @type api
 * @param key The unique identifier for the preloading task. It is recommended to use the URL MD5 value as the key. If using the URL MD5 value as the key, note that some URLs may contain information such as timestamps or signatures. These variable parts need to be removed before use to ensure that the MD5 value of a consistent URL is used.
 * @param videoId The unique identifier of the video must correspond one-to-one with the video source. This can be the unique identifier from the video management system or the same value as the `key`.
 * @param preloadSize Preload data size, in bytes. For example, 800 * 1024 represents preloading 800k of data.
 * @param urls Preload URL. Supports primary and backup URLs.
 */
+ (nullable instancetype)urlItem:(NSString *)key
                         videoId:(nullable NSString *)videoId
                     preloadSize:(NSInteger)preloadSize
                            urls:(NSArray<NSString *> *)urls;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构造一个 DirectUrl 播放源预加载 Item 实例。
 * @param key 预加载任务唯一标识。建议使用 URL MD5 值作为 key。如果使用 URL MD5 值作为 key，需要注意某些 URL 可能会包含时间戳或签名等信息，在使用之前需要将这些可变部分去除，以保证使用的是不变的 URL 的 MD5 值。
 * @param videoId 视频的唯一标识，必须与视频源一一对应。可以是您自己的视频管理系统中的视频唯一标识，也可以跟 `key` 赋值一样。
 * @param urls 预加载 URL。支持主备 URL。
 * @param preloadSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @return 返回 DirectUrl 播放源预加载 Item 实例。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct a DirectUrl playback source preload Item instance.
 * @type api
 * @param key The unique identifier for preloading tasks. It is recommended to use the URL MD5 value as the key. If using the URL MD5 value as the key, be aware that some URLs may contain information such as timestamps or signatures. These variable parts need to be removed before use to ensure the MD5 value is based on an immutable URL.
 * @param videoId The unique identifier for the video must correspond to the video source one-to-one. It can be the unique identifier from your own video management system, or it can have the same value as `key`.
 * @param urls Preload URL. Supports primary and backup URLs.
 * @param preloadSize Preload data size, unit: byte. For example, 800 * 1024 represents preloading 800k of data.
 */
+ (nullable instancetype)urlItemWithKey:(NSString *)key
                                videoId:(nullable NSString *)videoId
                                   urls:(NSArray<NSString *> *)urls
                            preloadSize:(NSInteger)preloadSize;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构造一个 DirectUrl 播放源预加载 Item 实例。
 * @param cacheFilePath 指定缓存路径。
 * @param videoId 视频的唯一标识，必须与视频源一一对应。可以是您自己的视频管理系统中的视频唯一标识，也可以跟 `key` 赋值一样。
 * @param urls 预加载 URL。支持主备 URL。
 * @param preloadSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @return 返回 DirectUrl 播放源预加载 Item 实例。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct a DirectUrl playback source preload Item instance.
 * @type api
 * @param cacheFilePath Specify the cache path.
 * @param videoId The unique identifier for the video must correspond to the video source one-to-one. It can be the unique identifier from your own video management system, or the same as the value assigned to `key`.
 * @param urls Preload URL. Supports primary and backup URLs.
 * @param preloadSize Size of preloaded data in bytes. For example, 800 * 1024 indicates preloading 800k of data.
 */
+ (nullable instancetype)urlItemWitFilePath:(NSString *)cacheFilePath
                                    videoId:(nullable NSString *)videoId
                                       urls:(NSArray<NSString *> *)urls
                                preloadSize:(NSInteger)preloadSize;

@end

/**
 * @locale zh
 * @type keytype
 * @brief VideoModel 播放源预加载信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Preload information for VideoModel playback source.
 */
@interface TTVideoEnginePreloaderVideoModelItem : TTVideoEnginePreloaderItem

/**
 * @locale zh
 * @brief 设置视频源分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief video resolution
 */
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;
/**
 * @locale zh
 * @brief 设置视频源信息。
 */
/**
 * @locale en
 * @brief video info
 */
@property (nonatomic, strong, nullable) TTVideoEngineModel *videoModel;
/**
 * @locale zh
 * @brief 设置预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 */
/**
 * @locale en
 * @brief preload size (byte)
 */
@property (nonatomic, assign) NSInteger preloadSize;

/**
 * @locale zh
 * @hidden
 * @brief preload to millisecond, work when videomodel have fitterifno, othrewise use preloadSize
 */
/**
 * @locale en
 * @hidden
 * @brief When `videomodel` has `fitterifno`, preload to millisecond; otherwise, use `preloadSize`.
 */
@property (nonatomic, assign) NSInteger preloadMilliSecond;

/**
 * @locale zh
 * @hidden
 * @brief preload form millisecond offset, work when videomodel have fitterifno, othrewise from start
 */
/**
 * @locale en
 * @hidden
 * @brief Preload from millisecond offset, works if videomodel has fitterinfo, otherwise starts from the beginning.
 */
@property (nonatomic, assign) NSInteger preloadMilliSecondOffset;

/**
 * @locale zh
 * @hidden
 * @brief precise preload Timestamp(ms); SDK solution;
 */
/**
 * @locale en
 * @hidden
 * @brief precise preload timestamp (ms); SDK solution;
 */
@property (nonatomic, assign) NSInteger preloadTimestamp;
/**
 * @locale zh
 * @hidden
 * @brief precise preload duration(ms); SDK solution;
 */
/**
 * @locale en
 * @hidden
 * @brief precise preload duration (ms); SDK solution;
 */
@property (nonatomic, assign) NSInteger preloadDurationMilliSecond;

/**
 * @locale zh
 * @hidden
 * @brief extend params
 */
/**
 * @locale en
 * @hidden
 * @brief extend params
 */
@property (nonatomic, nullable, strong) NSDictionary *params;

/**
 * @locale zh
 * @brief 预加载优先级，默认为 `TTVideoEnginePrloadPriorityDefault`。
 */
/**
 * @locale en
 * @brief priority level, default  TTVideoEnginePrloadPriorityDefault.
 */
@property (nonatomic, assign) NSInteger priorityLevel;

/**
 * @locale zh
 * @hidden
 * @brief tag
 */
/**
 * @locale en
 * @hidden
 * @brief tag
 */
@property (nonatomic, copy) NSString *tag;
/**
 * @locale zh
 * @hidden
 * @brief sub tag
 */
/**
 * @locale en
 * @hidden
 * @brief sub tag
 */
@property (nonatomic, copy) NSString *subTag;
/**
 * @locale zh
 * @hidden
 * @brief group id
 */
/**
 * @locale en
 * @hidden
 * @brief group ID
 */
@property (nonatomic, copy) NSString *groupId;

/**
 * @locale zh
 * @hidden
 * @brief audio preload size of dash
 */
/**
 * @locale en
 * @hidden
 * @brief audio preload size of dash
 */
@property (nonatomic, assign) NSInteger dashAudioPreloadSize;

/**
 * @locale zh
 * @hidden
 * @brief video preload size of dash
 */
/**
 * @locale en
 * @hidden
 * @brief Video Preload Size of DASH
 */
@property (nonatomic, assign) NSInteger dashVideoPreloadSize;

/**
 * @locale zh
 * @hidden
 * @brief Using urlInfos.
 */
/**
 * @locale en
 * @hidden
 * @brief Using urlInfos.
 * @type api
 */
@property (nonatomic, copy, nullable) void(^usingUrlInfo)(NSArray<TTVideoEngineURLInfo *> *urlInfos);

/**
 * @locale zh
 * @hidden
 * @brief 自定义缓存文件路径。
 */
/**
 * @locale en
 * @hidden
 * @brief Custom cache file path.
 * @type api
 */
@property (nonatomic, copy, nullable) NSString *(^cacheFilePath)(TTVideoEngineURLInfo *urlInfo);

/**
 * @locale zh
 * @hidden
 * @brief gear strategy
 */
/**
 * @locale en
 * @hidden
 * @brief gear strategy
 */
@property (nonatomic, assign) BOOL enableGearStrategy;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 VideoModel 播放源预加载 Item 实例。
 * @return 返回 VideoModel 视频源预加载 Item 实例。
 * @param data VideoModel 播放源。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param preloadSize 预加载数据大小，例如 800 * 1024 代表预加载 800k 数据。
 * @param params 扩展参数，您无需设置。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct a VideoModel Play Source Preload Item instance.
 * @type api
 * @param data VideoModel playback source.
 * @param resolution Video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 * @param preloadSize The size of preloaded data, such as 800 * 1024, represents preloading 800k of data.
 * @param params Extended parameter, no need to set.
 */
+ (instancetype)videoModelItem:(TTVideoEngineModel *)data
                    resolution:(TTVideoEngineResolutionType)resolution
                   preloadSize:(NSInteger)preloadSize
                        params:(nullable NSDictionary *)params;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 VideoModel 播放源预加载 Item 实例。
 * @return 返回 VideoModel 视频源预加载 Item 实例。
 * @param data VideoModel 播放源。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param preloadMilliSecondOffset 预加载偏移量，单位毫秒
 * @param preloadSize 预加载数据大小，例如 800 * 1024 代表预加载 800k 数据。
 * @param params 扩展参数，您无需设置。
 */
/**
 * @locale en
 * @hidden
 * @brief Create an instance of VideoModel playback source preload Item.
 * @type api
 * @param data VideoModel playback source.
 * @param resolution Video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @param preloadMilliSecondOffset Preload offset, in milliseconds
 * @param preloadSize The preload data size, for example, 800 * 1024 represents preloading 800k of data.
 * @param params Extended parameters, no setup required.
 */
+ (instancetype)videoModelItem:(TTVideoEngineModel *)data
                    resolution:(TTVideoEngineResolutionType)resolution
      preloadMilliSecondOffset:(NSInteger)preloadMilliSecondOffset
                   preloadSize:(NSInteger)preloadSize
                        params:(nullable NSDictionary *)params;


@end


/**
 * @locale zh
 * @type keytype
 * @brief Vid 播放源预加载信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Vid playback source preload information.
 */
@interface TTVideoEnginePreloaderVidItem : TTVideoEnginePreloaderItem

/**
 * @locale zh
 * @brief （必需）设置视频 ID。
 */
/**
 * @locale en
 * @brief video id
 */
@property (nonatomic, nullable, copy) NSString *videoId;
/**
 * @locale zh
 * @brief （必需）设置视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 */
/**
 * @locale en
 * @brief play auth token
 */
@property (nonatomic,   copy) NSString *playAuthToken;
/**
 * @locale zh
 * @brief （必需）设置预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 */
/**
 * @locale en
 * @brief video resolution
 */
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;
/**
 * @locale zh
 * @brief 设置预加载数据大小，例如 800 * 1024 代表预加载 800k 数据。
 */
/**
 * @locale en
 * @brief preload size
 */
@property (nonatomic, assign) NSInteger preloadSize;
/**
 * @locale zh
 * @brief 设置预加载视频源的编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) ，默认为 `TTVideoEngineH264`。
 */
/**
 * @locale en
 * @brief video codec type
 */
@property (nonatomic, assign) TTVideoEngineEncodeType codecType;
/**
 * @locale zh
 * @hidden
 * @brief H.265 enable
 */
/**
 * @locale en
 * @hidden
 */
@property (nonatomic, assign) BOOL h265Enable;
/**
 * @locale zh
 * @hidden
 * @brief dash enable
 */
/**
 * @locale en
 * @hidden
 * @brief Enable dash
 */
@property (nonatomic, assign) BOOL dashEnable;
/**
 * @locale zh
 * @hidden
 * @brief https enable
 */
/**
 * @locale en
 * @hidden
 * @brief Enable HTTPS
 */
@property (nonatomic, assign) BOOL httpsEnable;
/**
 * @locale zh
 * @hidden
 * @brief boe enable
 */
/**
 * @locale en
 * @hidden
 * @brief Enable boe
 */
@property (nonatomic, assign) BOOL boeEnable;
/**
 * @locale zh
 * @brief 预加载视频源是否加密。
 */
/**
 * @locale en
 * @brief is encryption video
 */
@property (nonatomic, assign) BOOL encryptionEnable;
/**
 * @locale zh
 * @brief 预加载视频源是否为 HLS。
 */
/**
 * @locale en
 * @brief is hls video
 */
@property (nonatomic, assign) BOOL hlsEnable;
/**
 * @locale zh
 * @hidden
 * @brief extend param
 */
/**
 * @locale en
 * @hidden
 * @brief extend param
 */
@property (nonatomic, nullable, strong) NSDictionary *params;
/**
 * @locale zh
 * @hidden
 * @brief tag
 */
/**
 * @locale en
 * @hidden
 * @brief tag
 */
@property (nonatomic, copy) NSString *tag;
/**
 * @locale zh
 * @hidden
 * @brief sub tag
 */
/**
 * @locale en
 * @hidden
 * @brief sub tag
 */
@property (nonatomic, copy) NSString *subTag;

/**
 * @locale zh
 * @brief 预加载优先级，默认为 `TTVideoEnginePrloadPriorityDefault`。
 */
/**
 * @locale en
 * @brief priority level, default  TTVideoEnginePrloadPriorityDefault.
 */
@property (nonatomic, assign) NSInteger priorityLevel;

/**
 * @locale zh
 * @hidden
 * @brief only fetch VideoInfo, Default: NO.
 */
/**
 * @locale en
 * @hidden
 * @brief Only fetch VideoInfo, default: NO.
 */
@property (nonatomic, assign) BOOL onlyFetchVideoModel;

/**
 * @locale zh
 * @hidden
 * @brief resolution map.
 */
/**
 * @locale en
 * @hidden
 * @brief resolution map.
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSNumber *> *resolutionMap;

/**
 * @locale zh
 * @hidden
 * @brief fetch data need.
 */
/**
 * @locale en
 * @hidden
 * @brief Fetching data is necessary.
 */
@property (nonatomic, strong, nullable) id<TTVideoEngineNetClient> netClient;

/**
 * @locale zh
 * @hidden
 * @brief api version
 */
/**
 * @locale en
 * @hidden
 * @brief API version
 */
@property (nonatomic, assign) TTVideoEnginePlayAPIVersion apiVersion;

/**
 * @locale zh
 * @hidden
 * @brief Return api-string for fetch videoinfo.
 */
/**
 * @locale en
 * @hidden
 * @brief Return api-string to fetch video information.
 */
@property (nonatomic, copy, nullable) TTVideoEngineReturnStringBlock apiStringCall;

/**
 * @locale zh
 * @hidden
 * @brief Return auth-string for fetch videoinfo.
 */
/**
 * @locale en
 * @hidden
 * @brief Return the authentication string for fetching video information.
 */
@property (nonatomic, copy, nullable) TTVideoEngineReturnStringBlock authCall;

/**
 * @locale zh
 * @hidden
 * @brief Fetch video-model finish.
 */
/**
 * @locale en
 * @hidden
 * @brief Video model fetching completed.
 * @type api
 */
@property (nonatomic, copy, nullable) void (^fetchDataEnd)(TTVideoEngineModel *_Nullable model, NSError *_Nullable error);

/**
 * @locale zh
 * @hidden
 * @brief Using urlInfos.
 */
/**
 * @locale en
 * @hidden
 * @brief Using urlInfos.
 * @type api
 */
@property (nonatomic, copy, nullable) void(^usingUrlInfo)(NSArray<TTVideoEngineURLInfo *> *urlInfos);

/**
 * @locale zh
 * @hidden
 * @brief Custom cache file path.
 */
/**
 * @locale en
 * @hidden
 * @brief Custom cache file path.
 * @type api
 */
@property (nonatomic, copy, nullable) NSString *(^cacheFilePath)(TTVideoEngineURLInfo *urlInfo);

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例。
 * @return 返回 Vid 播放源预加载 Item 实例。
 * @param vid 视频 ID。
 * @param resolution 预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 * @param preloaderSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param h265 是否是 h265 源。h265 为火山引擎自研编码器。
 */
/**
 * @locale en
 * @hidden
 */
+ (instancetype)preloaderVidItem:(NSString *)vid
                       reslution:(TTVideoEngineResolutionType)resolution
                     preloadSize:(NSInteger)preloaderSize
                       ish265:(BOOL)h265;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 创建 Vid 播放源预加载任务。
 * @return 返回 Vid 播放源预加载 Item 实例。
 * @param vid 视频 ID。
 * @param resolution 预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 * @param preloaderSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param codecType 预加载视频源的编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) ，默认为 `TTVideoEngineH264`。
 */
/**
 * @locale en
 * @hidden
 * @brief Create a Vid source preloading task.
 * @type api
 * @param vid Video ID.
 * @param resolution Preload video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details. The preload video resolution should be consistent with the playback resolution to ensure successful preloading.
 * @param preloaderSize The size of preloaded data, in bytes. For example, 800 * 1024 represents preloading 800k of data.
 * @param codecType The encoding format for preloading video sources can be found in [TTVideoEngineEncodeType](ios-player-sdk-type-definitions#TTVideoEngineEncodeType), and the default is `TTVideoEngineH264`.
 */
+ (instancetype)preloaderVidItem:(NSString *)vid
                       reslution:(TTVideoEngineResolutionType)resolution
                     preloadSize:(NSInteger)preloaderSize
                           codec:(TTVideoEngineEncodeType)codecType;
/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例。
 * @return 返回 Vid 播放源预加载 Item 实例。
 * @param vid 视频 ID。
 * @param playAuthToken（必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param resolution 预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 * @param preloaderSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param h265 是否是 h265 源。h265 为火山引擎自研编码器。
 * @param enableEncryption 是否是加密源。
 * @param hlsEnable  是否是 HLS 源。
 */
/**
 * @locale en
 * @hidden
 */
+ (instancetype)preloaderVidItem:(NSString *)vid
                           token:(NSString *)playAuthToken
                       reslution:(TTVideoEngineResolutionType)resolution
                     preloadSize:(NSInteger)preloaderSize
                       ish265:(BOOL)h265
                      encryption:(BOOL)enableEncryption
                       hlsEnable:(BOOL)hlsEnable;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例。
 * @return 返回 Vid 播放源预加载 Item 实例。
 * @param vid 视频 ID。
 * @param playAuthToken（必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param resolution 预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 * @param preloaderSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param h265 是否是 h265 源。h265 为火山引擎自研编码器。
 * @param enableEncryption 是否是加密源。
 */
/**
 * @locale en
 * @hidden
 */
+ (instancetype)preloaderVidItem:(NSString *)vid
                           token:(NSString *)playAuthToken
                       reslution:(TTVideoEngineResolutionType)resolution
                     preloadSize:(NSInteger)preloaderSize
                       ish265:(BOOL)h265
                      encryption:(BOOL)enableEncryption;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例， 仅获取 VideoInfo。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct a Vid source preloading Item instance to only obtain VideoInfo.
 * @type api
 */
+ (instancetype)preloaderVidItem:(NSString *)vid token:(NSString *)playAuthToken onlyFetchVideoModel:(BOOL)only;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 构建一个 Vid 播放源预加载 Item 实例。
 * @return 构建一个 Vid 播放源预加载 Item 实例。
 * @param vid 视频 ID。
 * @param playAuthToken（必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param resolution 预加载视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。预加载视频分辨率要和播放的分辨率保持一致，这样才会命中预加载。
 * @param preloaderSize 预加载数据大小，单位：byte。例如 800 * 1024 代表预加载 800k 数据。
 * @param codecType 预加载视频源的编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) ，默认为 `TTVideoEngineH264`。
 * @param enableEncryption 是否是加密源。
 */
/**
 * @locale en
 * @hidden
 * @brief Construct an instance of a Vid Play Source Preload Item.
 * @type api
 * @param vid Video ID.
 * @param resolution Preload video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details. The preload video resolution must match the playback resolution to ensure that preloading is effective.
 * @param preloaderSize The size of preloaded data, measured in bytes. For example, 800 * 1024 represents preloading 800k of data.
 * @param codecType The encoding format for preloading video sources can be found in [TTVideoEngineEncodeType](ios-player-sdk-type-definitions#TTVideoEngineEncodeType). The default is `TTVideoEngineH264`.
 * @param enableEncryption Is it an encrypted source?
 */
+ (instancetype)preloaderVidItem:(NSString *)vid
                           token:(NSString *)playAuthToken
                       reslution:(TTVideoEngineResolutionType)resolution
                     preloadSize:(NSInteger)preloaderSize
                           codec:(TTVideoEngineEncodeType)codecType
                      encryption:(BOOL)enableEncryption
                       hlsEnable:(BOOL)hlsEnable;

@end

/**
 * @locale zh
 * @type keytype
 * @brief Vid 播放源预加载信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Vid playback source preload information.
 */
@interface TTVideoEnginePreloaderSubtitleItem : TTVideoEnginePreloaderItem

/**
 * @locale zh
 * @brief 预加载字幕 id。
 */
/**
 * @locale en
 * @brief preload subtitle id.
 */
@property (nonatomic, assign) NSInteger subtitleId;

/**
 * @locale zh
 * @brief 预加载优先级，默认为 `TTVideoEnginePrloadPriorityDefault`。
 */
/**
 * @locale en
 * @brief The preloading priority defaults to `TTVideoEnginePrloadPriorityDefault`.
 */
@property (nonatomic, assign) NSInteger priorityLevel;

/**
 * @locale zh
 * @brief 字幕源。
 */
/**
 * @locale en
 * @brief subtitle info
 */
@property (nonatomic, strong, nonnull) TTVideoEngineSubDecInfoModel *subtitleInfoModel;

/**
 * @locale zh
 * @type api
 * @brief 创建字幕预加载任务。
 * @return 返回字幕预加载 Item 实例。
 * @param subtitleInfoModel 预加载字幕源
 * @param subtitleId 预加载字幕源
 */
/**
 * @locale en
 * @brief Create a subtitle preloading task.
 * @type api
 * @param subtitleInfoModel subtitle source.
 * @param subtitleId preload subtitle id.
 */
+ (instancetype)preloaderSubtitleItem:(TTVideoEngineSubDecInfoModel *)subtitleInfoModel
                           subtitleId:(NSInteger)subtitleId;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 数据加载模块中的缓存任务信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Cache task information in the data loading module.
 */
@interface TTVideoEngineLocalServerTaskInfo : NSObject

/**
 * @locale zh
 * @brief 视频源唯一标识。
 */
/**
 * @locale en
 * @brief Unique identifier for the video source.
 */
@property (nonatomic,   copy) NSString *key;
/**
 * @locale zh
 * @brief 视频 ID。
 */
/**
 * @locale en
 * @brief Video ID.
 */
@property (nonatomic, nullable, copy) NSString *videoId;
/**
 * @locale zh
 * @brief 视频源分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief Video source resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 */
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;
/**
 * @locale zh
 * @brief 本地缓存路径。
 */
/**
 * @locale en
 * @brief Local cache path.
 */
@property (nonatomic, nullable, copy) NSString *localFilePath;
/**
 * @locale zh
 * @brief 视频源大小，单位：byte。
 */
/**
 * @locale en
 * @brief The size of the video source, in bytes.
 */
@property (nonatomic, assign) int64_t mediaSize;
/**
 * @locale zh
 * @hidden
 * @brief Non-stop cache size from scratch.
 */
/**
 * @locale en
 * @brief Starting with the basics of non-stop cache size.
 * @hidden (iOS)
 */
@property (nonatomic, assign) int64_t cacheSizeFromZero;
/**
 * @locale zh
 * @hidden
 * @brief Decryption key.
 */
/**
 * @locale en
 * @brief Decryption key.
 * @hidden (iOS)
 */
@property (nonatomic, nullable, copy) NSString *decryptionKey;
/**
 * @locale zh
 * @brief 预加载数据大小，单位：byte。
 */
/**
 * @locale en
 * @brief Preloaded data size, unit: byte.
 */
@property (nonatomic, assign) int64_t preloadSize;
/**
 * @locale zh
 * @hidden
 * @brief 任务类型，Play or Preload.
 */
/**
 * @locale en
 * @brief Task type: Play or Preload.
 * @hidden (iOS)
 */
@property (nonatomic, assign) TTVideoEngineDataLoaderTaskType taskType;
/**
 * @locale zh
 * @brief 视频源 URL 信息，仅预加载 Vid 播放源时有值。
 */
/**
 * @locale en
 * @brief Video source URL information, only available when preloading Vid playback sources.
 */
@property (nonatomic, nullable, strong) TTVideoEngineURLInfo *urlInfo;
@end

/**
 * @locale zh
 * @type keytype
 * @brief 数据加载模块的本地缓存配置信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Configuration information for the local cache of the data loading module.
 */
@interface TTVideoEngineLocalServerCacheInfo : NSObject
/**
 * @locale zh
 * @brief 视频源数据大小，单位：byte。
 */
/**
 * @locale en
 * @brief The size of the video source data, in bytes.
 */
@property(nonatomic, assign) int64_t mediaSize;
/**
 * @locale zh
 * @hidden
 * @brief Non-stop cache size from scratch.
 */
/**
 * @locale en
 * @hidden
 * @brief From Zero to a Non-stop Cache Size.
 */
@property(nonatomic, assign) int64_t cacheSizeFromZero;
/**
 * @locale zh
 * @brief 本地缓存路径。
 */
/**
 * @locale en
 * @brief Local cache path.
 */
@property(nonatomic,   copy) NSString *localFilePath;

@end

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 缓存拷贝Item。
 */
/**
 * @locale en
 * @brief Cache copy of item.
 * @type api
 * @hidden 
 */
@interface TTVideoEngineCopyCacheItem : NSObject


/**
 * destPath, absolute path with file name
 */
@property (nonnull, nonatomic, copy) NSString* destPath;

/**
 * filekey
 */
@property (nonnull, nonatomic, copy) NSString* fileKey;

/**
 * 如果正在下载过程如播放，是否等待下载完
 */
@property (nonatomic, assign) BOOL waitIfCaching;
@property (nonatomic, copy) void (^completionBlock)(BOOL isSuccess,NSError* _Nullable  err);


/**
 * 强制拷贝未缓存完整，设置为 True 后， waitIfCaching 不生效
 */
@property (nonatomic, assign) BOOL forceCopy;

/**
 * info callback, key : @"meida_size",@"cache_size"
 */

@property (nonatomic, copy) void (^infoBlock)(NSDictionary<NSString*, id>* info);

- (instancetype)initWithKey:(NSString *)key
                   destPath:(NSString *)path
            completionBlock:(void (^)(BOOL isSuccess, NSError* err))completionBlock;

- (instancetype)initWithKey:(NSString *)key
                   destPath:(NSString *)path
               waitIfCaching:(BOOL)waitIfCaching
            completionBlock:(void (^)(BOOL isSuccess, NSError* err))completionBlock;

- (instancetype)initWithKey:(NSString *)key
                   destPath:(NSString *)path
               forceCopy:(BOOL)forceCopy
                infoBlock:(void(^)(NSDictionary<NSString*, id>* info))infoBlock
            completionBlock:(void (^)(BOOL isSuccess, NSError* err))completionBlock;

- (instancetype)initWithKey:(NSString *)key
                   destPath:(NSString *)path
              waitIfCaching:(BOOL)waitIfCaching
               forceCopy:(BOOL)forceCopy
                infoBlock:(void(^)(NSDictionary<NSString*, id>* info))infoBlock
            completionBlock:(void (^)(BOOL isSuccess, NSError* err))completionBlock;

@end

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Local server log 对象
 */
/**
 * @locale en
 * @brief Local server log object
 * @type api
 * @hidden 
 */
@interface TTVideoEngineLocalServerCDNLog : NSObject
/// Task key.
@property (nonatomic,   copy) NSString *fileKey;
/// host.
@property (nonatomic, nullable, copy) NSString *host;
/// host.
@property (nonatomic, nullable, copy) NSString *url;
/// server ip.
@property (nonatomic, nullable, copy) NSString *serverIp;
/// xcache.
@property (nonatomic, nullable, copy) NSString *xCache;
/// xmcache.
@property (nonatomic, nullable, copy) NSString *xMCache;
/// contentlength.
@property (nonatomic, assign) int64_t contentLength;
/// contentlength.
@property (nonatomic, assign) int64_t reqStartT;
/// contentlength.
@property (nonatomic, assign) int64_t reqEndT;

@end

/**
 * @locale zh
 * @hidden
 */
typedef NSNumber*  VEMDLKeyType;
#ifndef VEKMDLKEY
#define VEKMDLKEY(key)  @(key)
#endif

/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief Use these keys, set value correspond the key, also get value correspod the key.
 *       Please use marco VEKMDLKEY(key), example: VEKMDLKEY(VEMDLKeyMaxCacheSize_NSInteger)
 */
/**
 * @locale en
 * @type keytype
 * @brief Use these keys to set values corresponding to the keys, and also to get values corresponding to the keys. Please use the macro VEKMDLKEY(key), for example: VEKMDLKEY(VEMDLKeyMaxCacheSize_NSInteger).
 * @hidden 
 */
typedef NS_ENUM(NSInteger, VEMDLKey) {
    /// medialoader key start config pass to mdl native
    /// The max cache data size.
    VEMDLKeyMaxCacheSize_NSInteger = (1<<14) + 3,
    /// TCP establishment time.
    VEMDLKeyOpenTimeOut_NSInteger = (1<<14) + 4,
    /// TCP read write time.
    VEMDLKeyRWTimeOut_NSInteger = (1<<14) + 5,
    /// Error occurred, number of retries.
    VEMDLKeyTryCount_NSInteger = (1<<14) + 6,
    /// Paralle task number.
    VEMDLKeyPreloadParallelNum_NSInteger = (1<<14) + 7,
    /// is enable oc dns parse.
    VEMDLKeyEnableExternDNS_BOOL = (1<<14) + 8,
    /// reuse socket.
    VEMDLKeyEnableSoccketReuse_BOOL = (1<<14) + 9,
    /// socket idle timeout.
    VEMDLKeySocketIdleTimeout_NSInteger = (1<<14) + 10,
    /// checksumlevel.
    VEMDLKeyChecksumLevel_NSInteger = (1<<14) + 11,
    /// The longest time that cached data exists. unit is second.
    /// Default value is 14*24*60*60, 14 day.
    VEMDLKeyMaxCacheAge_NSInteger = (1<<14) + 12,
    /// The Cache data folder.
    VEMDLKeyCachDirectory_NSString = (1<<14) + 13,
    
    /// is enable auth play
    VEMDLKeyIsEnableAuth_NSInteger = (1<<14) + 14,
    
    // heart beat interval, 0 is disable, unit: ms
    VEMDLKeyHeartBeatInterval_NSInteger = (1<<14) + 15,
    /// download dir.
    VEMDLKeyDownloadDirectory_NSString = (1<<14) + 16,
    
    VEMDLKeyWriteFileNotifyIntervalMS_NSInteger = (1<<14) + 17,
    
    VEMDLKeyIsEnableLazyBufferPool_BOOL = (1<<14) + 18,
    
    VEMDLKeyIsEnablePreConnect_BOOL = (1<<14) + 19,
    
    VEMDLKeyPreConnectNum_NSInteger = (1<<14) + 20,
    
    VEMDLKeyIsEnableMDLAlog_BOOL = (1<<14) + 21,
    
    VEMDLKeyIsEnableNewBufferpool_BOOL = (1<<14) + 22,
    VEMDLKeyNewBufferpoolBlockSize_NSInteger = (1<<14) + 23,
    VEMDLKeyNewBufferpoolResidentSize_NSInteger = (1<<14) + 24,
    VEMDLKeyNewBufferpoolGrowBlockCount_NSInteger = (1<<14) + 25,
    
    VEMDLKeyIsEnableSessionReuse_BOOL = (1<<14) + 26,
    VEMDLKeySessionTimeout_NSInteger = (1<<14) + 27,
    VEMDLKeyMaxTlsVersion_NSInteger = (1<<14) + 28,
    
    VEMDLKeyIsEnableLoaderPreempt_BOOL = (1<<14) + 29,
    VEMDLKeyNextDownloadThreshold_NSInteger = (1<<14) + 30,
    
    VEMDLKeyMaxIPV4Count_NSInteger = (1<<14) + 31,
    VEMDLKeyMaxIPV6Count_NSInteger = (1<<14) + 32,
    
    VEMDLKeyIsEnablePlayLog_BOOL = (1<<14) + 33,
    
    VEMDLKeyIsEnableFileExtendBuffer_BOOL = (1<<14) + 34,
    
    VEMDLKeyIsEnableNetScheduler_BOOL = (1<<14) + 35,
    VEMDLKeyIsNetSchedulerBlockAllNetErr_BOOL = (1<<14) + 36,
    VEMDLKeyNetSchedulerBlockErrCount_NSInteger = (1<<14) + 37,
    VEMDLKeyNetSchedulerBlockDuration_NSInteger = (1<<14) + 38,
    VEMDLKeyIsAllowTryLastUrl_BOOL = (1<<14) + 39,
    VEMDLKeyIsEnableLocalDNSThreadOptimize_BOOL = (1<<14) + 40,
    
    VEMDLKeyIsEnableCacheReqRange_BOOL = (1<<14) + 41,
    
    VEMDLKeyConnectPoolStragetyValue_NSInteger = (1<<14) + 42,
    VEMDLKeyMaxAliveHostNum_NSInteger = (1<<14) + 43,
    VEMDLKeyMaxSocketReuseCount_NSInteger = (1<<14) + 44,
    
    VEMDLKeyFileExtendSizeKB_NSInteger = (1<<14) + 45,
    VEMDLKeyIsEnableFixCancelPreload_BOOL = (1<<14) + 46,
    
    VEMDLKeyIsEnableDNSNoLockNotify_BOOL = (1<<14) + 47,
    
    VEMDLKeyIsEnableEarlyData_NSInteger = (1<<14) + 48,
    
    VEMDLKeyIsCacheDirMaxCacheSize_NSDictionary = (1<<14) + 49,
    
    VEMDLKeyIsEnableByPassCookie_BOOL = (1<<14) + 50,
    
    VEMDLKeyIsSocketTrainingCenterConfig_NSString = (1<<14) + 51,
    VEMDLKeyIsNetSchedulerBlockHostErrIpCount_NSInteger = (1<<14) + 52,
    VEMDLKeyIsEnableIOManager_BOOL = (1<<14) + 53,
    VEMDLKeyIsEnableMaxCacheAgeForAllDir_BOOL = (1<<14) + 54,
    
    VEMDLKeyIsFileMemCacheMaxSize_NSInteger = (1<<14) + 55,
    VEMDLKeyIsFileMemCacheMaxNum_NSInteger = (1<<14) + 56,
    
    VEMDLKeyIsEnableReqWaitNetReachable_BOOL = (1<<14) + 57,
    VEMDLKeyIsLoadMonitorTimeInternal_NSInteger = (1<<14) + 58,
    VEMDLKeyIsLoadMonitorMinAllowLoadSize_NSInteger = (1<<14) + 59,
    VEMDLKeyIsNetSchedulerConfigStr_NSString = (1<<14) + 60,
    
    VEMDLKeyIsEnableUseOriginalUrl_BOOL = (1<<14) + 61,
    VEMDLKeyIsDynamicPreconnectConfigStr_NSString = (1<<14) + 62,
    VEMDLKeyIsEnableLoaderLogExtractUrls_BOOL = (1<<14) + 63,
    VEMDLKeyIsMaxLoaderLogNum_NSInteger = (1<<14) + 64,
    VEMDLKeyIsEnableMultiNetwork_BOOL = (1<<14) + 65,
    
    VEMDLKeyIsLoaderType_NSInteger = (1<<14) + 66,
    VEMDLKeyIsExtensionOpts_NSString = (1<<14) + 67,
    VEMDLKeyIsDashAudioPreloadMinSize_NSInteger = (1<<14) + 68, // Byte
    VEMDLKeyIsDashAudioPreloadRatio_NSInteger = (1<<14) + 69,   // value 1-100
    VEMDLKeyIsTemporaryOptStr_NSString = (1<<14) + 70,
    VEMDLKeyIsCustomUA_1_NSString = (1<<14) + 71,
    VEMDLKeyIsCustomUA_2_NSString = (1<<14) + 72,
    VEMDLKeyIsCustomUA_3_NSString = (1<<14) + 73,
    VEMDLKeyIsThreadStackSizeLevel = (1<<14) + 74,

    VEMDLKeyIsEnableUnlimitHttpHeader_BOOL = (1<<14) + 75,
    
    VEMDLKeyIsThreadPoolMinCount = (1<<14) + 76,
    VEMDLKeyIsEnableThreadPoolCheckIdle = (1<<14) + 77,
    VEMDLKeyIsThreadPoolIdleTTLSecond = (1<<14) + 78,
    
    VEMDLKeyIsVendorTestId_NSString = (1<<14) + 79,
    
    VEMDLKeyIsEnableFileMutexOptimize_BOOL = (1<<14) + 80,
    VEMDLKeyIsEnableMDL2_BOOL = (1<<14) + 81,
    VEMDLKeyIsSkipCDNBeforeExpire_NSInteger = (1<<14) + 82,   // value 1-100
    VEMDLKeyIsFileRingBufferOpts_NSString = (1<<14) + 83,
    VEMDLKeyIsVendorGroupId_NSString = (1<<14) + 84,
    
    VEMDLKeyIsRingBufferSize_NSInteger = (1<<14) + 85,
    VEMDLKeyIsIgnoreTextSpeedTest_BOOL = (1<<14) + 86,
    VEMDLKeyIsN80Config_NSString = (1<<14) + 87,
    VEMDLKeyIsCookieTokenCheckLevel_NSInteger = (1<<14) + 88,
    VEMDLKeyIsEnableUseGroupId_BOOL =(1<<14) + 89,
    VEMDLKeyIsDisableFilePathCheck_BOOL = (1<<14) + 90,
    VEMDLKeyIsEnableStorageModule_NSInteger = (1<<14) + 91,
    VEMDLKeyIsStoStrategyConfig_NSString = (1<<14) + 92,
    VEMDLKeyIsSessionCacheInterval_NSInteger = (1<<14) + 93,
    VEMDLKeyIsFileManagerInterval_NSInteger = (1<<14) + 94,
    VEMDLKeyIsEnablePreloadProgressCallback_BOOL = (1<<14) + 95,
    VEMDLKeyIsProtectCacheDirsAvoidClean_NSArray = (1<<14) + 96,
    VEMDLKeyIsCloseLocalServer_NSInteger = (1<<14) + 97,
    VEMDLKeyIsPrecisePreloadConfigStr_NSString = (1<<14) + 98,
    VEMDLKeyIsDisableFilePathCheckWhenPlay_BOOL = (1<<14) + 99,
    VEMDLKeyIsVideoBufferLength_NSInteger = (1<<14) + 100,
    VEMDLKeyIsEnableTsKeyUseAbsoluteURL = (1<<14) + 101,
    VEMDLKeyIsFileKeyRegularExpression = (1<<14) + 102,
    VEMDLKeyIKeyIsEncryptVersion = (1<<14) + 103,
    
    /// tob
    VEMDLKeyIsEnableReportHeaders = (1<<15) + 1,
    VEMDLKeyIsShouldNetNotReachableStopRetry = (1<<15) + 2,
	VEMDLKeyIsEnableDomainSpeed_BOOL = (1<<15) + 3,
	VEMDLKeyIsEnableDomainSpeedByRange_BOOL = (1<<15) + 4,
	VEMDLKeyIsDomainSpeedTTL_NSInteger = (1<<15) + 5,
    /// medialoader key end
};


/**
 * @locale zh
 * @type keytype
 * @brief 数据加载模块配置。数据加载模块（MDL，Media Data Loader）是点播 SDK 内部的关键模块之一，为播放器提供高速、低成本、可靠的数据加载服务。点播 SDK 的预加载、文件缓存、边下边播、网络质量和成本数据监控等功能均依赖于数据模块。点播 SDK 初始化时，会默认启动数据加载模块。
 */
/**
 * @locale en
 * @type keytype
 * @brief Configuration for the data loading module. The data loading module (MDL, Media Data Loader) is one of the key modules within the VOD SDK, providing the player with high-speed, low-cost, and reliable data loading services. Features like preloading, file caching, progressive downloading and playing, as well as network quality and cost data monitoring of the VOD SDK all depend on the data loading module. When the VOD SDK is initialized, the data loading module is started by default.
 */
@interface TTVideoEngineLocalServerConfigure : NSObject

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 初始化方法
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 初始化方法
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Set options by VEKMDLKEY
 *           Example:
 *           [self setOptions:@{VEKMDLKEY(VEMDLKeyMaxSocketReuseCount_NSInteger),@(1)}];
 *                     |                   |          |                          |
 *               Generate key            Field     valueType                   value
 */
/**
 * @locale en
 * @hidden
 * @brief Initialization Method
 * @type api
 */
- (void)setOptions:(NSDictionary<VEMDLKeyType,id> *)options;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief key is a type of VEMDLKey or VEKGetKey.
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief key is a type of VEMDLKey or VEKGetKey.
 */
- (void)setOptionForKey:(VEMDLKeyType)key value:(id)value;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取 option value
 */
/**
 * @locale en
 * @hidden
 * @brief Retrieve option value
 * @type api
 */
- (id)getOptionBykey:(VEMDLKeyType)key;

/**
 * @locale zh
 * @brief 设置本地缓存最大数据量，单位为 byte。
 */
/**
 * @locale en
 * @brief Set the maximum amount of local cache data, measured in bytes.
 */
@property(nonatomic, assign) NSInteger maxCacheSize;
/**
 * @locale zh
 * @hidden
 * @brief TCP establishment time.
 */
/**
 * @locale en
 * @hidden
 * @brief Time taken for TCP connection establishment.
 */
@property(nonatomic, assign) NSInteger openTimeOut;
/**
 * @locale zh
 * @hidden
 * @brief TCP read write time.
 */
/**
 * @locale en
 * @hidden
 * @brief TCP read-write time.
 */
@property(nonatomic, assign) NSInteger rwTimeOut;
/**
 * @locale zh
 * @hidden
 * @brief Error occurred, number of retries.
 */
/**
 * @locale en
 * @hidden
 * @brief An error occurred, number of retries.
 */
@property(nonatomic, assign) NSInteger tryCount;
/**
 * @locale zh
 * @brief 设置预加载并发数，默认值为 2。
 */
/**
 * @locale en
 * @brief Set the preloading concurrency, with a default value of 2.
 */
@property(nonatomic, assign) NSInteger preloadParallelNum;
/**
 * @locale zh
 * @hidden
 * @brief is enable oc dns parse.
 */
/**
 * @locale en
 * @hidden
 * @brief is enable OC DNS parsing.
 */
@property(nonatomic, assign) BOOL enableExternDNS;
/**
 * @locale zh
 * @hidden
 * @brief reuse socket.
 */
/**
 * @locale en
 * @hidden
 * @brief reuse socket.
 */
@property(nonatomic, assign) BOOL enableSoccketReuse;
/**
 * @locale zh
 * @hidden
 * @brief socket idle timeout.
 */
/**
 * @locale en
 * @hidden
 * @brief Socket idle timeout.
 */
@property(nonatomic, assign) NSInteger socketIdleTimeout;
/**
 * @locale zh
 * @hidden
 * @brief checksumlevel.
 */
/**
 * @locale en
 * @hidden
 * @brief checksumlevel.
 */
@property(nonatomic, assign) NSInteger checksumLevel;
/**
 * @locale zh
 * @hidden
 * @brief The longest time that cached data exists. unit is second.
 * Default value is 14*24*60*60, 14 day.
 */
/**
 * @locale en
 * @hidden
 * @brief The maximum duration that cached data exists. The unit is seconds. The default value is 14*24*60*60, which equals 14 days.
 */
@property(nonatomic, assign) NSInteger maxCacheAge;
/**
 * @locale zh
 * @hidden
 * @brief 缓存数据文件夹。
 */
/**
 * @locale en
 * @hidden
 * @brief The Cache data folder.
 */
@property(nonatomic, nullable, copy) NSString *cachDirectory;
/**
 * @locale zh
 * @hidden
 * @brief 启用认证播放
 */
/**
 * @locale en
 * @hidden
 * @brief is_enable_auth_play
 */
@property(nonatomic, assign) NSInteger isEnableAuth;
/**
 * @locale zh
 * @hidden
 * @brief heart beat interval, 0 is disable, unit: ms
 */
/**
 * @locale en
 * @hidden
 * @brief Heart beat interval, 0 means disable, unit: ms
 */
@property(nonatomic, assign) NSInteger heartBeatInterval;
/**
 * @locale zh
 * @brief 设置下载文件的沙盒存储路径，如果你使用下载功能，该路径必须设置。
 */
/**
 * @locale en
 * @brief Set the sandbox storage path for downloaded files. If using the download feature, this path must be configured.
 */
@property(nonatomic, nullable, copy) NSString *downloadDirectory;
/**
 * @locale zh
 * @hidden
 * @brief mdl 扩展 options
 */
/**
 * @locale en
 * @hidden
 * @brief mdl extension options
 */
@property(nonatomic, nullable, copy) NSString *mdlExtensionOpts;
/**
 * @locale zh
 * @hidden
 * @brief n80 配置
 */
/**
 * @locale en
 * @hidden
 * @brief n80 configuration
 */
@property(nonatomic, nullable, copy) NSString *n80Config;
/**
 * @locale zh
 * @hidden
 * @brief 写文件通知时间间隔，单位毫秒
 */
/**
 * @locale en
 * @hidden
 * @brief Write file notification interval, in milliseconds
 */
@property(nonatomic, assign) NSInteger writeFileNotifyIntervalMS;
/**
 * @locale zh
 * @hidden
 * @brief 禁止cookie
 */
/**
 * @locale en
 * @hidden
 * @brief Disable cookies
 */
@property(nonatomic, assign) NSInteger forbidByPassCookie;
/**
 * @locale zh
 * @hidden
 * @brief Whether to report network log。
 * Convenient to solve online issue
 */
/**
 * @locale en
 * @hidden
 * @brief Whether to report network log. Convenient for solving online issues.
 */
@property (nonatomic,assign) BOOL reportNetLogEnable;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableLazyBufferPool;
/**
 * @locale zh
 * @hidden
 * @brief 开启预链接
 */
/**
 * @locale en
 * @hidden
 * @brief Enable Prelinking
 */
@property(nonatomic, assign) BOOL isEnablePreConnect;
/**
 * @locale zh
 * @hidden
 * @brief 设置预链接个数
 */
/**
 * @locale en
 * @hidden
 * @brief Set number of prelinks
 */
@property(nonatomic, assign) NSInteger preConnectNum;
/**
 * @locale zh
 * @hidden
 * @brief 开启mdl alog
 */
/**
 * @locale en
 * @hidden
 * @brief Enable mdl alog
 */
@property(nonatomic, assign) BOOL isEnableMDLAlog;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableNewBufferpool;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger newBufferpoolBlockSize;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger newBufferpoolResidentSize;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger newBufferpoolGrowBlockCount;
/**
 * @locale zh
 * @hidden
 * @brief 开启 session 复用
 */
/**
 * @locale en
 * @hidden
 * @brief Enable Session Reuse
 */
@property(nonatomic, assign) BOOL isEnableSessionReuse;
/**
 * @locale zh
 * @hidden
 * @brief sesstion 超时时间
 */
/**
 * @locale en
 * @hidden
 * @brief Session Timeout
 */
@property(nonatomic, assign) NSInteger sessionTimeout;
/**
 * @locale zh
 * @hidden
 * @brief 设置tls版本
 */
/**
 * @locale en
 * @hidden
 * @brief Set TLS version
 */
@property(nonatomic, assign) NSInteger maxTlsVersion;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableLoaderPreempt;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger nextDownloadThreshold;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxIPV4Count;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxIPV6Count;
/**
 * @locale zh
 * @hidden
 * @brief 开启播放日志
 */
/**
 * @locale en
 * @hidden
 * @brief Enable Playback Logs
 */
@property(nonatomic, assign) BOOL isEnablePlayLog;
/**
 * @locale zh
 * @hidden
 * @brief 开启扩展buffer
 */
/**
 * @locale en
 * @hidden
 * @brief Enable Extended Buffer
 */
@property(nonatomic, assign) BOOL isEnableFileExtendBuffer;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableNetScheduler;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isNetSchedulerBlockAllNetErr;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger netSchedulerBlockErrCount;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger netSchedulerBlockDuration;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger netSchedulerBlockHostErrIpCount;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isAllowTryLastUrl;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableLocalDNSThreadOptimize;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableCacheReqRange;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger connectPoolStragetyValue;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxAliveHostNum;
/**
 * @locale zh
 * @hidden
 * @brief socket 复用个数
 */
/**
 * @locale en
 * @hidden
 * @brief Number of Socket Reuses
 */
@property(nonatomic, assign) NSInteger maxSocketReuseCount;
/**
 * @locale zh
 * @hidden
 * @brief 扩展buffer大小
 */
/**
 * @locale en
 * @hidden
 * @brief Expand buffer size
 */
@property(nonatomic, assign) NSInteger fileExtendSizeKB;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableFixCancelPreload;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableDNSNoLockNotify;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger isEnableEarlyData;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *socketTrainingCenterConfigStr;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, nullable, copy) NSDictionary<NSString*, NSNumber*>* cacheDirMaxCacheSize;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableByPassCookie;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL enableIOManager;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger socketRecvBufferSizeByte;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableNewNetworkSpeedTest;

/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableMaxCacheAgeForAllDir;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxFileMemCacheSize;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxFileMemCacheNum;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableAutoResolution;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, strong) TTVideoEngineAutoResolutionParams *autoResolutionParams;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL isEnableReqWaitNetReachable;
/**
 * @locale zh
 * @brief 断网停止数据下载重试请求
 * @hidden
*/
/**
 * @locale en
 * @hidden (iOS)
 */
@property(nonatomic, assign) BOOL isEnableNetNotReachableStopRetry;
/**
 * @locale zh
 * @brief multi domain dispatch by speed, default is NO
 * @hidden
*/
/**
 * @locale en
 * @brief multi domain dispatch by speed, default is NO
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableDomainSpeed;
/**
 * @locale zh
 * @brief default is NO; 0 by single play, 1 by range
 * @hidden
*/
/**
 * @locale en
 * @brief default is NO; 0 by single play, 1 by range
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableDomainSpeedByRange;
/**
 * @locale zh
 * @brief default is 300s
 * @hidden
*/
/**
 * @locale en
 * @brief default is 300s
 * @hidden
 */
@property(nonatomic, assign) NSInteger domainSpeedTtl;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger loadMonitorTimeInternal;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger loadMonitorMinAllowLoadSize;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *netSchedulerConfigStr;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *dynamicPreconnectConfigStr;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableUseOriginalUrl;
/**
 * @locale zh
 * @hidden
 * @brief bugfix:ts url key use absolute url
*/
/**
 * @locale en
 * @hidden
 * @brief bugfix: The ts URL key uses an absolute URL
 */
@property(nonatomic, assign) BOOL m3uTsKeyUseAbsoluteUrl;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableLoaderLogExtractUrls;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger maxLoaderLogNum;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableMultiNetwork;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger threadStackSizeLevel;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger threadPoolMinCount;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableThreadPoolCheckIdle;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger threadPoolIdleTTLSecond;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isIgnoreTextSpeedTest;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger mDashAudioPreloadMinSize;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger mDashAudioPreloadRatio;
/**
 * @locale zh
 * @hidden
 * @brief 开启本地缓存加密
*/
/**
 * @locale en
 * @hidden
 * @brief Enable Local Cache Encryption
 */
@property(nonatomic, assign) BOOL encryptVersion;
/**
 * @locale zh
 * @hidden
 * @brief loader type
 */
/**
 * @locale en
 * @hidden
 * @brief loader type
 */
@property(nonatomic, assign) NSInteger loaderType;

/**
 * @locale zh
 * @hidden
 * @brief pcdn auto
 */
/**
 * @locale en
 * @hidden
 * @brief pcdn auto
 */
@property(nonatomic, assign) NSInteger isEnablePcdnAuto;

/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *temporaryOptStr;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *vendorTestIdStr;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *vendorGroupIdStr;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *customUA_1;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *customUA_2;
/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *customUA_3;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableUnlimitHttpHeader;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableFileMutexOptimize;
/**
 * @locale zh
 * @hidden
 * @brief 开启MDL 2.0
*/
/**
 * @locale en
 * @hidden
 * @brief Enable MDL 2.0
 */
@property(nonatomic, assign) BOOL isEnableMDL2;
/**
 * @locale zh
 * @hidden  
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign, readonly) BOOL userDidConfigEnableMDL2;

/**
 * @locale zh
 * @hidden 
 */
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger skipCDNBeforeExpire;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger ringBufferSize;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *fileRingBufferOptStr;
/**
 * @locale zh
 * @hidden
 * @brief 是否启用 HLS 代理： <br>
 *        - YES: 是。<br>
 *        - NO: 否。
 */
/**
 * @locale en
 * @hidden
 * @brief Is HLS proxy enabled:<br>
 *        - YES: Yes.<br>
 *        - NO: No.
 */
@property(nonatomic, assign) BOOL isEnableHLSProxy;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableHLSProxyPreloadFirstTs;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableHLSProxyPreloadAllTs;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableUseGroupId;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isDisableFilePathCheck;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isDisableFilePathCheckWhenPlay;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableReportHeaders;
/**
 * @locale zh
 * @hidden
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger cookieTokenCheckLevel;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *fileKeyOptStr;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger enableStorageModule;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, nullable, copy) NSString *stoStrategyConfig;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) BOOL isEnableEnablePreloadProgressCallback;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger sessionCacheIntervalMs;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger fileManagerIntervalMs;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, nullable, copy) NSArray<NSString*>* protectCacheDirsAvoidClean;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, assign) NSInteger isCloseLocalServer;
/**
 * @locale zh
 * @hidden 
*/
/**
 * @locale en
 * @hidden
 */
@property(nonatomic, copy) NSString *precisePreloadConfigStr;
@end

/**
 * @locale zh
 * @hidden for internal use only
 * @type callback
 * @brief 播放器引擎内部回调，业务无需使用。
*/
/**
 * @locale en
 * @type callback
 * @brief Player engine internal callback, not needed for business use.
 * @hidden 
 */
@protocol TTVideoEngineInternalDelegate <NSObject>

@optional
- (void)didFinishVideoDataDownloadForKey:(NSString *)key;
- (void)noVideoDataToDownloadForKey:(NSString *)key;

@end

/**
 * @locale zh
 * @hidden for internal use only
 * @type api
 * @brief 播放器内部方法，业务无需使用。
 */
/**
 * @locale en
 * @brief Internal methods of the player, not needed for business use.
 * @type api
 * @hidden 
 */
@interface TTVideoEngine (Downloader_Private)
+ (nullable NSString *)_ls_downloadUrl:(NSString *)key
                                rawKey:(nullable NSString *)rawKey
                                  urls:(NSArray<NSString *> *)urls;
+ (void)_ls_startDownload:(NSString *)downloadUrl;
+ (void)_ls_cancelDownloadByKey:(NSString *)key;
@end

@class _TTVideoEnginePreloadTask;
/**
 * @locale zh
 * @hidden for internal use only
 * @type api
 * @brief 内部使用，业务无需关注。
 */
/**
 * @locale en
 * @brief For internal use only, no need for business attention.
 * @type api
 * @hidden 
 */
@interface TTVideoEngineLoadProgress (Private)
- (void)setUp:(_TTVideoEnginePreloadTask *)task;
@end

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 内部使用，业务无需关注。
 */
/**
 * @locale en
 * @brief For internal use only, no need for business attention.
 * @type api
 * @hidden 
 */
@interface TTVideoEngine (MediaLoaderExperiment)

+ (void)setMDLNetUnReachableStopRetry:(BOOL) stopRetry;
- (NSString*)ls_proxyUrl:(NSString *)key rawKey:(NSString *)rawKey urls:(NSArray<NSString *> *)urls extraInfo:(nullable NSString *)extra filePath:(nullable NSString *)filePath;

@end

/**
 * @locale zh
 * @type api
 * @brief 开启 HLSProxy 相关回调。
 */
/**
 * @locale en
 * @brief Enable HLSProxy-related callbacks.
 * @type api
 */
@protocol TTVideoEngineHLSProxyDelegate <NSObject>

@optional
/**
 * @locale zh
 * @hidden 
 * @type api
 * @brief 自定义 TS 文件的缓存 Key。注意：相同的url返回的文件缓存Key一定要相同，反之，不同的ulr返回的文件缓存Key一定不能相同。如果你不清楚这个委托方法的作用，请不要实现该委托方法。
 * @param url 文件 URL。
 * @param hlsFileKey 文件缓存 Key。
 * @param infos 其他信息，一般业务无需关注。
 * @return 返回该url对应的自定义文件缓存key。
 */
/**
 * @locale en
 * @brief Custom cache Key for TS files.Note: The file cache keys returned by the same URL must be the same. Conversely, the file cache keys returned by different URLs must be different. If you are not clear about the function of this delegate method, please do not implement it.
 * @param url File URL.
 * @param hlsFileKey File Cache Key.
 * @param infos Other information, generally not relevant for business purposes.
 * @return Returns the custom file cache key corresponding to the URL.
 */
- (NSString * _Nullable)generateFileKey:(NSString *_Nonnull)url hlsFileKey:(NSString *_Nonnull )hlsFileKey infos:(NSDictionary *_Nullable)infos;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 新链接的信息。
 * @param info 输入链接信息。
 */
/**
 * @locale en
 * @brief New url information.
 * @param in Input url information.
 */
- (NSDictionary *)OnExChangeUrl:(NSDictionary *)info;

@end

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief HLS  相关 API
*/
/**
 * @locale en
 * @brief HLS Related API
 * @type api
 * @hidden 
 */
@interface TTVideoEngine (HLSProxyManager)

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置 HLSProxy 代理回调
 * @param delgate 代理回调
 */
/**
 * @locale en
 * @brief Set HLSProxy Callback
 * @param delgate Proxy Callback
 */
+ (void)setHLSProxyDelegate:(id<TTVideoEngineHLSProxyDelegate>)delgate;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 设置预加载模式
 * @param parentKey parent key
 * @param mode 预链接模式
 */
/**
 * @locale en
 * @brief Set Preloading Mode
 * @param parentKey parent key
 * @param mode Prelink Mode
 */
+ (void)changePreloadTaskRunMode:(NSString*)parentKey RunMode:(TTCMPreConnectRunMode)mode;

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief 设置预加载最大个数
 * @param parentKey parent key
 * @param num 预加载并发数
 */
/**
 * @locale en
 * @brief Set Preload Maximum Count
 * @param parentKey parent key
 * @param num Preload Concurrency
 */
+ (void)setPreloadTaskMaxTaskNum:(NSString*)parentKey num:(int)num;

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief 暂停预加载任务
 * @param parentKey parent key
 */
/**
 * @locale en
 * @brief Pause Preloading Task
 * @param parentKey parent key
 */
+ (void)pausePreloadTask:(NSString*) parentKey;

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief 恢复预加载任务
 * @param parentKey parent key
 */
/**
 * @locale en
 * @brief Resume Preload Task
 * @param parentKey parent key
 */
+ (void)resumePreloadTask:(NSString*) parentKey;

@end

NS_ASSUME_NONNULL_END


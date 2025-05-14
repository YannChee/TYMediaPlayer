//
//  TTVideoEngineDownloader.h
//  TTVideoEngine
//
//  Created by 黄清 on 2020/3/12.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngine+Preload.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 下载状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief Download status.
 */
typedef NS_ENUM(NSInteger,TTVideoEngineDownloadState) {

   /**
    * @locale zh
    * @brief 初始化。
    */
   /**
    * @locale en
    * @brief Initialize.
    */
    TTVideoEngineDownloadStateInit      = 0,

   /**
    * @locale zh
    * @brief 等待中。
    */
   /**
    * @locale en
    * @brief Waiting.
    */
    TTVideoEngineDownloadStateWaiting   = 1,

   /**
    * @locale zh
    * @brief 运行中。
    */
   /**
    * @locale en
    * @brief Running.
    */
    TTVideoEngineDownloadStateRunning   = 2,

   /**
    * @locale zh
    * @brief 暂停。
    */
   /**
    * @locale en
    * @brief Pause.
    */
    TTVideoEngineDownloadStateSuspended = 3,

   /**
    * @locale zh
    * @brief 正在取消。
    */
   /**
    * @locale en
    * @brief Cancelling.
    */
    TTVideoEngineDownloadStateCanceling = 4,

   /**
    * @locale zh
    * @brief 完成。
    */
   /**
    * @locale en
    * @brief Completed.
    */
    TTVideoEngineDownloadStateCompleted = 5,
};


/**
 * @locale zh
 * @hidden
 * @brief 下载任务错误域名。
 */
/**
 * @locale en
 * @hidden
 * @brief Error Domain
 */
FOUNDATION_EXPORT NSErrorDomain const TTVideoEngineDownloadTaskErrorDomain;

/**
 * @locale zh
 * @hidden
 * @brief 下载用户取消错误键。
 */
/**
 * @locale en
 * @hidden
 * @brief Error Key。
 */
FOUNDATION_EXPORT NSErrorUserInfoKey const TTVideoEngineDownloadUserCancelErrorKey;

@class TTVideoEngineDownloadTask;
@class TTVideoEngineDownloadURLTask;
@class TTVideoEngineDownloadVidTask;
@protocol TTVideoEngineDownloaderDelegate;

/**
 * @locale zh
 * @type api
 * @brief 下载任务管理器。
 * @pos 10
 */
/**
 * @locale en
 * @brief Download Task Manager.
 * @pos 10
 * @type api
 */
@interface TTVideoEngineDownloader : NSObject

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 请不要直接调用，使用 [TTVideoEngineDownloader shareLoader] 单例
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 请不要直接调用，使用 [TTVideoEngineDownloader shareLoader] 单例
 */
+ (instancetype)new  NS_UNAVAILABLE;

/**
 * @locale zh
 * @type api
 * @brief 单例方法。
 */
/**
 * @locale en
 * @brief Please do not call directly, use the [TTVideoEngineDownloader shareLoader] singleton.
 * @hidden (iOS)
 */
+ (instancetype)shareLoader;

/**
 * @locale zh
 * @type api
 * @brief 获取所有下载任务。
 * @param completionHandler Block 回调。
 * @list 下载
 * @order 2
 */
/**
 * @locale en
 * @brief Retrieve all download tasks.
 * @param completionHandler Block callback.
 * @list 下载
 * @order 2
 */
- (void)getAllTasksWithCompletionHandler:(void (^)(NSArray<__kindof TTVideoEngineDownloadTask *> * _Nonnull))completionHandler;

/**
 * @locale zh
 * @type api
 * @brief 获取所有下载任务的总大小，单位为 byte。
 * @return 返回所有下载任务的总大小。
 * @notes <br>
 *        - 此方法必须在 `getAllTasksWithCompletionHandler` 的 block 回调中调用。
 *        - 播放 HLS 视频时，当前值可能不准。如果要获取下载进度，建议直接通过 `TTVideoEngineDownloadTask.progress` 属性获取。
 * @list 下载
 * @order 3
 */
/**
 * @locale en
 * @brief Retrieve the total size of all download tasks, in bytes.
 * @list 下载
 * @order 3
 * @notes <br>
 *        - This method must be called within the block callback of `getAllTasksWithCompletionHandler`.
 *        - When playing HLS videos, the current value might not be accurate. To get the download progress, it is recommended to directly use the `TTVideoEngineDownloadTask.progress` property.
 * @return Return the total size of all download tasks.
 */
- (NSInteger)downloadSize;

/**
 * @locale zh
 * @type api
 * @brief 暂停所有下载任务。
 * @notes 此方法必须在 `getAllTasksWithCompletionHandler` 的 block 回调中调用。
 * @list 下载
 * @order 5
 */
/**
 * @locale en
 * @list 下载
 * @order 5
 * @brief Pause all download tasks.
 * @notes This method must be called within the block callback of `getAllTasksWithCompletionHandler`.
 */
- (void)suspendAllTasks;

/**
 * @locale zh
 * @type api
 * @brief 恢复所有下载任务。
 * @notes 此方法必须在 `getAllTasksWithCompletionHandler` 的 block 回调中调用。
 * @list 下载
 * @order 4
 */
/**
 * @locale en
 * @list 下载
 * @order 4
 * @brief Resume all download tasks.
 * @notes This method must be called within the block callback of `getAllTasksWithCompletionHandler`.
 */
- (void)resumeAllTasks;

/**
 * @locale zh
 * @type api
 * @brief 删除所有下载任务。
 * @notes 此方法必须在 `getAllTasksWithCompletionHandler` 的 block 回调中调用。
 * @list 下载
 * @order 6
 */
/**
 * @locale en
 * @list 下载
 * @order 6
 * @brief Delete all download tasks.
 * @notes This method must be called within the block callback of `getAllTasksWithCompletionHandler`.
 */
- (void)removeAllTasks;

/**
 * @locale zh
 * @type api
 * @brief 设置最大并发数。默认值为 1。
 */
/**
 * @locale en
 * @brief Set the maximum concurrency. The default value is 1.
 */
@property (nonatomic, assign) NSUInteger maxDownloadOperationCount;

/**
 * @locale zh
 * @type api 
 * @brief 设置磁盘缓存剩余空间限制。单位为 bytes，默认值为 1024 * 1024 * 1024 * 1，表示 1 GB。如果剩余空间少于所设值，SDK 会报 `TTVideoEngineErrorNotEnoughDiskSpace` 错误。
 */
/**
 * @locale en
 * @brief Set the disk cache remaining space limit in bytes. The default value is 1024 * 1024 * 1024 * 1, which represents 1 GB. If the remaining space is less than the specified value, the SDK will raise a `TTVideoEngineErrorNotEnoughDiskSpace` error.
 */
@property (nonatomic, assign) int64_t limitFreeDiskSize;

/**
 * @locale zh
 * @type api
 * @brief 设置下载相关回调 [TTVideoEngineDownloaderDelegate](518261#TTVideoEngineDownloaderDelegate) 。
 */
/**
 * @locale en
 * @brief Set the download-related callback [TTVideoEngineDownloaderDelegate](ios-player-sdk-callbacks#TTVideoEngineDownloaderDelegate).
 */
@property (nonatomic, weak) id<TTVideoEngineDownloaderDelegate> delegate;

/**
 * @locale zh
 * @type api
 * @brief 创建 DirectUrl 播放源下载任务。
 * @return 返回 [TTVideoEngineDownloadURLTask](518146#TTVideoEngineDownloadURLTask)  实例。
 * @list 下载
 * @order 0
 * @param urls DirectUrl 播放源下载任务，支持主备 URL。
 * @param key DirectUrl 播放源下载任务唯一标识 cache key。
 * @param videoId 视频 ID，选填。
 */
/**
 * @locale en
 * @list 下载
 * @order 0
 * @brief Create a DirectUrl playback source download task.
 * @param urls DirectUrl playback source download task, supports primary and backup URLs.
 * @param key The unique cache key for the DirectUrl playback source download task.
 * @param videoId Video ID, optional.
 * @return Returns a [TTVideoEngineDownloadURLTask](ios-player-sdk-api-details#TTVideoEngineDownloadURLTask) instance.
 */
- (nullable TTVideoEngineDownloadURLTask *)urlTask:(NSArray *)urls key:(NSString *)key videoId:(nullable NSString *)videoId;

/**
 * @locale zh
 * @type api
 * @brief 创建 Vid 播放源下载任务。
 * @return 返回 [TTVideoEngineDownloadVidTask](518146#TTVideoEngineDownloadVidTask)  实例。
 * @list 下载
 * @order 1
 * @param videoId 视频 ID。
 * @param token 视频播放密钥。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @list 下载
 * @order 1
 * @brief Create a Vid playback source download task.
 * @param videoId Video ID.
 * @param token Video playback key.
 * @param resolution Video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @return Returns a [TTVideoEngineDownloadVidTask](ios-player-sdk-api-details#TTVideoEngineDownloadVidTask) instance.
 */
- (nullable TTVideoEngineDownloadVidTask *)vidTask:(NSString *)videoId
                                     playAuthToken:(NSString *)token
                                        resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @type api
 * @brief 创建 Vid 播放源下载任务。
 * @return 返回 [TTVideoEngineDownloadVidTask](518146#TTVideoEngineDownloadVidTask)  实例。
 * @param videoId 视频 ID。
 * @param token 视频播放密钥。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param codecType 编码类型，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。
 */
/**
 * @locale en
 * @brief Create a Vid playback source download task.
 * @param videoId Video ID.
 * @param token Video playback key.
 * @param resolution Video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType) for details.
 * @param codecType The encoding type is detailed in [TTVideoEngineEncodeType](ios-player-sdk-type-definitions#TTVideoEngineEncodeType).
 * @return Returns a [TTVideoEngineDownloadVidTask](ios-player-sdk-api-details#TTVideoEngineDownloadVidTask) instance.
 */
- (nullable TTVideoEngineDownloadVidTask *)vidTask:(NSString *)videoId
                                     playAuthToken:(NSString *)token
                                        resolution:(TTVideoEngineResolutionType)resolution
                                             codec:(TTVideoEngineEncodeType)codecType;

@end

/**
 * @locale zh
 * @type api
 * @brief 下载相关方法。
 * @pos 11
 */
/**
 * @locale en
 * @brief Methods related to downloading.
 * @pos 11
 * @type api
 */
@interface TTVideoEngineDownloadTask : NSObject

/**
 * @locale zh
 * @hidden
 * @type api
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * @locale zh
 * @hidden
 * @type api
 */
+ (instancetype)new  NS_UNAVAILABLE;

/**
 * @locale zh
 * @type api
 * @brief 设置下载任务描述。
 */
/**
 * @locale en
 * @type api
 * @brief The taskDescription property is available for the developer to provide a descriptive label for the task.
 * @hidden (iOS)
 */
@property (nullable, copy) NSString *taskDescription;

/**
 * @locale zh
 * @type api 
 * @brief 当前已下载字节数。
 */
/**
 * @locale en
 * @type api
 * @brief Current downloaded bytes.
 */
@property (readonly) int64_t countOfBytesReceived;

/**
 * @locale zh
 * @type api
 * @brief 视频总字节数。注意，播放 HLS 视频时，当前值可能不准。如果要获取下载进度，建议直接通过 `TTVideoEngineDownloadTask.progress` 属性获取。
 */
/**
 * @locale en
 * @type api
 * @brief Total bytes of the video. Note that this value may be inaccurate when playing HLS videos. For download progress, it is recommended to directly get it through the `TTVideoEngineDownloadTask.progress` property.
 */
@property (readonly) int64_t countOfBytesExpectedToReceive;

/**
 * @locale zh
 * @type api
 * @brief 当前下载进度。
 */
/**
 * @locale en
 * @type api
 * @brief Current download progress.
 */
@property (nonatomic, readonly) double progress;

/**
 * @locale zh
 * @type api
 * @brief 删除单个下载任务。
 * @notes 此方法可在子线程调用。
 * @list 下载
 * @order 9
 */
/**
 * @locale en
 * @type api
 * @list 下载
 * @order 9
 * @brief Delete a single download task.
 * @notes This method can be called in a child thread.
 */
- (void)invalidateAndCancel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 获取下载任务 ID。
 */
/**
 * @locale en
 * @type api
 * @brief Get the download task ID.
 * @hidden (iOS)
 */
- (NSString *)taskID;

/**
 * @locale zh
 * @type api
 * @brief 获取当前下载状态，详见 [TTVideoEngineDownloadState](803941#TTVideoEngineDownloadState) 。
 */
/**
 * @locale en
 * @type api
 * @brief The current state of the task within the session.
 */
@property (readonly) TTVideoEngineDownloadState state;

/**
 * @locale zh
 * @type api
 * @brief 下载错误信息，包含错误码和错误描述。
 */
/**
 * @locale en
 * @type api
 * @brief Download error information, including error codes and error descriptions.
 */
@property (nullable, readonly, copy) NSError *error;

/**
 * @locale zh
 * @type api
 * @brief 暂停单个下载任务。
 * @notes 此方法需在主线程调用。
 * @list 下载
 * @order 8
 */
/**
 * @locale en
 * @type api
 * @list 下载
 * @order 8
 * @brief Pause a single download task.
 * @notes This method needs to be called on the main thread.
 */
- (void)suspend;

/**
 * @locale zh
 * @type callback
 * @brief 开始或恢复单个下载任务。
 * @list 下载
 * @order 7
 */
/**
 * @locale en
 * @type api
 * @list 下载
 * @order 7
 * @brief Start or resume a single download task.
 */
- (void)resume;

/**
 * @locale zh
 * @type api
 * @brief 获取下载文件存储路径。
 */
/**
 * @locale en
 * @type api
 * @brief Available cache file path.
 */
@property (nullable, readonly, copy) NSString *availableLocalFilePath;

@end

/**
 * @locale zh
 * @type api
 * @brief DirectUrl 播放源下载任务。
 * @pos 12
 */
/**
 * @locale en
 * @type api
 * @brief DirectUrl play source download task.
 * @pos 12
 */
@interface TTVideoEngineDownloadURLTask : TTVideoEngineDownloadTask

/**
 * @locale zh
 * @hidden
 * @type api
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * @locale zh
 * @hidden
 * @type api
 */
+ (instancetype)new  NS_UNAVAILABLE;

/**
 * @locale zh
 * @type api
 * @brief URL 列表，支持主备 URL。
 * @hidden
 */
/**
 * @locale en
 * @type api
 * @brief List of URLs, supporting primary and secondary URLs.
 * @hidden (iOS)
 */
@property (nonatomic, copy, readonly) NSArray *urls;

/**
 * @locale zh
 * @type api
 * @brief 缓存 key，需和视频源一一对应。建议使用 URL 的 MD5 作为缓存 key。
 */
/**
 * @locale en
 * @type api
 * @brief The cache key should correspond to each video source. It is recommended to use the MD5 of the URL as the cache key.
 */
@property (nonatomic, copy, readonly) NSString *key;

/**
 * @locale zh
 * @type callback
 * @brief 更新 URL 列表。
 * @param urls
 */
/**
 * @locale en
 * @type api
 * @brief Update the URL list.
 */
- (void)updateUrls:(NSArray *)urls;

/**
 * @locale zh
 * @type api
 * @brief 视频 ID。视频的唯一标识，必须与视频源一一对应。
 */
/**
 * @locale en
 * @type api
 * @brief Video ID. The unique identifier for a video, which must correspond one-to-one with the video source.
 */
@property (nonatomic, copy, readonly, nullable) NSString *videoId;

@end

/**
 * @locale zh
 * @type api
 * @brief Video ID 视频源下载任务。
 * @pos 13
 */
/**
 * @locale en
 * @type api
 * @brief Video ID video source download task.
 * @pos 13
 */
@interface TTVideoEngineDownloadVidTask : TTVideoEngineDownloadTask

/**
 * @locale zh
 * @type api
 * @hidden
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * @locale zh
 * @type api
 * @hidden
 */
+ (instancetype)new  NS_UNAVAILABLE;

/**
 * @locale zh
 * @type api
 * @brief 视频 ID。
 * @hidden
 */
/**
 * @locale en
 * @type api
 * @brief Video ID.
 * @hidden (iOS)
 */
@property (nonatomic,   copy, readonly) NSString *videoId;

/**
 * @locale zh
 * @type api
 * @brief 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @type api
 * @brief Video resolution, see [TTVideoEngineResolutionType](ios-player-sdk-type-definitions#TTVideoEngineResolutionType).
 */
@property (nonatomic, assign, readonly) TTVideoEngineResolutionType resolution;

/**
 * @locale zh
 * @type api
 * @brief 编码类型，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。
 */
/**
 * @locale en
 * @type api
 * @brief Encoding type, see [TTVideoEngineEncodeType](ios-player-sdk-type-definitions#TTVideoEngineEncodeType) for details.
 */
@property (nonatomic, assign, readonly) TTVideoEngineEncodeType codecType;
/**
 * @locale zh
 * @type api
 * @brief 是否开启 H.265：<br>
 *        - YES: 开启。<br>
 *        - NO: 关闭。
 */
/**
 * @locale en
 * @type api
 * @brief h265 enable
 */
@property (nonatomic, assign, readonly) BOOL h265Enable;
/**
 * @locale zh
 * @type api
 * @brief 是否开启 DASH：<br>
 *        - YES: 开启。<br>
 *        - NO: 关闭。
 */
/**
 * @locale en
 * @type api
 * @brief Enable DASH:<br/>
 *        - YES: Enabled.
 *        - NO: Disabled.
 */
@property (nonatomic, assign, readonly) BOOL baseDashEnable;

/**
 * @locale zh
 * @type api
 * @brief 是否开启 HTTPS：<br>
 *        - YES: 开启。<br>
 *        - NO: 关闭。
 */
/**
 * @locale en
 * @type api
 * @brief Enable HTTPS:<br/>
 *        - YES: Enabled.
 *        - NO: Disabled.
 */
@property (nonatomic, assign, readonly) BOOL httpsEnable;

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief 是否开启 BOE 环境。<br>
 *        - YES: 开启。<br>
 *        - NO: 关闭。
 */
/**
 * @locale en
 * @type api
 * @brief boe enable
 * @hidden (iOS)
 */
@property (nonatomic, assign) BOOL boeEnable;

/**
 * @locale zh
 * @type api
 * @hidden
 * @brief Optional,filtering parameters
 */
/**
 * @locale en
 * @brief Optional filtering parameters
 * @hidden (iOS)
 */
@property (nonatomic, nullable, strong) NSDictionary *params;

/**
 * @locale zh
 * @type api
 * @brief 视频清晰度 map。
 */
/**
 * @locale en
 * @brief Map of video resolution.
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSNumber *> *resolutionMap;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief fetch data need.
 */
/**
 * @locale en
 * @brief fetch data needs.
 * @hidden (iOS)
 */
@property (nonatomic, strong, nullable) id<TTVideoEngineNetClient> netClient;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief api version
 */
/**
 * @locale en
 * @brief API version
 * @hidden (iOS)
 */
@property (nonatomic, assign) TTVideoEnginePlayAPIVersion apiVersion;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 返回用于获取 video 信息的 api 字符串。
 */
/**
 * @locale en
 * @brief Returns the API string for retrieving video information.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) TTVideoEngineReturnStringBlock apiStringCall;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief Return auth-string for fetch videoinfo.
 */
/**
 * @locale en
 * @brief Return the auth-string for fetching videoinfo.
 * @hidden (iOS)
 */
@property (nonatomic, copy, nullable) TTVideoEngineReturnStringBlock authCall;


/**
 * @locale zh
 * @type api
 * @brief 下载任务对应视频源清晰度。
 */
/**
 * @locale en
 * @brief The video quality corresponding to the download task.
 */
@property (nonatomic, assign, readonly) TTVideoEngineResolutionType currentResolution;

/**
 * @locale zh
 * @type api
 * @brief 下载任务的具体视频信息。
 */
/**
 * @locale en
 * @brief Details of the video information for the download task.
 */
@property (nonatomic, strong, nullable, readonly) TTVideoEngineModel *videoModel;

@end

/**
 * @locale zh
 * @type callback
 * @brief 下载相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief Download-related callbacks.
 */
@protocol TTVideoEngineDownloaderDelegate <NSObject>

/**
 * @locale zh
 * @type callback
 * @brief 下载任务结束回调。
 * @param downloader 下载任务管理器。
 * @param downloadTask 当前下载任务。
 * @param error 错误信息或结束原因：<br>
 *              * `error` 为 `nil` 表示下载成功。<br>
 *              * 否则下载任务失败，通过 `error` 查看错误信息。
 * @list 下载回调
 * @order 0
 */
/**
 * @locale en
 * @list 下载回调
 * @order 0
 * @type callback
 * @brief Callback for download task completion.
 * @param downloader Download the task manager.
 * @param downloadTask Current download task.
 * @param error Error message or reason for termination:<br/>
 *        * If `error` is `nil`, the download was successful.<br/>
 *        * Otherwise, the download task failed, and the error details can be checked via `error`.
 */
- (void)VideoEngineDownloader:(TTVideoEngineDownloader *)downloader
                 downloadTask:(TTVideoEngineDownloadTask *)downloadTask
         didCompleteWithError:(nullable NSError *)error;

/**
 * @locale zh
 * @type callback
 * @brief 下载任务进度回调。
 * @param downloader 下载任务管理器。
 * @param downloadTask 当前下载任务。
 * @param bytesWritten 在 `timeMS` 时间间隔内下载的字节数，可用于计算下载速度。
 * @param timeMS 时间间隔。
 * @notes 播放 HLS 视频时，`bytesWritten` 值可能不准。如果要获取下载进度，建议直接通过 `TTVideoEngineDownloadTask.progress` 属性获取。
 * @list 下载回调
 * @order 1
 */
/**
 * @locale en
 * @type callback
 * @list 下载回调
 * @order 1
 * @brief Callback for download task progress.
 * @param downloader Download task manager.
 * @param downloadTask Current download task.
 * @param bytesWritten The number of bytes downloaded within the `timeMS` interval, which can be used to calculate download speed.
 * @param timeMS Time Interval.
 * @notes When playing HLS videos, the value of `bytesWritten` may be inaccurate. To get the download progress, it is recommended to use the `TTVideoEngineDownloadTask.progress` property directly.
 */
- (void)VideoEngineDownloader:(TTVideoEngineDownloader *)downloader
                 downloadTask:(TTVideoEngineDownloadTask *)downloadTask
                    writeData:(int64_t)bytesWritten
                 timeInterval:(double)timeMS;

/**
 * @locale zh
 * @type callback
 * @brief 下载任务将要开始或恢复回调。
 * @param downloader 下载任务管理器。
 * @param downloadTask 当前下载任务。
 * @param fileOffset 开始或恢复位置。
 * @param expectedTotalBytes 总大小，单位为 byte。注意：播放 HLS 视频时，`expectedTotalBytes` 值可能不准。
 * @list 下载回调
 * @order 2
 */
/**
 * @locale en
 * @type callback
 * @list 下载回调
 * @order 2
 * @brief Callback for when a download task is about to start or resume.
 * @param downloader Download the task manager.
 * @param downloadTask Current download task.
 * @param expectedTotalBytes Total size, in bytes. Note: When playing HLS videos, the value of `expectedTotalBytes` may be inaccurate.
 * @param fileOffset Start or resume location.
 */
- (void)VideoEngineDownloader:(TTVideoEngineDownloader *)downloader
                 downloadTask:(TTVideoEngineDownloadTask *)downloadTask
            didResumeAtOffset:(int64_t)fileOffset
           expectedTotalBytes:(int64_t)expectedTotalBytes;

/**
 * @locale zh
 * @type callback
 * @brief 下载任务状态改变回调。
 * @list 下载回调
 * @order 3
 * @param downloader 下载任务管理器。
 * @param downloadTask 当前下载任务。
 * @param downloadState 当前下载状态，详见 [TTVideoEngineDownloadState](803941#TTVideoEngineDownloadState) 。
 */
/**
 * @locale en
 * @list 下载回调
 * @order 3
 * @type callback
 * @brief Callback for download task status change.
 * @param downloader Download the task manager.
 * @param downloadTask Current download task.
 * @param stateChanged current download state
 * @param downloadState Current download status, see [TTVideoEngineDownloadState](ios-player-sdk-type-definitions#TTVideoEngineDownloadState) for details.
 */
- (void)VideoEngineDownloader:(TTVideoEngineDownloader *)downloader
                 downloadTask:(TTVideoEngineDownloadTask *)downloadTask
                 stateChanged:(TTVideoEngineDownloadState)downloadState;

@end

NS_ASSUME_NONNULL_END

//
//  TTVideoEngineUrlSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/9/10.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"
#import "TTVideoEngine+SubTitle.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineMultiEncodingUrlSource;

/**
 * @locale zh
 * @type keytype
 * @brief DirectUrl 播放源。
 */
/**
 * @locale en
 * @type keytype
 * @brief DirectUrl source。
 */
@interface TTVideoEngineUrlSource : NSObject <TTVideoEngineMediaSource>

/**
 * @locale zh
 * @brief 视频 URL。支持备用 URL。
 */
/**
 * @locale en
 * @brief play urls, support backup url
 */
@property (nonatomic, strong) NSArray *urls;

/**
 * @locale zh
 * @hidden
 * @brief 视频 URL 过期时间
 */
/**
 * @locale en
 * @hidden
 * @brief URL expire timestamp string array for urls. (utc timestamp in second)
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *urlExpiredTimes;

/**
 * @locale zh
 * @brief 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *        - 不带特殊字符，能作为文件名。<br>
 *        - 能和视频资源文件一一对应。<br>
 *        - 建议使用 URL 的 MD5 值。
 */
/**
 * @locale en
 * @brief media data loader cache video unique identification key, recommended  you can use unique url md5 string
 */
@property (nonatomic, copy) NSString *cacheKey;

/**
 * @locale zh
 * @brief 视频编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。
 */
/**
 * @locale en
 * @brief encode type of this resource
 */
@property (nonatomic, assign) TTVideoEngineEncodeType encodeType;

/**
 * @locale zh
 * @brief 视频 ID。
 */
/**
 * @locale en
 * @brief video id
 */
@property (nonatomic, copy, nullable) NSString *vid;

/**
 * @locale zh
 * @brief 字幕Id。
 */
/**
 * @locale en
 * @brief subtitle id.
 */
@property (nonatomic, assign) NSInteger subtitleId;

/**
 * @locale zh
 * @brief 字幕源。
 */
/**
 * @locale en
 * @brief subtitle info
 */
@property (nonatomic, strong, nullable) TTVideoEngineSubDecInfoModel *subtitleInfoModel;

/**
 * @locale zh
 * @brief 是否为 HDR。
 */
/**
 * @locale en
 * @brief is hdr, defaut NO
 */
@property (nonatomic, assign) BOOL isHDRSource;

/**
 * @locale zh
 * @brief 开启播放过程中播放 URL 地址过期自动刷新功能。
 * @notes 开启该功能后，您需要实现 `TTVideoURLRefreshFetcher` 协议对象，并通过 `[TTVideoEngine urlRefreshFetcher]` 设置给 `TTVideoEngine` 播放器实例。
 */
/**
 * @locale en
 * @brief Enable 403 error self-refresh. The usage steps are as follows:
 * @notes After enabling the g feature, it is necessary to implement the TTVideoURLRefreshFetcher protocol object and set it to the TTVideoEngine player instance via `[TTVideoEngine urlRefreshFetcher]`.
 */
@property (nonatomic, assign) BOOL enableFallbackRefresh;

/**
 * @locale zh
 * @brief 视频封装格式，例如 mp4。
 */
/**
 * @locale en
 * @brief video format
 */
@property (nonatomic, copy) NSString *format;

/**
 * @locale zh
 * @brief 视频码率。
 */
/**
 * @locale en
 * @brief video bitrate
 */
@property (nonatomic, assign) NSInteger bitrate;

/**
 * @locale zh
 * @brief 自定义密钥。用于播放加密视频。
 */
/**
 * @locale en
 * @brief custom decryption key
 */
@property (nonatomic, strong, nullable) NSString *decryptionKey;

/**
 * @locale zh
 * @brief 文件路径。
 */
/**
 * @locale en
 * @brief custom defined cache file path.
 */
@property (nonatomic, copy, nullable) NSString *filePath;

/**
 * @locale zh
 * @hidden
 * @brief 设置编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
 */
/**
 * @locale en
 * @hidden
 * @brief codec strategy
 */
@property (nonatomic, assign) TTVideoEngineCodecStrategy codecStrategy;

/**
 * @locale zh
 * @hidden
 * @brief get cocde strategy url source
 */
/**
 * @locale en
 * @hidden
 * @brief get cocde strategy url source
 */
@property (nullable, nonatomic, strong, readonly) TTVideoEngineMultiEncodingUrlSource *multiEncodingUrlSource;

/**
 * @locale zh
 * @hidden
 * @brief 获取 hlsproxy url query
 */
/**
 * @locale en
 * @hidden
 * @brief get hlsproxy url query
 */
@property (nullable, nonatomic, copy, readonly) NSString *hlsproxyQuery;

/**
 * @locale zh
 * @type api
 * @hidden
 */
/**
 * @locale en
 * @hidden (iOS)
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
/**
 * @locale zh
 * @type api
 * @hidden
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


/**
 * @locale zh
 * @brief 初始化 DirectUrl 播放源。
 * @param url 视频 URL。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @return DirectUrl 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param url url
 * @param cacheKey cache key
 * @return TTVideoEngineUrlSource instance
 */
- (instancetype)initWithUrl:(NSString *)url
                   cacheKey:(NSString *)cacheKey;

/**
 * @locale zh
 * @hidden
 * @brief 初始化 DirectUrl 播放源。
 * @param url 视频 URL。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @param vid 视频 ID。
 * @return DirectUrl 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param url url
 * @param cacheKey cache key
 * @param vid Video ID.
 * @hidden (iOS)
 * @return TTVideoEngineUrlSource instance
 */
- (instancetype)initWithUrl:(NSString *)url
                   cacheKey:(NSString *)cacheKey
                    videoId:(NSString * _Nullable)vid;

/**
 * @locale zh
 * @brief 初始化 DirectUrl 播放源。
 * @param urls 视频 URL 列表。支持备用 URL。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @return DirectUrl 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param urls urls
 * @param cacheKey cache key
 * @return TTVideoEngineUrlSource instance
 */
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey;

/**
 * @locale zh
 * @hidden
 * @brief 初始化 DirectUrl 播放源。
 * @param urls 视频 URL 列表。支持备用 URL。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @param vid 视频 ID。
 * @return DirectUrl 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param urls urls
 * @param cacheKey cache key
 * @param vid video id
 * @hidden (iOS)
 * @return TTVideoEngineUrlSource instance
 */
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey
                     videoId:(NSString * _Nullable)vid;

/**
 * @locale zh
 * @brief 初始化 DirectUrl 播放源。
 * @return DirectUrl 播放源实例。
 * @param urls 视频 URL 列表。支持备用 URL。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @param vid
 * @param encodeType 视频编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。
 * @param decryptionKey 自定义密钥。用于播放加密视频。
 * @param filePath 视频存储路径，可与 `cacheKey` 二选一。
 * @param isHDRSource 是否为 HDR。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param urls urls
 * @param cacheKey cache key
 * @param vid video id
 * @param encodeType encode type
 * @param decryptionKey decryption key
 * @param filePath cache file path
 * @param isHDRSource is hdr source
 * @return TTVideoEngineUrlSource instance
 */
- (instancetype)initWithUrls:(NSArray *)urls
                    cacheKey:(NSString *)cacheKey
                     videoId:(NSString * _Nullable)vid
                  encodeType:(TTVideoEngineEncodeType)encodeType
               decryptionKey:(NSString * _Nullable)decryptionKey
                    filePath:(NSString * _Nullable)filePath
                 isHDRSource:(BOOL)isHDRSource;

/**
 * @locale zh
 * @brief 添加 DirectUrl 播放源。
 * @param urls 视频 URL 列表。支持备用 URL。
 * @param encodeType 视频编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。
 * @param cacheKey 缓存 key。这是 URL 对应的唯一标识，需遵循以下规则：<br>
 *                 - 不带特殊字符，能作为文件名。<br>
 *                 - 能和视频资源文件一一对应。<br>
 *                 - 建议使用 URL 的 MD5 值。
 * @param decryptionKey 自定义密钥。用于播放加密视频。
 * @param filePath 视频存储路径，可与 `cacheKey` 二选一。
 * @param isHDRSource 是否为 HDR 源。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param add urls urls
 * @param cacheKey cache key
 * @param encodeType encode type
 * @param decryptionKey decryption key
 * @param filePath cache file path
 * @param isHDRSource is hdr source
 * @param urls List of video URLs. Backup URLs are supported.
 * @return TTVideoEngineUrlSource instance
 */
- (void)addUrls:(NSArray *)urls
       cacheKey:(NSString *)cacheKey
     encodeType:(TTVideoEngineEncodeType)encodeType
  decryptionKey:(NSString * _Nullable)decryptionKey
       filePath:(NSString * _Nullable)filePath
    isHDRSource:(BOOL)isHDRSource;

@end


@class TTVideoEngineHLSProxyParam;
/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief HLS 私有方案
 */
/**
 * @locale en
 * @type keytype
 * @brief HLS Private Solution
 * @hidden 
 */
@interface TTVideoEngineUrlSource (Private)

/**
 * @locale zh
 * @hidden
 * @brief 设置 hls proxy 的参数
 */
/**
 * @locale en
 * @brief Parameters for setting hls proxy
 * @type api
 */
- (void)setHlsProxyParam:(TTVideoEngineHLSProxyParam *)hlsProxyParam;

@end

NS_ASSUME_NONNULL_END

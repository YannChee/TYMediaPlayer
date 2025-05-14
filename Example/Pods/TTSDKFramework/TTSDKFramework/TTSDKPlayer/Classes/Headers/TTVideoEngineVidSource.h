//
//  TTVideoEngineVidSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/18.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief Vid 播放源。
 */
/**
 * @locale en
 * @type keytype
 * @brief Vid play source
 */
@interface TTVideoEngineVidSource : NSObject <TTVideoEngineMediaSource>

/**
 * @locale zh
 * @brief （必需）设置视频 ID。
 */
/**
 * @locale en
 * @brief video id
 */
@property (nonatomic, copy) NSString *vid;

/**
 * @locale zh
 * @brief（必需）设置用于鉴权的 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 */
/**
 * @locale en
 * @brief play auth token
 */
@property (nonatomic, copy) NSString *playAuthToken;

/**
 * @locale zh
 * @brief fairplay drm auth token，仅支持 Byteplus
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief fairplay drm auth token, only support byteplus
 */
@property (nonatomic, copy) NSString *fpsLicenseAuthToken;

/**
 * @locale zh
 * @brief fairplay 证书数据，仅支持 Byteplus
 * @hidden (iOS)
 */
/**
 * @locale en
 * @hidden (iOS)
 * @brief airplay.cer file data, only support byteplus
 */
@property (nonatomic, copy) NSData *fpsCertData;

/**
 * @locale zh
 * @brief 设置视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 */
/**
 * @locale en
 * @brief resolution type
 */
@property (nonatomic, assign) TTVideoEngineResolutionType resolution;

/**
 * @locale zh
 * @brief 设置视频编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。默认为 H.264。
 */
/**
 * @locale en
 * @brief video encode type, default h264
 */
@property (nonatomic, assign) TTVideoEngineEncodeType encodeType;

/**
 * @locale zh
 * @brief 设置是否为 DASH。默认为 `NO`。
 */
/**
 * @locale en
 * @brief is dash source, default NO
 */
@property (nonatomic, assign) BOOL isDash;

/**
 * @locale zh
 * @brief 设置是否为 HLS。默认为 `NO`。
 */
/**
 * @locale en
 * @brief is hls Source, default NO
 */
@property (nonatomic, assign) BOOL isHLS;

/**
 * @locale zh
 * @hidden
 * @brief 设置视频编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
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
 */
/**
 * @locale en
 * @hidden
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 * @locale zh
 * @brief 初始化 Vid 播放源。
 * @return Vid 播放源实例。
 * @param vid 视频 ID。
 * @param playAuthToken （必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @return Vid 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer,
 * @param vid video id.
 * @param playAuthToken play auth token
 * @param resolution video resolution
 * @return TTVideoEngineVidSource instance
 */
- (instancetype)initWithVid:(NSString *)vid
              playAuthToken:(NSString *)playAuthToken
                 resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @brief 初始化 Vid 播放源。
 * @param vid 视频 ID。
 * @param playAuthToken （必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param fpsLicenseAuthToken fairplay drm license token
 * @param fpsCertData fairplay cer file data
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @hidden (iOS)
 * @return Vid 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer, only support byteplus
 * @param vid video id.
 * @param playAuthToken play auth token
 * @param fpsLicenseAuthToken fairplay drm license token
 * @param fpsCertData fairplay cer file data
 * @param resolution video resolution
 * @hidden (iOS)
 * @return TTVideoEngineVidSource instance
 */
- (instancetype)initWithVid:(NSString *)vid
              playAuthToken:(NSString *)playAuthToken
        fpsLicenseAuthToken:(NSString *)fpsLicenseAuthToken
                fpsCertData:(NSData *)fpsCertData
                 resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @brief 初始化 Vid 播放源。
 * @param vid 视频 ID。
 * @param playAuthToken （必需）视频 playAuthToken。这是由应用服务端签算并下发给客户端的，详见[客户端播放](https://www.volcengine.com/docs/4/67350)。
 * @param resolution 视频分辨率，详见 [TTVideoEngineResolutionType](803941#TTVideoEngineResolutionType) 。
 * @param encodeType 视频编码格式，详见 [TTVideoEngineEncodeType](803941#TTVideoEngineEncodeType) 。默认为 H.264。
 * @param isDash 是否为 DASH。默认为 `NO`。
 * @param isHLS 是否为 HLS。默认为 `NO`。
 * @return Vid 播放源实例。
 */
/**
 * @locale en
 * @brief Designated initializer,
 * @param vid video id.
 * @param playAuthToken play auth token
 * @param resolution video resolution
 * @param encodeType The encode type of current asset, make sure it is correct.
 * @param isDash is volc dash format video
 * @param isHLS is hls format video
 * @return TTVideoEngineVidSource instance
 */
- (instancetype)initWithVid:(NSString *)vid
              playAuthToken:(NSString *)playAuthToken
                 resolution:(TTVideoEngineResolutionType)resolution
                 encodeType:(TTVideoEngineEncodeType)encodeType
                     isDash:(BOOL)isDash
                      isHLS:(BOOL)isHLS;

@end

NS_ASSUME_NONNULL_END

//
//  TTVideoEngineMediaSource.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2021/11/18.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineModelDef.h"
#import "TTVideoEnginePlayerDefine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @brief 播放源类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Type of playback source.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineSourceType) {
    /**
     * @locale zh
     * @brief 使用 Vid 播放源。
     */
   /**
    * @locale en
    * @brief Use Vid playback source.
    */
    TTVideoEngineSourceTypeVideoId   = 0,
    /**
     * @locale zh
     * @brief 使用 DirectUrl 播放源。
     */
   /**
    * @locale en
    * @brief Use DirectUrl as the playback source.
    */
    TTVideoEngineSourceTypeDirectUrl = 1,
    /**
     * @locale zh
     * @brief 使用 VideoModel 播放源，需要按照 VideoModel 的格式组装播放源数据。
     */
   /**
    * @locale en
    * @brief To use VideoModel to play sources, assemble the source data according to the VideoModel format.
    */
    TTVideoEngineSourceTypeVideoModel = 2,
};

/**
 * @locale zh
 * @type keytype
 * @brief 定义播放源的接口。
 */
/**
 * @locale en
 * @type keytype
 * @brief Interface for defining playback sources.
 */
@protocol TTVideoEngineMediaSource <NSObject>

/**
 * @locale zh
 * @brief 当前播放源的唯一标识。 <br>
 *        - `TTVideoEngineSourceTypeVideoId` 类型和 `TTVideoEngineSourceTypeVideoModel` 类型的播放源使用 `vid` 作为唯一标识。 <br>
 *        - `TTVideoEngineSourceTypeDirectUrl` 类型的播放源使用 `cacheKey` 作为唯一标识。
 */
/**
 * @locale en
 * @brief The unique identifier of the current playback source.<br>
 *        - Playback sources of type `TTVideoEngineSourceTypeVideoId` and `TTVideoEngineSourceTypeVideoModel` use `vid` as the unique identifier.<br>
 *        - Playback sources of type `TTVideoEngineSourceTypeDirectUrl` use `cacheKey` as the unique identifier.
 */
@property (nonatomic, readonly, strong, getter=getUniqueId) NSString *uniqueId;

/**
 * @locale zh
 * @brief 设置播放源类型，详见 [TTVideoEngineSourceType](803941#TTVideoEngineSourceType) 。
 */
/**
 * @locale en
 * @brief Set the playback source type. For more details, see [TTVideoEngineSourceType](ios-player-sdk-type-definitions#TTVideoEngineSourceType).
 */
@property (nonatomic, assign) TTVideoEngineSourceType sourceType;

/**
 * @locale zh
 * @hidden
 * @brief 设置编解码策略，详见 [TTVideoEngineCodecStrategy](803941#TTVideoEngineCodecStrategy) 。
 */
/**
 * @locale en
 * @brief Set the codec strategy. For details, see [TTVideoEngineCodecStrategy](ios-player-sdk-type-definitions#TTVideoEngineCodecStrategy).
 * @hidden (iOS)
 */
@property (nonatomic, assign) TTVideoEngineCodecStrategy codecStrategy;

/**
 * @locale zh
 * @brief 开启播放过程中播放 URL 地址过期自动刷新功能。
 * @notes 开启该功能后，您需要实现 `TTVideoURLRefreshFetcher` 协议对象，并通过 `[TTVideoEngine urlRefreshFetcher]` 设置给 `TTVideoEngine` 播放器实例。
 */
/**
 * @locale en
 * @brief Enable the automatic refresh feature for expired URLs during playback.
 * @notes After enabling this feature, it is necessary to implement the `TTVideoURLRefreshFetcher` protocol object and set it to the `TTVideoEngine` player instance via `[TTVideoEngine urlRefreshFetcher]`.
 */
@property (nonatomic, assign) BOOL enableFallbackRefresh;

@end

NS_ASSUME_NONNULL_END

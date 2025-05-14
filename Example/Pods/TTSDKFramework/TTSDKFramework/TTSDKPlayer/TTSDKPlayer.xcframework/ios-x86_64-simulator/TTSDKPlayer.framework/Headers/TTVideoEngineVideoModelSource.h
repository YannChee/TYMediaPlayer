//
//  TTVideoEngineVideoModelSource.h
//  TTVideoEngine
//
//  Created by sjc on 6.2.23.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineMediaSource.h"
#import "TTVideoEngineModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type keytype
 * @hidden
 * @brief VideoModel 播放源。
 */
/**
 * @locale en
 * @type keytype
 * @hidden
 * @brief VideoModel play source。
 */
@interface TTVideoEngineVideoModelSource : NSObject <TTVideoEngineMediaSource>

/**
 * @locale zh
 * @brief 视频id。
 */
/**
 * @locale en
 * @brief video id。
 */
@property (nonatomic, copy) NSString *vid;

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
 * @brief 设置组装完成的 videoModel
 */
/**
 * @locale en
 * @brief video model
 */
@property (nonatomic, strong) TTVideoEngineModel *videoModel;

/**
 * @locale zh
 * @brief 初始化 VideoModel 播放源。
 * @param vid 视频 Id。
 * @param resolution 视频分辨率。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param vid video id.
 * @param resolution resolution type.
 * @return TTVideoEngineVideoModelSource instance
 */
- (instancetype)initWithVid:(NSString *)vid
                 resolution:(TTVideoEngineResolutionType)resolution;

/**
 * @locale zh
 * @brief 初始化 VideoModel 播放源。
 * @param vid 视频 Id。
 * @param resolution 视频分辨率。
 * @param videoModel 视频 VideoModel 源。
 */
/**
 * @locale en
 * @brief Designated initializer.
 * @param vid video id.
 * @param resolution resolution type.
 * @param videoModel video model play source.
 * @return TTVideoEngineVideoModelSource instance
 */
- (instancetype)initWithVid:(NSString *)vid
                 resolution:(TTVideoEngineResolutionType)resolution
                 videoModel:(TTVideoEngineModel *)videoModel;

@end

NS_ASSUME_NONNULL_END

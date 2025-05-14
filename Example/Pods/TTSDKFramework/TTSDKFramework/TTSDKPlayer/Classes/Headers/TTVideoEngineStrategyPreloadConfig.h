//
//  TTVideoEngineStrategyPreloadConfig.h
//  TTSDK
//
//  Created by zyw on 2024/5/14.
//

#import <Foundation/Foundation.h>

/**
 * @locale zh
 * @type keytype
 * @brief 自定义预加载策略配置。
 */
/**
 * @locale en
 * @type keytype
 * @brief Custom Preloading Strategy Configuration.
 */
@interface TTVideoEngineStrategyPreloadConfig : NSObject

/**
 * @locale zh
 * @brief 设置预加载视频个数。
 * @notes 建议设置 3 - 5 个，SDK 内部限制最多 10 个，设置过多可能会带来成本浪费。
 */
/**
 * @locale en
 * @brief Set the number of preloaded videos.
 * @notes It is recommended to set 3-5 items. The SDK imposes an internal limit of a maximum of 10. Setting too many may lead to unnecessary costs.
 */
@property (nonatomic, assign) NSInteger count;
/**
 * @locale zh
 * @brief 设置预加载视频大小，单位为（KB）。
 * @notes 短视频场景建议设置 500 - 800K。您可根据视频时长调整，确保可以加载出视频首帧。
 */
/**
 * @locale en
 * @brief Set the preload video size in KiloByte.
 * @notes For short video scenarios, it is recommended to set the size between 500 - 800K. Adjust the size according to the video length to ensure the first frame loads properly.
 */
@property (nonatomic, assign) NSInteger size;
/**
 * @locale zh
 * @brief 设置预加载任务开始时机。
 * @notes 播放器缓冲 buffer 大于设置时长才会开始预加载。建议设置 15 秒以上。
 */
/**
 * @locale en
 * @brief Set the preloading task start time.
 * @notes The player will start preloading only when the buffer size exceeds the set duration. It is recommended to set it to at least 15 seconds.
 */
@property (nonatomic, assign) NSInteger startBufferLimit;
/**
 * @locale zh
 * @brief 设置预加载任务停止时机。
 * @notes 播放器缓冲 buffer 小于设置时长才会停止预加载，并取消当前的预加载任务。建议设置 5 秒左右。
 */
/**
 * @locale en
 * @brief Set the timing for stopping preloading tasks.
 * @notes Preloading will only stop when the player buffer is less than the set duration, and the current preloading task will be canceled. It is recommended to set this duration to around 5 seconds.
 */
@property (nonatomic, assign) NSInteger stopBufferLimit;


/**
 * @locale zh
 * @hidden
 * @brief 字符串描述
 * @return 返回字符串描述
 */
/**
 * @locale en
 * @brief String Description
 * @type api
 * @hidden (iOS)
 */
- (NSString * _Nullable)toStringDescriptor;

@end

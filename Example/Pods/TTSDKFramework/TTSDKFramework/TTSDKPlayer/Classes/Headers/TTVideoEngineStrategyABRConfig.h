//
//  TTVideoEngineStrategyABRConfig.h
//  TTSDK
//
//  Created by zyw on 2024/10/23.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineModelDef.h"

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief ABR 相关配置对象，可对 TTVideoEngine 实例进行配置
 */
@interface TTVideoEngineStrategyABRConfig : NSObject

/**
 * @locale zh
 * @brief wifi 网络下允许切换最高档位
 */
@property (nonatomic, assign) TTVideoEngineResolutionType wifiMaxResolution;
/**
 * @locale zh
 * @brief 移动网络下允许切换最高档位
 */
@property (nonatomic, assign) TTVideoEngineResolutionType mobileMaxResolution;

/**
 * @locale zh
 * @type api
 * @brief 静态初始化方法
 * @param wifiMaxResolution wifi 网络下允许切换最高档位
 * @param mobileMaxResolution 移动网络下允许切换最高档位
 * @return 返回 TTVideoEngineStrategyABRConfig 实例
 */
+ (TTVideoEngineStrategyABRConfig * _Nonnull)abrConfigWithWifiMaxResolution:(TTVideoEngineResolutionType)wifiMaxResolution
                                                        mobileMaxResolution:(TTVideoEngineResolutionType)mobileMaxResolution;

@end

#define Global_ABRAlgo_Config [TTVideoEngineStrategyABRAlgoConfig shareInstance]

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief ABR 算法相关全局配置对象
 */
@interface TTVideoEngineStrategyABRAlgoConfig : NSObject
/**
 * @locale zh
 * @brief 无测速信息时，默认清晰度
 * @notes  一般为冷启动第一个起播视频使用默认清晰度，默认 TTVideoEngineResolutionTypeFullHD
 */
@property (nonatomic, assign) TTVideoEngineResolutionType defaultResolution;
/**
 * @locale zh
 * @brief 探测时间间隔（单位毫秒，默认值：1000ms）
 */
@property (nonatomic, assign) NSTimeInterval probeIntervalMS;
/**
 * @locale zh
 * @brief 算法参数（默认配置可以通过 [Global_ABRAlgo_Config getSDKDefaultAbrAlgoParams] 获取）
 */
@property (nonatomic, strong, nonnull, readonly, getter=globalAbrAlgoParams) NSDictionary *globalAbrAlgoParams;

/**
 * @locale zh
 * @type api
 * @brief 获取单例方法
 * @return 返回 TTVideoEngineStrategyABRAlgoConfig 单例
 */
+ (TTVideoEngineStrategyABRAlgoConfig * _Nonnull)shareInstance;

/**
 * @locale zh
 * @type api
 * @brief 获取默认算法配置参数
 * @return 返回默认算法配置参数
 * @notes
 * {
     "limit_switch_count" : 20,                                 // 最大切换次数
     "limit_up_switch_count" : 10,                           // 最大上切次数
     "limit_down_switch_count" : 10),                     // 最大下切次数
     "limit_enable_video_duration" : 240000,          // 视频切档时长限制，单位 ms
     "limit_enable_start_position" : 10000,               // 限制开始切档 position，单位 ms
     "limit_enable_end_position" : 10000,                // 限制播放切档 position，单位 ms
     "bandwidth_factor" : 0.8,                                  // 低于hurry水位时选档的网速系数
     "segment_duration" : 5000,                              // 默认分片时长，单位 ms，认为所有分片时长相等，HLS 视频播放 SDK 内部会自动获取 TS 分片时长
     "base_abr":
       {
         @"hurry_factor" : 0.3,                                // hurry水位的最小系数
         @"low_factor"   : 0.5,                                 // low水位的最小系数
         @"high_factor"  : 0.8,                                 // high水位的最小系数
         @"hurry_min_buffer_increase_rate" : 0.5,  // 低于hurry水位时，能够下切的最低buffer增长速率
         @"hurry_force_downgrade" : 0,                 // 低于hurry水位时，是否不考虑网速强制降档，建议设置为 0
        }
    }
 */
- (NSDictionary * _Nonnull)getSDKDefaultAbrAlgoParams;

/**
 * @locale zh
 * @type api
 * @brief 设置业务自定义算法配置参数
 */
- (void)setCustomAbrAlgoorithmParam:(NSDictionary * _Nonnull)param;

@end

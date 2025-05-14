//
//  TTVideoEngine+Tracker.h
//  TTVideoEngine
//
//  Created by 黄清 on 2018/12/10.
//

#import "TTVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef __TTVIDEOENGINE_TRACKER__
#define __TTVIDEOENGINE_TRACKER__
#if  __has_include("BDTrackerSDK.h")
#define TTVIDEOENGINE_ENABLE_TRACKER 1
#else
#define TTVIDEOENGINE_ENABLE_TRACKER 0
#endif
#endif

/**
 * @locale zh
 * @hidden
 */
/**
 * @locale en
 * @hidden
 */
typedef void(^TTVideoEngineDeviceInfo)(NSString *_Nullable deviceID, NSString *_Nullable installID, NSString *_Nullable ssID);

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
 * @type api
 * @brief 是否上报日志，默认开启。
 * @notes 强烈建议业务不要关闭。
 */
/**
 * @locale en
 * @hidden
 * @brief report log switch. default: YES
 * @type api
 */
@property (nonatomic, assign) BOOL reportLogEnable;

/**
 * @locale zh
 * @type api
 * @brief 设置视频的tag，推荐在[engine play]前设置
 * @param tag 例如可设置 short vdieo、long video
 * @hidden (iOS)
 */
/**
 * @locale en
 * @brief Set video tag, recommended to set before calling [engine play]
 * @type api
 * @param tag example: short vdieo、long video
 * @hidden (iOS)
 */
- (void)setTag:(NSString *)tag;

/**
 * @locale zh
 * @type api
 * @brief 获取播放生命周期播放器唯一标识。
 * @return 播放器生命周期唯一标识。
 */
/**
 * @locale en
 * @brief Get once play session id
 * @type api
 * @return player session id
 */
- (NSString *)getPlayerSessionId;

/**
 * @locale zh
 * @type api
 * @brief 获取设备唯一标识。
 * @notes App 重新安装后，设备唯一标识会改变。
 * @return 设备唯一标识。
 */
/**
 * @locale en
 * @type api
 * @brief Gets the device unique ID.
 * @notes This ID will change if the app is reinstalled.
 * @return The device unique ID
 */
+ (NSString *)getEngineUniqueId;

@end

NS_ASSUME_NONNULL_END

//
//  TTSDKManager.h
//  TTSDK
//
//  Created by 陈昭杰 on 2020/2/4.
//  Copyright © 2020 ByteDance. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseDidAdd;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationIdKey;
FOUNDATION_EXTERN NSString * const TTLicenseNotificationLicenseResultKey;

NS_ASSUME_NONNULL_BEGIN

typedef void(^TTSDKLogger)(NSString * _Nullable log);

/**
 * @locale zh
 * @type keytype
 * @brief 定义 TTSDK Region
 */
typedef NS_ENUM(NSInteger, TTSDKServiceVendor) {
    /**
     * @locale zh
     * @brief 火山引擎- Default region
     */
    TTSDKServiceVendorCN = 0x010,
    /**
     * @locale zh
     * @brief Byteplus- Default region
     */
    TTSDKServiceVendorSG,
    /**
     * @locale zh
     * @brief 暂未开放
     */
    TTSDKServiceVendorVA,
    /**
     * @locale zh
     * @brief 火山引擎-海外 Region
     */
    TTSDKServiceVendorMYA,
};

/**
 * @locale zh
 * @type keytype
 * @brief 定义 TTSDK 业务模块
 */
typedef NS_ENUM (NSInteger, TTSDKServiceBizType) {
    /**
     * @locale zh
     * @brief 点播业务
     */
    TTSDKServiceBizType_Vod     = 1 << 0,
    /**
     * @locale zh
     * @brief 直播业务
     */
    TTSDKServiceBizType_Live    = 1 << 1,
    /**
     * @locale zh
     * @brief 上传业务
     */
    TTSDKServiceBizType_Upload  = 1 << 2,
    /**
     * @locale zh
     * @brief 图片业务
     */
    TTSDKServiceBizType_Image   = 1 << 3,
    /**
     * @locale zh
     * @brief 图片独立解码业务
     */
    TTSDKServiceBizType_Heif    = 1 << 5,
    
    /**
     * @locale zh
     * @brief All
     */
    TTSDKServiceBizType_All = (TTSDKServiceBizType_Vod |
                              TTSDKServiceBizType_Live |
                              TTSDKServiceBizType_Upload |
                              TTSDKServiceBizType_Image |
                              TTSDKServiceBizType_Heif),

    /**
     * @locale zh
     * @hidden
     * @brief 仅火山引擎内部使用，App 请勿设置。仅在二方库与TTSDK联合交付场景中使用
     */
    TTSDKServiceBizType_SecondParty = 1 << 4,
};

/**
 * @locale zh
 * @type keytype
 * @brief 定义日志输出级别
 */
typedef NS_ENUM(NSUInteger, TTSDKLogLevel) {
    /** {zh}
     * @brief 输出 VERBOSE、DEBUG、INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelVerbose,
    /** {zh}
     * @brief 输出 DEBUG、INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelDebug,
    /** {zh}
     * @brief 输出 INFO、WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelInfo,
    /** {zh}
     * @brief 输出 WARNING 和 ERROR 级别的日志
     */
    TTSDKLogLevelWarn,
    /** {zh}
     * @brief 输出 ERROR 级别的日志
     */
    TTSDKLogLevelError,
    /** {zh}
     * @brief 关闭日志打印
     */
    TTSDKLogLevelNone,
};

/**
 * @locale zh
 * @type keytype
 * @brief 点播业务配置对象
 */
@interface TTSDKVodConfiguration : NSObject

/**
 * @locale zh
 * @type keytype
 * @brief 设置点播缓存目录，默认 "NSCachesDirectory/com.video.cache"
 */
@property (nonatomic, copy, nullable) NSString *cachePath;

/**
 * @locale zh
 * @type keytype
 * @brief 设置点播缓存大小，默认 100M ( 100 * 1024 * 1024 )
 * @notes 建议设置 300M 以上
 */
@property (nonatomic, assign) NSInteger cacheMaxSize;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 日志相关配置对象
 */
@interface TTSDKLogConfiguration : NSObject

/**
 * @locale zh
 * @brief 是否开启日志功能，默认为NO。
 */
@property (nonatomic, assign) BOOL enable;

/**
 * @locale zh
 * @brief 设备ID，没有自定义的需求时，设置为nil即可。
 */
@property (nonatomic, copy) NSString *deviceID;

/**
 * @locale zh
 * @brief logPath, 日志写入路径. 如果为空，会使用默认的路径，默认路径为/Library/Volclog目录
 */
@property (nonatomic, copy) NSString *logPath;

/**
 * @locale zh
 * @brief maxLogSizeM, 日志文件最大值，单位M，默认值为100M
 */
@property (nonatomic, assign) NSUInteger maxLogSizeM;

/**
 * @locale zh
 * @brief singleLogSizeM, 单个日志文件大小（单位M），默认值为2M
 */
@property (nonatomic, assign) NSUInteger singleLogSizeM;

/**
 * @locale zh
 * @brief logExpireTime, 日志文件的过期时间（过期后下次创建文件时会删除之前的文件)，单位 s，默认值为7天
 */
@property (nonatomic, assign) NSUInteger logExpireTimeS;

/**
 * @locale zh
 * @brief enableConsole, 是否开启日志输出到console，默认值为YES
 */
@property (nonatomic, assign) BOOL enableConsole;

/**
 * @locale zh
 * @brief enableLogFile, 是否开启日志保存到文件，默认值为YES
 */
@property (nonatomic, assign) BOOL enableLogFile;

/**
 * @locale zh
 * @brief 允许写入的日志等级，默认为 TTSDKLogLevelDebug
 */
@property (nonatomic, assign) TTSDKLogLevel logLevel;
@end

/**
 * @locale zh
 * @type keytype
 * @brief 图片业务配置对象
 */
@interface TTSDKImagexConfiguration : NSObject
/**
 * @locale zh
 * @brief 是否需要在 TTSDK 中进行 httpdns 功能的初始化，默认是YES
 * @notes 须先接入 `TTNet`
 */
@property (nonatomic, assign) BOOL shouldInitHttpDns;

/**
 * @locale zh
 * @brief 是否需要在 TTSDK 中进行 quic 功能的初始化，默认是NO
 * @notes 须先接入 `TTNet`
 */
@property (nonatomic, assign) BOOL shouldInitQuic;

/**
 * @locale zh
 * @brief 唯一token
 */
@property (nonatomic, copy) NSString *token;

/**
 * @locale zh
 * @brief 本地授权码
 */
@property (nonatomic, copy) NSArray<NSString *> *authCodes;

/**
 * @locale zh
 * @brief 默认图片配置
 */
+ (instancetype)defaultImagexConfig;

@end

/**
 * @locale zh
 * @type keytype
 * @brief TTSDK配置对象
 */
@interface TTSDKConfiguration : NSObject

/**
 * @locale zh
 * @brief AppID，非空，必须设置
 */
@property (nonatomic, copy, nonnull, readonly) NSString *appID;

/**
 * @locale zh
 * @brief app 名称
 */
@property (nonatomic, copy) NSString *appName;

/**
 * @locale zh
 * @brief app 渠道名称, 默认 "App Store"
 */
@property (nonatomic, copy) NSString *channel;

/**
 * @locale zh
 * @brief 新版本已弃用，业务如果使用了该字段建议尽早处理下，直接删除赋值即可
 */
@property (nonatomic, assign) TTSDKServiceVendor serviceVendor DEPRECATED_MSG_ATTRIBUTE("deprecated");

/**
 * @locale zh
 * @brief 请勿擅自选择，需要与申请服务地区一致或者联系客服确认,  默认 TTSDKServiceVendorCN
 */
@property (nonatomic, assign) TTSDKServiceVendor appRegion;

/**
 * @locale zh
 * @brief 默认 TTSDKServiceBizType_All 支持所有模块，业务可以指定使用单独模块
 */
@property (nonatomic, assign) TTSDKServiceBizType bizType;

/**
 * @locale zh
 * @brief license文件路径
 */
@property (nonatomic, copy) NSString *licenseFilePath;

/**
 * @locale zh
 * @brief app version
 */
@property (nonatomic, copy) NSString *appVersion;

/**
 * @locale zh
 * @brief bundle identifier
 */
@property (nonatomic, copy) NSString *bundleID;

/**
 * @locale zh
 * @brief 是否需要初始化 `Rangers App Log` SDK，默认是YES
 * @notes 须先接入 `RangersAppLog`
 */
@property (nonatomic, assign) BOOL shouldInitAppLog;

/**
 * @locale zh
 * @brief 是否需要初始化 `TTNet` SDK，默认是YES
 * @notes 须先接入 `TTNet`
 */
@property (nonatomic, assign) BOOL shouldInitTTNet;

/**
 * @locale zh
 * @brief 是否需要拉取上传云控配置，默认是NO
 */
@property (nonatomic, assign) BOOL shouldUseCloudControl;

/**
 * @locale zh
 * @brief 用于视频点播初始化配置
 */
@property (nonatomic, strong) TTSDKVodConfiguration *vodConfiguration;

/**
 * @locale zh
 * @brief 用于Imagex初始化配置
 */
@property (nonatomic, strong) TTSDKImagexConfiguration *imagexConfiguration;

/**
 * @locale zh
 * @brief 初始化日志配置，不设置会使用默认值
 */
@property (nonatomic, strong) TTSDKLogConfiguration *logConfiguration;

/**
 * @locale zh
 * @type api
 * @brief 用指定appID获取默认配置
 * @param appID appID
 */
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID;

/**
 * @locale zh
 * @type api
 * @brief 用指定appID&licensePath获取默认配置
 * @param appID appID
 * @param licensePath license file path
 */
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID licensePath:(NSString *)licensePath;

/**
 * @locale zh
 * @type api
 * @brief 用指定appID&licensePath获取默认配置
 * @param appID appID
 * @param licenseName license name from volc ( E.g demo.lic )
 */
+ (instancetype)defaultConfigurationWithAppID:(NSString *)appID licenseName:(NSString *)licenseName;

@end

/**
 * @locale zh
 * @type api
 * @brief TTSDK管理对象
 */
@interface TTSDKManager : NSObject

/**
 * @locale zh
 * @brief TTSDK版本号
 */
@property (class, nonatomic, copy, nonnull, readonly) NSString *SDKVersionString;

/**
 * @locale zh
 * @type api
 * @brief 使用给定的配置启动TTSDK相关任务，启动app时调用
 * @param configuration TTSDK相关配置信息
 */
+ (void)startWithConfiguration:(TTSDKConfiguration *)configuration;

/**
 * @locale zh
 * @type api
 * @brief 设置当前UserUniqueID，UserUniqueID发生变化时使用
 * @param uniqueID 用户id，如无特殊需求，请勿传 空字符串 或者 全是空格的字符串
 */
+ (void)setCurrentUserUniqueID:(nullable NSString *)uniqueID;

/**
 * @locale zh
 * @type api
 * @brief 获取业务设置的 UserUniqueID
 * @return 返回 UserUniqueID
 */
+ (nullable NSString *)getCurrentUserUniqueID;

/**
 * @locale zh
 * @type api
 * @brief 获取业务设置的 UserUniqueID
 */
+ (void)clearUserUniqueID;

/**
 * @locale zh
 * @type api
 * @brief 获取ID对应的证书信息
 * @param licenseId 证书id
 * @return 证书信息
 */
+ (NSDictionary *)getCurrentLicenseInfo:(NSString *)licenseId;

/**
 * @locale zh
 * @type api
 * @brief 默认业务只有一个License调用 startWithConfiguration 会自动更新License，不需要调用该方法，当业务集成多个License，通过该方法更新License
 * @param configuration TTSDK相关配置信息
 */
+ (void)updateLicenseWithConfiguration:(TTSDKConfiguration *)configuration;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief TTSDK日志是否上报到RangersAppLog
 */
+ (void)setShouldReportToAppLog:(BOOL)shouldReport DEPRECATED_MSG_ATTRIBUTE("use [VeLiveCommon enableReportApplog:]");

/**
 * @locale zh
 * @hidden
 */
+ (void)setAppLogCustomData:(nullable NSDictionary *)data DEPRECATED_MSG_ATTRIBUTE("use [VeLiveCommon setAppLogCustomData:]");


/**
 * @locale zh
 * @api
 * @brief 获取device id
 * @notes 须先接入 `RangersAppLog`
 * @return 返回 device id
 */
+ (NSString *)getRangersDeviceID;

/**
 * @locale zh
 * @api
 * @brief 获取deviceid
 * @notes 须先接入 `RangersAppLog`
 * @return 返回 deviceid
 */
+ (NSString *)getRangersDeivceID DEPRECATED_MSG_ATTRIBUTE("use [TTSDKManager getRangersDeviceID]");

/// 仅当SDK初始化未配置启用AppLog（startWithConfiguration中，shouldInitAppLog为NO）时，该方法提供在启动后启用AppLog的能力
/// @param configuration TTSDK相关配置信息
+ (void)startRangersAppLogWithConfiguration:(TTSDKConfiguration *)configuration;
@end

NS_ASSUME_NONNULL_END

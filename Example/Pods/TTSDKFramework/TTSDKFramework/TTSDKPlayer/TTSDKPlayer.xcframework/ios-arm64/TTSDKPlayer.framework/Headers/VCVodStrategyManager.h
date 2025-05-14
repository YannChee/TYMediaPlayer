//
//  VCVodStrategyManager.h
//  VCPreloadStrategy
//
//  Created by 黄清 on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import "VCStrategyMedia.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, VCVodStrategyAlgoConfigType) {
    VCVodStrategyAlgoConfigCommon = 31001,       /// VCKeyConfigAlgoCommon
    VCVodStrategyAlgoConfigSmartPreload = 31002, /// VCKeyConfigAlgoSmartPreload
    VCVodStrategyAlgoConfigPreloadTimeliness = 31003, /// VCKeyConfigAlgoPreloadTimeliness
    VCVodStrategyAlgoConfigPlayLoad = 31004,  /// VCKeyConfigAlgoPlayLoad
    VCVodStrategyAlgoConfigPlayRange = 31005, /// VCKeyConfigAlgoPlayRange
    VCVodStrategyAlgoConfigSelectBirate = 31006,
    VCVodStrategyAlgoConfigBandwidth = 31007,
    VCVodStrategyAlgoConfigModuleCenter = 31008,
    VCVodStrategyAlgoConfigSmartRangeRequest = 31009,
    VCVodStrategyAlgoConfigPreload = 31010,
    VCVodStrategyAlgoConfigDynamic = 31011,
    VCVodStrategyAlgoConfigOption = 31012,
    VCVodStrategyAlgoConfigDynamicTimeInfo = 31013,
    VCVodStrategyAlgoConfigDynamicPreload = 31014,
    VCVodStrategyAlgoConfigDynamicPlayLoad = 31015,
    VCVodStrategyAlgoConfigDynamicPlayRange = 31016,
    VCVodStrategyAlgoConfigDynamicSelectBitrate = 31017,
    VCVodStrategyAlgoConfigPlayBuffer = 31018,
    VCVodStrategyAlgoConfigDynamicPlayBuffer = 31019,
    VCVodStrategyAlgoConfigPreloadBackground = 31020,
    VCVodStrategyAlgoConfigSmartServicePackageUrl = 31021,
    VCVodStrategyAlgoConfigIODemandConfig = 31022,
    VCVodStrategyAlgoConfigDownloadIo = 31023,
    VCVodStrategyAlgoConfigDynamicDownloadIo = 31024,
    VCVodStrategyAlgoConfigDasp = 31026,
};

typedef NS_ENUM(NSInteger, VCVodStrategyPlayerOption) {
    VCVodStrategyPlayerOptionRangeControl = 108,     /// VCKeyPlayerPlayRange
};

typedef NS_ENUM(NSInteger, VCVodStrategyEventType) {
    VCVodStrategyEventAppState = 1001,           /// VCKeyBusinessAppState
    VCVodStrategyBandwidthQueueSize = 1002,
    VCVodStrategyEventPortraitChanged = 1003,
    VCVodStrategyEventLiveMediaOperate = 1014,
    VCVodStrategyEventSmartPreloadLabel = 31201, /// VCKeyPreloadSmartRetUpdate
    VCVodStrategyEventPreloadTimeliness =
        31202, /// VCKeyPreloadTimelinessRetUpdate
    VCVodStrategyEventAppTraceHostUpdate = 31207,
    VCVodStrategyEventEngineNetScore = 31213,
    VCVodStrategyEventVodSettingsPortrait = 31214,
    VCVodStrategyEventAppPauseAllPreload = 31215,
    VCVodStrategyEventAppResumeAllPreload = 31216,
    VCVodStrategyEventAppPauseScenePreload = 31217,
    VCVodStrategyEventAppResumeScenePreload = 31218,
    VCVodStrategyEventAppRefreshMediaList = 31219,
    VCVodStrategyEventAppMediaListLoadMore = 31220,
    VCVodStrategyEventAppMediaListUpdate = 31221,
    VCVodStrategyEventAppSolariaPortrait = 31222,
    VCVodStrategyEventDeviceDynamicScore = 31223,
    VCVodStrategyEventBizAdModelValue = 31228,
};

typedef NS_ENUM(NSInteger, VCVodStrategyEvent) {
    VCVodStrategyEventPlayTaskOperate = 2000,
    VCVodStrategyEventPreloadSwitch = 2001,
    VCVodStrategyEventReBufferDurationInitial = 2002,
    VCVodStrategyEventStartupDuration = 2003,
    VCVodStrategyEventPreloadPersonalizedOption = 2004,
    VCVodStrategyEventWatchDurationLabel = 2005,
    VCVodStrategyEventStallLabel = 2006,
    VCVodStrategyEventFirstFrameLabel = 2007,
    VCVodStrategyEventAdaptiveRangeEnabled = 2008,
    VCVodStrategyEventAdaptiveRangeBuffer = 2009,
    VCVodStrategyEventRemainingBufferDurationAtStop = 2010,
    VCVodStrategyEventPlayBufferDiffResult = 2011,
    VCVodStrategyEventPlayRelatedPreloadFinished = 2012,
    VCVodStrategyEventPlayerRangeDetermined = 2013,
    VCVodStrategyEventModuleActivated = 2014,
    VCVodStrategyEventPreloadDecisionInfo = 2015,
    VCVodStrategyEventLoadControlVersion = 2016,
    VCVodStrategyEventLoadControlSlidingWindow = 2017,
    VCVodStrategyEventSceneSwitch = 2018,
    VCVodStrategyEventSerializedData = 2019,
    VCVodStrategyEventNetworkStallList = 2020,
    VCVodStrategyEventDecisionInfo = 2021,
};

typedef NS_ENUM(NSInteger, VCVodStrategyPlayTaskOperateValue) {
    VCVodStrategyPlayTaskOperatePause = 1,
    VCVodStrategyPlayTaskOperateResume = 2,
    VCVodStrategyPlayTaskOperateStop = 3,
    VCVodStrategyPlayTaskOperateRange = 4,
    VCVodStrategyPlayTaskOperateRangeDuration = 5,
    VCVodStrategyPlayTaskOperateTargetBuffer = 6,
    VCVodStrategyPlayTaskOperateSafeFactor = 7,

    VCVodStrategyPlayTaskOperateSeekLabel = 100,
    VCVodStrategyPlayTaskOperateFirstBlockDecisionTime = 101,
    VCVodStrategyPlayTaskOperateFirstBlockExecTime = 102,
    VCVodStrategyPlayTaskEstPlayTime = 103,
    VCVodStrategyPlayTaskOperateSmartLevelUsed = 104,
    
};

typedef NS_ENUM(NSInteger, VCVodStrategyAppState) {
    VCVodStrategyAppStateForeground = 1, /// foreground
    VCVodStrategyAppStateBackground = 2, /// background
};

typedef NS_ENUM(NSInteger, VCVodStrategySelectType) {
    VCVodStrategySelectTypePreload = 1,
    VCVodStrategySelectTypePlay = 2,
    VCVodStrategySelectTypeABR = 100,
};

typedef NS_ENUM(NSInteger, VCVodStrategyNetState) {
    VCVodStrategyNetStateUnKnown = -1,
    VCVodStrategyNetStateUnReachable = 0,
    VCVodStrategyNetStateWWAN = 10,
    VCVodStrategyNetStateWifi = 20,
};

typedef NS_ENUM(NSInteger, VCVodStrategySetKeyValue) {
    VCVodStrategySetKeyLogLevel = 10000,
};

typedef NS_ENUM(NSInteger, VCVodStrategyKey) {
    VCVodStrategyNetStateChanged = 1202,
    VCVodStrategyKeyNetworkSpeed = 20401,
};

typedef NS_ENUM(NSInteger, VCVodStrategyLogLevel) {
    VCVodStrategyLogLevelDebug = 1,
    VCVodStrategyLogLevelInfo = 2,
    VCVodStrategyLogLevelWarn = 3,
    VCVodStrategyLogLevelError = 4,
    VCVodStrategyLogLevelNone = 50,
    VCVodStrategyLogLevelAlog = 100,
};

typedef NS_ENUM(NSInteger, VCVodStrategyLogType) {
    VCVodStrategyLogTypePlay = 0,           // OnePlay
    VCVodStrategyLogTypeEvent = 1,          // OneEvent
    VCVodStrategyLogTypeStrategy = 2,       // OneStrategy
    VCVodStrategyLogTypeError = 3,          // OneError
    VCVodStrategyLogTypePriorityTask = 4,
};

typedef NS_ENUM(NSInteger, VCVodStrategyOnePlayConfig) {
    VCVodStrategyOnePlayConfigPlayLoad = 56006,
    VCVodStrategyOnePlayConfigPlayRange = 56007,
    VCVodStrategyOnePlayConfigPlayBuffer = 56008,
};

@class VCVodStrategyManager;
@protocol VCVodStrategyLogProtocol <NSObject>

@required
- (void)vodStrategy:(VCVodStrategyManager *)manager log:(NSString *)logString;

@end

@protocol VCVodStrategyEventDelegate <NSObject>

@optional
- (void)vodStrategy:(VCVodStrategyManager *)manager
          eventName:(NSString *)eventName
           eventLog:(NSDictionary *)logInfo;

- (void)vodStrategy:(VCVodStrategyManager *)manager
            videoId:(NSString *)videoId
              event:(NSInteger)key
              value:(NSInteger)value
               info:(nullable NSString *)logInfo;

@end

@protocol VCVodStrategyStateSupplier <NSObject>

@optional
- (NSDictionary<NSString *, NSNumber *> *)
      vodStrategy:(VCVodStrategyManager *)manager
    selectBitrate:(NSString *)videoId
             type:(VCVodStrategySelectType)type;
- (NSDictionary<NSString *, NSNumber *> *)
      vodStrategy:(VCVodStrategyManager *)manager
    selectBitrate:(NSString *)videoId
          sceneId:(NSString *)sceneId
             type:(VCVodStrategySelectType)type;
- (nullable NSString *)vodStrategy:(VCVodStrategyManager *)manager
                    onBeforeSelect:(NSString *)mediaInfo
                         extraInfo:(NSString *)extraInfo
                              type:(VCVodStrategySelectType)type
                           context:(id)context;
- (nullable NSString *)vodStrategy:(VCVodStrategyManager *)manager
                     onAfterSelect:(NSString *)mediaInfo
                         extraInfo:(NSString *)extraInfo
                              type:(VCVodStrategySelectType)type
                           context:(id)context;

- (double)getNetworkSpeed:(VCVodStrategyManager *)manager;
- (VCVodStrategyNetState)getNetworkType:(VCVodStrategyManager *)manager;

@end


@protocol VCVodStrategyAppService <NSObject>

@optional
/// portrait
- (nullable NSString *)vodStrategy:(VCVodStrategyManager *)manager
                       getPortrait:(nonnull NSString *)name
                            source:(nonnull NSString *)source;
- (nullable NSDictionary<NSString *, id> *)vodStrategy:(VCVodStrategyManager *)manager
                                     getGroupPortraits:(nonnull NSString *)group
                                                source:(nonnull NSString *)source;
- (nullable NSDictionary<NSString *, id> *)vodStrategy:(VCVodStrategyManager *)manager
                                      getMediaPortrait:(nonnull NSString *)mediaId
                                                  name:(nonnull NSString *)name
                                                source:(nonnull NSString *)source;
- (nullable NSDictionary<NSString *, id> *)vodStrategy:(VCVodStrategyManager *)manager
                                getMediaGroupPortraits:(nonnull NSString *)mediaId
                                                 group:(nonnull NSString *)group
                                                source:(nonnull NSString *)source;
//
- (void)vodStrategy:(VCVodStrategyManager *)manager
     addGroupConfig:(nonnull NSString *)group
              names:(nonnull NSArray<NSString *> *)names
             source:(nonnull NSString *)source;
@end


@protocol VCVodStrategyDataSource <NSObject>

// At the moment can't delete cause zhongkui ci need update major version (x.x.x.x) confict with vod version format (x.x.x).
// !!! deprecated start !!!
// deprecated casue offet typo with offset.
@optional
- (nullable NSArray<VCStrategyMedia *> *)mediaListForStrategy:(VCVodStrategyManager *)manager
                                                   forSceneId:(NSString*)sceneId
                                                        offet:(NSInteger)offset
                                                        count:(NSInteger)count
                                                     userData:(nullable id)userData;  
// !!! deprecated end !!!

@optional
- (nullable NSDictionary<NSString*, NSString*>*)strategy:(VCVodStrategyManager *)manager
                                   prefetchPreloadInfoOf:(NSString*)sceneId;


@optional
- (nullable NSArray<VCStrategyMedia *> *)mediaListForStrategy:(VCVodStrategyManager *)manager
                                                   forSceneId:(NSString*)sceneId
                                                       offset:(NSInteger)offset
                                                        count:(NSInteger)count
                                                     userData:(nullable id)userData;

@end

@interface VCVodStrategyManager : NSObject

@property(nonatomic, copy, nullable) NSString *appInfo;
@property(nonatomic, weak, nullable) id<VCVodStrategyLogProtocol>
    logHandle;
@property(nonatomic, weak, nullable) id<VCVodStrategyEventDelegate>
    eventDelegate;
@property(nonatomic, weak, nullable) id<VCVodStrategyStateSupplier>
    stateSupplier;
@property(nonatomic, weak, nullable) id<VCVodStrategyAppService> appService;

@property(nonatomic, weak, nullable) id<VCVodStrategyDataSource> dataSource;

@property(atomic, weak, nullable) id userData;
 
@property(nonatomic, assign) void *ioManager;

+ (NSInteger)iPlayerVersion;

- (void)start;
- (void)stop;

- (BOOL)isRunning;

- (void)setIntValue:(NSInteger)value forKey:(NSInteger)key;
- (NSInteger)getIntValue:(NSInteger)key dVal:(NSInteger)dVal;
- (float)getFloatValue:(NSInteger)key dVal:(float)dVal;
- (void)setLongValue:(int64_t)value forKey:(NSInteger)key;
- (int64_t)getLongValue:(NSInteger)key dVal:(int64_t)dVal;
- (int64_t)getLongValue:(NSInteger)key
                 strKey:(NSString *)strKey
                   dVal:(int64_t)dVal;
- (void)setStringValue:(NSString *)value forKey:(NSInteger)key;
- (NSString *)getStringValue:(NSInteger)key dVal:(NSString *)dVal;
- (void)updateSettingsInfo:(NSString *)module info:(NSString *)infoString;

- (NSString *) getEventLog:(NSString *)mediaId DEPRECATED_ATTRIBUTE;
- (void) removeLogData:(NSString *)mediaId DEPRECATED_ATTRIBUTE;
- (NSString *) popLogData:(VCVodStrategyLogType)type forTraceId:(NSString *)traceId;

- (void)setAlgorithmJson:(NSInteger)key jsonString:(NSString *)json;

- (void)addMedia:(NSString *)mediaJson
         sceneId:(nullable NSString *)sceneId
            last:(BOOL)isLast;
- (void)addMedia:(NSString *)mediaJson
         sceneId:(nullable NSString *)sceneId
            last:(BOOL)isLast
         interim:(BOOL)needRemove;
- (void)removeMedia:(NSString *)mediaId sceneId:(nullable NSString *)sceneId;
- (void)removeAllMedias:(NSString *)sceneId stopTask:(BOOL)stopTask;
- (void)focusMedia:(NSString *)mediaId type:(NSInteger)forceType;
- (void)updateMedia:(NSString *)mediaId
            sceneId:(nullable NSString *)sceneId
          mediaInfo:(NSString *)mediaInfo;

- (void)createScene:(NSString *)sceneJson;
- (void)destroyScene:(NSString *)sceneId;
- (void)switchToScene:(NSString *)scendId;

- (void)createPlayer:(int64_t)player
             mediaId:(NSString *)mediaId
             traceId:(NSString *)traceId;
- (void)createPlayer:(int64_t)player
             mediaId:(NSString *)mediaId
             traceId:(NSString *)traceId
                 tag:(NSString *)tag;
- (void)releasePlayer:(NSString *)mediaId traceId:(NSString *)traceId;
- (void)makeCurrentPlayer:(NSString *)mediaId;
- (void)setPlayerOption:(int64_t)player optionKey:(NSInteger)key optionValue:(NSInteger)value;

- (void)setPlayConfig:(NSString *)traceId key:(NSInteger)key stringVal:(NSString *)value;
- (void)setPlayConfig:(NSString *)traceId key:(NSInteger)key intVal:(NSInteger)value;
- (void)setPlayConfig:(NSString *)traceId key:(NSInteger)key doubleVal:(double)value;
- (void)setPlayConfig:(NSString *)traceId key:(NSInteger)key int64Val:(int64_t)value;

- (void)businessEvent:(NSInteger)key intValue:(NSInteger)value;
- (void)businessEvent:(NSInteger)key stringValue:(NSString *)value;
/// APP's custom number type event
- (void)businessEvent:(NSInteger)appId custom:(NSInteger)event intVal:(NSInteger)val;
/// APP's custom string type event
- (void)businessEvent:(NSInteger)appId custom:(NSInteger)event stringVal:(NSString *)val;

/// Preload
- (void)pausePreload;
- (void)resumePreload;

- (void)pausePreload:(NSString *)sceneId;
- (void)resumePreload:(NSString *)sceneId;

- (void)addStrategyMedias:(NSArray<VCStrategyMedia *> *) medias sceneId:(nullable NSString *)sceneId;

- (void)addPriorityTasks:(NSArray<VCStrategyMedia *> *) medias;
- (void)removePriorityTaskBy:(NSString *) key;

- (NSDictionary<NSString *, id> *)selectBitrate:(VCStrategyMedia *)mediaInfo
                                           type:(VCVodStrategySelectType)type
                                          param:(NSDictionary<NSString *, id> *)param
                                        context:(id)context;

//MARK: - Super resolution

@property (nonatomic, assign, readonly) BOOL enableDowngradeGearToSuperResolution;

@property (nonatomic, assign, readonly) BOOL enableSuperResolution;

- (NSDictionary<NSString *, id> *)playSRStrategy:(nullable VCStrategyMedia *)media param:(NSDictionary<NSString *,id> *)param;

@end

NS_ASSUME_NONNULL_END

//
//  TTVideoEngineNetworkPortraitData.h
//  Pods
//
//  Created by zhangchao on 2023/2/16.
//

#ifndef TTVideoEngineNetworkPortraitData_h
#define TTVideoEngineNetworkPortraitData_h

#import <Foundation/Foundation.h>
@protocol NetworkRTTLevelListener <NSObject>
@optional
- (int)onNetworkLog;

- (int)getNetworkRTTMs;

@end
@interface TTVideoEngineNetworkPortraitData : NSObject

@property (nonatomic, assign) NSInteger mNetMinDataSize;
@property (nonatomic, assign) NSInteger mNetLevelMaxCount;
@property (nonatomic, assign) NSInteger mNetTimerTaskIntervalMs;
@property (nonatomic, strong) NSMutableArray* _Nullable mCatowerRttList;
@property (nonatomic, strong) NSMutableArray* _Nullable mCatowerRttMsList;
@property (nonatomic, strong) NSMutableArray* _Nullable mNetTypeList;
@property (nonatomic, strong) NSMutableArray* _Nullable mMdlSpeedList;
@property (nonatomic,   weak) id<NetworkRTTLevelListener> _Nullable RTTLevelListener;
@property (nonatomic, strong) NSTimer * _Nullable timer;

//NetworkQualityAlgorithmV2
@property (nonatomic, assign) double mLastTargetBitrate;
@property (nonatomic, copy) NSArray* _Nullable mParameters;
@property (nonatomic, copy) NSString* _Nullable mVarsToParse;
@property (nonatomic, assign) double mLinkFuncOffset;

+ (nonnull instancetype)sharedInstance;
- (void)setMaxCount:(NSInteger)maxCount;
- (void)setSampleInterval:(NSInteger)interval;
- (void)setMinDataSize:(NSInteger)ms;
- (void)setmVarsToParse:(NSString*__nullable)networkVars;

- (int)getRTTMs;
- (int)getRTTLevel;
- (void)setRttListener:(id<NetworkRTTLevelListener>_Nullable)Listener;
- (NSMutableArray*_Nullable)getRttList;
- (NSMutableArray*_Nullable)getRttMsList;
- (NSMutableArray*_Nullable)getMdlSpeedList;
- (NSMutableArray*_Nullable)getNetTypeList;
- (void)setNetSpeed:(float)speed;
- (void)setnetType:(NSString*_Nullable)type;
- (void)startRttListen;
- (NSMutableArray*_Nullable)getSubListToMeetMinSize:(NSMutableArray*_Nullable)list size:(int)size;
- (NSMutableArray*_Nullable)getRttHistoryData:(int)size;
- (NSMutableArray*_Nullable)getRttMsHistoryData:(int)size;
- (NSMutableArray*_Nullable)getNetSpeedHistoryData:(int)size;

//NetworkQualityAlgorithmV2
- (double)getLastTargetBitrate;
- (void)parseVariable:(NSString*_Nullable)networkVar;
- (double)calculateTargetBitrate:(NSMutableArray*_Nullable)rttList speedList:(NSMutableArray*_Nullable)speedList netType:(NSString*_Nullable)netType;
@end

#endif /* TTVideoEngineNetworkPortraitData_h */

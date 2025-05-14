//
//  TTVideoEngineStrategyMedia.h
//  TTVideoEngine
//
//  Created by zhongzhendong on 2022/12/12.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineInfoModel;
@class TTVideoEngineLocalServerTaskInfo;
@class TTVideoEngineLoadProgress;
@class TTVideoEngineModel;

typedef NS_ENUM(NSInteger, TTVideoEngineStrategyMediaPriority) {
    TTVideoEngineStrategyMediaPriorityIDLE      =  0,
    TTVideoEngineStrategyMediaPriorityDefault   =  1,
    TTVideoEngineStrategyMediaPriorityHigh      =  2,
    TTVideoEngineStrategyMediaPriorityHighest   =  3,
};

typedef NS_ENUM(NSInteger, TTVideoEngineStrategyMediaUrlItemType) {
    TTVideoEngineStrategyMediaUrlItemSubtitle      =  0,
    TTVideoEngineStrategyMediaUrlItemDubbedAudio   =  1,
};

@interface TTVideoEngineStrategyMediaUrlItem: NSObject

/// Cache-key.
@property (nonatomic, copy, nullable) NSString *key;
/// Urls
@property (nonatomic, copy, nullable) NSArray<NSString *> *urls;
/// preloadsize, TTVideoEngineStrategyMedia.preloadSize fallback
@property (nonatomic, assign) NSInteger preloadSize;

@property (nonatomic, assign) NSInteger priorityLevel;

@property (nonatomic, assign) NSInteger urlExpiredTime;

@property (nonatomic, copy) NSDictionary *headerInfo;

@property (nonatomic, copy) NSString *preloadCustomPath;


/// preload task end callback
@property (nonatomic, copy, nullable) void(^preloadEnd)(NSError *_Nullable error);

/// preload task cancel call back.
@property (nonatomic, copy, nullable) void(^preloadCanceled)(void);

/// preload task started
/// info @{@"index": @(index), @"url": url}
@property (nonatomic, copy, nullable) void(^preloadDidStart)(NSDictionary *_Nullable info);

/// preload task progress
@property (nonatomic, copy, nullable) void(^preloadProgress)(TTVideoEngineLoadProgress *progress);

- (NSMutableDictionary *)toDict;

@end


@interface TTVideoEngineStrategyMedia: NSObject

@property (nonatomic, copy) NSDictionary *mediaInfo;
@property (nonatomic, strong) TTVideoEngineInfoModel* engineInfoModel;

@property (nonatomic, assign) TTVideoEngineStrategyMediaPriority preloadPriorityLevel;
@property (nonatomic, assign) NSInteger CDNUrlExpiredTime;
@property (nonatomic, assign) NSInteger preloadSize;
@property (nonatomic, assign) double preloadSizeFactor;
@property (nonatomic, copy) NSString* preloadSizeInfo;
@property (nonatomic, copy) NSString* preloadCustomPath;
@property (nonatomic, copy) NSDictionary* preloadCustomHttpHeader;
@property (nonatomic, assign) NSInteger preloadOffsetMilliSecond;

@property (nonatomic, copy) NSString* tag;
@property (nonatomic, copy) NSString* subtag;
@property (nonatomic, copy) NSString* groupId;

@property (nonatomic, copy) NSString* mContext;
@property (nonatomic, copy) NSDictionary *extraInfo;

-(instancetype)initWithMediaInfo:(NSDictionary *)mediaInfo;

-(instancetype)initWithVideoModelInfo:(NSDictionary *)videoModelDict;
-(instancetype)initWithVideoModelString:(NSString *)videoModelJson;
-(instancetype)initWithVideoModel:(TTVideoEngineInfoModel*)infoModel;

- (void)appendExternalResource:(TTVideoEngineStrategyMediaUrlItem *) item
                      withType:(TTVideoEngineStrategyMediaUrlItemType) type;

-(NSMutableDictionary*)toVodStrategyDictionary;
-(NSString*)toVodStrategyJson;
- (NSMutableDictionary *)externalUrlItemDic;

/// preload task end callback
@property (nonatomic, copy, nullable) void(^preloadEnd)(NSError *_Nullable error);

/// preload task cancel call back.
@property (nonatomic, copy, nullable) void(^preloadCanceled)(void);

/// preload task started
/// info @{@"index": @(index), @"url": url}
@property (nonatomic, copy, nullable) void(^preloadDidStart)(NSDictionary *_Nullable info);

/// preload task progress
@property (nonatomic, copy, nullable) void(^preloadProgress)(TTVideoEngineLoadProgress *progress);

/// preload select bitrate result
@property (nonatomic, copy, nullable) NSDictionary*(^preloadSelectBitrate)(void);

@end

__attribute__((deprecated("Class TTVideoEngineModelMedia is deprecated , use TTVideoEngineStrategyMedia instead")))
@interface TTVideoEngineModelMedia: NSObject
@property (nonatomic, strong) TTVideoEngineModel *videoModel;
@property (nonatomic, copy) NSDictionary *extraInfo;
@end

NS_ASSUME_NONNULL_END

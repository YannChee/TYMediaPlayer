//
//  VCStrategyMedia.h
//  TTVideoEngine
//
//  Created by bytedance on 2022/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, VodStrategyTaskType) {
    VodStrategyTaskTypePreload,
    VodStrategyTaskTypePlay,
};

@interface VodStrategyTaskInfo : NSObject
/// Task key, vidItem task is file-hash.
/// If you customize the cache file path, you must ignore this field.
@property (nonatomic,   copy) NSString *key;
/// Video-id.
@property (nonatomic, nullable, copy) NSString *videoId;
/// The local file path of media.
@property (nonatomic, nullable, copy) NSString *localFilePath;
/// The origin size of media.
@property (nonatomic, assign) int64_t mediaSize;
/// Non-stop cache size from scratch.
@property (nonatomic, assign) int64_t cacheSizeFromZero;
/// Decryption key.
@property (nonatomic, nullable, copy) NSString *decryptionKey;
/// PreloadSize.
@property (nonatomic, assign) int64_t preloadSize;
/// Play or Preload.
@property (nonatomic, assign) VodStrategyTaskType taskType;

@end

@interface VodStrategyCacheInfo : NSObject <NSCopying>
@property (nonatomic,   copy) NSString *cacheKey;
@property (nonatomic, assign) NSInteger mediaSize;
@property (nonatomic, assign) NSInteger preloadHeaderSize;
@property (nonatomic, assign) NSInteger preloadOffset;
@property (nonatomic, assign) NSInteger preloadSize;
@property (nonatomic,   copy) NSString *localFilePath;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign, readonly) NSInteger maxCacheEnd;


- (void)setCacheSize:(NSInteger)cacheSize;
- (BOOL)isFinished;

@end

@interface VodStrategyLoadProgress : NSObject <NSCopying>
@property (nonatomic,   copy, nullable) NSString *videoId;
@property (nonatomic, assign) VodStrategyTaskType taskType;
@property (nonatomic,   copy) NSArray<VodStrategyCacheInfo *> *cacheInfos;

@property (nonatomic, assign, readonly, getter=isPreloadComplete) BOOL preloadComplete;
@property (nonatomic, assign, readonly, getter=isCacheEnd) BOOL cacheEnd;

- (NSInteger)getTotalCacheSize; /// all file cache size.
- (NSInteger)getTotalMediaSize; /// all file media size.


- (VodStrategyCacheInfo *)getCahceInfo:(NSString *)key;
- (void)receiveError:(NSString *)key error:(NSError *)error;

@end


typedef NS_ENUM(NSInteger, VCStrategyMediaUrlItemType) {
    VCStrategyMediaUrlItemSubtitle      =  0,
    VCStrategyMediaUrlItemDubbedAudio   =  1,
};

@interface VCStrategyMediaUrlItem : NSObject

-(instancetype)initWithInfo:(NSDictionary *)info;

@property (nonatomic, copy) NSDictionary *info;

/// preload task end callback
@property (nonatomic, copy, nullable) void(^preloadEnd)(NSError *_Nullable error);

/// preload task cancel call back.
@property (nonatomic, copy, nullable) void(^preloadCanceled)(void);

/// preload task started
/// info @{@"index": @(index), @"url": url}
@property (nonatomic, copy, nullable) void(^preloadDidStart)(NSDictionary *_Nullable info);

/// preload task progress
@property (nonatomic, copy, nullable) void(^preloadProgress)(VodStrategyLoadProgress *progress);

@end


@interface VCStrategyMedia : NSObject

-(instancetype)initWithMediInfo:(NSDictionary *)info;

@property (nonatomic, copy) NSDictionary *extraInfo;
@property (nonatomic, copy) NSDictionary *mediInfo;

@property (nonatomic, copy) NSMutableDictionary* externalUrlItemDic;

- (void)appendExternalResource:(VCStrategyMediaUrlItem *) item
                      withType:(VCStrategyMediaUrlItemType) type;

/// preload task end callback
@property (nonatomic, copy, nullable) void(^preloadEnd)(NSError *_Nullable error);

/// preload task cancel call back.
@property (nonatomic, copy, nullable) void(^preloadCanceled)(void);

/// preload task started
/// info @{@"index": @(index), @"url": url}
@property (nonatomic, copy, nullable) void(^preloadDidStart)(NSDictionary *_Nullable info);

/// preload task progress
@property (nonatomic, copy, nullable) void(^preloadProgress)(VodStrategyLoadProgress *progress);

/// preload select bitrate result
@property (nonatomic, copy, nullable) NSDictionary*(^preloadSelectBitrate)(void);

@end

NS_ASSUME_NONNULL_END

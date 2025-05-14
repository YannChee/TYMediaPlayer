//
//  TTVideoEngineStrategyDataSource.h
//  TTVideoEngine
//
//  Created by bytedance on 2022/12/12.
//

#import <Foundation/Foundation.h>
#import "TTVideoEngineStrategyMedia.h"

NS_ASSUME_NONNULL_BEGIN

@class TTVideoEngineStrategy;

@protocol TTVideoEngineStrategyDataSource <NSObject>

// At the moment can't delete cause zhongkui ci need update major version (x.x.x.x) confict with vod version format (x.x.x).
// warning param with typo, use second one. will by deleted;
@optional
- (nullable NSArray<TTVideoEngineStrategyMedia *> *)mediaListForStrategy:(TTVideoEngineStrategy *)vodStrategy
                                                              forSceneId:(NSString*)sceneId
                                                                   offet:(NSInteger)ofsset
                                                                   count:(NSInteger)count
                                                                userData:(nullable id)userData;

//use this
@optional
- (nullable NSArray<TTVideoEngineStrategyMedia *> *)mediaListForStrategy:(TTVideoEngineStrategy *)vodStrategy
                                                              forSceneId:(NSString*)sceneId
                                                                   offset:(NSInteger)offset
                                                                   count:(NSInteger)count
                                                                userData:(nullable id)userData;

@optional
- (nullable NSDictionary<NSString*, NSString*>*)strategy:(TTVideoEngineStrategy *)vodStrategy
                                   prefetchPreloadInfoOf:(NSString*)sceneId;

@end

NS_ASSUME_NONNULL_END

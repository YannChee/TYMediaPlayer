//
//  TTVideoEngineConfigCenter.h
//  TTVideoEngine
//
//  Created by real on 2023/1/6.
//

#import "TTVideoEngineConfigCenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngineConfigCenter : NSObject

+ (TTVideoEngineConfigCenter *)defaultCenter;

- (void)saveConfig:(id<TTVideoEngineConfigItemProtocol>)config forKey:(NSInteger)key ofTag:(NSString *)tag;

- (id<TTVideoEngineConfigItemProtocol>)configForKey:(NSInteger)key ofTag:(NSString *)tag;

- (void)saveConfigurations:(id<TTVideoEngineConfigsDefaultWrapper>)configs ofTag:(NSString *)tag;

- (void)removeConfigurationsForTag:(NSString *)tag;


// print 
- (void)alogWithConfig:(NSInteger)key value:(id)value tag:(NSString *)tag;

- (void)releaseLog;

@end

NS_ASSUME_NONNULL_END

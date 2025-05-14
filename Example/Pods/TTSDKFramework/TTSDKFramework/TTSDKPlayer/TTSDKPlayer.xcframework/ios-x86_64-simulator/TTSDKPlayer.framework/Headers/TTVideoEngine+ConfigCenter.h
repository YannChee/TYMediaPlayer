//
//  TTVideoEngine+ConfigCenter.h
//  TTVideoEngine
//
//  Created by real on 2023/2/1.
//

#import "TTVideoEngine.h"
#import "TTVideoEngineConfigCenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngine (ConfigCenter)

- (void)setConfigValue:(NSObject *)value forKey:(NSInteger)key;

- (id<TTVideoEngineConfigItemProtocol>)configItemForKey:(NSInteger)key;

- (id)configValueForKey:(NSInteger)key;

- (void)setConfigurations:(id<TTVideoEngineConfigsDefaultWrapper>)configs forTag:(NSString *)tag;

- (void)removeConfigurations;

- (void)releaseLog;

@end

NS_ASSUME_NONNULL_END

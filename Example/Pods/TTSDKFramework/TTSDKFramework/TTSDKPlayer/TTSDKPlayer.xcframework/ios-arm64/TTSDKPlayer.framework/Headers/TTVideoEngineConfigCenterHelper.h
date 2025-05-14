//
//  TTVideoEngineConfigCenterHelper.h
//  TTVideoEngine
//
//  Created by real on 2023/2/1.
//

#import "TTVideoEngineConfigCenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TTVideoEngineConfigCenterHelper : NSObject

+ (SEL)selectorForOption:(NSInteger)optionKey;

+ (TTVideoEngineActionArea)actionAreaForOption:(NSInteger)optionKey;

+ (TTVideoEngineConfigDataType)dataTypeForOption:(NSInteger)optionKey;

+ (id)defaultValueForOption:(NSInteger)optionKey;

+ (NSNumber *)executeKeyForOption:(NSInteger)optionKey;

@end

NS_ASSUME_NONNULL_END

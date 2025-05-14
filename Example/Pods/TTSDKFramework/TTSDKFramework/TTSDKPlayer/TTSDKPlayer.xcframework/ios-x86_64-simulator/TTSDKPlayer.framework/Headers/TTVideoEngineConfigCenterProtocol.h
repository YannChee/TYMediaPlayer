//
//  TTVideoEngineConfigCenterProtocol.h
//  Pods
//
//  Created by real on 2023/1/10.
//

#ifndef TTVideoEngineConfigCenterProtocol_h
#define TTVideoEngineConfigCenterProtocol_h

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TTVideoEngineActionOfEngine = 0,
    TTVideoEngineActionOfEngineOptions = 1,
    TTVideoEngineActionOfEngineEventLogger = 2,
    TTVideoEngineActionOfCore = 10,
    TTVideoEngineActionOfMDL = 20
} TTVideoEngineActionArea;

typedef enum : NSUInteger {
    TTVideoEngineConfigDataInt = 0,
    TTVideoEngineConfigDataLong = 1,
    TTVideoEngineConfigDataLongLong = 2,
    TTVideoEngineConfigDataFloat = 3,
    TTVideoEngineConfigDataDouble = 4,
    TTVideoEngineConfigDataBOOL = 5,
    TTVideoEngineConfigDataString = 6,
    
    TTVideoEngineConfigDataKeyValueInt = 100,
    TTVideoEngineConfigDataKeyValueLong = 101,
    TTVideoEngineConfigDataKeyValueLongLong = 102,
    TTVideoEngineConfigDataKeyValueFloat = 103,
    TTVideoEngineConfigDataKeyValueDouble = 104,
    TTVideoEngineConfigDataKeyValueBOOL = 105,
    TTVideoEngineConfigDataKeyValueString = 106,
} TTVideoEngineConfigDataType;

// TTVideoEngineConfig 
@protocol TTVideoEngineConfigItemProtocol <NSObject>

@property (nonatomic, assign) NSInteger key;

@property (nonatomic, assign) NSInteger executeKey;

@property (nonatomic, strong) id value;

@property (nonatomic, strong) id defaultValue;

@property (nonatomic, assign) TTVideoEngineConfigDataType dataType;

@property (nonatomic, weak) id executeVariable;

@property (nonatomic, assign) SEL executeSelector;

@property (nonatomic, assign) TTVideoEngineActionArea actionArea;
// in this case, sync == mainthread & sync, async = {(concurrent thread | serial thread) & async}
//@property (nonatomic, assign) BOOL shouldSync;

- (void)execute;

@end

// If you wanna to give a personal arch, please inherit this protocol
@protocol TTVideoEngineConfigsDefaultWrapper <NSObject>

@required
- (NSArray<NSDictionary<NSString *, id> *> *)engineConfigs;

@end

NS_ASSUME_NONNULL_END

#endif /* TTVideoEngineConfigCenterProtocol_h */

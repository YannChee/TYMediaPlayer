#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TTAVTraitType) {
    TTAVIllegal = 0,
    TTAVExtVoice = 1,
    TTAVDrawByPass = 2,
    TTAVProxyAudio = 3,
    TTLiveCallback = 4,
    TTAVLoadControl = 5,
    TTAVHLSChooseStream = 7,
};

@interface TTAVTraitObject : NSObject

@property (nonatomic, assign, readonly) int type;
@property (nonatomic, assign, readonly) int version;

- (instancetype) initWithType: (int) type andVersion:(int) version;
- (instancetype) initWithType: (int) type andObj:(intptr_t) obj;

- (bool) sameAs:(TTAVTraitObject *) traitObject;

- (void) releaseObj;

@end


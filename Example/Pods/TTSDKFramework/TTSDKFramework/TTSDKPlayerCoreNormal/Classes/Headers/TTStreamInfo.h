#import <Foundation/Foundation.h>
#import "TTPlayerDef.h"

@interface TTStreamInfo : NSObject
@property (nonatomic, assign) TTMediaStreamType streamType;
@property (nonatomic, assign) NSInteger streamIndex;
@property (nonatomic, copy) NSString* codecName;
@property (nonatomic, assign) NSInteger frameRate;
@property (nonatomic, assign) NSInteger bitRate;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger sampleRate;
@property (nonatomic, assign) NSInteger channels;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, assign) NSInteger rotation;

- (instancetype)init;

@end

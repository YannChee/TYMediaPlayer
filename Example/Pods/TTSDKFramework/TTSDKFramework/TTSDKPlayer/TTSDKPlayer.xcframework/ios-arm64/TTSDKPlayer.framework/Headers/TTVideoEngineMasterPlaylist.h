//
//  TTVideoEngineMasterPlaylist.h
//  AFNetworking
//
//  Created by sjc on 31.3.24.
//

#import <Foundation/Foundation.h>

@class TTVideoEngineVariantStream;
@class TTVideoEngineRendition;
@class TTCMMasterPlaylist;
@class TTMultiVariantPlaylist;
@interface TTVideoEngineMasterPlaylist : NSObject

@property (nonatomic, copy, nullable) NSArray<TTVideoEngineVariantStream *> *variantStreams;
@property (nonatomic, copy, nullable) NSArray<TTVideoEngineRendition *> *renditions;

- (nullable instancetype)initWithMasterPlaylist:(TTCMMasterPlaylist * _Nullable)source;
- (nullable instancetype)initWithTTPlayerMasterPlaylist:(TTMultiVariantPlaylist * _Nullable)source;

@end

@interface TTVideoEngineVariantStream : NSObject
@property (nonatomic, copy, nullable) NSString *codecs;
@property (nonatomic, copy, nullable) NSString *resolution;
@property (nonatomic, copy, nullable) NSString *hdcpLevel;
@property (nonatomic, copy, nullable) NSString *audioGroupId;
@property (nonatomic, copy, nullable) NSString *videoGroupId;
@property (nonatomic, copy, nullable) NSString *subtitleGroupId;
@property (nonatomic, copy, nullable) NSString *closedCaptionsGroupId;
@property (nonatomic, assign) NSInteger bandwidth;
@property (nonatomic, assign) NSInteger averageBandwidth;
@property (nonatomic, assign) double frameRate;
@property (nonatomic, copy, nullable) NSString *uri;
@end

@interface TTVideoEngineRendition : NSObject
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *uri;
@property (nonatomic, copy, nullable) NSString *groupId;
@property (nonatomic, copy, nullable) NSString *language;
@property (nonatomic, copy, nullable) NSString *assocLanguage;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, assign) BOOL isDefault;
@property (nonatomic, assign) BOOL autoSelect;
@property (nonatomic, assign) BOOL forced;
@property (nonatomic, copy, nullable) NSString *inStreamId;
@property (nonatomic, copy, nullable) NSString *characteristics;
@property (nonatomic, copy, nullable) NSString *channels;
@end


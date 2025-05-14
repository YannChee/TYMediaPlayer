//
//  TTVideoEngineMultiEncodingDirectUrlSource.h
//  TTVideoEngine
//
//  Created by bytedance on 4.6.21.
//

#import <Foundation/Foundation.h>
#import "TTVideoEnginePlayerDefine.h"
#import "TTVideoEngineUrlSource.h"

NS_ASSUME_NONNULL_BEGIN

/// TTVideoEngineMultiEncodingUrlSource is a class which can aggregate multi encoding url sources,
/// in cases of  those video/audio programs support more than one encode type.
/// for example, if there is a video program, not only support h264 encode but also support h265 encode, each encode source link to a single url,
/// then construct the two urls in an instance of TTVideoEngineMultiEncodingUrlSource is convenient.
@interface TTVideoEngineMultiEncodingUrlSource : TTVideoEngineUrlSource

- (void)setAsset:(nullable TTVideoEngineUrlSource *)asset forCodec:(TTVideoEngineEncodeType)encodeType;

- (nullable TTVideoEngineUrlSource *)assetForCodec:(TTVideoEngineEncodeType)encodeType;

/// If there is a url asset link to h265
- (BOOL)hash265Asset;

@end
NS_ASSUME_NONNULL_END

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "av_audio_wrapper.h"
#import "TTAVPlayerLoadControlInterface.h"
#import "TTAVPlayerMaskInfoInterface.h"
#import "TTAVTraitObject.h"
#import "TTPlayerDef.h"
#import "TTStreamInfo.h"

#if defined(__cplusplus)
#import "av_nativetrait.h"
#endif


FOUNDATION_EXPORT double TTSDKPlayerCoreNormalVersionNumber;
FOUNDATION_EXPORT const unsigned char TTSDKPlayerCoreNormalVersionString[];

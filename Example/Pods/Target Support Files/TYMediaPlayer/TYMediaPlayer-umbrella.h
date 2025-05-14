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

#import "FPPlayer.h"
#import "FPPlayerMediaPlayback.h"
#import "FPPlayerViewDefinitions.h"
#import "TYMediaPlayer.h"

FOUNDATION_EXPORT double TYMediaPlayerVersionNumber;
FOUNDATION_EXPORT const unsigned char TYMediaPlayerVersionString[];


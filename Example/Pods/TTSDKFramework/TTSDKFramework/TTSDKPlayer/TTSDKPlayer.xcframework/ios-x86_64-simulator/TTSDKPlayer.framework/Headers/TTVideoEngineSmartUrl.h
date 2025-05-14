//
//  TTVideoEngineSmartUrl.h
//  TTVideoEngine
//
//  Created by sjc on 14.2.22.
//
//  All public headers for SmartUrl(i.e. SmartStrategy).

#import <Foundation/Foundation.h>

#import "TTVideoEngineUrlSource.h"
#import "TTVideoEngine+Preload.h"

NS_ASSUME_NONNULL_BEGIN

/// Distinguish by the different OpenAPI
typedef NS_ENUM(NSInteger, TTVideoEngineSmartUrlVersion) {
    TTVideoEngineSmartUrlVersionLite = 0,
    TTVideoEngineSmartUrlVersionPro = 1,
};

// MARK: - TTVideoEngineSmartUrlDelegate

/// TTVideoEngineSmartUrlDelegate supply callbacks for extension of SmartUrl, holded by types those conforms to `TTVideoEngineSmartUrlProtocol`.
@protocol TTVideoEngineSmartUrlDelegate <NSObject>

@optional

- (void)smartUrlFetchDidFinish:(id _Nullable)result error:(NSError * _Nullable)error;

@end


// MARK: - TTVideoEngineSmartUrlProtocol

@protocol TTVideoEngineMediaSource;

/// - Conforming types:
///     - TTVideoEngineUrlSource
///     - TTVideoEngineMultiEncodingUrlSource
@protocol TTVideoEngineSmartUrlProtocol <TTVideoEngineMediaSource>

@required

/// If enable smart url
@property (nonatomic, assign) BOOL smartUrlEnabled;

/// Default value is TTVideoEngineSmartUrlVersionLite
@property (nonatomic, assign) TTVideoEngineSmartUrlVersion smartUrlVersion;

/// Implement a delegate instance to observe the smart url fetching status.
@property (nonatomic, weak) id<TTVideoEngineSmartUrlDelegate> smartUrlDelegate;

@end


//MARK: - Class extensions

@interface TTVideoEngineUrlSource (SmartUrl) <TTVideoEngineSmartUrlProtocol>
@end

@interface TTVideoEnginePreloaderURLItem (SmartUrl) <TTVideoEngineSmartUrlProtocol>
@end

NS_ASSUME_NONNULL_END

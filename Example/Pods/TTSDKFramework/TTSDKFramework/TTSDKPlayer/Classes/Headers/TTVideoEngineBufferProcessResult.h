//
//  TTVideoEngineBufferProcessResult
//
//  Created by ByteDance on 2024/11/4.
//

#import <Foundation/Foundation.h>

@interface TTVideoEngineBufferProcessResult : NSObject

@property(nonatomic, strong, nullable) NSData *resultData;
@property(assign) int ret;
@end


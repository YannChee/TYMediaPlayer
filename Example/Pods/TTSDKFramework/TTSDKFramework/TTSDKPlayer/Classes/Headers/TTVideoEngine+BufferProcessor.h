//
//  TTVideoEngine+BufferProcessor.h
//  Pods
//
//  Created by sj on 2.4.24.
//

#ifndef TTVideoEngine_Buffer_Processor_Delegate_h
#define TTVideoEngine_Buffer_Processor_Delegate_h

#import <Foundation/Foundation.h>
@class TTVideoEngineBufferProcessResult;
@protocol TTVideoEngineBufferProcessorDelegate <NSObject>

@optional
-(void)opened:(NSString *)url result:(NSInteger)ret;
-(void)seeked:(NSString *)url result:(NSInteger)ret whence:(NSInteger)whence;
-(void)readed:(NSString *)url result:(NSInteger)ret;
-(void)closed:(NSString *)url result:(NSInteger)ret;
-(int)isChuck:(NSString *)url;
-(void)clearRemainBuffer:(NSString *)url;
-(TTVideoEngineBufferProcessResult*)prcocess:(NSString *)url intput:(NSData*)intputData;
@end

@interface TTVideoEngine()
/* masterPlaylist interface*/
@property (nonatomic, weak, nullable) id<TTVideoEngineBufferProcessorDelegate> bufferProcessorDelegate;

@end



#endif /* TTVideoEngine_MasterPlaylist_h */

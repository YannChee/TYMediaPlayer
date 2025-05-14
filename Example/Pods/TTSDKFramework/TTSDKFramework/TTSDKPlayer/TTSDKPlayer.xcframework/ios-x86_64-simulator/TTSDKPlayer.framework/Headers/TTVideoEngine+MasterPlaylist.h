//
//  TTVideoEngine+MasterPlaylist.h
//  Pods
//
//  Created by sjc on 2.4.24.
//

#ifndef TTVideoEngine_MasterPlaylist_h
#define TTVideoEngine_MasterPlaylist_h

#import "TTVideoEngineMasterPlaylist.h"

@protocol TTVideoEngineMasterPlaylistDelegate <NSObject>

- (void)videoEngine:(TTVideoEngine * _Nonnull)videoEngine onMasterPlaylist:(TTVideoEngineMasterPlaylist * _Nullable)masterPlaylist;
- (int)videoEngine:(TTVideoEngine * _Nonnull)videoEngine indexOfVariantOnPlayMasterPlaylist:(TTVideoEngineMasterPlaylist * _Nullable)masterPlaylist;
- (int)videoEngine:(TTVideoEngine * _Nonnull)videoEngine indexOfRenditionOnPlayMasterPlaylist:(TTVideoEngineMasterPlaylist * _Nullable)masterPlaylist;

@end

@interface TTVideoEngine()
/* masterPlaylist interface*/
@property (nonatomic, weak, nullable) id<TTVideoEngineMasterPlaylistDelegate> masterPlaylistDelegate;
@property (nonatomic, strong, nullable) TTVideoEngineMasterPlaylist *masterPlaylist;

@end



#endif /* TTVideoEngine_MasterPlaylist_h */

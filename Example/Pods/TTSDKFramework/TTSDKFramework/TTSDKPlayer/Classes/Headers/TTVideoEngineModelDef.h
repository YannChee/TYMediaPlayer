//
//  TTVideoEngineModelDef.h
//  Article
//
//  Created by Chen Hong on 15/5/8.
//
//

#import "TTAVPreloaderItem.h"

/**
 * @locale zh
 * @type keytype
 * @hidden
 * @brief 播放类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Playback type.
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEnginePlayType) {
    TTVideoEnginePlayTypeDefault = 0, // 默认
    TTVideoEnginePlayTypeNormal = 1, // 点播
    TTVideoEnginePlayTypeLive = 2, // 直播
    TTVideoEnginePlayTypeLivePlayback = 3, // 直播回放
    TTVideoEnginePlayTypePasterAD = 100 // 贴片广告 (server不依赖该值)
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频格式。
 */
/**
 * @locale en
 * @type keytype
 * @brief video container format.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineVideoModelSourceType) {
    /**
     * @locale zh
     * @brief 未知
     */
   /**
    * @locale en
    * @brief Unknown
    */
    TTVideoEngineVideoModelSourceTypeUnkonw    = 0,
    /**
     * @locale zh
     * @brief MP4
     */
   /**
    * @locale en
    * @brief MP4
    */
    TTVideoEngineVideoModelSourceTypeMp4       = 1,
    /**
     * @locale zh
     * @brief DASH
     */
   /**
    * @locale en
    * @brief DASH
    */
    TTVideoEngineVideoModelSourceTypeDash      = 10,
    /**
     * @locale zh
     * @brief BASH
     */
   /**
    * @locale en
    * @brief BASH
    */
    TTVideoEngineVideoModelSourceTypeBash      = 11,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频清晰度。
 */
/**
 * @locale en
 * @type keytype
 * @brief Video resolution.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineResolutionType) {
    /**
     * @locale zh
     * @brief 标清 360P
     */
   /**
    * @locale en
    * @brief Standard Definition 360P
    */
    TTVideoEngineResolutionTypeSD = 0,
    /**
     * @locale zh
     * @brief 高清 480P
     */
   /**
    * @locale en
    * @brief High Definition 480P
    */
    TTVideoEngineResolutionTypeHD = 1,
    /**
     * @locale zh
     * @brief 超清 720P
     */
   /**
    * @locale en
    * @brief HD 720P
    */
    TTVideoEngineResolutionTypeFullHD = 2,
    /**
     * @locale zh
     * @brief 1080P
     */
   /**
    * @locale en
    * @brief 1080P
    */
    TTVideoEngineResolutionType1080P = 3,
    /**
     * @locale zh
     * @brief 4K
     */
   /**
    * @locale en
    * @brief 4K
    */
    TTVideoEngineResolutionType4K = 4,

    /**
     * @locale zh
     * @brief 自动调节。该选项仅适用于 DASH 视频，表示根据网速动态调节清晰度。
     */
   /**
    * @locale en
    * @brief Automatic adjustment. This option applies only to DASH videos, meaning that the quality is dynamically adjusted based on network speed.
    */
    TTVideoEngineResolutionTypeAuto = 5,
    /**
     * @locale zh
     * @hidden
     * @brief 未知
     */
   /**
    * @locale en
    * @hidden
    * @brief unknown
    */
    TTVideoEngineResolutionTypeUnknown = 6,
    /**
     * @locale zh
     * @hidden
     * @brief 240P
     */
   /**
    * @locale en
    * @hidden
    * @brief 240P
    */
    TTVideoEngineResolutionTypeSD_L = 7,
    /**
     * @locale zh
     * @brief 540P
     */
   /**
    * @locale en
    * @brief 540P
    */
    TTVideoEngineResolutionTypeHD_H = 8,
    /**
     * @locale zh
     * @hidden
     */
    /**
     * @locale en
     * @hidden
     */
    TTVideoEngineResolutionTypeHDR = 9,
    /**
     * @locale zh
     * @brief 2K
     */
   /**
    * @locale en
    * @brief 2K
    */
    TTVideoEngineResolutionType2K = 10,
    /**
     * @locale zh
     * @hidden
     * @brief 1080P 50Fps
     */
   /**
    * @locale en
    * @hidden
    * @brief 1080P 50Fps
    */
    TTVideoEngineResolutionType1080P_50F = 11,
    /**
     * @locale zh
     * @hidden
     * @brief 2K 50Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 2K 50Fps
     */
    TTVideoEngineResolutionType2K_50F = 12,
    /**
     * @locale zh
     * @hidden
     * @brief 4K 50Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 4K 50Fps
     */
    TTVideoEngineResolutionType4K_50F = 13,
    /**
     * @locale zh
     * @hidden
     * @brief 1080P 60Fps
     */
   /**
    * @locale en
    * @hidden
    * @brief 1080P 60Fps
    */
    TTVideoEngineResolutionType1080P_60F = 14,
    /**
     * @locale zh
     * @hidden
     * @brief 2K 60Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 2K 60Fps
     */
    TTVideoEngineResolutionType2K_60F = 15,
    /**
     * @locale zh
     * @hidden
     * @brief 4K 60Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 4K 60Fps
     */
    TTVideoEngineResolutionType4K_60F = 16,
    /**
     * @locale zh
     * @hidden
     * @brief 1080P 120Fps
     */
   /**
    * @locale en
    * @hidden
    * @brief 1080P 120Fps
    */
    TTVideoEngineResolutionType1080P_120F = 17,
    /**
     * @locale zh
     * @hidden
     * @brief 2K 120Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 2K 120Fps
     */
    TTVideoEngineResolutionType2K_120F = 18,
    /**
     * @locale zh
     * @hidden
     * @brief 4K 120Fps
     */
    /**
     * @locale en
     * @hidden
     * @brief 4K 120Fps
     */
    TTVideoEngineResolutionType4K_120F = 19,
    
    /**
     * @locale zh
     * @hidden
     * @brief 240P HDR
     */
   /**
    * @locale en
    * @brief 240P HDR
    * @hidden
    */
    TTVideoEngineResolutionTypeHDR_240P = 20,
    /**
     * @locale zh
     * @hidden
     * @brief 360P HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 360P HDR
     */
    TTVideoEngineResolutionTypeHDR_360P = 21,
    /**
     * @locale zh
     * @hidden
     * @brief 480P HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 480P HDR
     */
    TTVideoEngineResolutionTypeHDR_480P = 22,
    /**
     * @locale zh
     * @hidden
     * @brief 540P HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 540P HDR
     */
    TTVideoEngineResolutionTypeHDR_540P = 23,
    /**
     * @locale zh
     * @hidden
     * @brief 720P HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 720P HDR
     */
    TTVideoEngineResolutionTypeHDR_720P = 24,
    /**
     * @locale zh
     * @hidden
     * @brief 1080P HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 1080P HDR
     */
    TTVideoEngineResolutionTypeHDR_1080P = 25,
    /**
     * @locale zh
     * @hidden
     * @brief 2K HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 2K HDR
     */
    TTVideoEngineResolutionTypeHDR_2K = 26,
    /**
     * @locale zh
     * @hidden
     * @brief 4K HDR
     */
    /**
     * @locale en
     * @hidden
     * @brief 4K HDR
     */
    TTVideoEngineResolutionTypeHDR_4K = 27,
    
    /**
     * @locale zh
     * @hidden
     * @brief ABR自动档位通过configResolutin设置这个档位开启abr，但是本质和resoluttion不同，所以lastResolution,currentResoulution不应该设置这个值
     */
   /**
    * @locale en
    * @hidden
    * @brief ABR automatic mode is enabled through configResolution, but it differs fundamentally from resolution, so lastResolution and currentResolution should not be set to this value.
    */
    TTVideoEngineResolutionTypeABRAuto = 500,
 
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 获取所有的清晰度
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 */
NS_INLINE NSArray<NSNumber *> *TTVideoEngineAllResolutions(void) {
    return @[@(TTVideoEngineResolutionTypeSD_L),
             @(TTVideoEngineResolutionTypeSD),
             @(TTVideoEngineResolutionTypeHD),
             @(TTVideoEngineResolutionTypeHD_H),
             @(TTVideoEngineResolutionTypeFullHD),
             @(TTVideoEngineResolutionType1080P),
             @(TTVideoEngineResolutionType1080P_50F),
             @(TTVideoEngineResolutionType1080P_60F),
             @(TTVideoEngineResolutionType1080P_120F),
             @(TTVideoEngineResolutionTypeHDR),
             @(TTVideoEngineResolutionType2K),
             @(TTVideoEngineResolutionType2K_50F),
             @(TTVideoEngineResolutionType2K_60F),
             @(TTVideoEngineResolutionType2K_120F),
             @(TTVideoEngineResolutionType4K),
             @(TTVideoEngineResolutionType4K_50F),
             @(TTVideoEngineResolutionType4K_60F),
             @(TTVideoEngineResolutionType4K_120F),
             @(TTVideoEngineResolutionTypeHDR_240P),
             @(TTVideoEngineResolutionTypeHDR_360P),
             @(TTVideoEngineResolutionTypeHDR_480P),
             @(TTVideoEngineResolutionTypeHDR_540P),
             @(TTVideoEngineResolutionTypeHDR_720P),
             @(TTVideoEngineResolutionTypeHDR_1080P),
             @(TTVideoEngineResolutionTypeHDR_2K),
             @(TTVideoEngineResolutionTypeHDR_4K),];
}

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 获取所有的清晰度+描述
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 * @brief Default video resolution map.
 */
NS_INLINE NSDictionary *TTVideoEngineDefaultVideoResolutionMap(void) {
    static dispatch_once_t onceToken;
    static NSDictionary *s_video_resolution_map = nil;
    dispatch_once(&onceToken, ^{
        s_video_resolution_map = @{
                                  @"240p":@(TTVideoEngineResolutionTypeSD_L),
                                  @"360p":@(TTVideoEngineResolutionTypeSD),
                                  @"480p":@(TTVideoEngineResolutionTypeHD),
                                  @"540p":@(TTVideoEngineResolutionTypeHD_H),
                                  @"720p":@(TTVideoEngineResolutionTypeFullHD),
                                  @"1080p":@(TTVideoEngineResolutionType1080P),
                                  @"1080p 50fps":@(TTVideoEngineResolutionType1080P_50F),
                                  @"1080p 60fps":@(TTVideoEngineResolutionType1080P_60F),
                                  @"1080p 120fps":@(TTVideoEngineResolutionType1080P_120F),
                                  @"hdr":@(TTVideoEngineResolutionTypeHDR),
                                  @"240p HDR":@(TTVideoEngineResolutionTypeHDR_240P),
                                  @"360p HDR":@(TTVideoEngineResolutionTypeHDR_360P),
                                  @"480p HDR":@(TTVideoEngineResolutionTypeHDR_480P),
                                  @"540p HDR":@(TTVideoEngineResolutionTypeHDR_540P),
                                  @"720p HDR":@(TTVideoEngineResolutionTypeHDR_720P),
                                  @"1080p HDR":@(TTVideoEngineResolutionTypeHDR_1080P),
                                  @"2k HDR":@(TTVideoEngineResolutionTypeHDR_2K),
                                  @"4k HDR":@(TTVideoEngineResolutionTypeHDR_4K),
                                  @"2k":@(TTVideoEngineResolutionType2K),
                                  @"2k 50fps":@(TTVideoEngineResolutionType2K_50F),
                                  @"2k 60fps":@(TTVideoEngineResolutionType2K_60F),
                                  @"2k 120fps":@(TTVideoEngineResolutionType2K_120F),
                                  @"4k":@(TTVideoEngineResolutionType4K),
                                  @"4k 50fps":@(TTVideoEngineResolutionType4K_50F),
                                  @"4k 60fps":@(TTVideoEngineResolutionType4K_60F),
                                  @"4k 120fps":@(TTVideoEngineResolutionType4K_120F),
                                  };
    });
    return s_video_resolution_map;
}

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 获取音频档位+描述
 */
/**
 * @locale en
 * @hidden
 * @type keytype
 * @brief Default audio resolution map.
 */
NS_INLINE NSDictionary *TTVideoEngineDefaultAudioResolutionMap(void) {
    static dispatch_once_t onceToken;
    static NSDictionary *s_audio_resolution_map = nil;
    dispatch_once(&onceToken, ^{
        s_audio_resolution_map = @{
                                   @"medium":@(TTVideoEngineResolutionTypeSD),
                                   @"higher":@(TTVideoEngineResolutionTypeHD),
                                   @"highest":@(TTVideoEngineResolutionTypeFullHD),
                                   @"original":@(TTVideoEngineResolutionType1080P),
                                   @"lossless":@(TTVideoEngineResolutionType4K),
                                   };
    });
    return s_audio_resolution_map;
}

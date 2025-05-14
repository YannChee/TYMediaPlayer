//
//  TTVideoEnginePublicEnum.h
//  TTVideoEngine
//
//  Created by 黄清 on 2019/7/22.
//

#ifndef TTVideoEnginePublicEnum_h
#define TTVideoEnginePublicEnum_h

#import <Foundation/Foundation.h>

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 播放器内核类型
 */
/**
 * @locale en
 * @type keytype
 * @brief Player Core Type
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEnginePlayerType) {
    TTVideoEnginePlayerTypeSystem       = 0,
    TTVideoEnginePlayerTypeVanGuard     = 1,
    TTVideoEnginePlayerTypeRearGuard    = 2,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief playback state。
 */
typedef NS_ENUM(NSInteger, TTVideoEnginePlaybackState) {
    /**
     * @locale zh
     * @brief 播放停止。
     */
    /**
     * @locale en
     * @brief stop
     */
    TTVideoEnginePlaybackStateStopped,
    /**
     * @locale zh
     * @brief 播放中。
     */
    /**
     * @locale en
     * @brief playing
     */
    TTVideoEnginePlaybackStatePlaying,
    /**
     * @locale zh
     * @brief 播放暂停。
     */
    /**
     * @locale en
     * @brief pause
     */
    TTVideoEnginePlaybackStatePaused,
    /**
     * @locale zh
     * @brief 播放错误。
     */
    /**
     * @locale en
     * @brief error
     */
    TTVideoEnginePlaybackStateError,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器加载状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player loading status.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineLoadState) {
    /**
     * @locale zh
     * @brief 播放器加载初始状态。
     */
    /**
     * @locale en
     * @brief The player loads the initial state.
     */
    TTVideoEngineLoadStateUnknown        = 0,
    /**
     * @locale zh
     * @brief 播放器加载完成，可开始或恢复播放。
     */
    /**
     * @locale en
     * @brief load finish
     */
    TTVideoEngineLoadStatePlayable,
    /**
     * @locale zh
     * @brief 播放器发生卡顿，正在加载数据。
     */
    /**
     * @locale en
     * @brief The player is experiencing a lag and is currently loading data.
     */
    TTVideoEngineLoadStateStalled,
    /**
     * @locale zh
     * @brief 播放器加载数据错误。
     */
    /**
     * @locale en
     * @brief Player failed to load data.
     */
    TTVideoEngineLoadStateError,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器卡顿原因。
 */
/**
 * @locale en
 * @type keytype
 * @brief the reason of engine stall
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineStallReason) {
    /**
     * @locale zh
     * @brief 默认值。
     */
    /**
     * @locale en
     * @brief default
     */
    TTVideoEngineStallReasonNone        = 0,
    /**
     * @locale zh
     * @brief 播放器因为网络原因导致卡顿。
     */
    /**
     * @locale en
     * @brief network
     */
    TTVideoEngineStallReasonNetwork     = 1,
    /**
     * @locale zh
     * @brief 播放器因为解码器异常导致卡顿。
     */
    /**
     * @locale en
     * @brief decoder
     */
    TTVideoEngineStallReasonDecoder     = 2,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief AV Outsync type
 */
/**
 * @locale en
 * @type keytype
 * @brief AV Outsync type
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineAVOutsyncType) {
    TTVideoEngineAVOutsyncTypeStart,
    TTVideoEngineAVOutsyncTypeEnd,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief NOVARenderStateType
 */
/**
 * @locale en
 * @type keytype
 * @brief NOVARenderStateType
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineNOVARenderStateType) {
    TTVideoEngineNOVARenderStateTypeStart,
    TTVideoEngineNOVARenderStateTypeEnd,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief drm type
 */
/**
 * @locale en
 * @type keytype
 * @brief drm type
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineDrmType) {
    TTVideoEngineDrmNone,
    TTVideoEngineDrmIntertrust,
    TTVideoEngineDrmFairPlay,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放结束原因。
 */
/**
 * @locale en
 * @type keytype
 * @brief Reason for end of playback.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineFinishReason) {
    /**
     * @locale zh
     * @brief 用户主动退出播放。
     */
   /**
    * @locale en
    * @brief The user actively stopped the playback.
    */
    TTVideoEngineFinishReasonUserExited,
    /**
     * @locale zh
     * @brief 播放器被释放。
     */
   /**
    * @locale en
    * @brief The player has been released.
    */
    TTVideoEngineFinishReasonRelease,
    /**
     * @locale zh
     * @brief 播放器被异步释放。
     */
   /**
    * @locale en
    * @brief The player is released asynchronously.
    */
    TTVideoEngineFinishReasondReleaseAsync,
    /**
     * @locale zh
     * @brief 播放器正常播放完成。
     */
   /**
    * @locale en
    * @brief The player has finished playing normally.
    */
    TTVideoEngineFinishReasonPlaybackEnded,
    /**
     * @locale zh
     * @brief 播放器发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred in the player.
    */
    TTVideoEngineFinishReasonPlaybackError,
    /**
     * @locale zh
     * @brief 播放器发生异常。
     */
   /**
    * @locale en
    * @brief An exception occurred in the player.
    */
    TTVideoEngineFinishReasonStatusExcp,
    /**
     * @locale zh
     * @brief 播放器重置。
     */
   /**
    * @locale en
    * @brief Reset the player.
    */
    TTVideoEngineFinishReasonReset,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器旋转角度。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player rotation angle.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineRotateType) {
    /**
     * @locale zh
     * @brief 无旋转。
     */
   /**
    * @locale en
    * @brief No rotation.
    */
    TTVideoEngineRotateTypeNone = 0,
    /**
     * @locale zh
     * @brief 90 度旋转。
     */
   /**
    * @locale en
    * @brief Rotate 90 degrees.
    */
    TTVideoEngineRotateType90   = 1,
    /**
     * @locale zh
     * @brief 180 度旋转。
     */
   /**
    * @locale en
    * @brief Rotate 180 degrees.
    */
    TTVideoEngineRotateType180  = 2,
    /**
     * @locale zh
     * @brief 270 度旋转。
     */
   /**
    * @locale en
    * @brief 270-degree rotation.
    */
    TTVideoEngineRotateType270  = 3,
};

/**
 * @locale zh
 * @type keytype
 * @brief 镜像模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief Mirror mode.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineMirrorType) {
    /**
     * @locale zh
     * @brief 无镜像。
     */
   /**
    * @locale en
    * @brief No mirroring.
    */
    TTVideoEngineMirrorTypeNone       = 0,
    /**
     * @locale zh
     * @brief 水平镜像。
     */
   /**
    * @locale en
    * @brief Horizontal mirroring.
    */
    TTVideoEngineMirrorTypeHorizontal = 1,
    /**
     * @locale zh
     * @brief 垂直镜像。
     */
   /**
    * @locale en
    * @brief Vertical mirroring.
    */
    TTVideoEngineMirrorTypeVertical   = 2,
    /**
     * @locale zh
     * @brief 同时开启水平镜像和垂直镜像。
     */
   /**
    * @locale en
    * @brief Enable both horizontal and vertical mirroring simultaneously.
    */
    TTVideoEngineMirrorTypeHV         = 3,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 播放器视图旋转角度。
 */
/**
 * @locale en
 * @type keytype
 * @brief Rotation angle of the player view.
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineImageRotationType) {
   /**
    * @locale zh
    * @brief 无旋转。
    */
   /**
    * @locale en
    * @brief No rotation.
    */
    TTVideoEngineImageRotationTypeNone = 0,
   /**
    * @locale zh
    * @brief 90 度旋转。
    */
   /**
    * @locale en
    * @brief Rotate 90 degrees.
    */
    TTVideoEngineImageRotationType90   = 90,
   /**
    * @locale zh
    * @brief 180 度旋转。
    */
   /**
    * @locale en
    * @brief Rotate 180 degrees.
    */
    TTVideoEngineImageRotationType180  = 180,
   /**
    * @locale zh
    * @brief 270 度旋转。
    */
   /**
    * @locale en
    * @brief Rotate 270 degrees.
    */
    TTVideoEngineImageRotationType270  = 270,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineTestSpeedMode
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineTestSpeedMode
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineTestSpeedMode) {
    TTVideoEngineTestSpeedModeDisable,
    TTVideoEngineTestSpeedModeOnce,
    TTVideoEngineTestSpeedModeContinue,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineImageScaleType
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineImageScaleType
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineImageScaleType) {
    TTVideoEngineImageScaleTypeLinear,
    TTVideoEngineImageScaleTypeLanczos,
    TTVideoEngineImageScaleTypeDefault = TTVideoEngineImageScaleTypeLinear,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineEnhancementType
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineEnhancementType
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineEnhancementType) {
    TTVideoEngineEnhancementTypeNone,
    TTVideoEngineEnhancementTypeContrast,
    TTVideoEngineEnhancementTypeDefault = TTVideoEngineEnhancementTypeNone,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineImageLayoutType
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineImageLayoutType
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineImageLayoutType) {
    TTVideoEngineLayoutTypeAspectFit,
    TTVideoEngineLayoutTypeToFill,
    TTVideoEngineLayoutTypeAspectFill
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器缩放模式。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player zoom mode.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineScalingMode) {
    /**
     * @locale zh
     * @brief 无拉伸，不会变形，可能有黑边。
     */
   /**
    * @locale en
    * @brief No stretching, no deformation, possible black edges.
    */
    TTVideoEngineScalingModeNone,
    /**
     * @locale zh
     * @brief 按照视频宽高等比适配画面，不会变形，可能有黑边。
     */
   /**
    * @locale en
    * @brief Adapt the screen according to the video aspect ratio. It will not be distorted, but black borders may appear.
    */
    TTVideoEngineScalingModeAspectFit,
    /**
     * @locale zh
     * @brief 按照视频宽高等比填充画面，不会变形，可能有画面裁剪。
     */
   /**
    * @locale en
    * @brief Fill the frame according to the video's aspect ratio without distortion; some parts of the video may be cropped.
    */
    TTVideoEngineScalingModeAspectFill,
    /**
     * @locale zh
     * @brief 拉伸填充，视频宽高比例与画面比例不一致，可能会导致画面变形。
     */
    TTVideoEngineScalingModeFill
/**
 * @locale en
 * @brief Stretch filling, when the video aspect ratio is inconsistent with the screen ratio, may cause image distortion.
 */
};

/**
 * @locale zh
 * @type keytype
 * @brief 音频左右声道。
 */
/**
 * @locale en
 * @type keytype
 * @brief invalid in audio channel for mono
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineAudioChannelType) {
    /**
     * @locale zh
     * @brief 默认双声道。
     */
   /**
    * @locale en
    * @brief Default stereo sound.
    */
    TTVideoEngineAudioChannelNormal             = 0,
    /**
     * @locale zh
     * @brief 关闭右声道。
     */
   /**
    * @locale en
    * @brief Turn off the right channel.
    */
    TTVideoEngineAudioChannelRightDisable       = 1,
    /**
     * @locale zh
     * @brief 关闭左声道。
     */
   /**
    * @locale en
    * @brief Close the left channel.
    */
    TTVideoEngineAudioChannelLeftDisable        = 2,
    /**
     * @locale zh
     * @brief 使用左声道数据播放左右声道。
     */
   /**
    * @locale en
    * @brief Use left channel data to play both left and right channels.
    */
    TTVideoEngineAudioChannelLeftUesdForLR      = 3,
    /**
     * @locale zh
     * @brief 使用右声道数据播放左右声道。
     */
   /**
    * @locale en
    * @brief Use the right channel data to play both the left and right channels.
    */
    TTVideoEngineAudioChannelRightUesdForLR     = 4,
};

/**
 * @locale zh
 * @type keytype
 * @brief Seek 类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Seek type.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineSeekModeType) {
    /**
     * @locale zh
     * @brief 精准 Seek。
     */
   /**
    * @locale en
    * @brief Precise Seek.
    */
    TTVideoEngineSeekModeAccurateAny             = 0,
    /**
     * @locale zh
     * @brief 非精准 Seek，有助于提升起播速度。
     */
   /**
    * @locale en
    * @brief Non-precise Seek can help improve startup speed.
    */
    TTVideoEngineSeekModeInAccurateBackWard      = 1,
};

/**
 * @locale zh
 * @type keytype
 * @brief 音频效果。
 */
/**
 * @locale en
 * @type keytype
 * @brief Audio effects.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineAudioEffectType) {
    /**
     * @locale zh
     * @hidden
     */
    /**
     * @locale en
     * @hidden
     */
    TTVideoEngineAudioEffectCompressor          = 0,
    /**
     * @locale zh
     * @hidden
     */
    /**
     * @locale en
     * @hidden
     */
    TTVideoEngineAudioEffectClimiter            = 1,
    /**
     * @locale zh
     * @hidden
     */
    /**
     * @locale en
     * @hidden
     */
    TTVideoEngineAudioEffectCompressor2         = 2,
    /**
     * @locale zh
     * @hidden
     */
    /**
     * @locale en
     * @hidden
     */
    TTVideoEngineAudioEffectOnlineLoudNorm      = 3,
    /**
     * @locale zh
     * @brief 音量均衡。
     */
   /**
    * @locale en
    * @brief Volume normalization.
    */
    TTVideoEngineAudioEffectRTCLoudNorm         = 4,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 */
/**
 * @locale en
 * @type keytype
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineAlignMode) {
    TTVideoEngineAlignModeCenter = 0,
    TTVideoEngineAlignModeLeftTop = 1,
    TTVideoEngineAlignModeLeftCenter = 2,
    TTVideoEngineAlignModeLeftBottom = 3,
    TTVideoEngineAlignModeTopCenter = 4,
    TTVideoEngineAlignModeBottomCenter = 5,
    TTVideoEngineAlignModeRightTop = 6,
    TTVideoEngineAlignModeRightCenter = 7,
    TTVideoEngineAlignModeRightBottom = 8,
    TTVideoEngineAlignModeSelfDefineRatio = 9,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 渲染类型
 */
/**
 * @locale en
 * @type keytype
 * @brief Render Type
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineRenderType) {
    TTVideoEngineRenderTypePlane,
    TTVideoEngineRenderTypePano,
    TTVideoEngineRenderTypeVR,
    TTVideoEngineRenderTypeDefault,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频渲染方式。
 */
/**
 * @locale en
 * @type keytype
 * @brief Video rendering methods.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineRenderEngine) {
    /**
     * @locale zh
     * @brief OpenGLES 渲染。
     */
   /**
    * @locale en
    * @brief Render with OpenGLES.
    */
    TTVideoEngineRenderEngineOpenGLES,
    /**
     * @locale zh
     * @brief Metal 渲染。
     */
   /**
    * @locale en
    * @brief Metal Rendering.
    */
    TTVideoEngineRenderEngineMetal,
    /**
     * @locale zh
     * @brief 业务外部渲染，不使用 SDK 渲染。
     */
   /**
    * @locale en
    * @brief External business rendering, not using SDK rendering.
    */
    TTVideoEngineRenderEngineOutput,
    /**
     * @locale zh
     * @hidden
     * @brief SBD
     */
   /**
    * @locale en
    * @brief SBD
    * @hidden (iOS)
    */
    TTVideoEngineRenderEngineSBDLayer,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 视频渲染方式
 */
/**
 * @locale en
 * @type keytype
 * @brief Video Rendering Method
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineAudioDeviceType) {
    TTVideoEngineDeviceAudioUnit,
    TTVideoEngineDeviceAudioGraph,
    TTVideoEngineDeviceExternVoice = 4,
    TTVideoEngineDeviceDefault = TTVideoEngineDeviceAudioUnit,
    TTVideoEngineDeviceDummyAudio = 10,
    TTVideoEngineDeviceHookedDummy = 20,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器状态。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player status.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineState) {
    /**
     * @locale zh
     * @type keytype
     * @brief 初始状态。
     */
   /**
    * @locale en
    * @brief Initial state.
    */
    TTVideoEngineStateUnknown = 0,
    /**
     * @locale zh
     * @type keytype
     * @brief 使用 Vid 模式播放，正在获取播放信息。
     */
   /**
    * @locale en
    * @brief Playing in Vid mode, fetching playback information.
    */
    TTVideoEngineStateFetchingInfo,
    /**
     * @locale zh
     * @type keytype
     * @brief 播放器正在进行 DNS 解析。
     */
   /**
    * @locale en
    * @brief The player is performing DNS resolution.
    */
    TTVideoEngineStateParsingDNS,
    /**
     * @locale zh
     * @type keytype
     * @brief 播放器正常播放中。
     */
   /**
    * @locale en
    * @brief The player is playing normally.
    */
    TTVideoEngineStatePlayerRunning,
    /**
     * @locale zh
     * @type keytype
     * @brief 播放器运行发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred during player operation.
    */
    TTVideoEngineStateError,
};

/**
 * @locale zh
 * @type keytype
 * @brief 网络类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Network type.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineNetworkType) {
    /**
     * @locale zh
     * @brief 使用 WiFi。
     */
   /**
    * @locale en
    * @brief Use WiFi.
    */
    TTVideoEngineNetworkTypeWifi,
    /**
     * @locale zh
     * @brief 使用非 WiFi。
     */
   /**
    * @locale en
    * @brief Use non-WiFi.
    */
    TTVideoEngineNetworkTypeNotWifi,
    /**
     * @locale zh
     * @brief 未知状态。
     */
   /**
    * @locale en
    * @brief Unknown state.
    */
    TTVideoEngineNetworkTypeNone,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEnginePlayAPIVersion
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEnginePlayAPIVersion
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEnginePlayAPIVersion) {
    TTVideoEnginePlayAPIVersion0 = 0,
    TTVideoEnginePlayAPIVersion1 = 1,
    TTVideoEnginePlayAPIVersion2 = 2,//open api 1.0
    TTVideoEnginePlayAPIVersion3 = 3,//STS
    TTVideoEnginePlayAPIVersion4 = 4,//open api 2.0
};

/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief TTVideoEngineVideoModelVersion
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineVideoModelVersion
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineVideoModelVersion) {
    TTVideoEngineVideoModelVersion0 = 0,
    TTVideoEngineVideoModelVersion1 = 1,
    TTVideoEngineVideoModelVersion2 = 2,
    TTVideoEngineVideoModelVersion3 = 3,
    TTVideoEngineVideoModelVersion4 = 4,
};

/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief TTVideoEnginePlaySourceType
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEnginePlaySourceType
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEnginePlaySourceType) {
    TTVideoEnginePlaySourceTypeUnknown      = -1,
    TTVideoEnginePlaySourceTypeLocalUrl     = 0,
    TTVideoEnginePlaySourceTypeDirectUrl    = 1,
    TTVideoEnginePlaySourceTypePlayitem     = 2,
    TTVideoEnginePlaySourceTypePreloaditem  = 3,
    TTVideoEnginePlaySourceTypeFeed         = 4,
    TTVideoEnginePlaySourceTypeVid          = 5,
    TTVideoEnginePlaySourceTypeModel        = 6,
    TTVideoEnginePlaySourceTypeFileDescriptor = 7,
};

/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief TTVideoEnginePrelaodStrategy
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEnginePreloadStrategy
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEnginePrelaodStrategy) {
    TTVideoEnginePrelaodAllowPreload                = 0, /// Default
    TTVideoEnginePrelaodNotAllowPlayKeyPrelaod      = 1,
    TTVideoEnginePrelaodNotAllowPreload             = 2,
    TTVideoEnginePrelaodNewStrategy                 = 100,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频数据加载错误。
 */
/**
 * @locale en
 * @type keytype
 * @brief Error loading video data.
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineDataLoaderErrorType) {
    /**
     * @locale zh
     * @brief 默认值。
     */
   /**
    * @locale en
    * @brief Default value.
    */
    TTVideoEngineDataLoaderErrorNone,
    /**
     * @locale zh
     * @brief 获取视频信息时发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred while fetching video information.
    */
    TTVideoEngineDataLoaderErrorFetchVideoInfo,
    /**
     * @locale zh
     * @brief 启动数据加载模块时发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred while initializing the data loading module.
    */
    TTVideoEngineDataLoaderErrorStart,
    /**
     * @locale zh
     * @brief 下载数据时发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred while downloading the data.
    */
    TTVideoEngineDataLoaderErrorFetchData,
    /**
     * @locale zh
     * @brief 写数据时发生错误。
     */
   /**
    * @locale en
    * @brief An error occurred while writing data.
    */
    TTVideoEngineDataLoaderErrorWriteFile,
};

/**
 * @locale zh
 * @hidden for internal use only
 * @type keytype
 * @brief 解码后输出数据类型
 */
/**
 * @locale en
 * @type keytype
 * @brief Decoded Output Data Type
 * @hidden 
 */
typedef NS_ENUM(NSUInteger, TTVideoEngineDecoderOutputType) {
    TTVideoEngineDecoderOutputYUV,
    TTVideoEngineDecoderOutputRGB,
};

/**
 * @locale zh
 * @type keytype
 * @brief 播放器输出日志模块。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player Output Log Module.
 */
typedef NS_OPTIONS(NSInteger, TTVideoEngineLogFlag) {
    /**
     * @locale zh
     * @brief 不输出日志。
     */
   /**
    * @locale en
    * @brief Do not output logs.
    */
    TTVideoEngineLogFlagNone           = 0,
    /**
     * @locale zh
     * @brief 输出 Engine 日志。
     */
   /**
    * @locale en
    * @brief Output Engine logs.
    */
    TTVideoEngineLogFlagEngine         = 1 << 0,
    /**
     * @locale zh
     * @brief 输出播放内核日志。
     */
   /**
    * @locale en
    * @brief Output the playback kernel log.
    */
    TTVideoEngineLogFlagPlayer         = 1 << 1,
    /**
     * @locale zh
     * @brief 输出数据加载模块日志。
     */
   /**
    * @locale en
    * @brief Output data loading module logs.
    */
    TTVideoEngineLogFlagMDL            = 1 << 2,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
    /**
     * @locale en
     * @hidden
     * @brief Alog logs, used for internal versions
     */
    TTVideoEngineLogFlagAlogEngine     = 1 << 3,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
   /**
    * @locale en
    * @hidden
    * @brief Alog logs, for internal versions use
    */
    TTVideoEngineLogFlagAlogPlayer     = 1 << 4,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
   /**
    * @locale en
    * @hidden
    * @brief Alog log, for internal use
    */
    TTVideoEngineLogFlagAlogMDL        = 1 << 5,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
   /**
    * @locale en
    * @hidden
    * @brief Alog logs, for internal version use
    */
    TTVideoEngineLogFlagAlogPlayerAll  = 1 << 6,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
   /**
    * @locale en
    * @hidden
    * @brief Alog logs, for internal versions
    */
    TTVideoEngineLogFlagPlaylistCacheModule = 1 << 7,
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
   /**
    * @locale en
    * @hidden
    * @brief Alog logs, for internal version use
    */
    TTVideoEngineLogFlagAlogPlaylistCacheModule = 1 << 8,
    /**
     * @locale zh
     * @brief 输出 Engine、内核、数据加载模块日志。
     */
    /**
    * @locale en
    * @brief Output logs for Engine, Kernel, and Data Loading Module.
    */
    TTVideoEngineLogFlagDefault        = (TTVideoEngineLogFlagAlogEngine |
                                          TTVideoEngineLogFlagAlogMDL |
                                          TTVideoEngineLogFlagAlogPlayer |
                                          TTVideoEngineLogFlagAlogPlaylistCacheModule),
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
    /**
    * @locale en
    * @hidden
    * @brief Alog logs, for internal version use only
    */
    TTVideoEngineLogFlagPrint          = (TTVideoEngineLogFlagEngine |
                                          TTVideoEngineLogFlagPlayer |
                                          TTVideoEngineLogFlagMDL |
                                          TTVideoEngineLogFlagPlaylistCacheModule),
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
    /**
     * @locale en
     * @hidden
     * @brief Alog log, internal version usage
     */
    TTVideoEngineLogFlagAlog           = (TTVideoEngineLogFlagAlogEngine |
                                          TTVideoEngineLogFlagAlogPlayer |
                                          TTVideoEngineLogFlagAlogMDL |
                                          TTVideoEngineLogFlagAlogPlayerAll |
                                          TTVideoEngineLogFlagAlogPlaylistCacheModule),
    /**
     * @locale zh
     * @hidden
     * @brief Alog日志，内部版本使用
     */
    /**
     * @locale en
     * @hidden
     * @brief Alog logs, for internal use only
     */
    TTVideoEngineLogFlagAll            = (TTVideoEngineLogFlagEngine |
                                          TTVideoEngineLogFlagPlayer |
                                          TTVideoEngineLogFlagMDL |
                                          TTVideoEngineLogFlagPlaylistCacheModule |
                                          TTVideoEngineLogFlagAlogEngine |
                                          TTVideoEngineLogFlagAlogPlayer |
                                          TTVideoEngineLogFlagAlogMDL |
                                          TTVideoEngineLogFlagAlogPlayerAll |
                                          TTVideoEngineLogFlagAlogPlaylistCacheModule),
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineThreadSafeRefFlag
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineThreadSafeRefFlag
 * @hidden 
 */
typedef NS_OPTIONS(NSInteger, TTVideoEngineThreadSafeRefFlag) {
    TTVideoEngineThreadSafeRefFlagNone           = 0,
    TTVideoEngineThreadSafeRefFlagAudio          = 1 << 0, //enable audio_outlet thread-safe ref
    TTVideoEngineThreadSafeRefFlagALL            = TTVideoEngineThreadSafeRefFlagAudio
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 控制 mp4 / dash 是否允许使用 bash 协议 eg:允许 dash 使用 bash: TTVideoEngineDashSegmentFlagFormatFMP4，允许 mp4 使用 bash: TTVideoEngineDashSegmentFlagFormatMp4
 */
/**
 * @locale en
 * @type keytype
 * @brief Control whether mp4/dash is allowed to use the bash protocol, e.g., allow dash to use bash: TTVideoEngineDashSegmentFlagFormatFMP4, allow mp4 to use bash: TTVideoEngineDashSegmentFlagFormatMp4
 * @hidden 
 */
typedef NS_OPTIONS(NSInteger, TTVideoEngineDashSegmentFlag) {
    TTVideoEngineDashSegmentFlagUnkown = 0,
    TTVideoEngineDashSegmentFlagFormatFMP4 = 1 << 0,
    TTVideoEngineDashSegmentFlagFormatMp4 = 1 << 1,
    
    
    TTVideoEngineDashSegmentFlagFormatAll = (TTVideoEngineDashSegmentFlagFormatMp4 | TTVideoEngineDashSegmentFlagFormatFMP4),
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineDashABRSwitchMode
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineDashABRSwitchMode
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineDashABRSwitchMode) {
    TTVideoEngineDashABRSwitchAuto = 0,
    TTVideoEngineDashABRSwitchUser = 1
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineNormalClockType
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineNormalClockType
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineNormalClockType) {
    TTVideoEngineClockTypeDefault = 1,
    TTVideoEngineClockTypePrevFallback = 2,
    TTVideoEngineClockTypeFFPlay = 3
};

/**
 * @locale zh
 * @type keytype
 * @brief 导致播放器发生卡顿的具体动作。
 */
/**
 * @locale en
 * @type keytype
 * @brief Specific actions that cause the player to stutter.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineStallAction) {
    /**
     * @locale zh
     * @brief 默认值。
     */
   /**
    * @locale en
    * @brief Default value.
    */
    TTVideoEngineStallActionNone        = 0,
    /**
     * @locale zh
     * @brief 用户 seek。
     */
   /**
    * @locale en
    * @brief The user performs a seek.
    */
    TTVideoEngineStallActionSeek        = 1,
    /**
     * @locale zh
     * @brief 切换分辨率。
     */
   /**
    * @locale en
    * @brief Switch resolution.
    */
    TTVideoEngineStallActionSwitch      = 2,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频流类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Video stream type.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineStreamType) {
    /**
     * @locale zh
     * @brief 视频流。
     */
   /**
    * @locale en
    * @brief Video stream.
    */
    TTVideoEngineVideoStream = 0,
    /**
     * @locale zh
     * @brief 音频流。
     */
   /**
    * @locale en
    * @brief Audio stream.
    */
    TTVideoEngineAudioStream = 1,
};

/**
 * @locale zh
 * @type keytype
 * @brief 视频编码类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Video encoding type.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineEncodeType) {
    /**
     * @locale zh
     * @brief H.264
     */
   /**
    * @locale en
    * @brief H.264
    */
    TTVideoEngineH264    =  0,
    /**
     * @locale zh
     * @brief H.265
     */
    TTVideoEngineh265 =  3,
    /**
     * @locale zh
     * @hidden
     * @brief H.266
     */
   /**
    * @locale en
    * @brief H.266
    * @hidden (iOS)
    */
    TTVideoEngineh266 =  4,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief 播放器编解码策略类型。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player codec strategy type.
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineCodecStrategy) {
   /**
    * @locale zh
    * @type keytype
    * @brief 默认行为
    */
   /**
    * @locale en
    * @brief Default Behavior
    */
    TTVideoEngineCodecStrategyUnspecified = 0,
   /**
    * @locale zh
    * @type keytype
    * @brief 硬解优先。如果同时设置 H.264 和 H.265 视频源，播放器行为如下：<br>
    *        - 如果设备支持 H.265，优先 H.265 播放。 <br>
    *        - 如果设备不支持 H.265 硬解，优先选择使用 H.264 硬解。
    */
   /**
    * @locale en
    * @brief Hardware decoding is prioritized. If both H.264 and H.265 video sources are set, the player behaves as follows:<br>
    *        - If the device supports H.265, H.265 playback is prioritized.<br>
    *        - If the device does not support H.265 hardware decoding, H.264 hardware decoding is prioritized.
    */
    TTVideoEngineCodecStrategyHardwareDecodeFirst = 1,
   /**
    * @locale zh
    * @type keytype
    * @brief 成本优先。如果同时设置 H.264 和 H.265 视频源，播放器会优先播放 H.265。如果设备不支持 H.265 播放，再播放 H.264。
    */
   /**
    * @locale en
    * @brief Cost-first approach. If both H.264 and H.265 video sources are set, the player will prioritize playing H.265. If the device does not support H.265 playback, H.264 will be played instead.
    */
    TTVideoEngineCodecStrategyLowDataCostFirst = 2,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEnginePostPrepareWay
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEnginePostPrepareWay
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEnginePostPrepareWay) {
    TTVideoEnginePostPrepareInEngine = 0,
    TTVideoEnginePostPrepareInKernal = 1,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEnginePostPrepareCallStartMoment
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEnginePostPrepareCallStartMoment
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEnginePostPrepareCallStartMoment) {
    TTVideoEnginePostPrepareCallStartMomentAfterPrepared = 0,
    TTVideoEnginePostPrepareCallStartMomentAfterOpened = 1,
};
    
/**
 * @locale zh
 * @hidden
 * @type keytype
 * @brief TTVideoEngineVideoModelPriority
 */
/**
 * @locale en
 * @type keytype
 * @brief TTVideoEngineVideoModelPriority
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineVideoModelPriority) {
    TTVideoEngineVideoModelUseRemote,
    TTVideoEngineVideoModelUseLocal
};

/**
 * @locale zh
 * @hidden
 */
FOUNDATION_EXPORT NSString *const TTVideoEngineBufferStartAction;
/**
 * @locale zh
 * @hidden
 */
FOUNDATION_EXPORT NSString *const TTVideoEngineBufferStartReason;

/**
 * @locale zh
 * @type keytype
 * @brief 用户控制播放器动作。
 */
/**
 * @locale en
 * @type keytype
 * @brief The user controls the player actions.
 */
typedef NS_ENUM(NSInteger, TTVideoEngineUserAction) {
   /**
    * @locale zh
    * @brief 初始化播放器。
    */
   /**
    * @locale en
    * @brief Initialize the player.
    */
    TTVideoEngineUserActionInit     = 0,
   /**
    * @locale zh
    * @brief 调用 `prepare`。
    */
   /**
    * @locale en
    * @brief Call `prepare`.
    */
    TTVideoEngineUserActionPrepare  = 1,
    /**
     * @locale zh
     * @brief 调用 `play`。
     */
   /**
    * @locale en
    * @brief Call `play`.
    */
    TTVideoEngineUserActionPlay     = 2,
    /**
     * @locale zh
     * @brief 调用 `pause`。
     */
   /**
    * @locale en
    * @brief Call `pause`.
    */
    TTVideoEngineUserActionPause    = 3,
    /**
     * @locale zh
     * @brief 调用 `stop`。
     */
   /**
    * @locale en
    * @brief Call `stop`.
    */
    TTVideoEngineUserActionStop     = 4,
    /**
     * @locale zh
     * @brief 调用 `close`。
     */
   /**
    * @locale en
    * @brief Call `close`.
    */
    TTVideoEngineUserActionClose    = 5,
};

/**
 * @locale zh
 * @hidden
 * @type keytype
 */
/**
 * @locale en
 * @type keytype
 * @hidden 
 */
typedef NS_ENUM(NSInteger, TTVideoEngineVolumeFadeMode) {
    TTVideoEngineVolumeFadeModeDisable  = 0,
    TTVideoEngineVolumeFadeModeFadeIn   = 1,
    TTVideoEngineVolumeFadeModeFadeOut  = 2,
};

#endif

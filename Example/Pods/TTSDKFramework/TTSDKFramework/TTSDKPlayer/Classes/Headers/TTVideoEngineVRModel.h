//
//  TTVideoEngineVRModel.h
//  TTVideoEngine
//
//  Created by shen chen on 2022/7/26.
//

#ifndef ttvideoengine_model_h
#define ttvideoengine_model_h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern int const kTTVideoEngineVideoProcessingProcessorActionInitEffect;
extern int const kTTVideoEngineVideoProcessingProcessorActionUseEffect;
extern int const kTTVideoEngineVideoProcessingProcessorActionVRConfiguration;
extern int const kTTVideoEngineVideoProcessingProcessorActionVRRecenter;

extern int const kTTVideoEngineVideoProcessingProcessorEffectTypeVR;

extern NSString * const kTTVideoEngineVideoProcessingProcessorAction;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVROutputTextureWidth;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVROutputTextureHeight;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRHeadTrackingEnabled;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRScopicType;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRRotationPitch;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRRotationYaw;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRRotationRoll;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRZoom;
extern NSString * const kTTVideoEngineVideoProcessingProcessorEffectType;
extern NSString * const kTTVideoEngineVideoProcessingProcessorUseEffect;
extern NSString * const kTTVideoEngineVideoProcessingProcessorIntValue;
extern NSString * const kTTVideoEngineEnableVRMode;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRContentType;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRFOVType;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRFOVAngle;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRProjectionType;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRExpand;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRZOffset;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVROffsetCubicPitch;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVROffsetCubicYaw;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRCMPFaceDimension;


extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPoseDidUpdateNotification;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPoseOrientationQuaternionX;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPoseOrientationQuaternionY;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPoseOrientationQuaternionZ;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPoseOrientationQuaternionW;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPosePositionX;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPosePositionY;
extern NSString * const kTTVideoEngineVideoProcessingProcessorHeadPosePositionZ;

extern NSString * const kTTVideoEngineVideoProcessingProcessorVREnableVsyncHelper;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRCustomizedVideoRenderingFrameRate;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRDisableZAxis;
extern NSString * const kTTVideoEngineVideoProcessingProcessotVRVRPostNotifiVRPoseInterval;
extern NSString * const kTTVideoEngineVideoProcessingProcessotVRFirstFrameOptimize;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRSpaceOrientationOptDisable;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRScopicMonoOnceDraw;
extern NSString * const kTTVideoEngineVideoProcessingProcessorVRTouchRotationInWorldCoord;

//tracker key
typedef NS_ENUM(NSInteger, TTVideoEngineVROptionKey) {
    TTVideoEngineVideoEnableVR = 0,
    TTVideoEngineVideoVRScopicType = 1,
    TTVideoEngineVideoVRHeadTrackEnable = 2,
    TTVideoEngineVideoVRZoom = 3,
    TTVideoEngineVideoVRContentType = 4,
    TTVideoEngineVideoVRFovType = 5,
    TTVideoEngineVideoVRDisableZAxis = 6,
    TTVideoEngineVideoVRProjectionType = 7,
    TTVideoEngineVideoVRExpand = 8,
    TTVideoEngineVideoVRZoffset = 9,
    TTVideoEngineVideoVROffsetCubicPitch = 10,
    TTVideoEngineVideoVROffsetCubicYaw = 11,
    TTVideoEngineVideoVRCmpFaceDimension = 12,
    TTVideoEngineVideoVRFovAngle = 13,
    TTVideoEngineVideoVREnableFirstFrameOpt = 14,
    TTVideoEngineVideoVRPostNotifyVRPoseInterval = 15,
    TTVideoEngineVideoVRSpaceOrientationOptDisable = 16,
    TTVideoEngineVideoVRScopicMonoOnceDraw = 17,
    TTVideoEngineVideoVRTouchRotationInWorldCoord = 18
};

typedef NS_ENUM(NSInteger, TTVideoEngineVRScopicType) {
    TTVideoEngineVRScopicTypeUnknow = -1,
    TTVideoEngineVRScopicTypeMono   = 0,
    TTVideoEngineVRScopicTypeStereo = 1,
};

typedef NS_ENUM(NSInteger, TTVideoEngineVROption) {
    TTVideoEnginePlayerOptionEnableVsyncHelper = 0,
    TTVideoEnginePlayerOptionCustomizedVideoRenderingFrameRate = 1,
};

typedef NS_ENUM(NSInteger, TTVideoEngineVRContentType) {
    TTVideoEngineVRContentTypePano_2D,
    TTVideoEngineVRContentTypeSideBySide_3D,   // for 180 degrees video mostly
    TTVideoEngineVRContentTypeTopAndBottom_3D, // for 360 degrees video mostly
};

typedef NS_ENUM(NSInteger, TTVideoEngineVRFOV) {
    TTVideoEngineVRFOV_180,
    TTVideoEngineVRFOV_360,
};

typedef NS_ENUM(NSInteger, TTVideoEngineVRProjectionType) {
    TTVideoEngineVRSpaceTypeERP    = 0,
    TTVideoEngineVRSpaceTypeEAC    = 1,
    TTVideoEngineVRSpaceTypeCMP    = 2,
    TTVideoEngineVRSpaceTypeMESH   = 3,
    TTVideoEngineVRSpaceTypeCMPVod    = 4,
    TTVideoEngineVRSpaceTypeOffsetCubic = 5,
};

NS_ASSUME_NONNULL_END
#endif


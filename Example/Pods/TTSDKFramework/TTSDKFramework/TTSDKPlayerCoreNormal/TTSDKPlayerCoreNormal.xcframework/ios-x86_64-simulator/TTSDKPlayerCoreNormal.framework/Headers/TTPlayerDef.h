//
//  TTPlayerDef.h
//  bdm
//
//  Created by lzx on 11/6/16.
//
//

#ifndef TTM_DUAL_CORE_TTPLAYER_DEF_H
#define TTM_DUAL_CORE_TTPLAYER_DEF_H

typedef NS_ENUM(NSInteger ,ValuesForKey) {
    KeyIsDuration,
    KeyIsCurrentPosition,
    KeyIsVideoWidth,
    KeyIsVideoHeight,
    KeyIsLooping,
    KeyIsPlaying,
    KeyIsHttpReconnect,
    KeyIsHttpReconnectDelayMax,
    KeyIsHttpTimeOut,
    KeyIsPanoControlModel,
    KeyIsVideoType,
    KeyIsVolumeMute,
    KeyIsSyncMaster,
    KeyIsSaveFileModeType,
    KeyIsCacheFileMode,
    KeyIsHLSCLoadPerPercent,
    KeyIsMediaFileKey,
    KeyIsDecryptionKey,
    KeyIsHurryTime,
    KeyIsPlayType,
    KeyIsSettingCacheMaxSeconds,
    KeyIsDownloadBytes,
    KeyIsPlayBytes,
    KeyIsMediaFileSize,
    KeyIsPlayerDownloadSpeed,
    KeyIsUrlAddress,
    KeyIsImageEnhancementType,
    KeyIsVideoHardwareDecoderState,
    KeyIsImageScaleType,
    KeyIsImageLayout,
    KeyIsSmoothDelayedSec,
    KeyIsIgnorAudioInterruption,
    KeyIsMediaComment,
    KeyIsStartTime,
    KeyIsDecodeSEIInfo,
    KeyIsRenderType,
    KeyIsRenderDevice,
    KeyIsUsedKsyCodec,
    KeyIsPlaySpeed,
    KeyIsSaveHostTime,
    KeyIsTranConnectTime,
    KeyIsTranFirstPacketTime,
    KeyIsReceiveFirstVideoFrameTime,
    KeyIsReceiveFirstAudioFrameTime,
    KeyIsDecodeFirstVideoFrameTime,
    KeyIsDecodeFirstAudioFrameTime,
    KeyIsVideoBufferLength,
    KeyIsAudioBufferLength,
    KeyIsBufferingTimeOut,
    KeyIsPlaySpiltStream,
    KeyIsTestSpeed,
    KeyIsDefaultVideoBitrate,
    KeyIsDefaultAudioBitrate,
    KeyIsDisableAccurateStartTime,
    KeyIsExtraInfoCallBack,
    KeyIsMaxBufferEndTime,
    KeyIsFastOpenLiveStream,
    KeyIsEmbellishVolumeTime,
    KeyIsLoopStartTime,
    KeyIsLoopEndTime,
    KeyIsReuseSocket,
    KeyIsEnableDashABR,
    KeyIsAudioCodecId,
    KeyIsVideoCodecId,
    KeyIsMetaDataInfo,
    KeyIsVideoOutFPS,
    KeyIsCacheFileDir,
    KeyIsVideoId,
    KeyIsDrmType,
    KeyIsTokenUrlTemplate,
    KeyIsVideoBufferMilliSeconds,
    KeyIsAudioBufferMilliSeconds,
    KeyIsVTBOutputRGB,
    KeyIsAudioDevice,
    KeyIsABRProbeCount,
    KeyIsABRSwitchCount,
    KeyIsABRAverageBitrate,
    KeyIsABRAveragePlaySpeed,
    KeyIsABRHurryThreshold,
    KeyIsABRLowThreshold,
    KeyIsABRHighThreshold,
    KeyIsVideoCodecName,
    KeyIsAudioCodecName,
    KeyIsVideoCodecModName,
    KeyIsAudioCodecModName,
    KeyIsVideoBitrate,
    KeyIsMediaBitrate,
    KeyIsLiveStreamMaxCacheSeconds,
    KeyIsFileUrl,
    KeyIsLogInfoCallBack,
    KeyIsHurryType,
    KeyIsCatchupSpeed,
    KeyIsSlowPlayTime,
    KeyIsSlowPlaySpeed,
    KeyIsIgnoreVideoBufferring,
    KeyIsVideoDeviceOpenTime,
    KeyIsVideoDeviceOpenedTime,
    KeyIsAudioDeviceOpenTime,
    KeyIsAudioDeviceOpenedTime,
    KeyIsFirstFrameRenderedTime,
    KeyIsPlayerLogInfo,
    KeyIsKeepDecodingFreezeSize,
    KeyIsContainerFPS,
    KeyIsVideoCheckInfo,
    KeyIsAudioCheckInfo,
    KeyIsHijackCode,
    KeyIsSeekEndEnable,
    KeyIsGetVideoResolutionFromSPS,
    KeyIsByteVC1CodecType,              // deprecated
    KeyIsOutputFramesWaitNum,
    KeyIsFpsProbeSize,
    KeyIsEnableAudioEffect,
    KeyIsAudioEffectPregain,
    KeyIsAudioEffectThreshold,
    KeyIsAudioEffectRatio,
    KeyIsAudioEffectPredelay,
    KeyIsEnableAdaptedWatermark,
    KeyIsStartPlayAudioBufferThreshold,
    KeyIsBufferingEndIgnoreVideo,
    KeyIsVideoDecoderType,
    KeyIsAudioProcessWrapperPTR,
    KeyIsMirrorType,
    KeyIsHijackExit,
    KeyIsTimeBarPercentage,
    KeyIsEnterBufferingDirectly,
    KeyIsEnableIndexCache,
    KeyIsEnableFragRange,
    KeyIsVideoRangeSize,
    KeyIsAudioRangeSize,
    KeyIsSkipFindStreamInfo,
    KeyIsTTHlsDrmToken,
    KeyIsTTHlsDrm,
    KeyIsThreadWaitTimeMS,
    KeyIsAudioEffectPostgain,
    KeyIsVideoClcokDiffAve,
    KeyIsVideoClcokDiffMax,
    KeyIsVideoDecoderOutputFps,
    KeyIsAudioDeviceType,
    KeyIsAudioUnitPoolReachMax,
    KeyIsAVStartSync,
    KeyIsUseAudioPool,
    KeyIsCodecDropSikppedFrame,
    KeyIsEnableAsync,
    KeyIsRangeMode,
    KeyIsVideoRangeTime,
    KeyIsAudioRangeTime,
    KeyIsMediaFormatType,
    KeyIsRadioMode,
    KeyIsVideoSaveHostTime,
    KeyIsVideoTranConnectTime,
    KeyIsVideoTranFirstPacketTime,
    KeyIsAudioSaveHostTime,
    KeyIsAudioTranConnectTime,
    KeyIsAudioTranFirstPacketTime,
    KeyIsVideoSwitchCacheTime,
    KeyIsAudioSwitchCacheTime,
    KeyIsDummyAudioSleep,
    KeyIsReadMode,
    KeyIsVideoCurrentTime,
    KeyIsDefaultBufferEndTime,
    KeyIsMaxFps,
    KeyIsHandleAudioExtradata,
    KeyIsUpdateTimestampMode,
    KeyIsEnableOpenTimeout,
    KeyIsPrepareMaxCacheMs,
    KeyIsMDLCacheMode,
    KeyIsHttpAutoRangeOffset,
    KeyIsEnableVideoSR,
    KeyIsEnableVideoSRFPSThreshold,
    KeyIsVideoSRWidth,
    KeyIsVideoSRHeight,
    KeyIsVideoSRType,
    KeyIsSeekLazyInRead,
    KeyIsEnableRange,
    KeyIsAudioCodecProfile,
    KeyIsVideoCodecProfile,
    KeyIsNormalClockType,
    KeyIsEnableAllResolutionVideoSR,
    KeyIsVideoProcesser, // deprecated, since 2024-02-06
    KeyIsSkipBufferLimit,
    KeyIsLiveStartIndex,
    KeyIsEnableRefreshByTime,
    KeyIsEnableAVStack,
    KeyIsTerminalAudioUnitPool,
    KeyIsDynAudioLatencyByTime,
    KeyIsSettingVideoEndIsAllEof,
    KeyIsLoopCount,
    KeyIsEnableBufferingMilliSeconds,
    KeyIsDefaultBufferingEndMilliSeconds,
    KeyIsMaxBufferEndMilliSeconds,
    KeyIsDecreaseVtbStackSize,
    KeyIsEnableLoadControlBufferingTimeout,
    KeyIsPostPrepare,
    KeyIsDisableShortSeek,
    KeyIsVideoWrapperPTR,
    KeyIsPreferNearestSample,
    KeyIsPreferNearestMaxPosOffset,
    KeyIsQueueMaxFulled,
    KeyIsFindStreamInfoProbeSize,
    KeyIsFindStreamInfoProbeDuration,
    //notice that KeyIsFindStreamInfoProbeDuration is 199

    KeyIsDrmDowngrade = 200,
    KeyIsEnableFallbackSwDec,

    KeyIsHurryMillisecond,
    KeyIsSlowPlayMillisecond,
    
    KeyIsAVPtsDiffList,
    KeyIsVideoOutletDropCountOnce,
    KeyIsVideoDecoderOutputFpsList,
    KeyIsFrameDropCount,
    KeyIsColorTrc,
    KeyIsPixelFormat,
    KeyIsSocketRecvBufferSize,
    KeyIsEnableOutletDropLimit,
    KeyIsVideoStreamDuration,
    KeyIsAudioStreamDuration,
    KeyIsSetAudioInfoId,
    KeyIsSetVideoInfoId,
    KeyIsSetDefaultAudioInfoId,
    KeyIsSetDefaultVideoInfoId,
    KeyIsEnableDeinterlace,
    // notice: KeyIsEnableDeinterlace is 218
    KeyIsImageRotationType,
    KeyIsIosNewOutlet = 220,  //only for ios
    KeyIsMediaId = 221,
    KeyIsGetPlayerHolder = 222,
    KeyIsPreciseCache = 223,
    KeyIsAVOutsyncMaxAVDiff = 224,
    KeyIsClockDiff = 225,
    KeyIsClockResumeResetEof = 226,
    KeyIsColorSpace = 227,
    KeyIsColorPrimaries = 228,
    KeyIsRenderErrcWhenNoVRenderStart = 229,
    KeyIsAudioBitrate = 230,
    KeyIsMaxSamplePosBackDiff = 231,
    KeyIsEnableDemuxNonBlockRead = 232,
    KeyIsSetPrecisePausePts = 233,
    KeyIsSetFramesDrop = 234,
    KeyIsCustomizedVideoRenderingFrameRate = 235,
    KeyIsEnableVsyncHelper = 236,
    KeyIsStreamTrackInfo = 237,
    KeyIsAccumulateDownloadBytes = 238,
    KeyIsMinAudioFrameSize = 239,
    KeyIsMinVideoFrameSize = 240,
    KeyIsFeedInCountBeforeFirstDecode = 241,
    KeyIsPreloadGear = 242,
    KeyIsEnablePreloadGear = 243,
    KeyIsPlayerReqOffset = 244,
    KeyIsEnableReportFirstAVSyncFrame = 245,
    KeyIsBufferingThresholdSize = 246,
    KeyIsVideoCodec = 247,
    KeyIsAudioCodec = 248,
    KeyIsEnableUseMachTime = 249,

    //ABR相关 250~299
    KeyIsABRPredictVideoBitrate = 250,
    KeyIsABRDownloadVideoBitrate,
    KeyIsABRAverageBitrateDiff,
    KeyIsLiveAbrBitrate4UpCeiling,

    KeyIsAdvancedBufferringCheckEnabled = 300,
    KeyIsWaitedTimeAfterFirstFrame,
    KeyIsJXCodecErrorProtection,
    KeyIsEnableTcpFastOpen,
    KeyIsLastVideoRenderTime,
    KeyIsLastAudioRenderTime,
    KeyIsAudioRenderStallThreshold,
    KeyIsVideoRenderStallThreshold,
    KeyIsEnableRenderStall,
    KeyIsVideoCropInfo,
    KeyIsPacketDidReceiveCallback,
    KeyIsFrameDroppingTerminatedDTS,
    KeyIsFrameWillRenderCallback,
    KeyIsFrameDroppingDTSMaxDiff,
    KeyIsEnableCacheSei,
    KeyIsVideoDeviceWaitStartTime,
    KeyIsVideoDeviceWaitEndTime,
    KeyIsCheckSilenceInterval,
    KeyIsStreamFormat,
    KeyIsEnableFLVABR,
    KeyIsStartRenderIgnoreWindowSize,
    KeyIsVideoFrameWillProcessCallback,
    KeyIsPTSSyncedSEINotificationEnabled,
    KeyIsVideoAreaFramePattern,
    KeyIsVideoCropAreaFramePattern,
    KeyIsEnableStallCounter,
    KeyIsStallCounterInfoJson,
    KeyIsShouldSkipNextSRProcess,
    KeyIsPacketDidReceiveWithPacketInfoCallback,
    KeyIsOpenFailToTry,
    KeyIsEnableDecodeMultiSei,
    KeyIsEnableNotifySeiImmediatelyBeforeFirstFrame,
    KeyIsUseAudioGraphPool,
    KeyIsEnableDecodeSeiOnce,
    KeyIsEnableCmafFastMode,
    KeyIsEnableVideoMpdRefresh,
    KeyIsEnableSkipNullTag,     //336
    KeyIsEnableGetTimeOptimize, //337
    KeyIsDroppingDTSRollbackFrameEnabled,
    KeyIsIgnoreBackgroundRenderStallEnabled,
    KeyIsEnableFlushSeek,
    KeyIsBytevc1SwForbiden,
    KeyIsEnableNotifyCompletedImmediately,
    KeyIsLiveAbrOptimumStartupBiterateEnabled,  // 343
    KeyIsStartupDownloadSpeedInBitsPerSecond,   // 344
    KeyIsLiveAbrCurrentBitrate,                 // 345
    KeyIsResetInternalPlayerWhenReuse, //346   // Deprecated， 2024-06-25
    KeyIsPlaySpeedExtendEnable,  //347
    KeyIsEnableMasterM3u8Optimize = 348,
    KeyIsPlayerReadState,
    KeyIsGetProtocolType = 350,
    KeyIsQuicConfigCached,
    KeyIsQuicCHLOCount,
    
    KeyIsFormaterCreateTime,
    KeyIsDemuxerBeginTime,
    KeyIsDNSStartTime,
    KeyIsAudioDNSStartTime,
    KeyIsAVFormatOpenTime,
    KeyIsDemuxerCreateTime,
    KeyIsDecCreateTime,
    KeyIsOutletCreateTime,
    KeyIsAudioRendFirstFrameTime,
    KeyIsVideoDecoderStartTime,
    KeyIsVideoDecoderOpenedTime,
    KeyIsAudioDecoderStartTime,
    KeyIsAudioDecoderOpenedTime,
    KeyIsVideoTrackEnable,
    KeyIsAudioTrackEnable,
    KeyIsMoovPosition,
    KeyIsMdatPosition,
    KeyIsMaxAVPosGap,
    KeyIsVideoDecoderBufferLen,
    KeyIsAudioDecoderBufferLen,
    KeyIsVideoBasePlayerBufferLen,
    KeyIsAudioBasePlayerBufferLen,
    KeyIsBufsWhenBufferStart,
    KeyIsQuicSCFGAddress,
    KeyIsQuicCertVerify,
    KeyIsQuicOpenResult,//notice that KeyIsQuicOpenResult is 378
    KeyIsFileFormat,
    KeyIsQuicInitMTU,
    KeyIsQuicMtuDiscovery,
    KeyIsQuicInitRtt,                           // 382
    KeyIsQuicMaxCryptoRetransmissions,
    KeyIsQuicMaxCryptoRetransmissionTimeMs,
    KeyIsQuicMaxRetransmissions,
    KeyIsQuicMaxRetransmissionTimeMs,
    KeyIsQuicMaxAckDelay,
    KeyIsQuicMinReceivedBeforeAckDecimation,
    KeyIsQuicPadHello, // 389
    KeyIsQuicFixWillingAndAbleToWrite,
    KeyIsQuicFixProcessTimer,
    KeyIsQuicReadBlockTimeout,
    KeyIsQuicReadBlockMode,         //393
    KeyIsQuicEnableUnreliable,      //394
    KeyIsForceDecodeSwitch,         //395
    KeyIsForceDecodeMsGaps,         //396
    KeyIsForceRenderMsGaps,         //397
    KeyIsQuicFixStreamFinAndRst,    //398
    KeyIsQuicVersion,               //399
    
    KeyIsReportRequestHeaders = 400,
    KeyIsReportResponseHeaders,
    KeyIsSeekTimeCostInfo,

    KeyIsFlvTagBasedSpeed = 449,
    KeyIsMediaLoaderRegisterNativeHandle = 450,
    keyIsMediaLoaderNativeHandleStatus,
    
    KeyIsSinglePlayDownloadBytes = 470,
    KeyIsRotation,
    KeyIsVideoRenderStallDiffList,
    KeyIsVideoRenderStallDiffCount,
    KeyIsVideoRenderAvgCostTime,
    KeyIsVideoRenderFrameCount,
    KeyIsRealAudioEffectType,
    
    //mask sub
    KeyIsBarrageMaskUrl = 500,
    KeyIsBarrageMaskEnable,
    KeyIsSubPathInfo,
    KeyIsSubEnable,
    KeyIsSwitchSubId,
    KeyIsSubFirstLoadTime,
    KeyIsMaskStreamOpenTime,
    KeyIsMaskStreamOpenedTime,
    KeyIsOptSubFirstLoadTime,
    KeyIsEnableOptSubSearch,//509
    
    //license
    KeyIsModuleName = 510,
    KeyIsHLSProxyRegisterNativeHandle = 511,
    keyIsHLSProxyNativeHandleStatus = 512,
    
    //blue tooth opt
    KeyISOptBlueToothRenderSync        = 530,
    KeyISVoiceWriteTimeoutMultiple     = 531,
    KeyISAudioSkipLimitedTimes         = 532,
    
    //thread-safe ref
    KeyISEnableThreadSafeRef           = 540,

    // rts
    KeyIsRtcPlayAudioEngineCreatePtr    = 546,
    KeyIsRtcPlayAudioEngineDestoryPtr   = 547,
    KeyIsRtcTlsHandShakeTime            = 548,
    KeyIsRtcSignalTransportTime         = 549,
    KeyIsEnableRtcPlay                  = 550,
    KeyIsRtcPlayEngineIns               = 551,
    KeyIsRtcPlayEngineConfig            = 552,
    KeyIsRtcInitedTime                  = 553,
    KeyIsRtcOfferSendTime               = 554,
    KeyIsRtcAnswerRecvTime              = 555,
    KeyIsRtcStartTime                   = 556,
    KeyIsRtcStatInfo                    = 557,
    KeyIsRtcSessionId                   = 558,
    KeyIsRtcFallbackThreshold           = 559,
    KeyIsRtcTimimgInfo                  = 561,
    KeyIsRtcPlayVideoRenderSeries       = 562,
    KeyIsRtcEnableEarlyInitRender       = 563, // deprecated
    KeyIsRtcUninitLockFree              = 564,
    KeyIsRtcExpectServerIP              = 565,
    KeyIsRtcTracePrint                  = 566,
    KeyIsLiveRtsParams                  = 567,
    KeyIsRTCFixAbnormalDestruct         = 568,
    KeyIsLiveRtcProfileConfig           = 569,
    KeyIsRtcPlayEngineCreatePtr         = 570,
    KeyIsRtcPlayEngineDestoryPtr        = 571,
    KeyIsRtsToAlogFuncPtr               = 572,
    KeyIsRtcICEConnectedTime            = 573,
    KeyIsRtcAvunsyncInfoEnable          = 574,
    KeyIsRtcAVUnSyncInfo                = 575,
    KeyIsRtcAVUnSyncDiffMs              = 576,
    KeyIsRtcAVUnSyncDurationMs          = 577,
    KeyIsRtcAVSyncDurationMs            = 578,
    KeyIsRtcPreloading                  = 579,
    KeyIsRtcPreloadResult               = 580,
    KeyIsRtcAnsweUpdatedTime            = 581,
    KeyIsRtcDNSFinshedTime              = 582,

    //first_frame
    KeyIsHttpOpenStart = 583,
    KeyIsTransOpenStart,
    KeyIsSocketCreateSuccess,
    KeyIs3xxHappen,
    KeyIsAudioHttpOpenStart,
    KeyIsAudioTransOpenStart,
    KeyIsAudioSocketCreateSuccess,
    KeyIsRedirectURL = 590,

    // avph
    KeyIsAVPHVideoProbeSize = 600,
    KeyIsAVPHVideoMaxDuration,
    KeyIsAVPHAudioProbeSize,
    KeyIsAVPHAudioMaxDuration,
    KeyIsAVPHOpenVideoFirst,
    KeyIsAVPHMaxAVDiff,
    KeyIsAVPHEnableAutoReopen,
    KeyIsAVPHAutoExit,
    KeyIsAVPHVideoDiffThreshold,
    KeyIsAVPHReadRetryCount,
    KeyIsAVPHReadErrorExit,
    KeyIsAVPHStreamInfo,

    KeyIsEnableSkipFindUnnecessaryStream = 620,
    KeyIsEnableAVPHDnsParse              = 621,
    KeyIsAVPHDnsParseTimeout             = 622,

    // http request cdn status
    KeyIsAudioHitCDNCache       = 630,
    KeyIsVideoHitCDNCache       = 631,
    KeyIsAudioTimeToSource      = 632,
    KeyIsVideoTimeToSource      = 633,
    KeyIsAudioTimeForCDN        = 634,
    KeyIsVideoTimeForCDN        = 635,

    //audio climiter
    KeyIsAudioEffectType           = 643,
    KeyIsAESrcLufs                 = 644,
    KeyIsAETarLufs                 = 645,
    KeyIsAESrcPeak                 = 646,
    KeyIsTranErrCode               = 647,
    KeyIsTranErrType               = 648,
    KeyIsAudioEffectKnee           = 649,
    KeyIsAEReleaseTime             = 650,
    KeyIsAELookAheadTime           = 651,
    KeyIsAELuRange                 = 652,
    KeyIsAELuStart                 = 653,
    KeyIsAELuEnd                   = 654,
    KeyIsAEMaxMomLu                = 655,
    KeyIsAEMaxShortermLu           = 656,
    KeyIsAEJsonConfig              = 657,
    KeyIsAEVolumInfoVer            = 658,
    KeyIsAEDevicePlayAbility       = 659,
    KeyIsAEVolumeInfoJson          = 660,
    KeyIsAEGraphConfig             = 661,
    
    //quic options
    KeyISQuicTimerVersion          = 700,
    KeyIsQuicConfigOptimize        = 701,   //deprecated
    KeyIsQuicInitSessionWindow     = 702,
    KeyIsQuicInitStreamWindow      = 703,
    KeyIsQuicParams                = 704,
    KeyIsAvphParams                = 705,
    KeyIsHttpxParams               = 706,
    KeyIsHttpxContextStartCost     = 707,
    KeyIsUdpRealSpeed              = 708,
    KeyIsTTQuicSDKVersion          = 709,
    KeyIsHttpxReused               = 710,
    KeyIsQuicRejCount              = 711,
    KeyIsQuicRejReasons            = 712,
    KeyIsEnableProtocolDowngrade   = 713,
    KeyIsProtocolRetryTimes        = 714,
    KeyIsQuicReportInfo            = 715,
    KeyIsCertVerifyDetail          = 716,
    KeyIsCertVerifyFailed          = 717,
    KeyIsH1QuicConnectionId        = 718,
    KeyIsHttpxRaceResult           = 719,
    KeyIsHttpxAudioRaceResult      = 720,
    KeyIsStartPlayBufferWaitTime   = 760,
    KeyIsSrExtraMode               = 761,
    KeyIsNetworkHandle             = 762,
    
    //pcdn config
    KeyIsPcdnEnabel                = 780,
    KeyIsPcdnWatchThreshold        = 781,
    KeyIsPcdnH2pCache              = 782,
    KeyIsPcdnAndFlvAdaptEnable     = 783,
    
    KeyIsKeepFormatThreadAlive     = 800,
    KeyIsEnable720PSR              = 801,
    KeyIsStopSourceAsync           = 802,
    KeyIsEnablePrimingWorkAround   = 803,
    KeyIsEnableHDR10               = 804,
    KeyIsPreferSpdlForHDR          = 805,
    KeyIsEnableSeekInterrupt       = 806,
    KeyIsUpdateClockWithOffset     = 807,
    KeyIsChangeVtbSizePicSizeBound = 808,
    KeyIsAudioEffectEnabled        = 809,
    KeyIsEnableLazyVoiceOp         = 810, // deprecated since 2.10.118 (20230118), force enabled
    KeyIsHandleBackgroundInAvView  = 811,
    KeyIsVoiceSplitHeaacV2         = 812,  // deprecated
    KeyIsAudioHardwareDecode       = 813,
    KeyIsVoiceBlockDuration        = 814,
    KeyIsKeepVoiceDuration         = 815, // deprecated
    KeyIsSkipSetSameWindow         = 816,
    KeyIsCacheVoiceId              = 817,
    KeyIsVtbFlushKeepSesssion      = 818,
    KeyIsMaskStopTimeout           = 819,
    KeyIsEnableVtbDropRASL         = 820,
    KeyIsSubtitleStopTimeout       = 821,
    KeyIsCheckVoiceInBufferingStart= 822,
    KeyIsOpenVoiceDuringPrepare    = 823,
    KeyIsAllAVViewHoldBackground   = 824,
    KeyIsOpenSubRetryTimes         = 825,
    KeyIsRecreateSubIfDetached     = 826,
    KeyIsKeepDurationBufferSize    = 827, // deprecated
    KeyIsAVSyncInterruptEnable     = 828,
    KeyIsAOutletCPUTest            = 829, // deprecated
    KeyIsCacheMetalDevice          = 830,
    KeyIsFixVoiceLatency           = 831,
    KeyIsEnableVtbIgnoreBadDataErr = 833,
    KeyIsHijackVoiceType           = 834,

    KeyIsEnableDemuxerStall        = 850,
    KeyIsEnableDecoderStall        = 851,
    KeyIsDemuxerStallThreshold     = 852,
    KeyIsDecoderStallThreshold     = 853,

    KeyIsEnableVideoProcessorMultiMode = 900,
    KeyIsVideoProcessorStartMode   = 901,
    KeyIsEnableRangeCacheDuration  = 902,
    KeyIsDelayBufferingUpdate      = 903,
    KeyIsNoBufferingUpdate         = 904,
    KeyIsEnableSRBound             = 905,
    KeyIsSRLongDimensionLowerBound = 906,
    KeyIsSRLongDimensionUpperBound = 907,
    KeyIsSRShortDimensionLowerBound = 908,
    KeyIsSRShortDimensionUpperBound = 909,
    KeyIsFilePlayNoBuffering       = 910,
    KeyIsEnableDisplayP3           = 911,
    KeyIsEnableVideoTimestampMonotonic = 912,
    KeyIsEnableThreadPriority       = 913,
    KeyIsThreadPriorityValue        = 914,
    KeyIsTtmpDnsParseEnable         = 915,
    KeyIsTtmpDnsParseTimeout        = 916,
    KeyIsPositionUpdateInterval     = 917,
    KeyIsEnableVideo15SR            = 918,
    KeyIsEnableBufferingDirectlyRenderStartReport = 919,
    KeyIsEnableDirectlyBufferingEndTimeMilliSeconds = 920,
    KeyIsDirectlyBufferingEndTimeMilliSeconds = 921,
    KeyIsEnableDirectlyBufferingSendVideoPacket = 922,
    KeyIsNetworkClass               = 923,
    KeyIsGetNetworkConnectCount     = 924,
    KeyIsServerIp                   = 925,
    KeyIsSsrAlways                  = 926,
    KeyIsSuggestSendingRate         = 927,
    KeyIsReportCcreTagInChlo        = 928,
    KeyIsReportSsrTagInChlo         = 929,
    KeyIsReportIrttTagInChlo        = 930,
    KeyIsReportCctkTagInChlo        = 931,
    KeyIsReportNtypTagInChlo        = 932,
    KeyIsReportCcfbTagInShlo        = 933,
    KeyIsReportCCTKFrameData        = 934,
    KeyIsReportJccoTagInChlo        = 935,
    KeyIsHttpUserAgent              = 936,
    KeyIsStreamInfoFindEndTime      = 937,
    KeyIsBussnessTag                = 938,
    KeyIsBussnessSubtag             = 939,
    KeyIsVoiceVolumeFadeModeK2      = 940,

    // cmaf
    KeyIsCmafMpdDnsAnalysisEnd          = 950,
    KeyIsCmafMpdConnectTime             = 951,
    KeyIsCmafMpdHttpReqFinishTime       = 952,
    KeyIsCmafMpdTcpFirstPackageEnd      = 953,
    KeyIsCmafMpdHttpResFinishTime       = 954,
    KeyIsCmafMpdTcpConnectTime          = 955,
    KeyIsCmafAudioDnsAnalysisEnd        = 956,
    KeyIsCmafAudioTcpConnectTime        = 957,
    KeyIsCmafAudioHttpReqFinishTime     = 958,
    KeyIsCmafAudioTcpFirstPacketTime    = 959,
    KeyIsCmafAudioHttpResFinishTime     = 960,
    KeyIsCmafAudioFirstsegConnectTime   = 961,
    KeyIsCmafVideoHttpReqFinishTime     = 962,
    KeyIsCmafVideoHttpResFinishTime     = 963,
    KeyIsCmafVideoFirstsegConnectTime   = 964,
    KeyIsCmafSkipInitSection            = 965,
    KeyIsCmafOptimizeRetry              = 966,
    KeyIsCmafUpdateMpdAsync             = 967,
    KeyIsCmafSegmentSyncThreshold       = 968,
    KeyIsCmafStartSeqDiff               = 969,
    KeyIsCmafParams                     = 970,
    KeyIsCmafVideoRequestLog            = 971,
    KeyIsCmafAudioRequestLog            = 972,
    
    // speed auto change after N milliseconds
    KeyIsDurationOfStartAutoSpeed               = 980,
    
    // no video or audio render threshold
    KeyIsNoVARenderThreshold            = 981,
    
    // hardware codec fallback to software codec error solver
    KeyIsCodecFallbackErrorSolverEnabled = 982,
    
    //Get voice db value from stream
    KeyIsStreamVoiceDBValue = 986,
    KeyIsStreamVoiceDBEnable = 987,

    KeyIsEnableChangeStartPlayBuffer = 988,
    KeyIsAudioChannelCtl = 989,
    KeyIsEnableSetDrawableSizeWithLiveSize = 990,
    KeyIsEnableCompareDrawableWithWindow = 991,
    
    KeyIsNeedCheckDropAudio = 995,
    
    //smooth switch in abr
    KeyIsABRDisableAlgorithm                    = 996,
    KeyIsABRExpectBitrate                       = 997,
    
    KeyIsLiveStreamSessionId                    = 998,
    KeyIsEstimatedBandwidthInBitsPerSecond      = 999,
    
    // llash
    KeyIsLLASHFastOpenEnabled                   = 1000,
    KeyIsLLASHCheckEnhance                      = 1001,
    KeyIsLLASHCheckInterval                     = 1002,
    KeyIsLLASHMethod                            = 1003,
    KeyIsLLASHNonKeyFrameSwitchBufferThreshold  = 1004,
    KeyIsLLASHSwitchCost                        = 1005,
    KeyIsLLASHSwitchAction                      = 1006,
    KeyIsLLASHUpgradeTimeThreshold              = 1007,
    KeyIsLLASHBandwidthDownParameter            = 1008,
    KeyIsLLASHRebufferPenalty                   = 1009,
    KeyIsLLASHTargetBuffer                      = 1010,
    KeyIsLLASHSafeBuffer                        = 1011,
    KeyIsLLASHPIDKp                             = 1012,
    KeyIsLLASHPIDKi                             = 1013,
    KeyIsLLASHPIDKd                             = 1014,
    KeyIsLLASHCounterThreshold                  = 1015,
    KeyIsLLASHCounterPenalized                  = 1016,
    
    KeyIsEstimatedBandwidthStandardDeviation    = 1017,
    
    //NNSR
    KeyIsForceSetNNSRInputProperty = 1018,
    
    KeyIsBandwidthEstimationSamplesStandardDeviation = 1019,
    
    KeyIsLLASHReqParams                         = 1020,

    // private drm
    KeyIsSpadeInfo      = 1021,
    KeyIsSpadeUnionInfo = 1022,
    //encrypted local time
    KeyIsSpadeLocalTime = 1023,
    KeyIsSpadeExpireTime = 1024,

    // Async close VtbCodec
    KeyIsCloseVtbCodecAsync = 1025,  // deprecated， 20240105, use video decode thread skip join.
    
    KeyIsEnableFlvTagBasedSpeed = 1026,
    KeyIsEnableFlvAudioTagForSpeed = 1027,
    KeyIsFlvSpeedUpdateIntInMs = 1028,
    KeyIsEstimatedBandwidthAverage = 1029,
    
    //Keep origin host
    KeyIsHttpKeepOriginHost = 1030,
    
    KeyIsViewWidth = 1031,
    KeyIsViewHeight = 1032,
    KeyIsFormaterCurrentPts = 1033,
    KeyIsAudioRenderCurrentPts = 1034,
    
    KeySpecialFuncitonType   = 1041,
    KeyIsVC2AdspLibraryPath  = 1042,
    
    // mdl protocol 
    KeyIsEnableMdlSeekReopen = 1100,
    
    KeyIsLiveABRSwitchFindStreamInfoCost = 1120,
    KeyIsLiveABRRequestUrl = 1121,
    KeyIsLiveABRSwitchPrevVideoBufferLength = 1122,
    KeyIsLiveABRSwitchPrevAudioBufferLength = 1123,
    KeyIsLiveABRSwitchBufferThreshold = 1124,
    KeyIsLiveABREnableBandwidthStrategy = 1125,
    KeyIsLiveABRPredictBitrate = 1126,
    KeyIsLiveABRCloseIOImmediately = 1127,
    KeyIsLiveABRCloseIOCost = 1128,
    
    //thirdparty ffmpeg protocol
    KeyIsEnableThirdPartyProtocol = 1150,
    KeyIsThirdPartyProtocolPtr = 1151,
    KeyIsThirdPartyProtocolName = 1152,
    KeyIsThirdPartyAVDictionarylPtr = 1153,
    
    //ptr
    KeyIsFramDidReceiveBinarySeiCallback      = 1200,
    KeyIsAbrDecisionInfoCallback              = 1201,
    KeyIsAbrDecisionInfoRecordMaxCount        = 1202,
    KeyIsEnableOptimizeVolume2 = 1210,
    
    // sei callback before first frame
    KeyIsSeiImmediatlyCallback                = 1250,
    // VideoOutlet render time
    KeyIsVideoRendFirstFrameTime                 = 1260,
    
    // LiveBalance ModelPath
    KeyIsAudioEffectModelPath               = 1270,
    
    //audio frame dropping
    KeyIsAudioFrameDropCnt = 1300,
    
    //player debug state
    KeyIsPlayerDebugState = 1301,

    //AI Barrage control
    KeyIsAIBarrageUrl = 1400,
    KeyIsAIBarrageEnable = 1401,
    
    //LiveStrategy Params Keys
    KeyIsStrategyParamsCallback = 1500,
    
    KeyIsDropFrameByUser                 = 1510,
    KeyIsDropFrameRate                   = 1511,
    KeyIsDropFrameMinFps                 = 1512,
    
    //Audio Processor Unbind
    KeyIsEnableCheckUnbindAudioProcessor = 1550,
    KeyIsAudioProcessorUnbindStatus = 1551,
    KeyIsEnableSetAudioProcessorAfterPlay = 1552,

    //get real time metadata info
    KeyIsRealTimeMetaDataInfo = 1580,
    
    //subtitle II
    KeyIsAdditionSubInfo = 1600,
    KeyIsMaskDownloadSize = 1601,
    KeyIsSubTitleDownloadSize = 1602,
    
    
    //set liveIo protocol handle
    KeyIsSetLiveIOProtocolHandle = 1650,
    
    //Hurry params in live
    KeyIsHurryInterval = 1700,
    KeyIsHurryOnceMax = 1701,
    KeyIsHurryCacheType = 1702,
    KeyIsHurryStartMs = 1703,
    KeyIsHurryStopType = 1704,
    KeyIsBufferingStartIDLTime = 1705,
    KeyIsEnableSkipOnBufferingEnd = 1706,
    KeyIsMinBufferMsStopDropFrame = 1707,
    KeyIsMaxDropFrameCostMs = 1708,
    KeyIsEnableCheckDropTimeCost = 1709,
    
    KeyIsEnableFixSpeedFilterPtsShiftAndDropFrame = 1720,
    KeyIsHurryDelayThreshold = 1721,
    KeyIsEnableAccurateSleepForDummyVoice = 1722,
    KeyIsSkipBufferingBeforeFirstFrame = 1723,

    //LLASH
    KeyIsLLASHSwitchNumberThreshold = 1800,
    KeyIsLLASHSwitchDownBufferThreshold = 1801,
    KeyIsLLASHTargetBitrateWith32bitsSuffix = 1802,

    //RTM monitor
    KeyIsReceiveFirstVideoPacketTime = 1950,
    KeyIsReceiveFirstAudioPacketTime = 1951,
    KeyIsToDecodeFirstVideoFrameTime = 1952,
    KeyIsToDecodeFirstAudioFrameTime = 1953,

    //skip audio effect
    KeyIsEnableSkipAudioEffect = 1990,
    
    // Videoprocessor log
    KeyIsEffectChainAverageTime = 2000,
    KeyIsPerEffectAverageTime = 2001,
    KeyIsProcessorVersion = 2002,
    KeyIsProcessorErrorCode = 2003,
    KeyIsProcessorErrorMsg = 2004,
    KeyIsProcessorEffectParamStr = 2005,
    KeyIsProcessorEffectGetViewWidth = 2006,
    KeyIsProcessorEffectGetViewHeight = 2007,
    KeyIsProcessorEffectGetOSViewWidth = 2008,
    KeyIsProcessorEffectGetOSViewHeight = 2009,
    KeyIsProcessorEffectGetScaleType = 2010,
    KeyIsProcessorEffectGetActuallyValid = 2011,

    KeyIsProcessorLogLevelPrint = 2100,
    KeyIsProcessorLogLevelCallback = 2101,
    KeyIsProcessorLogErrorCallbackFirstOnly = 2102,
    
    KeyIsBmfFlexSrMode = 2150,
    
    //voice pool event track
    KeyIsVoiceOpenHitVoicePool = 2500,
    KeyIsVoiceWritingFailedTimes = 2501,
    KeyIsAudioRenderFirstPts = 2502,
    KeyIsDashEventStr = 2503,
    KeyIsReadSizeAtOpenInput = 2504,
    keyIsVideoDemuxSwitchCnt = 2505,
    keyIsVideoDemuxSwitchUpCnt = 2506,
    KeyIsEnableSCABRStrategy = 2507,
    KeyIsVC2DecodeCount = 2508,
    KeyIsVC2AvgLogDecodeTime = 2509,
    KeyIsVC2StdLogDecodeTime = 2510,
    
    // bmf model download
    KeyIsBmfSRDownloadSuccessRate        = 2600,
    KeyIsBmfSRDownloadCostTime           = 2601,
    KeyIsBmfSRDownloadErrorCode          = 2602,
    KeyIsBmfHDRDownloadSuccessRate       = 2603,
    KeyIsBmfHDRDownloadCostTime          = 2604,
    KeyIsBmfHDRDownloadErrorCode         = 2605,
    KeyIsBmfDBHQDownloadSuccessRate      = 2606,
    KeyIsBmfDBHQDownloadCostTime         = 2607,
    KeyIsBmfDBHQDownloadErrorCode        = 2608,
    KeyIsSRSharpLevel                    = 2609,
    
    //audio metric
    KeyIsEnableAudioMetricBeforeAE = 2700,
    KeyIsEnableAudioMetricAfterAE = 2701,
    KeyIsAudioMetricModelPath = 2702,
    KeyIsAudioMetricDetect = 2703,
    KeyIsAudioMetricDetectDurationThres = 2704,
    KeyIsAudioMetricGetBFAEResults = 2705,
    KeyIsAudioMetricGetAFAEResults = 2706,
    KeyIsAudioMetricUseHandlePool = 2707,
    KeyIsLiveBalanceUseHandlePool = 2708,

    // dummy player
    KeyIsDummyPlayerBase                = 10000,
    KeyIsDummyPlayerSessionDescription  = 10001,

    // audio rms
    keyIsAudioOutletDBValue        = 10100,
    keyIsAudioRMSMonitorEnable      = 10101,
    keyIsAudioDecoderDBValue       = 10102,

    // LoudnessStrategy3 related
    KeyIsAudioLoudnessStrategy3NoiseGateCompressRatio = 10103,
    KeyIsAudioLoudnessStrategy3ShorttermLoudness = 10104,
    KeyIsAudioLoudnessStrategy3MomentaryLoudness = 10105,
    KeyIsAudioLoudnessStrategy3WindowLoudness = 10106,
    KeyIsAudioLoudnessStrategy3WindowPeak =10107,
    KeyIsEnableAudioLoudnessStrategy3 = 10108,
    KeyIsAudioLoudnessStrategy3DrcCompressorRatio = 10113,
    KeyIsAudioLoudnessStrategy3IsFixedDrcCompressorRatio = 10114,
    KeyIsAudioLoudnessStrategy3GainSmoothingInSeconds = 10115,
    KeyIsAudioLoudnessStrategy3LimiterMakeupGain = 10116,
    KeyIsAudioLoudnessStrategy3MaxGain = 10117,

    /// Direct Int Option set Before prepare
    ///
    /// Make sure the key value is same as the one in TTVideoEngine+Options.h
    KeyIsDirIntMinGuard  = 40000,
    /// To automatically set options and align with ttvideoengine, do NOT set 40001 here
    /// otherwise will cause all auto keys fail
    KeyIsMetalCommitTimeout           = 40002, // deprecated
    KeyIsEnableVideoIOSurfaceRender   = 40003, // deprecated, used in opengl
    KeyIsClipHEAACV2FirstPtsPacket    = 40004,
    KeyIsEnableCPPBYTEVC1CodecOpt     = 40005,
    KeyIsVoiceRequiredDuration        = 40006,
    KeyIsEnableDynamicFrameDropping   = 40007,
    KeyIsDynamicDroppingFrameMultiple = 40008,
    KeyIsDynamicDroppingCheckPeriod   = 40009,
    /** blue tooth opt II */
    KeyIsOutleterSenseBuffering       = 40010,
    KeyIsBTOptOnlyWorksOnPause        = 40011,
    KeyIsBTOptEffectiveTime           = 40012,
    KeyIsVoiceDropHeaderNode          = 40013,
    /** blue tooth opt II */
    KeyIsEnableFastStop               = 40014, // deprecated
    KeyIsEnableMp4Check               = 40015,
    KeyIsEnableHEAACV2PtsMSCorrection = 40016,
    KeyIsPostPrepareCallStartMoment   = 40017,
    KeyIsEnableMetalVideoIOSurfaceRender = 40018,
    //when start time not is zero,mRecivePktCount did not cal AV_SKIP_SERIAL packet
    KeyIsEnableStartTimeSkipAVSkipSerial = 40019,
    KeyIsDynamicDroppingCheckCount       = 40020,
    KeyIsBTOptAddConsumingTime           = 40021,
    KeyIsEnablexHEAACSupport             = 40022,
    KeyIsPreDemuxAutoPause               = 40023,
    KeyIsDemuxerRecycle                  = 40024, // deprecated
    KeyIsCodecRecycle                    = 40025, // deprecated
    KeyIsFilterRecycle                   = 40026, // deprecated
    KeyIsPlayerRecycle                   = 40027, // deprecated
    KeyIsAOutletFastStop                 = 40028, // deprecated
    KeyIsVOutletFastStop                 = 40029, // deprecated
    KeyIsAGraphFastStop                  = 40030, // deprecated
    KeyIsADecoderFastStop                = 40031, // deprecated
    KeyIsVDecoderFastStop                = 40032, // deprecated
    KeyIsReaderFastStop                  = 40033, // deprecated
    KeyIsPostPauseAfterClose             = 40034, // deprecated
    KeyIsUnlimitHeaderSize               = 40035,
    KeyIsPostResume                      = 40036,
    KeyIsDecodeAACThroughFDKAAC          = 40037,
    KeyIsStopCloseIO                     = 40038,
    KeyIsOnlyPlayAudioForBothStream      = 40039,
    KeyIsAudioEOSDelayDiscontinuousSleep = 40040,
    KeyIsEnableImageScale                = 40041,
    KeyIsEnableDrawableSizeInMinVideoView= 40042,
    KeyIsEnableProcessorCrop             = 40043,
    KeyIsEnableBufferingLowerCapacity    = 40044,
    KeyIsSupportFastStopCancelWait       = 40045, // deprecated
    KeyIsEnableHWDropFrameWhenVOIsInDropState = 40046,
    KeyIsEnableHWDropFrameWhenAVOutSyncing    = 40047,
    KeyIsCodecFramesDrop                      = 40048,
    KeyIsMaskDelayLoading                     = 40049,
    KeyIsEnableVideoBmf                  = 40050,
    KeyIsEnableCheckVtbMaxRefFrame       = 40051,
    KeyIsEnableVideoSoftBmfSr            = 40052,
    KeyIsMetalPauseNoLock                = 40053,  // deprecated
    KeyIsHandleResolutionChange          = 40054,

    KeyIsMaskRangeOpt                    = 40055,
    KeyIsMaskHeaderLen                   = 40056,
    KeyIsEnableMetalViewDoubleBuffering  = 40057,
    KeyIsThreadNamePad2Char              = 40058,
    KeyIsEnableDemuxerRWLock             = 40059, //deprecated
    KeyIsEnableAVVoiceReuse              = 40060,
    KeyIsAutoAudioDeviceChangeDetection  = 40061, //deprecated
    KeyIsVoiceStartFailedSense           = 40062,
    KeyIsTestDeviceAfterPause            = 40063,
    KeyIsPostResetAfterClose             = 40064,
    KeyIsPostStart                       = 40065,
    KeyIsEnableSampleBufferLayerDirectly = 40066,
    KeyIsBMFSRALGORITH                   = 40067,
    KeyIsEnableBMFSrSync                 = 40068,
    KeyIsSubtitleSenseBuffering          = 40069,
    KeyIsEnableOptimizeLivePtsRollback   = 40070,
    KeyIsDisableVoiceReuseOnPause        = 40071, //deprecated
    KeyIsEnableSubtitleLazyLoading       = 40072,
    KeyIsEnableCPPBYTEVC2CodecOpt        = 40073,
    KeyIsAudioPtsMSCorrectionExtension   = 40074,
    KeyIsVC2WppMode                      = 40075,
    KeyIsBYTEVC2LowLatency               = 40076,
    KeyIsSrSuccessRate                   = 40077,
    KeyIsSrAverageCostTime               = 40078,
    KeyIsEnableRenderSwitching           = 40079,
    KeyIsRenderFailureLimitedTimes       = 40080,
    KeyIsForceStartVoiceAfterPause       = 40081, //deprecated
    KeyIsCorretClockAfterWritingFailed   = 40082, //deprecated
    KeyIsSaveBlocksWhileVoiceChanging    = 40083, //deprecated
    KeyIsEnableSeekBuffering             = 40084,
    KeyIsVC2ThreadNum                    = 40085,
    KeyIsEnableAudioSeekingNoaccurate    = 40086,
    KeyIsEnableFindAmbientForHDR         = 40087,
    KeyIsEnableYUV420PVideoProcessor     = 40088,
    KeyIsEnableOptimizeRadioMode         = 40089,
    KeyIsMovingIOSViewOpToMainThread     = 40090,
    KeyIsFixingStartingPlayIssue         = 40091,
    KeyIsEnableDynamicGaussianBlur       = 40092,
    KeyIsDynamicGaussianBlurViewSize     = 40093,
    KeyIsDynamicGaussianBlurResetViewSize = 40094,
    
    KeyIsAllowAllExtensions              = 40095,
    KeyIsDisableVc2Recycle               = 40096, //deprecated
    KeyIsVoiceVolumeFadeMode             = 40097, //use KeyIsVoiceVolumeFadeModeK2 instead.
    KeyIsEnableVc1Recycle                = 40098, //deprecated
    KeyIsAudioGraphRefactor              = 40099,
    KeyIsPipeStartOffset                 = 40100, //deprecated, 40000-50000 只支持 int，不支持 int64
    KeyIsPipeDeclareLength               = 40101, //deprecated, 40000-50000 只支持 int，不支持 int64

    KeyIsUseTargetVideoWindow            = 42001,
    KeyIsAudioHardwareDecodeK2           = 42002,
    KeyIsDecreaseVtbStackSizeK2          = 42003,
    KeyIsEnableCorrectRealClock          = 42004,
    KeyIsEnableOptimizeDashSeek          = 42005,
    KeyIsEnableAccurateSleepForDummyVoiceK2 = 42007,
    KeyIsEnableBMFAsyncInit              = 42008,
    KeyIsForceSRInLowFrameRateVideo      = 42009,
    KeyIsEnableSoftSRReleaseTmpBuffer    = 42013,
    KeyIsEnableMultiAudioTrack           = 42017,
    KeyIsEnableVolumeFade = 42018,
    KeyIsVoiceFadeEmbellishmentTime = 42019,
    KeyIsEnableGlobalMuteFadeIn = 42020,
    KeyIsEnableAudioTypeChangeFadeIn = 42021,
    KeyIsRefactorAsyncDownload       = 42022,
    KeyIsEnableSubtitleCpuProtection = 42023,
    KeyIsSubtitleCpuProtectionGap = 42024,
    KeyIsTryOptSubtitleLogic = 42025,
    KeyIsExtVoiceOutputFormat            = 42026,
    KeyIsEnableOutletThreadOptimize      = 42027,
    KeyIsBandwidthEstimationUpperBoundInBitsPerSecond   = 42028,
    KeyIsBandwidthEstimationLowerBoundInBitsPerSecond   = 42029,
    KeyIsBandwidthEstimationWindowLengthInMilliseconds  = 42030,
    KeyIsEnableEnsureSRGetFirstFrame     = 42034,
    KeyIsEnableAlignSkipFindStreamInfo   = 42035,
    KeyIsEnableSBDLDeallocFlush = 42036,
    KeyIsSampleBufferWriteInMainThread  = 42041,
    KeyIsDashEnableAsyncDownload        = 42042,
    KeyIsEnableVPRGBToYUVOnceHandle = 42047,
    KeyIsEnableDisplayP3NV12        = 42052,
    KeyIsOptSoftStride              = 42059,
    KeyIsEnableVodVideoRenderStall  = 42064,
    KeyIsFormaterSleepDuration      = 42072,
    KeyIsPlayerSleepDuration        = 42073,
    KeyIsSampleBufferLayerFlushInSyncMainThread = 42074,
    KeyIsEnableFLVDummyABR          = 42076,
    KeyIsSegMaxRetrySI              = 42077,
    KeyIsEnableSegErrorSI           = 42078,
    KeyIsEnableMetalRenderHDR       = 42091,
    KeyIsVOutletPreRenderOpt        = 42095,
    KeyIsEnableRenderVertexOpt      = 42099,
    
    KeyIsEnablePixelFormatFullRange       = 42100,
    // vioce balance type using in end node at live scene
    KeyIsPreprocessAudioEffectType        = 42110,
    KeyIsHDRAutomaticIdentification       = 42116,
    KeyIsEnableOptInaccStart              = 42119,
    KeyIsEnableOptSeekClk                 = 42120,
    
    //42301---42320 use by video abnormal detect
    KeyIsAbnormalDetectInterval           = 42302,
    KeyIsAbnormalDetectStrategy           = 42303,

    //42400- 42500 vc2 dec options
    KeyIsVC2HEAACV2SampleNumberAdapter    = 42400,
    KeyIsVC2DecParallelFrameNum           = 42401,
    KeyIsVC2DecSimpDowngrade              = 42402,
    KeyIsVC2DecSimdCmdOpt                 = 42403,
    KeyIsEnableNewBMFSRInterface       = 42801,
    KeyIsVPAsyncInitEffect                = 42855,
    KeyIsEnableSoftDecodeHDR               = 42856,
    KeyIsHDRLightnessNormalizaThreshold    = 42857,
    KeyIsEnableVtbIgnoreHDRBadDataErr      = 42858,
    KeyIsSoftDecodeUseCVPixelBuffer       = 42859,
    
    ///
    KeyIsSmartFlowKey1                   = 49001,
    KeyIsSmartFlowKey2                   = 49002,
    KeyIsSmartFlowKey3                   = 49003,
    KeyIsSmartFlowKey4                   = 49004,
    KeyIsSmartFlowKey5                   = 49005,
    KeyIsSmartFlowKey6                   = 49006,
    KeyIsSmartFlowKey7                   = 49007,
    KeyIsSmartFlowKey8                   = 49008,
    KeyIsSmartFlowKey9                   = 49009,
    KeyIsSmartFlowKey10                  = 49010,
    KeyIsSmartFlowKey11                  = 49011,
    KeyIsSmartFlowKey12                  = 49012,
    KeyIsSmartFlowKey13                  = 49013,
    KeyIsSmartFlowKey14                  = 49014,
    KeyIsSmartFlowKey15                  = 49015,
    KeyIsSmartFlowKey16                  = 49016,
    KeyIsSmartFlowKey17                  = 49017,
    KeyIsSmartFlowKey18                  = 49018,
    KeyIsSmartFlowKey19                  = 49019,
    KeyIsSmartFlowKey20                  = 49020,
    KeyIsSmartFlowKey21                  = 49021,
    KeyIsSmartFlowKey22                  = 49022,
    KeyIsSmartFlowKey23                  = 49023,
    KeyIsSmartFlowKey24                  = 49024,
    KeyIsSmartFlowKey25                  = 49025,

    KeyIsDirIntMaxGuard  = 49999,
    
    // audio track info [50100~50199]
    KeyIsSampleRate                      = 50100,
    KeyIsChannels                        = 50101,
    
    // Optimized key
    KeyIsEnableMinMagFilterNearest       = 50300,
    KeyIsDropFrameThresholdMs            = 50301,
};

// Global static
typedef NS_ENUM(NSInteger, Key4GlobalValue) {
    GSKeyUseBaseThread_BOOL             = 0,
    GSKeyUseThreadPool_BOOL             = 1,
    GSKeyThreadPoolSize_INT             = 2,
    GSKeyThreadSafeRefSwitcher          = 3, //deprecated
    GSKeyEnableGlobalMuteFeature        = 4,
    GSKeyGlobalMute                     = 5, // is start global mute
    GSKeyLooperOpenWait                 = 6,
    GSKeyQosLooper                      = 7,
    GSKeyLooperDetach                   = 8,
    GSKeySetStateInOpenFail             = 9,
    GSKeyVoiceReusePoolSize             = 10,
    GSKeyVoicePoolStopAllMembers        = 11,
    GSKeyDemuxerBox_BOOL                = 12,
    GSKeyVoiceReuseEnableChangeSampleNB = 13, //deprecated
    GSKeySBDLHoldBackground             = 14,
    GSKeyThreadV2_BOOL                  = 15,
    GSKeyTlsLog_BOOL                    = 16,
    GSKeyLooperV2_INT                   = 17,
    GSKeyGlobalSendAudioDevice          = 18,
    GSKeyGlobalTestDeviceAfterPause     = 19,
    GSKeyGlobalEnableVC2ThreadPriority  = 20,
    GSKeyGlobalVC2ThreadPriorityValue   = 21,
    GSKeyGlobalIgnoreGlActive           = 22,
    GSKeyGlobalRenderAfterResignActive  = 23,
    GbKeySBDLReusePoolSize              = 24,
    //occpied by TTVideoEngine unexpectly 25,
    GbKeyOptVoicePoolLogic              = 26, //deprecated
    GbKeyEnableVC2DecPool               = 27,
    GbKeyVC2DecPoolSize                 = 28,
    GbKeyEnableCheckAudioSession        = 29,
    GbKeyVoicePoolEnableStatusControl   = 30, //deprecated
    GbKeyEnableSBDLReuse                = 31,
    GbKeyEnableThread2Pool              = 32,
    GbKeyThread2PoolSize                = 33,
    GbKeyEnableForceMetal               = 34,
    GbKeyEnableOptimizeMemory           = 35,
    GbKeyEnableThread2StackSizeOpt      = 36,
    GbKeyThread2StackSize               = 37,
};

typedef NS_ENUM(NSInteger, ImageEnhancementType) {
    DefaultEnhancement  = 0,
    ContrastEnhancement = 1,
};
typedef NS_ENUM(NSInteger, ImageScaleType) {
    LinearScale     = 0,
    LanczosScale    = 1,
};

typedef NS_ENUM(NSInteger, ImageLayoutType) {
    ImageScaleAspectFit = 0,
    ImageScaleToFill    = 1,
    ImageScaleAspectFill = 2,
};

typedef NS_ENUM(NSInteger, ImageRotationType) {//clockwise
    ImageRotationNone   = 0,
    ImageRotation90     = 90,
    ImageRotation180    = 180,
    ImageRotation270    = 270,
};

typedef NS_ENUM(NSInteger, ImageMirrorType) {
    ImageNoMirror            = 0,
    ImageHorizontalMirror    = 1,
    ImageVerticalMirror      = 2,
    ImageHVMirror            = 3,
};

typedef NS_ENUM(NSInteger, AudioChannelType) {
    AudioChannelTypeNormal           = 0,
    AudioChannelTypeRightDisable     = 1,
    AudioChannelTypeLeftDisable      = 2,
    AudioChannelTypeLeftUesdForLR    = 3,
    AudioChannelTypeRightUesdForLR   = 4,
};

typedef NS_ENUM(NSInteger, VideoRenderType) {
    VideoRenderTypePlane = 0,
    VideoRenderTypePano = 1,
    VideoRenderTypeVR = 2,
    VideoRenderTypeNone = 3,
};

typedef NS_ENUM(NSInteger, VideoRenderDevice) {
    VideoRenderDeviceOpengl = 0,
    VideoRenderDeviceNativeWindow = 1,//android type
    VideoRenderDeviceCoreGraphic = 2,
    VideoRenderDeviceMetal = 3,
};

typedef NS_ENUM(NSInteger, AVCodecId) {
    H264CodecId = 0,
    BYTEVC1CodecId = 1,
    AACCodecId  = 2,
    MP3CodecId  = 3,
    PCMS16LECodecId = 4,
    BYTEVC2CodecId = 33,
};

typedef NS_ENUM(NSInteger, HurryType) {
    NoHurryType = -1,
    IsCatchTime = 0,
    IsSkipTime  = 1,
};

typedef NS_ENUM(NSInteger, TTMediaStreamType) {
    TTMediaStreamTypeUnknown = -1,
    TTMediaStreamTypeVideo = 0,
    TTMediaStreamTypeAudio,
    TTMediaStreamTypeSubtitle,
};

typedef NS_ENUM(NSInteger, FastOpenLiveStream) {
    FastOpenLiveStreamDisable = 0,
    FastOpenLiveStreamEnable,
};

typedef NS_ENUM(NSInteger, AudioRenderDevice) {
    AudioRenderDeviceAudioUnit = 0,
    AudioRenderDeviceAudioGraph = 1,
    AudioRenderDeviceAudioQueue = 2,
    AudioRenderDeviceOpenAL = 3,
    AudioRenderDeviceExtern = 4,
    AudioRenderDevcieDefault = AudioRenderDeviceAudioUnit,
    AudioRenderDeviceNone = 10,
};

typedef NS_ENUM(NSInteger, CodecType) {
    ByteVC1CodecFFmpeg = 0,
    ByteVC1CodecKSY = 1,
    ByteVC1CodecJX = 2,
};


typedef NS_ENUM(NSInteger, PlayerLogLevel) {
    PlayerLogVerbose = 0,
    PlayerLogDebug = 1,
    PlayerLogInfo = 2,
    PlayerLogTrack = 3,
    PlayerLogKill = 4,
    PlayerLogPtr = 5,
    PlayerLogWarn= 6,
    PlayerLogError = 7,
};

typedef NS_ENUM(NSInteger, AudioEffectType) {
    AECompressor,
    AEClimiter,
    AECompressor2,
    AEOnlineLoudNorm,
    AERTCLoudNorm,
};

typedef NS_ENUM(NSInteger, AVSeekType) {
    AVSeekTypeAny,
    AVSeekTypeBackWard,
};

static NSString *const kTTPlayerRecordDir = @"ttplayer-record";
static NSString *const kTTPlayerLogDir = @"media-player-log";
static NSString *const kTTPlayerAudioFile = @"audio.pcm";
static NSString *const kTTPlayerVideoFile = @"video.yuv";
static NSString *const kTTPlayerMP4File = @"result.mp4";

#define TTPlayerVideoSizeChangeNotification @"TTPlayerVideoSizeChangeNotification"
#define TTPlayerVideoMetaInfoNotification   @"TTPlayerVideoMetaInfoNotification"
#define TTPlayerRtcTraceInfoDidReceiveNotification   @"TTPlayerRtcTraceInfoDidReceiveNotification"
#define TTPlayerRtcEventDidReceiveNotification   @"TTPlayerRtcEventDidReceiveNotification"
#define TTPlayerDidReceiveVideoCodecParameterSet @"TTPlayerDidReceiveVideoCodecParameterSet"
#define TTPlayerResponseHeadersDidGetNotification @"TTPlayerResponseHeadersDidGetNotification"
#define TTPlayerPlayspeedDidChangeNotification   @"TTPlayerPlayspeedDidChangeNotification"
#define TTPlayerVideoBitrateChangedNotification @"TTPlayerVideoBitrateChangedNotification"
#define TTPlayerAudioRenderStartNotification @"TTPlayerAudioRenderStartNotification"
#define TTPlayerRenderStallNotification @"TTPlayerRenderStallNotification"
#define TTPlayerDemuxStallNotification @"TTPlayerDemuxStallNotification"
#define TTPlayerDecodeStallNotification @"TTPlayerDecodeStallNotification"
#define TTPlayerAudioSilenceDetected @"TTPlayerAudioSilenceDetected"
#define TTPlayerDeviceOpenedNotification @"TTPlayerDeviceOpenedNotification"
#define TTPlayerPreBufferingNotification @"TTPlayerPreBufferingNotification"
#define TTPlayerOutleterPausedNotification @"TTPlayerOutleterPausedNotification"
#define TTPlayerBarrageMaskInfoNotification @"TTPlayerBarrageMaskInfoNotification"
#define TTPlayerAVOutsyncStartNotification @"TTPlayerAVOutsyncStartNotification"
#define TTPlayerAVOutsyncEndNotification @"TTPlayerAVOutsyncEndNotification"
#define TTPlayerDummySessionDidStopNotification @"TTPlayerDummySessionDidStopNotification"
#define TTPlayerDummyLiveMessageNotification @"TTPlayerDummyLiveMessageNotification"
#define TTPlayerNoVARenderStartNotification @"TTPlayerNoVARenderStartNotification"
#define TTPlayerNoVARenderEndNotification @"TTPlayerNoVARenderEndNotification"
#define TTPlayerNoVARenderBeforeFirstFrameNotification @"TTPlayerNoVARenderBeforeFirstFrameNotification"
#define TTPlayerStartTimeNoVideoFrame @"TTPlayerStartTimeNoVideoFrame"
#define TTPlayerInfoIdChangedNotification @"TTPlayerInfoIdChangedNotification"
#define TTPlayerFirstAVSyncNotification @"TTPlayerFirstAVSyncNotification"
#define TTPlayerVideoAbnormalOccurNotification @"TTPlayerVideoAbnormalOccurNotification"
#define TTPlayerSubtitleLoadCompleteNotification @"TTPlayerSubtitleLoadCompleteNotification"
#define TTPlayerSubtitleRenderFailedNotification @"TTPlayerSubtitleRenderFailedNotification"
#define TTPlayerSubtitleSwitchStartNotification @"TTPlayerSubtitleSwitchStartNotification"
#define TTPlayerSubtitleSwitchCompleteNotification @"TTPlayerSubtitleSwitchCompleteNotification"
#define TTPlayerLLASHSwitchPerformedNotification @"TTPlayerLLASHSwitchPerformedNotification"
#define TTPlayerVQScoreResultNotification @"TTPlayerVQScoreResultNotification"
#define TTPlayerDidReciveAudioMetricResultNotification @"TTPlayerDidReciveAudioMetricResultNotification"

#define kTTPlayerMetaInfoKey    @"meta"
#define kTTPlayerInfoDataKey    @"info"
#define kTTPlayerRtcTraceInfoKey    @"trace"
#define kTTPlayerRtcEventKey        @"rtc_event"
#define kTTPlayerVideoSizeWidthKey  @"width"
#define kTTPlayerVideoSizeHeightKey @"height"
#define kTTPlayerBitrateKey @"bitrate"
#define kTTPlayerStreamTypeKey @"stream_type"
#define kTTPlayerPacketInfoContainsKeyframeKey    @"contains_keyframe"
#define kTTPlayerVideoCodecParameterSetKey    @"parameter_set"
#define kTTPlayerPreBufferingChangeTypeKey   @"buffer_change_type"
#define kTTPlayerBarrageMaskInfoErrorCodeKey   @"barrage_mask_info_error_code"
#define kTTPlayerTimestamp    @"timestamp"
#define kTTPlayerNoVARenderType              @"norender_type"
#define kTTPlayerStreamDuration  @"stream_duration"
#define kTTPlayerInfoIdKey @"info_id"
#define kTTPlayerSeiPayLoadType @"seiPayLoadType"
#define kTTPlayerVQScoreResult @"vqscore_result"
#define kTTPlayerAudioMetricResult @"audioMetricResult"
#define kTTPlayerAudioMetricAfterEffect @"audioMetricAfterEffect"

#define kReplaceFileMode  0
#define kOpenFileMode     1
#define kDirMode          2

#define kNotSaveFile 0
#define kSaveFile    1

#define kNotCacheFile 0
#define kCacheFile   1

#define kIsHttpLoader     0
#define kIsNHttpLoader    1
#define kIsCacheLoader    4

#define kDisableVideoHardwareDecoder    0
#define kEnableVideoHardwareDecoder     1

#endif /* TTM_DUAL_CORE_TTPLAYER_DEF_H */

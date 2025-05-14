//
//  av_audio_wrapper.h
//  ttmp
//
//  Created by guikunzhi on 2019/12/24.
//
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark AudioProcessor
/**
 * @brief deprecated
 * Use TTAudioProxyWrapper instead
 */
typedef struct PlayerAudioWrapper{
    void (*open)(void *context, int samplerate, int channels, int duration); //创建资源
    void (*process)(void *context, float **inout, int samples, int64_t timestamp); //处理函数
    void (*close)(void *context); //释放资源，须与open成对调用
    void (*release)(void *context); //在release里销毁PlayerAudioWrapper，只调用一次
    void *context;
}PlayerAudioWrapper;


#pragma mark AudioVoice

enum TTPCMFormat {
 TT_PCM_FMT_NONE = -1,
 TT_PCM_FMT_U8   = 0,      ///< unsigned 8 bits
 TT_PCM_FMT_S16  = 1,      ///< signed 16 bits
 TT_PCM_FMT_S32  = 2,      ///< signed 32 bits
 TT_PCM_FMT_FLT  = 3,      ///< float
 TT_PCM_FMT_DBL  = 4,      ///< double
    ///
 TT_PCM_FMT_U8P  = 5,      ///< unsigned 8 bits, planar
 TT_PCM_FMT_S16P = 6,      ///< signed 16 bits, planar
 TT_PCM_FMT_S32P = 7,      ///< signed 32 bits, planar
 TT_PCM_FMT_FLTP = 8,      ///< float, planar
 TT_PCM_FMT_DBLP = 9,      ///< double, planar
};

///
typedef struct TTAudioMediaInfo {
    int sampleRate;
    int frameSampleNB;
    int bytePerSample;
    int channels;
    int format;
    int isPacked;
    int64_t duration;
} TTAudioMediaInfo;

typedef struct TTAudioFrameInfo {
    uint8_t **buffers;
    int bufferSize;
    int samples;
    int64_t timestamp;
} TTAudioFrameInfo;

#define AUDIO_VOICE_VERSION_0 0 // deprecated, use PLAYER_TRAIT_AUDIO_VOICE_VERSION_0
#define PLAYER_TRAIT_AUDIO_VOICE_VERSION_0 0

typedef struct TTVoiceTraitWrapper {
     int (*audioOpen)(void *nativeTrait, TTAudioMediaInfo *info);   //V0, 操作成功返回0，失败返回-1
     int (*audioWrite)(void *nativeTrait, TTAudioFrameInfo *frame); //V0, 操作成功返回0，失败返回-1
    void (*audioPause)(void *nativeTrait);  // V0
    void (*audioResume)(void *nativeTrait); // V0
    void (*audioFlush)(void *nativeTrait);  // V0, 清除音频缓存
    void (*audioClose)(void *nativeTrait);  // V0
     int (*getLatency)(void *nativeTrait);  // V0, 获取音频缓存持续时间，单位毫秒
} TTVoiceTraitWrapper;


#define PLAYER_TRAIT_AUDIO_PROXY_VERSION_0 0
typedef struct TTAudioProxyWrapper {
    void (*audioOpen)(void *nativeTrait, TTAudioMediaInfo *info);    // V0
    void (*audioWrite)(void *nativeTrait, TTAudioFrameInfo *frame);  // V0
    void (*audioClose)(void *nativeTrait);                           // V0
} TTAudioProxyWrapper ;

#ifdef __cplusplus
} //extern "C"
#endif
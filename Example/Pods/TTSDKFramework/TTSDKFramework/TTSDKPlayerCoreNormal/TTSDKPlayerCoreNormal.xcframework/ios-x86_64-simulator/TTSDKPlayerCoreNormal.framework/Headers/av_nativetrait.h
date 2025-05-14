/**
 * @file av_nativetrait.h
 * @owners 
 *      baishuai@bytedance.com
 * @date 2023-03-13
 * 
 * 
 * @notice
 *   !!!Nerver change this file!!!
 *   !!!Nerver change this file!!!
 *   !!!Nerver change this file!!!
 *
 */

#ifdef __cplusplus

#pragma once

namespace com { 
namespace ss { 
namespace ttm { 
namespace player{


enum TraitType: int {
    Illegal = 0,
    ExtVoice = 1,
    DrawByPass = 2,
    ProxyAudio = 3,
    LiveCallback = 4,
    LoadControl = 5,
    ExtRender = 6,
    HLSChooseStream = 7,
    BufferProcessProto = 8,

    // Raw Ptr Wrapper Traits
    PtrVPiOS = 1001,
};

class NativeTrait {
protected:
    virtual ~NativeTrait() = default;
public:
    NativeTrait(int _type, int _version, void *_c_funcs)
        :type(_type)
        ,version(_version)
        ,c_funcs(_c_funcs){}
    virtual void releaseNativeObj() {
        //default release operation
        delete this;
    }
    virtual bool equals(NativeTrait *other) {
        return this == other;
    }
public:
    const int type;
    const int version;
    const void *c_funcs;
};

}}}} // end of namespace com::ss::ttm::player

#endif // __cplusplus

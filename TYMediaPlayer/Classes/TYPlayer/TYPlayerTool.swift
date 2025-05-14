//
//  TYPlayerTool.swift
//  Playlet
//
//  Created by YannMacMini on 2025/1/15.
//


import TTSDKFramework

public class TYPlayerTool {
    
}


extension TYPlayerTool {
    
    public class func createEngineVidSource(vidPlayInfoModel: VidPlayInfoModel) -> TTVideoEngineVidSource {
        let vid = vidPlayInfoModel.vid
        let playAuthToken = vidPlayInfoModel.playAuthToken
        
        let resolution: TTVideoEngineResolutionType = TTVideoEngineResolutionType.init(rawValue: vidPlayInfoModel.resolutionType.rawValue) ?? .typeFullHD
        // 判断是否支持H265
        let isDeviceSupportH265: Bool = TTVideoEngineCodecStrategyUtil.isDeviceSupporth265HardwareDecode()
        let encodeType: TTVideoEngineEncodeType = isDeviceSupportH265 ? .engineh265 : .engineH264
        //
        let enginVideSource =  TTVideoEngineVidSource(vid: vid,
                                                      playAuthToken: playAuthToken,
                                                      resolution: resolution, // resolution --> 起播分辨率
                                                      encodeType: encodeType, isDash: false, isHLS: false)
        return enginVideSource
    }
    
    
    
    
    
}

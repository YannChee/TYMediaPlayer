//
//  MYPlayerModel.swift
//  Playlet
//
//  Created by YannMacMini on 2025/1/9.
//

import Foundation


/// 视频清晰度
@objc
public enum TYSDKPlayerResolutionType: UInt {
    case resolution720P = 2
    case resolution1080P = 3
    case resolution540P = 8
    
    
}




@objcMembers
public class VidPlayInfoModel: NSObject {
    public var vid: String = ""
    public var playAuthToken: String = ""
    public var resolutionType: TYSDKPlayerResolutionType = .resolution540P
    
    /// 是否是有效参数
    public var isValid: Bool {
        vid.count >  1 && playAuthToken.count > 1
    }
    
    public override init() {
        super.init()
    }
    
    public convenience init(vid: String,
         playAuthToken: String,
         resolutionType: TYSDKPlayerResolutionType) {
        self.init()
        self.vid = vid
        self.playAuthToken = playAuthToken
        self.resolutionType = resolutionType
    }
}

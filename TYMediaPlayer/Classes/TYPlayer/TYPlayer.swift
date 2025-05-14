//
//  MYTTSdkPlayer.swift
//  MYMediaFeedListAndPlayer_Example
//
//  Created by YannMacMini on 2024/11/8.
//  Copyright © 2024 CocoaPods. All rights reserved.
//

import TTSDKFramework


 protocol TTSDKSpesificPlayerPlayback  {
    var playerPrepareToPlayForVidMode: ((any FPPlayerMediaPlayback, _ vidPlayInfoModel: VidPlayInfoModel) -> Void)? { get set }
    var playerReadyToPlayForVidMode: ((any FPPlayerMediaPlayback, _ vidPlayInfoModel: VidPlayInfoModel) -> Void)? { get set }
}

open class TYPlayer: FPPlayer,TTSDKSpesificPlayerPlayback {
    var playerPrepareToPlayForVidMode: ((any FPPlayerMediaPlayback, VidPlayInfoModel) -> Void)?
    
    var playerReadyToPlayForVidMode: ((any FPPlayerMediaPlayback, VidPlayInfoModel) -> Void)?
    
    public var vidPlayInfo: VidPlayInfoModel?
 
    
    public override var shouldAutoPlay: Bool {
        didSet {
            manager.shouldAutoPlay = shouldAutoPlay
        }
    }
  
    public var playerEnginDidCreate: (() -> Void)?
    
    private var manager: TYSDKPlayerManager!
    
    private var videoSourceType: SDKPlayerVideoSourceType?
    
    open override var currentPlayerManager: any FPPlayerMediaPlayback {
        manager
    }
    
    public var totalWhatchedTime: TimeInterval {
        manager.durationWatched ?? 0
    }
    
    public var timeRefreshInterval: TimeInterval {
        manager.timeRefreshInterval
    }
    
    var videoFirstFrameRendFinish: (() -> Void)?
    
    var isLooping: Bool = false {
        didSet {
            manager.looping = isLooping
        }
    }
    
    private init() {
        let manager = TYSDKPlayerManager.init(videoSourceType: .vid)
        manager.timeRefreshInterval = 0.2
        self.videoSourceType = .vid
        self.manager = manager
        super.init(playerManager: manager)
        
        AVAudioSession.sharedInstance()
        manager.currentEnginDidCreate = { [weak self] in
            guard let self = self else { return }
            self.playerEnginDidCreate?()
        }
        
        manager.playerPrepareToPlayForVidMode = {[weak self] playerManager,vidPlayInfoModel in
            guard let self = self else { return }
            // 布局播放器UI
            self.addSubViews()
            self.layoutPlayerSubViews()
            
            self.playerPrepareToPlayForVidMode?(playerManager,vidPlayInfoModel)
        }
        
        manager.playerReadyToPlayForVidModel = {[weak self] playerManager,vidPlayInfoModel in
            guard let self = self else { return }
            self.playerReadyToPlayForVidMode?(playerManager,vidPlayInfoModel)
        }
        
        manager.videoFirstFrameRendFinish = { [weak self] in
            guard let self = self else { return }
            self.placeholderImageView.isHidden = true
            
            self.videoFirstFrameRendFinish?()        
        }
        
        manager.playerPlayTimeChanged = { [weak self] playerManager,currentTime,totalTime in
            guard let self = self else { return }
            self.playerPlayTimeChanged?(playerManager,currentTime,totalTime)
            
            // 缓存时间
            if let vidPlayInfo = self.vidPlayInfo,vidPlayInfo.vid.count > 0,currentTime >= 3 {
                TYMediaPlayRecoredManager.storeRecord(mediaUniqueKey: vidPlayInfo.vid, playTime: currentTime)
            }
            
        }
        
        manager.playerDidToEnd = { [weak self] playerManager in
            guard let self = self else { return }
            self.playerDidToEnd?(playerManager)
            
            // 重置时间
            if let vidPlayInfo = self.vidPlayInfo,vidPlayInfo.vid.count > 0 {
                TYMediaPlayRecoredManager.storeRecord(mediaUniqueKey: vidPlayInfo.vid, playTime: 0)
            }
        }
    }
    
    
  
    private override init(playerManager: any FPPlayerMediaPlayback) {
        super.init(playerManager: playerManager)
    }

    
    open override func seek(toTime time: TimeInterval, completionHandler: ((Bool) -> Void)? = nil) {
        manager.seek(toTime: time) { [weak self] isSuccess in
            completionHandler?(isSuccess)
            
            guard let self = self else { return }
            if let vidPlayInfo = self.vidPlayInfo,vidPlayInfo.vid.count > 0,time >= 3  {
                
                TYMediaPlayRecoredManager.storeRecord(mediaUniqueKey: vidPlayInfo.vid, playTime: time)
            }
        }
    }

   
}


// MARK: - public
extension TYPlayer {
    public class func player() -> TYPlayer {
        let player = TYPlayer()
        player.placeholderImageView.backgroundColor = .black
        player.playerView.layer.masksToBounds = true
        player.playerView.sendSubviewToBack(player.placeholderImageView)
        player.isLooping = true
        return player
    }
    
    public func createEngin(vidPlayInfo: VidPlayInfoModel?) {
        self.vidPlayInfo = vidPlayInfo
        manager.vidPlayInfoModel = vidPlayInfo
    }
    
    
    
    public class func initPlayerSDK(appID: String, licenseFileName: String) {
        TYSDKPlayerManager.initPlayeSDKWhenAppLaunch(appID: appID, licenseFileName: licenseFileName)
    }

    
    
    public func checkIsExistPreRenderedPlayerEngin(vidPlayInfo: VidPlayInfoModel?) -> Bool {
        self.vidPlayInfo = vidPlayInfo
        return  manager.checkIsExistPreRenderedPlayerEngin(vidPlayInfo: vidPlayInfo)
        
    }
    
    public class func getHistoryPlayTime(vid: String?) -> TimeInterval? {
        return TYMediaPlayRecoredManager.getRecord(mediaUniqueKey: vid)
    }
    
    public class func takeOverAudioRightOfControl() {
        do {
            try AVAudioSession.sharedInstance().setCategory(.playback, options: .allowBluetooth)
            try AVAudioSession.sharedInstance().setActive(true)
        } catch {
            print("设置或者激活 AVAudioSession 类别时发生错误: \(error)")
        }
        
    }
}

extension TYPlayer {
    
    public class func showDebugView(toWindwow: UIWindow) {
        DispatchQueue.main.async {
            TTVideoEngine.showDebugTool(toWindwow, in: CGRect(x: 0, y: 90, width: 300, height: 580))
        }
        
    }
    
    public class func openPlayerLog(isOpen: Bool = true) {
        guard isOpen else {return}
//        TTVideoEngine.setLogFlag(.engine)
        // 建议开发的过程中打开 logcat 日志，获取更多播放信息
        TTVideoEngine.setLogFlag(.all)
    }
    
}


extension TYPlayer {
    /// 切换播放器清晰度
    public func changePlayerResolution(resolutionType: TYSDKPlayerResolutionType,completion: @escaping (_ isSuccess: Bool) -> Void) {
           
        manager.changePlayerResolution(resolutionType: resolutionType,completion: completion)
    }
}



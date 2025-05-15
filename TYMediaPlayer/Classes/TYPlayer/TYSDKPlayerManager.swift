//
//  QYSDKPlayerManager.swift
//  MYMediaFeedListAndPlayer_Example
//
//  Created by YannMacMini on 2024/11/5.
//  Copyright © 2024 CocoaPods. All rights reserved.
//


import TTSDKFramework


@objc
enum SDKPlayerVideoSourceType: UInt {
    /// 包含本地url 和远程服务器url
    case videoUrl
    /// Vid 方式播放视频。您需要将播放器的 vid 参数设为视频点播服务生成的 Vid，将 playAuthToken 参数设为临时播放 Token
    case vid
}



@objcMembers
class TYSDKPlayerManager: NSObject,FPPlayerMediaPlayback {
    
    // MARK: - FPPlayerMediaPlayback协议属性
    var view: UIView {
        if let engine = engine {
            return engine.playerView
        }
        return UIView()
    }
    
    
    var volume: Float {
        set {
            engine?.volume = CGFloat(newValue)
        }
        
        get {
            Float(engine?.volume ?? 0)
        }
    }
    
    var isMuted: Bool {
        set {
            engine?.muted = newValue
        }
        
        get {
            engine?.muted ?? false
        }
    }
    
    var rate: Float = 1 {
        didSet {
            engine?.playbackSpeed = CGFloat(rate)
        }
    }
    
    var currentTime: TimeInterval {
        engine?.currentPlaybackTime ?? 0
    }
    
    var totalTime: TimeInterval {
        engine?.duration ?? 0
    }
    
    var bufferTime: TimeInterval {
        engine?.playableDuration ?? 0
    }
    
    
    var seekTime: TimeInterval = 0
    
    /// 播放器是否正在播放
    private(set) var isPlaying: Bool = false

    var scalingMode: FPPlayerScalingMode = .none {
        didSet {
            setupPlayerScalingMode(scalingMode: scalingMode)
        }
    }
    
    private(set) var isPreparedToPlay: Bool = false
   
    var shouldAutoPlay: Bool = true
    
    var assetURL: URL? {
        didSet {
            guard assetURL != nil else {
                assert(assetURL != nil,"assetURL can't be nil")
                return
            }
            if engine != nil {
                stop()
            }
            prepareToPlay()
        }
    }
    
    var presentationSize: CGSize = CGSize.zero
    
    private(set) var playState: FPPlayerPlaybackState = .playStateUnknown
    
    
    private(set) var loadState: FPPlayerLoadState = FPPlayerLoadState.unknown
    
    var playerPrepareToPlay: ((any FPPlayerMediaPlayback, URL) -> Void)?
    
    var playerReadyToPlay: ((any FPPlayerMediaPlayback, URL) -> Void)?
    
    var playerPlayTimeChanged: ((any FPPlayerMediaPlayback, TimeInterval, TimeInterval) -> Void)?
    
    var playerBufferTimeChanged: ((any FPPlayerMediaPlayback, TimeInterval) -> Void)?
    
    var playerPlayStateChanged: ((any FPPlayerMediaPlayback, FPPlayerPlaybackState) -> Void)?
    
    var playerLoadStateChanged: ((any FPPlayerMediaPlayback, FPPlayerLoadState) -> Void)?
    
    var playerPlayFailed: ((any FPPlayerMediaPlayback, Any) -> Void)?
    
    var playerDidToEnd: ((any FPPlayerMediaPlayback) -> Void)?
    
    var presentationSizeChanged: ((any FPPlayerMediaPlayback, CGSize) -> Void)?
    
    
    // 其它新增  属性
    
    // public 属性
    var timeRefreshInterval: TimeInterval = 0.5
    
    var currentEnginDidCreate: (() -> Void)?
    
    var playerPrepareToPlayForVidMode: ((any FPPlayerMediaPlayback, _ vidPlayInfoModel: VidPlayInfoModel) -> Void)?
    var playerReadyToPlayForVidModel: ((any FPPlayerMediaPlayback, _ vidPlayInfoModel: VidPlayInfoModel) -> Void)?
    
    var looping: Bool = false {
        didSet {
            engine?.looping = looping
        }
    }
    
    // private 属性
    private var engine: TTVideoEngine?
    private var timer: Timer?
    private var isReadyToPlay = false
    
    var videoSourceType: SDKPlayerVideoSourceType = .videoUrl
    
    
    var vidPlayInfoModel: VidPlayInfoModel? {
        didSet {
            guard vidPlayInfoModel != nil else {
                return
            }
            
            if engine != nil {
                stop()
            }
            // 准备创建播放器engin
            prepareToPlay()
        }
    }
    
    var durationWatched: TimeInterval? {
        engine?.durationWatched
    }
    
    /// 是否正在切换清晰度
    var isChangingResolution: Bool = false
    
    var videoFirstFrameRendFinish: (() -> Void)?
    
    convenience init(videoSourceType: SDKPlayerVideoSourceType) {
        self.init()
        self.videoSourceType = videoSourceType
    }
    
    private override init() {
        super.init()
    }
    
    
    deinit {
        stop()
    }
    
    
}

extension TYSDKPlayerManager {
    // MARK: 检查是否存在预渲染的engin
    /// 检查是否存在预渲染的engin
    final func checkIsExistPreRenderedPlayerEngin(vidPlayInfo: VidPlayInfoModel?) -> Bool {
        // 1.
        guard videoSourceType == .vid else {
            return false
        }
        // 2.
        guard let vidPlayInfoModel = vidPlayInfo,
              vidPlayInfoModel.vid.isEmpty == false else {
            return false
        }
        // 3.
        let enginVideSource: TTVideoEngineMediaSource =  TYPlayerTool.createEngineVidSource(vidPlayInfoModel: vidPlayInfoModel)
        guard let preRenderVideoEngine: TTVideoEngine = TTVideoEngine.getPreRenderVideoEngine(withVideoSource: enginVideSource) else {
            return false
        }
        
        // 当preRenderVideoEngine 不为 nil
        
        // 4.
        guard vidPlayInfoModel.isValid == true else {
            // 关闭无效的engin
            preRenderVideoEngine.stop()
            return false
        }
        
        if preRenderVideoEngine != engine {
            engine?.stop()
        }
        
        isPreparedToPlay = true
        engine = preRenderVideoEngine
        
        currentEnginDidCreate?()
        
        engine?.delegate = self
        engine?.resolutionDelegate = self
        engine?.looping = self.looping
        
        if shouldAutoPlay {
            play()
        } else {
            pause()
        }
        loadState = .prepare
        
        if  videoSourceType == .videoUrl {
            playerPrepareToPlay?(self,assetURL!)
        } else {
            //
            playerPrepareToPlayForVidMode?(self,vidPlayInfoModel)
        }
        
        engine?.delegate?.videoEnginePrepared?(engine!)
        return true
        
    }
    
    
    
    
    public  class func initPlayeSDKWhenAppLaunch(appID: String, licenseFileName: String) {

        //         let configuration = TTSDKConfiguration.defaultConfiguration(withAppID: Constants.TT.appId, licenseName: "l-105565-ch-vod-a-539538")
        //         let vodConfig = TTSDKVodConfiguration()
        //         vodConfig.cacheMaxSize = 300 * 1024 * 1024
        //         configuration.vodConfiguration = vodConfig
        //         TTSDKManager.start(with: configuration)
        
        let configuration = TTSDKConfiguration.defaultConfiguration(withAppID: appID, licenseName: licenseFileName)
        let vodConfig = TTSDKVodConfiguration()
        vodConfig.cacheMaxSize = 1000 * 1024 * 1024
        configuration.vodConfiguration = vodConfig
        TTSDKManager.start(with: configuration)
    }
}

// MARK: - 其它private方法
extension TYSDKPlayerManager {
    
    private func createPlayer(assetURL: URL) {
        
        if engine != nil {
            // 异步关闭播放器，不影响主线程
            engine?.closeAysnc()
            // 记得移除视图
            engine?.playerView.removeFromSuperview()
            // engine实例置为空
            engine = nil;
        }
        isPreparedToPlay = true
        // 初始化播放器实例并以属性持有
        engine = TTVideoEngine(ownPlayer: true)
        
        
        let isFilePath =  assetURL.absoluteString.hasPrefix("file://")
        if isFilePath {
            engine?.setLocalURL(assetURL.absoluteString)
        } else {
            let urlSource = TTVideoEngineUrlSource(url: assetURL.absoluteString, cacheKey:assetURL.absoluteString)
            engine?.setVideoEngineVideoSource(urlSource)
        }
        
        engine?.delegate = self
        engine?.resolutionDelegate = self
        
        // 该方法适用于预渲染策略。您设置播放源后，需要调用此方法，播放器会渲染第一帧，但不会马上播放。
        engine?.prepareToPlay()
        
    }
    
    
    private func createPlayer(vidPlayInfoModel: VidPlayInfoModel) {
        
        if engine != nil {
            // 异步关闭播放器，不影响主线程
            engine?.closeAysnc()
            // 记得移除视图
            engine?.playerView.removeFromSuperview()
            // engine实例置为空
            engine = nil;
        }
        
        guard vidPlayInfoModel.isValid == true else {
            return
        }
        
        isPreparedToPlay = true
        
        // 初始化播放器实例并以属性持有
        
        engine = TTVideoEngine(ownPlayer: true)
        
        currentEnginDidCreate?()
        
        let vid = vidPlayInfoModel.vid
        let playAuthToken = vidPlayInfoModel.playAuthToken
        
        guard vid.isEmpty == false, playAuthToken.isEmpty == false else {
            return
        }
        
        let enginVideSource: TTVideoEngineMediaSource =  TYPlayerTool.createEngineVidSource(vidPlayInfoModel: vidPlayInfoModel)
        engine?.setVideoEngineVideoSource(enginVideSource)
        
        engine?.delegate = self
        engine?.resolutionDelegate = self
        engine?.looping = self.looping
        
        engine?.reportLogEnable = true
        engine?.setOptionForKey(VEKKey.VEKKeyPlayerHardwareDecode_BOOL.rawValue, value:  true)
        engine?.setOptionForKey(VEKKey.VEKKeyPlayerSeekEndEnabled_BOOL.rawValue, value:  true)
        engine?.setOptionForKey(VEKKey.VEKKEYPlayerKeepFormatAlive_BOOL.rawValue, value:  true)
        engine?.setOptionForKey(VEKKey.VEKKeyPlayerh265Enabled_BOOL.rawValue, value:  true)
        engine?.setOptionForKey(VEKKey.VEKKeyPlayerIdleTimerAuto_NSInteger.rawValue, value:  1)
        
        let targetResolutionType: TTVideoEngineResolutionType = convertResolutionType(modelResolutionType: vidPlayInfoModel.resolutionType)
        engine?.configResolution(targetResolutionType)
        // MP4 播放源平滑切换
        engine?.setOptionForKey(VEKKey.VEKKeyPlayerBashEnabled_BOOL.rawValue, value:  true)
        engine?.setOptionForKey(VEKKey.VEKeyPlayerSegmentFormatFlag.rawValue,
                                                 value:  (TTVideoEngineDashSegmentFlag.formatMp4 , TTVideoEngineDashSegmentFlag.formatFMP4))
        
        // 该方法适用于预渲染策略。您设置播放源后，需要调用此方法，播放器会渲染第一帧，但不会马上播放。
        engine?.prepareToPlay()
        
    }
    
    private func timerUpdate() {
        if currentTime > 0, isReadyToPlay == false {
            isReadyToPlay = true
            loadState = .playThroughOK
        }
        
        playerPlayTimeChanged?(self,currentTime,totalTime)
        playerBufferTimeChanged?(self,bufferTime)
    }
    
    private func setupPlayerScalingMode(scalingMode: FPPlayerScalingMode) {
        switch scalingMode {
        case .none: // 无拉伸，不会有变形，可能有黑边
            engine?.setOptionForKey(VEKKey.VEKKeyViewScaleMode_ENUM.rawValue, value: TTVideoEngineScalingMode.none.rawValue)
            break
        case .aspectFit: // 等比例适配，不会有变形，按照视频宽高等比适配画面，可能有黑边
            engine?.setOptionForKey(VEKKey.VEKKeyViewScaleMode_ENUM.rawValue, value: TTVideoEngineScalingMode.aspectFit.rawValue)
            break
        case .aspectFill: // 等比例填充，不会有变形，按照视频宽高等比充满画面，可能有画面裁切
            engine?.setOptionForKey(VEKKey.VEKKeyViewScaleMode_ENUM.rawValue, value: TTVideoEngineScalingMode.aspectFill.rawValue)
            break
        case .fill: // 拉伸填充，视频宽高比例与画面比例不一致，会导致画面变形
            engine?.setOptionForKey(VEKKey.VEKKeyViewScaleMode_ENUM.rawValue, value: TTVideoEngineScalingMode.fill.rawValue)
            break
        default:
            break
        }
    }
}


// MARK: - FPPlayerMediaPlayback协议方法
extension TYSDKPlayerManager {
    // 协议方法
    func prepareToPlay() {
        // url 播放
        if videoSourceType == .videoUrl {
            guard let assetURL = assetURL else {
                return
            }
            
            isPreparedToPlay = true
            createPlayer(assetURL: assetURL)
            
            
            if shouldAutoPlay {
                play()
            } else {
                pause()
            }
            loadState = .prepare
            playerPrepareToPlay?(self,assetURL)
            return
        }
        
        // vid 播放
        guard let vidPlayInfoModel = vidPlayInfoModel else {
            return
        }
        isPreparedToPlay = true
        
        createPlayer(vidPlayInfoModel: vidPlayInfoModel)
        if shouldAutoPlay {
            play()
        } else {
            pause()
        }
        loadState = .prepare
        
        if  videoSourceType == .videoUrl {
            playerPrepareToPlay?(self,assetURL!)
        } else {
            //
            
            playerPrepareToPlayForVidMode?(self,vidPlayInfoModel)
        }
    }
    
    func reloadPlayer() {
        prepareToPlay()
    }
    
    func play() {
        guard isPreparedToPlay else {
            prepareToPlay()
            return
        }
        engine?.play()
        if let timer = timer {
            // 开启定时器
            timer.fireDate = Date()
        }
        
        engine?.playbackSpeed = CGFloat(rate)
        isPlaying = true
        playState = .playStatePlaying
    }
    
    func pause() {
        isPlaying = false
        if let timer = timer {
            // 暂停定时器
            timer.fireDate = Date.distantFuture
        }
        engine?.pause()
        isPlaying = false
        playState = .playStatePaused
    }
    
    func replay() {
        seek(toTime: 0) {[weak self] isFinished in
            if isFinished {
                self?.play()
            }
        }
    }
    
    func stop() {
        engine?.stop()
        // 异步关闭播放器，不影响主线程
        engine?.closeAysnc()
        // 记得移除视图
        engine?.playerView.removeFromSuperview()
        // engine实例置为空
        engine = nil;
        
        if assetURL != nil  {  assetURL = nil }
        if vidPlayInfoModel != nil { vidPlayInfoModel = nil }
        timer?.invalidate()
        timer = nil
        presentationSize = CGSize.zero
        
        isPlaying = false
        isPreparedToPlay = false
        isReadyToPlay = false
        
    }
    
    func seek(toTime time: TimeInterval, completionHandler: ((Bool) -> Void)? = nil) {
        guard totalTime > 0 else {
            seekTime = time
            return
        }
        engine?.setCurrentPlaybackTime(time, complete: { isSuccess in
            completionHandler?(isSuccess);
        })
    }
    
    
}

extension TYSDKPlayerManager: TTVideoEngineResolutionDelegate {
    // 视频分辨率发生变化回调
    func videoSizeDidChange(_ videoEngine: TTVideoEngine, videoWidth: Int, videoHeight: Int) {
        presentationSizeChanged?(self,CGSize(width: videoWidth, height: videoHeight))
    }
}

// MARK: - TTVideoEngineDelegate
extension TYSDKPlayerManager: TTVideoEngineDelegate {
    // 播放停止回调。 如果您调用了 `stop` 方法，执行完毕 SDK 触发此回调。
    func videoEngineUserStopped(_ videoEngine: TTVideoEngine) {
        
    }
    
    // 播放结束回调
    func videoEngineDidFinish(_ videoEngine: TTVideoEngine, error: (any Error)?) {
        // error` 为空表示正常结束播放   `error` 不为空表示播放失败，`error` 对应具体的错误信息
        if error == nil { // error` 为空表示正常结束播放
            playState = .playStatePlayStopped
            playerDidToEnd?(self)
        } else { // 不为空表示播放失败，`error` 对应具体的错误信息
            playState = .playStatePlayFailed
            playerPlayFailed?(self,error!)
        }
    }
    
    // 异常播放结束回调
    func videoEngineDidFinish(_ videoEngine: TTVideoEngine, videoStatusException status: Int) {
        playState = .playStatePlayFailed
        
        let err = NSError(domain: assetURL?.absoluteString ?? "", code: status)
        playerPlayFailed?(self,err)
    }
    
    // 播放器实例销毁回调
    func videoEngineCloseAysncFinish(_ videoEngine: TTVideoEngine) {
        
    }
    
    // 播放器各模块准备完成、可以播放
    func videoEnginePrepared(_ videoEngine: TTVideoEngine) {

        guard isChangingResolution == false else {
            return
        }
        
        if  timer == nil {
            timer = Timer.scheduledTimer(withTimeInterval: timeRefreshInterval, repeats: true) {[weak self] _ in
                guard let self = self else { return }
                self.timerUpdate()
            }
            RunLoop.main.add(timer!, forMode: RunLoop.Mode.common)
        }
        
        if isPlaying {
            play()
            
            if seekTime > 0 {
                seek(toTime: seekTime, completionHandler: nil)
                seekTime = 0; // 清空, 防止下次播放出错
                play()
            }
            
        }
        
        if  videoSourceType == .videoUrl {
            if let assetURL = assetURL {
                playerReadyToPlay?(self,assetURL)
            }
        } else {
            if let vidPlayInfoModel = vidPlayInfoModel {
                playerReadyToPlayForVidModel?(self,vidPlayInfoModel)
            }
        }
        
        
    }
    
    // 显示视频的首帧，可以根据该回调隐藏封面图，显示视频画面
    func videoEngineReady(toDisPlay videoEngine: TTVideoEngine) {
        videoFirstFrameRendFinish?()
    }
    
    
    
    // 内部加载状态发生变化时 SDK 会触发此回调。您可以根据此回调显示或者隐藏 loading 视图。
    func videoEngine(_ videoEngine: TTVideoEngine, loadStateDidChanged loadState: TTVideoEngineLoadState, extra extraInfo: [String : Any]?) {
        switch loadState {
        case .playable:
            // 加载状态变成了缓存数据足够开始播放，但是视频并没有缓存完全
            self.loadState = .playable
            break
        case .stalled:
            // 播放器发生卡顿，正在加载数据。网速不好等因素导致了暂停
            self.loadState = .stalled
            break
        case .error:
            self.loadState = .error
        default:
            self.loadState = .unknown
        }
        
        playerLoadStateChanged?(self, self.loadState)
    }
    
    func videoEngine(_ videoEngine: TTVideoEngine, playbackStateDidChanged playbackState: TTVideoEnginePlaybackState) {
        switch playbackState {
        case .stopped:
            playState = .playStatePlayStopped
            break
        case .playing:
            playState = .playStatePlaying
            break
            
        case .paused:
            playState = .playStatePaused
            break
            
        case .error:
            playState = .playStatePlayFailed
        default:
            playState = .playStateUnknown
        }
        
        playerPlayStateChanged?(self,playState)
    }
    
    
}


extension TYSDKPlayerManager {
    /// 切换播放器清晰度
    public func changePlayerResolution(resolutionType: TYSDKPlayerResolutionType,completion: @escaping (_ isSuccess: Bool) -> Void) {
        isChangingResolution = true
        guard let allResolutions = engine?.supportedResolutionTypes() else {
            completion(false)
            isChangingResolution = false
            return
        }
        
        let targetResolutionType: TTVideoEngineResolutionType = convertResolutionType(modelResolutionType: resolutionType)
        
        guard let currentResolution = engine?.currentResolution,currentResolution != targetResolutionType else {
            completion(true)
            isChangingResolution = false
            return
        }
        
        var isSupport = false
        for r in allResolutions {
            
            if r.intValue == targetResolutionType.rawValue {
                isSupport = true
                break
            }
        }
        
        guard isSupport else {
            print("播放器不支持此清晰度")
            completion(false)
            isChangingResolution = false
            return
        }
        // 切换
        engine?.configResolution(targetResolutionType) {[weak self] success, videoEngineResolutionType in
            DispatchQueue.main.async {
                guard success else {
                    print("播放器切换清晰度失败,请稍后再试")
                    completion(false)
                    self?.isChangingResolution = false
                    return
                }
                completion(true)
                self?.isChangingResolution = false
            }
           
        }
    }
    
    private func convertResolutionType(modelResolutionType: TYSDKPlayerResolutionType) -> TTVideoEngineResolutionType {
        
        var engineResolution: TTVideoEngineResolutionType
        
        switch modelResolutionType {
        case .resolution720P:
            engineResolution = .typeFullHD
        case .resolution1080P:
            engineResolution = .type1080P
        case .resolution540P:
            engineResolution = .typeHD_H
        }
        return engineResolution
    }
}

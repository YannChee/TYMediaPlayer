//
//  TYMediaPlayRecoredManager.swift
//  MYMediaFeedListAndPlayer
//
//  Created by YannMacMini on 2025/3/5.
//

import Foundation

class TYMediaPlayRecoredManager {
    private static var playRecordDict: [String : TimeInterval] = [:]
    
    private static let cacheKey = "MYMediaPlayRecoredManager_cacheKey"
}

extension TYMediaPlayRecoredManager {
    
    class func storeRecord(mediaUniqueKey: String, playTime: TimeInterval) {
        DispatchQueue.main.async {
            playRecordDict[mediaUniqueKey] = playTime
        }
        
    }
    
    class func getRecord(mediaUniqueKey: String?) -> TimeInterval? {
        guard let mediaUniqueKey = mediaUniqueKey, mediaUniqueKey.count > 0 else {
            return nil
        }
        return playRecordDict[mediaUniqueKey]
    }
}

extension TYMediaPlayRecoredManager {
    class func storeAllRecoredToDisk() {
        UserDefaults.standard.set(playRecordDict, forKey: cacheKey)
    }
    
    class func readDiskCache() -> [String : TimeInterval]?  {
        let cachedDict: [String : TimeInterval]? = UserDefaults.standard.object(forKey: cacheKey) as? [String : TimeInterval]
        return cachedDict
        
    }
}

//
//  TTVideoEngine+SubTitle.h
//  TTVideoEngine
//
//  Created by haocheng on 2020/11/4.
//

#import "TTVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

//sub model json field name
extern NSString *const kTTVideoEngineSubModelURLKey;
extern NSString *const kTTVideoEngineSubModelLangIdKey;
extern NSString *const kTTVideoEngineSubModelFormatKey;
extern NSString *const kTTVideoEngineSubModelIndexKey;
extern NSString *const kTTVideoEngineSubModelLanguageKey;
extern NSString *const kTTVideoEngineSubModelExpireTimeKey;
extern NSString *const kTTVideoEngineSubModelListKey;
extern NSString *const kTTVideoEngineSubModelSubtitleIdKey;
extern NSString *const kTTVideoEngineSubModelSourceKey;
extern NSString *const kTTVideoEngineSubModelVersionKey;
extern NSString *const kTTVideoEngineSubModelCacheKey;

/**
 * @locale zh
 * @type keytype
 * @brief 所有语言的字幕数据源协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief Subtitle data source protocol for all languages.
 */
@protocol TTVideoEngineSubDecInfoProtocol <NSObject>

/**
 * @locale zh
 * @brief 注入 JSON 格式的字幕数据源。
 * @return 返回 JSON 格式的字幕源数据。
 */
/**
 * @locale en
 * @brief Inject JSON-formatted subtitle data source.
 * @type api
 */
- (NSString *_Nullable)jsonString;
/**
 * @locale zh
 * @brief 获取字幕语言的个数。
 * @return 返回字幕语言的个数。
 */
/**
 * @locale en
 * @brief Retrieve the number of subtitle languages.
 * @type api
 */
- (NSInteger)subtitleCount;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 单个语言的字幕数据源协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief Single language subtitle data source protocol.
 */
@protocol TTVideoEngineSubProtocol <NSObject>

/**
 * @locale zh
 * @brief 字幕语言 ID。详见[字幕语言](https://www.volcengine.com/docs/4/70518#%E5%AD%97%E5%B9%95%E8%AF%AD%E8%A8%80)。
 */
/**
 * @locale en
 * @brief Subtitle language ID. Refer to [Subtitle Languages](https://www.volcengine.com/docs/4/70518#%E5%AD%97%E5%B9%95%E8%AF%AD%E8%A8%80).
 */
@property (nonatomic, assign, readonly) NSInteger languageId;
/**
 * @locale zh
 * @brief 字幕 URL 地址。
 */
/**
 * @locale en
 * @brief Subtitle URL address.
 */
@property (nonatomic, copy, readonly) NSString *urlString;
/**
 * @locale zh
 * @brief 字幕格式。
 */
/**
 * @locale en
 * @brief Subtitle format.
 */
@property (nonatomic, copy, readonly) NSString *format;
/**
 * @locale zh
 * @brief 字幕 ID。
 */
/**
 * @locale en
 * @brief Subtitle ID.
 */
@property (nonatomic, assign, readonly) NSInteger subtitleId;
/**
 * @locale zh
 * @brief 本地缓存唯一标识。
 */
/**
 * @locale en
 * @brief Subtitle cache key.
 */
@property (nonatomic, copy, readonly) NSString *cacheKey;

/**
 * @locale zh
 * @brief 将字幕数据源 Model 转换为 Dictionary。
 */
/**
 * @locale en
 * @brief Convert the subtitle data source model into a dictionary.
 * @type api
 */
- (NSDictionary *_Nullable)toDictionary;
/**
 * @locale zh
 * @brief 将字幕数据源 Model 转换为 JSON String。
 */
/**
 * @locale en
 * @brief Convert Subtitle Data Source Model to JSON String.
 * @type api
 */
- (NSString *_Nullable)jsonString;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 单个语言的字幕数据源，遵守 [TTVideoEngineSubProtocol](803941#TTVideoEngineSubProtocol)  协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief The subtitle data source for a single language adheres to the [TTVideoEngineSubProtocol](ios-player-sdk-type-definitions#TTVideoEngineSubProtocol) protocol.
 */
@interface TTVideoEngineSubModel : NSObject <TTVideoEngineSubProtocol>

/**
 * @locale zh
 * @brief 当前字幕 index。
 */
/**
 * @locale en
 * @brief Current subtitle index.
 */
@property (nonatomic, assign, readonly) NSInteger index;
/**
 * @locale zh
 * @brief 字幕语言，详见[字幕语言](https://www.volcengine.com/docs/4/70518#%E5%AD%97%E5%B9%95%E8%AF%AD%E8%A8%80)。
 */
/**
 * @locale en
 * @brief For subtitle languages, see [Subtitle Languages](https://www.volcengine.com/docs/4/70518#%E5%AD%97%E5%B9%95%E8%AF%AD%E8%A8%80).
 */
@property (nonatomic, copy, readonly) NSString *language;
/**
 * @locale zh
 * @brief 字幕过期时间戳。精度为毫秒的 Unix 时间戳。
 */
/**
 * @locale en
 * @brief Subtitle expiration timestamp. Unix timestamp with millisecond precision.
 */
@property (nonatomic, assign, readonly) NSInteger expireTime;
/**
 * @locale zh
 * @brief 本地缓存唯一标识。
 */
/**
 * @locale en
 * @brief Subtitle cache key.
 */
@property (nonatomic, copy, readonly) NSString *cacheKey;

/**
 * @locale zh
 * @brief 初始化单个语言的字幕数据源。
 * @return 返回单个语言的字幕源数据 [TTVideoEngineSubModel](803941#TTVideoEngineSubModel) 。
 * @param dict 字幕数据源。
 */
/**
 * @locale en
 * @brief Initialize a subtitle data source for a single language.
 * @type api
 * @param dict Subtitle Data Source.
 */
- (instancetype)initWithDictionary:(NSDictionary * _Nonnull)dict;
/**
 * @locale zh
 * @brief 将字幕数据源 Model 转换为 Dictionary。
 */
/**
 * @locale en
 * @brief Convert the subtitle data source Model into a Dictionary.
 * @type api
 */
- (NSDictionary *_Nullable)toDictionary;
/**
 * @locale zh
 * @brief 将字幕数据源 Model 转换为 JSON String。
 */
/**
 * @locale en
 * @brief Convert the subtitle data source model to a JSON string.
 * @type api
 */
- (NSString *_Nullable)jsonString;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 所有语言的字幕数据源，遵守 [TTVideoEngineSubDecInfoProtocol](803941#TTVideoEngineSubDecInfoProtocol)  协议。
 */
/**
 * @locale en
 * @type keytype
 * @brief All subtitle data sources must adhere to the [TTVideoEngineSubDecInfoProtocol](ios-player-sdk-type-definitions#TTVideoEngineSubDecInfoProtocol) protocol.
 */
@interface TTVideoEngineSubDecInfoModel : NSObject <TTVideoEngineSubDecInfoProtocol>

/**
 * @locale zh
 * @brief 所有字幕源列表。
 * @type api
 */
/**
 * @locale en
 * @brief list of all subtitle sources.
 * @type api
 */
@property (nonatomic, strong, readonly) NSMutableArray<id<TTVideoEngineSubProtocol>> *subModels;

/**
 * @locale zh
 * @brief 初始化所有语言的字幕数据源。
 * @param dict Dictionary 格式的字幕数据源。
 * @return 返回字幕数据源 Model。
 */
/**
 * @locale en
 * @brief Initialize the subtitle data sources for all languages.
 * @type api
 * @param dict Dictionary format subtitle data source.
 */
- (instancetype)initWithDictionary:(NSDictionary *_Nonnull)dict;
/**
 * @locale zh
 * @brief 初始化所有语言的字幕数据源。
 * @return 返回字幕数据源 [TTVideoEngineSubDecInfoModel](803941#TTVideoEngineSubDecInfoModel)  实例。
 * @param models 字幕数据源 [TTVideoEngineSubModel](803941#TTVideoEngineSubModel)  数组。
 */
/**
 * @locale en
 * @brief Initialize subtitle data sources for all languages.
 * @type api
 * @param models An array of subtitle data sources [TTVideoEngineSubModel](ios-player-sdk-type-definitions#TTVideoEngineSubModel).
 */
- (instancetype)initWithSubModels:(NSArray<id<TTVideoEngineSubProtocol>> *_Nonnull)models;
/**
 * @locale zh
 * @brief 增加单个语言的字幕数据源。
 * @param model 单个语言的字幕数据源 [TTVideoEngineSubDecInfoModel](803941#TTVideoEngineSubDecInfoModel) 。
 */
/**
 * @locale en
 * @brief Add subtitle data source for a single language.
 * @type api
 * @param model Subtitle data source for a single language [TTVideoEngineSubDecInfoModel](ios-player-sdk-type-definitions#TTVideoEngineSubDecInfoModel).
 */
- (void)addSubModel:(id<TTVideoEngineSubProtocol> _Nonnull)model;

/**
 * @locale zh
 * @brief 获取字幕源 JSON String。
 * @return 返回字幕源 JSON String。
 */
/**
 * @locale en
 * @brief Retrieve subtitle source JSON string.
 * @type api
 */
- (NSString *_Nullable)jsonString;
/**
 * @locale zh
 * @brief 获取字幕源个数。
 * @return 返回字幕源个数。
 */
/**
 * @locale en
 * @brief Retrieve the number of subtitle sources.
 * @type api
 */
- (NSInteger)subtitleCount;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 单段字幕信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Single subtitle information.
 */
@interface TTVideoEngineSubInfo: NSObject

/**
 * @locale zh
 * @brief 该段字幕对应的时间戳，单位为毫秒。
 */
/**
 * @locale en
 * @brief The timestamp corresponding to the subtitle segment, measured in milliseconds.
 */
@property (nonatomic, assign) NSInteger pts;
/**
 * @locale zh
 * @brief 该段字幕的内容。
 */
/**
 * @locale en
 * @brief The content of this subtitle.
 */
@property (nonatomic, copy) NSString *content;
/**
 * @locale zh
 * @brief 该段字幕持续的时间，单位为毫秒。
 */
/**
 * @locale en
 * @brief The duration of the subtitle segment, measured in milliseconds.
 */
@property (nonatomic, assign) NSInteger duration;

@end

/**
 * @locale zh
 * @type keytype
 * @brief 播放器字幕加载信息。
 */
/**
 * @locale en
 * @type keytype
 * @brief Player Subtitle Loading Information.
 */
@interface TTVideoEngineLoadInfo: NSObject

/**
 * @locale zh
 * @brief 首段字幕展示时间戳。
 */
/**
 * @locale en
 * @brief Timestamp for displaying the first subtitle.
 */
@property (nonatomic, assign) NSInteger firstPts;
/**
 * @locale zh
 * @brief 字幕加载状态。`code` 为 `0` 表示加载成功。
 */
/**
 * @locale en
 * @brief The subtitle loading status.  `code` with a value of `0` indicates successful loading.
 */
@property (nonatomic, assign) NSInteger code;

/**
 * @locale zh
 * @brief 字幕加载阶段状态码，用于字幕加载失败问题分析
 */
/**
 * @locale en
 * @brief The status code of subtitle loading stage, used for analyzing subtitle loading failure
 */
@property (nonatomic, assign) NSInteger loadStageCode;

@end

/**
 * @locale zh
 * @type callback
 * @brief 字幕相关回调。
 */
/**
 * @locale en
 * @type callback
 * @brief Subtitles-related callback.
 */
@protocol TTVideoEngineSubtitleDelegate <NSObject>

@optional

/**
 * @locale zh
 * @type callback
 * @brief 获取到单段字幕信息的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param content 该段字幕的内容。
 * @param pts 该段字幕对应的时间戳，单位为毫秒。
 */
/**
 * @locale en
 * @brief Callback for retrieving a single subtitle segment's information.
 * @type api
 * @param videoEngine The `videoEngine` object.
 * @param content The content of this subtitle.
 * @param pts The timestamp corresponding to the subtitle segment, in milliseconds.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubtitleInfoCallBack:(NSString *)content pts:(NSUInteger)pts;

/**
 * @locale zh
 * @type callback
 * @brief 获取到单段字幕信息的回调。
 * @param videoEngine `videoEngine` 对象。
 * @param subInfo 单段字幕信息，详见 [TTVideoEngineSubInfo](803941#TTVideoEngineSubInfo) 。
 */
/**
 * @locale en
 * @brief Callback for retrieving information of a single subtitle segment.
 * @type api
 * @param videoEngine The `videoEngine` object.
 * @param subInfo Single segment subtitle information, see [TTVideoEngineSubInfo](ios-player-sdk-type-definitions#TTVideoEngineSubInfo) for details.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubtitleInfoCallBack:(TTVideoEngineSubInfo *)subInfo;

/**
 * @locale zh
 * @type callback
 * @brief 获取到所有语言字幕信息回调。
 * @param videoEngine `videoEngine` 对象。
 * @param info 所有语言字幕信息 JSON。
 * @param error 请求字幕错误信息。`error` 为 `nil` 表示请求成功。
 */
/**
 * @locale en
 * @brief Callback for retrieving information of all language subtitles.
 * @type api
 * @param videoEngine The `videoEngine` object.
 * @param info JSON for subtitles in all languages.
 * @param error The request subtitle error message. A value of `nil` for `error` indicates a successful request.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubtitleInfoRequested:(id _Nullable)info error:(NSError * _Nullable)error DEPRECATED_MSG_ATTRIBUTE("use videoEngine:onSubtitleInfoRequestFinish:error");

/**
 * @locale zh
 * @type callback
 * @brief 获取到所有语言字幕信息回调。
 * @param videoEngine `videoEngine` 对象。
 * @param subtitleInfoModel 所有语言字幕信息 InfoModel。
 * @param error 请求字幕错误信息。`error` 为 `nil` 表示请求成功。
 */
/**
 * @locale en
 * @brief Callback for retrieving information of all language subtitles.
 * @type api
 * @param videoEngine The `videoEngine` object.
 * @param subtitleInfoModel subtitle info model for all languages.
 * @param error The request subtitle error message. A value of `nil` for `error` indicates a successful request.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubtitleInfoRequestFinish:(TTVideoEngineSubDecInfoModel *)subtitleInfoModel error:(NSError * _Nullable)error;

/**
 * @locale zh
 * @type callback
 * @brief 字幕语言切换回调。
 * @param videoEngine `videoEngine` 对象。
 * @param success 字幕语言是否成功切换：<br>
 *                - YES: 成功。<br>
 *                - NO: 失败。
 * @param currentSubtitleId 当前字幕 ID。
 */
/**
 * @locale en
 * @brief Subtitle language switch callback.
 * @type api
 * @param videoEngine The `videoEngine` object.
 * @param success Whether subtitle language was successfully switched:<br>
 *        - YES: Success.<br>
 *        - NO: Failure.
 * @param currentSubtitleId Current subtitle ID.
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubSwitchCompleted:(BOOL)success currentSubtitleId:(NSInteger)currentSubtitleId;

/**
 * @locale zh
 * @type callback
 * @hidden
 * @brief 字幕回调，已过时，请尽快使用推荐替代方法。
 */
/**
 * @locale en
 * @brief Subtitle callback , deprecated, Please use the recommended alternative method as soon as possible.
 * @type api
 * @hidden (iOS)
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubLoadFinished:(BOOL)success DEPRECATED_MSG_ATTRIBUTE("use videoEngine:onSubLoadFinished:info:");

/**
 * @locale zh
 * @hidden
 * @type callback
 * @brief 字幕加载回调。
 * @param videoEngine `videoEngine` 对象。
 * @param success 字幕是否成功加载：<br>
 *                - YES: 成功。<br>
 *                - NO: 失败。
 * @param info 字幕加载信息，详见 [TTVideoEngineLoadInfo](803941#TTVideoEngineLoadInfo) 。
 */
/**
 * @locale en
 * @brief Subtitle loading callback.
 * @type api
 * @param videoEngine `videoEngine` object.
 * @param success Subtitle load status:<br>
 *        - YES: Success.<br>
 *        - NO: Failure.
 * @param info Subtitle loading information, see [TTVideoEngineLoadInfo](ios-player-sdk-type-definitions#TTVideoEngineLoadInfo) for details.
 * @hidden (iOS)
 */
- (void)videoEngine:(TTVideoEngine *)videoEngine onSubLoadFinished:(BOOL)success info:(TTVideoEngineLoadInfo * _Nullable)info;

/**
 * @locale zh
 * @type callback
 * @brief 自定义本地缓存字幕 cache key
 * @param videoEngine `videoEngine` 对象
 * @param subTitleUrl 请求字幕地址
 * @param extendInfo 字幕其它息
 * @return 返回本地缓存字幕 cache key
 */
- (NSString *)videoEngine:(TTVideoEngine *)videoEngine generateSubtitleCachKey:(NSString *)subTitleUrl extendInfo:(NSDictionary *)extendInfo;

@end

@interface TTVideoEngine()
/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 请求字幕信息 Host
 */
/**
 * @locale en
 * @brief Request Subtitle Information Host
 * @hidden (iOS)
 */
@property (nonatomic, copy) NSString *subtitleHostName;
/**
 * @locale zh
 * @type api
 * @brief 设置字幕相关回调，详见 [TTVideoEngineSubtitleDelegate](518261#TTVideoEngineSubtitleDelegate) 。
 */
/**
 * @locale en
 * @brief Set subtitle-related callbacks. For details, see [TTVideoEngineSubtitleDelegate](ios-player-sdk-callbacks#TTVideoEngineSubtitleDelegate).
 */
@property (nonatomic, weak, nullable) id<TTVideoEngineSubtitleDelegate> subtitleDelegate;
/**
 * @locale zh
 * @type api
 * @brief 设置字幕数据源，详见 [TTVideoEngineSubDecInfoProtocol](803941#TTVideoEngineSubDecInfoProtocol) 。
 */
/**
 * @locale en
 * @brief Set the subtitle data source, for details see [TTVideoEngineSubDecInfoProtocol](ios-player-sdk-type-definitions#TTVideoEngineSubDecInfoProtocol).
 */
@property (nonatomic, weak) id<TTVideoEngineSubDecInfoProtocol> subDecInfoModel;

@end

/**
 * @locale zh
 * @type api
 * @brief 字幕相关方法
 * @pos 9
 */
/**
 * @locale en
 * @brief Subtitle-Related Methods
 * @pos 9
 * @type api
 */
@interface TTVideoEngine(SubTitle)

/**
 * @locale zh
 * @type api
 * @brief 获取支持的字幕 ID 列表。
 * @return 返回支持的字幕 ID 列表。
 */
/**
 * @locale en
 * @brief Retrieve the list of supported subtitle IDs.
 * @return Return a list of supported subtitle IDs.
 */
- (NSArray * _Nullable)subtitleIDs;
/**
 * @locale zh
 * @type api
 * @brief 获取支持的多种语言字幕信息列表。
 * @return 返回 [TTVideoEngineSubModel](803941#TTVideoEngineSubModel)  列表。
 */
/**
 * @locale en
 * @brief Retrieve a list of subtitle information in multiple supported languages.
 * @return Returns a list of [TTVideoEngineSubModel](ios-player-sdk-type-definitions#TTVideoEngineSubModel).
 */
- (NSArray<TTVideoEngineSubModel *> *)subtitleDescriptions;

/**
 * @locale zh
 * @type api
 * @brief 获取 Vid 请求字幕详细信息。
 * @return 返回 Vid 请求字幕详细信息。
 */
/**
 * @locale en
 * @brief Retrieve subtitle details for Vid request.
 * @return Return Vid to request subtitle details.
 */
- (NSDictionary * _Nullable)requestedSubtitleInfo DEPRECATED_MSG_ATTRIBUTE("use TTVideoEngineSubtitleDelegate videoEngine:onSubtitleInfoRequestFinish:error:");
/**
 * @locale zh
 * @type api
 * @brief 获取所有 Vid 请求字幕源详细信息。
 * @return 返回所有 Vid 请求字幕源详细信息。
 */
/**
 * @locale en
 * @brief Get detailed information about subtitle sources for all Vid requests.
 * @return Return detailed information of all subtitle sources requested by Vid.
 */
- (NSArray * _Nullable)subtitleInfos;

/**
 * @locale zh
 * @type api
 * @brief 判断当前视频源是否已内嵌字幕。
 * @return 是否内嵌字幕： <br>
 *         - YES: 是。<br>
 *         - NO: 否。
 */
/**
 * @locale en
 * @brief Check if the current video source has embedded subtitles.
 * @return Is subtitle embedded:<br/>
 *         - YES: Yes.
 *         - NO: No.
 */
- (BOOL)hasEmbeddedSubtitle;

/**
 * @locale zh
 * @type api
 * @brief 切换成另一个语言的字幕。
 * @param subModel 单个语言的字幕数据源信息 [TTVideoEngineSubProtocol](803941#TTVideoEngineSubProtocol) 。
 */
/**
 * @locale en
 * @brief Switch to subtitles in another language.
 * @param subModel Subtitle data source information for a single language can be found in [TTVideoEngineSubProtocol](ios-player-sdk-type-definitions#TTVideoEngineSubProtocol).
 */
- (void)switchNewSubtitleModel:(id<TTVideoEngineSubProtocol>)subModel;

/**
 * @locale zh
 * @hidden
 * @type api
 * @brief 请求字幕详细信息
 * @param hostName 域名
 * @param vid video id
 * @param fileId file id
 * @param language 字幕语言
 * @param client custom client
 * @param completionHandler 请求 block 回调
 */
/**
 * @locale en
 * @hidden
 * @type api
 * @brief Request Subtitle Details
 * @param hostName domain name
 * @param vid video id
 * @param fileId file id
 * @param language Subtitle Language
 * @param client custom client
 * @param completionHandler Request block callback
 * @hidden (iOS)
 */
+ (void)requestSubtitleInfoWith:(NSString * _Nonnull)hostName 
                            vid:(NSString * _Nonnull)vid
                         fileId:(NSString * _Nonnull)fileId
                       language:(NSString * _Nullable)language
                         client:(id<TTVideoEngineNetClient> _Nullable)client
                     completion:(nullable void (^)(id _Nullable jsonObject, NSError * _Nullable error))completionHandler;

/**
 * @locale zh
 * @type api
 * @brief 获取指定播放时间的字幕信息。
 * @return 返回指定播放时间的字幕信息 [TTVideoEngineSubInfo](803941#TTVideoEngineSubInfo) 。
 * @param queryTime 指定的播放时间。
 */
/**
 * @locale en
 * @brief Retrieve subtitle information for a specified playback time.
 * @param queryTime Specified playback time.
 * @return Returns subtitle information at the specified playback time [TTVideoEngineSubInfo](ios-player-sdk-type-definitions#TTVideoEngineSubInfo).
 */
- (TTVideoEngineSubInfo *)getSubtitleInfo:(NSInteger)queryTime;

@end

NS_ASSUME_NONNULL_END

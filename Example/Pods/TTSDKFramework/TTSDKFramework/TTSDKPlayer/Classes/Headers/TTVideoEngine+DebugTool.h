//
//  TTVideoEngine+DebugTool.h
//  TTVideoEngine
//
//  Created by wangzhiyong on 2022/7/1.
//

#import "TTVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @locale zh
 * @type api
 * @brief Debug 工具相关接口，方便您在开发期间查看播放信息和版本信息。
 * @pos 6
 */
/**
 * @locale en
 * @brief Interfaces related to debug tools. Make it convenient to view playback information and version details during development.
 * @pos 6
 * @type api
 */
@interface TTVideoEngine (DebugTool)

/**
 * @locale zh
 * @type api
 * @brief 确认 Debug 工具是否正在显示中。
 * @list Debug 工具
 * @order 1
 */
/**
 * @locale en
 * @type api
 * @list Debug 工具
 * @brief Check whether the debug tool is currently displayed.
 */
+ (BOOL)debugToolIsShowing;

/**
 * @locale zh
 * @type api
 * @brief 添加 Debug 工具。
 * @param containerView 用于展示 Debug 工具的 `containerView`。
 * @notes <br> 
 *        - 调用该方法后，播放器内部会把当前正在播放的 `TTVideoEngine` 实例自动添加到 Debug 工具中，不需要您再频繁地设置 `TTVideoEngine` 实例。<br>
 *        - 该方法适合短视频（例如抖音）、中视频（例如西瓜）等需要频繁切换播放的场景。
 */
/**
 * @locale en
 * @type api
 * @brief Add Debug tools.
 * @param containerView A `containerView` used to display Debug tools.
 * @notes <br>
 *        - After calling this method, the player will automatically add the currently playing `TTVideoEngine` instance to the Debug tool, eliminating the need to frequently set the `TTVideoEngine` instance manually.<br>
 *        - This method is suitable for scenarios requiring frequent playback switches, such as in short videos (e.g., Douyin) and medium videos (e.g., Xigua).
 */
+ (void)showDebugTool:(UIView *)containerView;

/**
 * @locale zh
 * @type api
 * @brief 添加 Debug 工具。
 * @param containerView 用于展示 Debug 工具的 `containerView`。
 * @param rect 设置 debug view 在 container view 中的展示区域。
 * @notes <br> 
 *        - 调用该方法后，播放器内部会把当前正在播放的 `TTVideoEngine` 实例自动添加到 Debug 工具中，不需要您再频繁地设置 `TTVideoEngine` 实例。<br>
 *        - 该方法适合短视频（例如抖音）、中视频（例如西瓜）等需要频繁切换播放的场景。
 * @list Debug 工具
 * @order 0
 */
/**
 * @locale en
 * @type api
 * @list Debug 工具
 * @brief Add Debug tools.
 * @param containerView Used to display the Debug tool's `containerView`.
 * @param rect Set the display area of the debug view in the container view.
 * @notes <br>
 *        - After calling this method, the player will automatically add the currently playing `TTVideoEngine` instance to the Debug tool, so there is no need to frequently set the `TTVideoEngine` instance again.<br>
 *        - This method is suitable for scenarios that require frequent switching of playback, such as short videos (e.g., Douyin) and medium videos (e.g., Xigua).
 */
+ (void)showDebugTool:(UIView *)containerView inRect:(CGRect)rect;

/**
 * @locale zh
 * @type api
 * @brief 刷新当前 Debug 工具关联的 `TTVideoEngine` 实例。
 * @param videoEngine `videoEngine` 对象。
 * @notes 默认情况下，SDK 内部会自动关联正在播放 `TTVideoEngine` 实例。
 * @list Debug 工具
 * @order 2
 */
/**
 * @locale en
 * @type api
 * @list Debug 工具
 * @brief Refresh the `TTVideoEngine` instance associated with the current Debug tool.
 * @param videoEngine The `videoEngine` object.
 * @notes By default, the SDK will automatically associate the currently playing `TTVideoEngine` instance.
 */
+ (void)refreshCurrentVideoEngine:(TTVideoEngine *)videoEngine;

/**
 * @locale zh
 * @type api
 * @brief 移除 Debug 工具。
 * @list Debug 工具
 * @order 3
 */
/**
 * @locale en
 * @type api
 * @list Debug 工具
 * @brief Remove Debug tools.
 */
+ (void)removeDebugTool;

@end

NS_ASSUME_NONNULL_END

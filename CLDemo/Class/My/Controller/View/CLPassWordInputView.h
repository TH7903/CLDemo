//
//  CLPassWordInputView.h
//  CLDemo
//
//  Created by AUG on 2019/1/15.
//  Copyright © 2019年 JmoVxia. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CLPassWordInputView;

@protocol  CLPassWordInputViewDelegate<NSObject>
@optional

/**输入改变*/
- (void)passWordDidChange:(CLPassWordInputView *)passWord;

/**点击删除*/
- (void)passWordDidDeleteBackward:(CLPassWordInputView *)passWord;

/**输入完成*/
- (void)passWordCompleteInput:(CLPassWordInputView *)passWord;

/**开始输入*/
- (void)passWordBeginInput:(CLPassWordInputView *)passWord;

/**结束输入*/
- (void)passWordEndInput:(CLPassWordInputView *)passWord;

@end

@interface CLPassWordInputViewConfigure : NSObject

/**密码的位数*/
@property (nonatomic, assign) NSUInteger passWordNum;
/**边框正方形的大小*/
@property (nonatomic, assign) CGFloat squareWidth;
/**黑点的半径*/
@property (nonatomic, assign) CGFloat pointRadius;
/**边距相对中间间隙倍数*/
@property (nonatomic, assign) CGFloat spaceMultiple;
/**黑点的颜色*/
@property (nonatomic, strong) UIColor *pointColor;
/**边框的颜色*/
@property (nonatomic, strong) UIColor *rectColor;
/**默认配置*/
+ (instancetype)defaultConfig;

@end

@interface CLPassWordInputView : UIView<UIKeyInput>

//代理
@property (nonatomic, weak) id<CLPassWordInputViewDelegate> delegate;
//保存密码的字符串
@property (nonatomic, strong, readonly) NSMutableString *textStore;

/**更新基本配置*/
- (void)updateWithConfig:(void(^)(CLPassWordInputViewConfigure *config))configBlock;

@end

NS_ASSUME_NONNULL_END
//
//  AgoraChatTranslationResult.h
//  AgoraChat
//
//  Created by lixiaoming on 2021/11/9.
//  Copyright © 2021 easemob.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AgoraChatTranslationResult : NSObject
/*!
 *  \~chinese
 *  消息Id
 *
 *  \~english
 *  The Translation's messageId
 */
@property (nonatomic,strong)    NSString* msgId;
/*!
 *  \~chinese
 *  是否显示翻译
 *
 *  \~english
 *  Weather to show the translations
 */
@property (nonatomic,assign)   BOOL showTranslation;
/*!
 *  \~chinese
 *  翻译次数
 *
 *  \~english
 *  How many tims the message have been translated
 */
@property (nonatomic,assign)   NSUInteger translateTimes;
/*!
 *  \~chinese
 *  翻译内容
 *
 *  \~english
 *  The translation result content
 */
@property (nonatomic,strong)   NSString* translations;
@end

NS_ASSUME_NONNULL_END

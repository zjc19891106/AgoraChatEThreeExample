/**
 *  \~chinese
 *  @header AgoraChatTextMessageBody.h
 *  @abstract 文本消息体。
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatTextMessageBody.h
 *  @abstract The text message body.
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "AgoraChatMessageBody.h"

/**
 *  \~chinese 
 *  文本消息体。
 *
 *  \~english 
 *  The text message body.   
 */
@interface AgoraChatTextMessageBody : AgoraChatMessageBody

/**
 *  \~chinese 
 *  文本内容。
 *
 *  \~english 
 *  The text content.
 */
@property (nonatomic, copy, readonly) NSString *text;
 
/**
 *  \~chinese 
 *  初始化文本消息体。
 *
 *  @param aText   文本内容。
 *  
 *  @result 文本消息体实例。
 *
 *  \~english
 *  Initializes a text message body instance.
 *
 *  @param aText   The text content.
 *
 *  @result The text message body instance.
 */
- (instancetype)initWithText:(NSString *)aText;

@end

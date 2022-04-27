/**
 *  \~chinese
 *  @header AgoraChatMessageBody.h
 *  @abstract 消息体类型的基类
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatMessageBody.h
 *  @abstract Base class of message body
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

/**
 *  \~chinese 
 *  消息体类型。
 *
 *  \~english
 *  The enum of message body types.
 */
typedef enum {
    AgoraChatMessageBodyTypeText   = 1,    /** \~chinese 文本消息。 \~english A text message.*/
    AgoraChatMessageBodyTypeImage,         /** \~chinese 图片消息。 \~english An image message.*/
    AgoraChatMessageBodyTypeVideo,         /** \~chinese 视频消息。 \~english A video message.*/
    AgoraChatMessageBodyTypeLocation,      /** \~chinese 位置消息。 \~english A location message.*/
    AgoraChatMessageBodyTypeVoice,         /** \~chinese 语音消息。 \~english A voice message.*/
    AgoraChatMessageBodyTypeFile,          /** \~chinese 文件消息。 \~english A file message.*/
    AgoraChatMessageBodyTypeCmd,           /** \~chinese 指令消息。 \~english A command message.*/
    AgoraChatMessageBodyTypeCustom,        /** \~chinese 自定义消息。\~english A custom message.*/
} AgoraChatMessageBodyType;

/**
 *  \~chinese 
 *  消息体。
 *  不直接使用，由子类继承实现。
 *
 *  \~english 
 *  The message body.
 */
@interface AgoraChatMessageBody : NSObject

/**
 *  \~chinese 
 *  消息体类型。
 *
 *  \~english 
 *  The message body type.
 */
@property (nonatomic, readonly) AgoraChatMessageBodyType type;

@end

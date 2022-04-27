//
//  AgoraChatThreadEvent.h
//  AgoraChat
//
//  Created by 朱继超 on 2022/3/3.
//  Copyright © 2022 easemob.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AgoraChatMessage;
@interface AgoraChatThreadEvent : NSObject
/*!
 *  \~chinese
 *  子区id
 *
 *  \~english
 *  sub-zone id
 */
@property (readonly) NSString *threadId;
/*!
 *  \~chinese
 *  子区name
 *
 *  \~english
 *  sub-zone name
 */
@property (readonly) NSString *threadName;
/*!
 *  \~chinese
 *  接收到别人对子区的操作类型
 *
 *  \~english
 *  Received the operation type of the sub-area from others
 */
@property (readonly) NSString *threadOperation;
/*!
 *  \~chinese
 *  子区创建时依赖的那一条消息的消息id
 *
 *  \~english
 *  The message id of the message on which the subarea was created
 */
@property (readonly) NSString *messageId;
/*!
 *  \~chinese
 *  子区中的消息数
 *
 *  \~english
 *  Number of messages in subsection
 */
@property (readonly) int messageCount;
/*!
 *  \~chinese
 *  子区创建时依赖的那一条消息的会话id
 *
 *  \~english
 *  The session id of the message on which the subarea was created
 */
@property (readonly) NSString *channelId;
/*!
 *  \~chinese
 *  操作子区的用户id
 *
 *  \~english
 *  User id of the operation sub-area
 */
@property (readonly) NSString *from;
/*!
 *  \~chinese
 *  接受操作通知子区的用户id，目前是所有群成员
 *
 *  \~english
 *  The user id of the sub-area that accepts the operation notification, currently all group members
 */
@property (readonly) NSString *to;
/*!
 *  \~chinese
 *  操作子区的用户时操作的时间戳
 *
 *  \~english
 *  The timestamp of the operation when the user of the subarea was operated
 */
@property (readonly) uint timeStamp;
/*!
 *  \~chinese
 *  子区中最后一条消息，为空代表最后一条消息被撤回，不为空代表新消息
 *
 *  \~english
 *  The last message in the sub-area, if it is empty, it means the last message is withdrawn. If it is not empty, it means a new message.
 */
@property (readonly) AgoraChatMessage *lastMessage;

@end


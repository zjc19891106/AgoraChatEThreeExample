//
//  AgoraChatThread.h
//  AgoraChat
//
//  Created by 朱继超 on 2022/3/1.
//  Copyright © 2022 easemob.com. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface AgoraChatThread : NSObject

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
*  子区的名称(请求子区列表与子区详情都会有)
*
*  \~english
*  Subject of the sub-zone(There will be a list of requested sub-areas and sub-area details)
*/
@property (nonatomic, strong) NSString *threadName;

/*!
 *  \~chinese
 *  子区的创建者,需要请求获取子区详情接口后当前对象会有这个属性
 *
 *  \~english
 *  create  of the sub-zone, require fetch thread's detail first
 */
@property (readonly) NSString *owner;
/*!
 *  \~chinese
 *  创建子区的messageId （可空，因为目前群消息可被撤回）
 *
 *  \~english
 *  A messageId that create sub-zone
 */
@property (readonly) NSString *messageId;
/*!
 *  \~chinese
 *  创建子区的messageContent （获取thread详情时可用）
 *
 *  \~english
 *  A messageContent that create sub-zone
 */
@property (readonly) NSString *msgContent;
/*!
 *  \~chinese
 *  创建子区的会话id
 *
 *  \~english
 *  A channelId that create sub-zone
 */
@property (readonly) NSString *channelId;


/*!
 *  \~chinese
 *  子区的成员列表数目，需要请求获取子区详情接口后当前对象会有这个属性
 *
 *  \~english
 *  Member list of the sub-zone, require fetch thread's detail first
 */
@property (readonly) int membersCount;

/*!
 *  \~chinese
 *  子区创建的时间戳
 *
 *  \~english
 *  Timestamp of subarea creation
 */
@property (readonly) int timeStamp;

@end



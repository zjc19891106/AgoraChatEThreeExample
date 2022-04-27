/**
 *  \~chinese
 *  @header AgoraChatroom.h
 *  @abstract 聊天室
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatroom.h
 *  @abstract Chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "AgoraChatCommonDefs.h"

/**
 *  \~chinese
 *  聊天室成员类型枚举。
 *
 *  \~english
 *  The enum of chat room permission types.
 */
typedef enum{
    AgoraChatroomPermissionTypeNone   = -1,    /** \~chinese 未知类型  \~english Unknown type*/
    AgoraChatroomPermissionTypeMember = 0,     /** \~chinese 普通成员类型  \~english Normal member type*/
    AgoraChatroomPermissionTypeAdmin,          /** \~chinese 聊天室管理员类型  \~english Chatroom admin type*/
    AgoraChatroomPermissionTypeOwner,          /** \~chinese 聊天室拥有者类型  \~english Chatroom owner  type*/
}AgoraChatroomPermissionType;


/**
 *  \~chinese 
 *  聊天室实例，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  \~english 
 *  The chat room object.
 */
@interface AgoraChatroom : NSObject

/**
 *  \~chinese 
 *  聊天室 ID，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  \~english 
 *  The chat room ID.
 */
@property (nonatomic, copy, readonly) NSString *chatroomId;

/**
 *  \~chinese
 *  聊天室的主题，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  \~english 
 *  The subject of the chat room.
 */
@property (nonatomic, copy, readonly) NSString *subject;

/**
 *  \~chinese 
 *  聊天室的描述，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  \~english 
 *  The description of chat room.
 */
@property (nonatomic, copy, readonly) NSString *description;

/**
 *  \~chinese
 *  聊天室的所有者，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  聊天室的所有者只有一人。
 *
 *  \~english
 *  The owner of the chat room. There is only one owner per chat room. 
 */
@property (nonatomic, copy, readonly) NSString *owner;

/**
 *  \~chinese
 *  聊天室的公告，需要先调用 getChatroomAnnouncementWithId 方法获取该聊天室详情。
 *
 *  \~english
 *  The announcement of the chat room.
 */
@property (nonatomic, copy, readonly) NSString *announcement;

/**
 *  \~chinese
 *  聊天室的管理者，拥有聊天室的最高权限，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *
 *  \~english
 *  The admins of the chatroom.
 *
 */
@property (nonatomic, copy, readonly) NSArray *adminList;

/**
 *  \~chinese
 *  聊天室的成员列表，通过分页获取聊天室成员列表接口加载。
 *
 *  \~english
 *  The list of members in the chat room.
 */
@property (nonatomic, copy, readonly) NSArray *memberList;

/**
 *  \~chinese
 *  聊天室的黑名单，需要先调用获取聊天室黑名单方法。
 *
 *  只有聊天室所有者有权限调用该方法，非聊天室所有者返回 nil。
 *
 *  \~english
 *  The blocklist of the chatroom.
 *
 *  Only the chatroom owner can call the method. Returns nil if the user is not the chatroom owner.
 */
@property (nonatomic, strong, readonly) NSArray *blacklist;

/**
 *  \~chinese
 *  聊天室的被禁言列表。
 *
 *  只有聊天室所有者有权限调用该方法，非聊天室所有者返回 nil。
 *
 *  \~english
 *  The list of muted members.
 *
 *  Only the chatroom owner can call the method. Returns nil if the user is not the chatroom owner.
 */
@property (nonatomic, strong, readonly) NSArray *muteList;

/**
*  \~chinese
*  聊天室的白名单列表。
*
*  只有聊天室所有者有权限调用该方法，非聊天室所有者返回 nil。
*
*  \~english
*  The allowlist members <NSString>
*
*  Only the chatroom owner can call the method. Returns nil if the user is not the chatroom owner.
*/
@property (nonatomic, strong, readonly) NSArray *whitelist;

/**
 *  \~chinese
 *  当前登录账号的聊天室成员类型。
 *
 *  \~english
 *  The chatroom membership type of the current login account.
 */
@property (nonatomic, readonly) AgoraChatroomPermissionType permissionType;

/**
 *  \~chinese
 *  聊天室的最大人数，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。如果没有获取聊天室详情将返回 0。
 *
 *  \~english
 *  The maximum member number of the chat room.
 */
@property (nonatomic, readonly) NSInteger maxOccupantsCount;

/**
 *  \~chinese
 *  聊天室的当前人数，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。如果没有获取聊天室详情将返回 0。
 *
 *  \~english
 *  The current number of members in the chat room.
 */
@property (nonatomic, readonly) NSInteger occupantsCount;

/**
 *  \~chinese
 *  聊天室成员是否全部被禁言。
 *
 *  \~english
 *  Whether all members of the chat room are muted.
 */
@property (nonatomic, readonly) BOOL isMuteAllMembers;
/**
 *  \~chinese
 *  获取聊天室实例。
 *
 *  @param aChatroomId   聊天室 ID
 *
 *  @result 聊天室实例
 *
 *  \~english
 *  Constructs a chatroom instance with chatroom ID.
 *
 *  @param aChatroomId   The chatroom ID.
 *
 *  @result The chatroom instance.
 */
+ (instancetype)chatroomWithId:(NSString *)aChatroomId;

#pragma mark - EM_DEPRECATED_IOS 3.8.8

/**
*  \~chinese
*  聊天室的白名单列表。
*
*  需要owner权限才能查看，非owner返回nil
*
*  \~english
*  List of whitelist members<NSString>
*
*  Need owner's authority to access, return nil if user is not the chatroom owner.
*/
@property (nonatomic, strong, readonly) NSArray *whiteList __deprecated_msg("Use whitelist instead");

#pragma mark - EM_DEPRECATED_IOS 3.3.0

/**
 *  \~chinese
 *  该方法已废弃，用 {@link -memberList} 代替。聊天室的成员列表，需要先调用 getChatroomSpecificationFromServerWithId 方法获取该聊天室详情。
 *
 *  \~english
 *  Deprecated, please use -memberList instead. The list of members in the chat room.
 */
@property (nonatomic, copy, readonly) NSArray *members EM_DEPRECATED_IOS(3_1_0, 3_3_0, "Use -memberList instead");

/**
 *  \~chinese
 *  该方法已废弃，用 {@link -occupantsCount} 代替。聊天室的当前人数，如果没有获取聊天室详情将返回 0。
 *
 *  \~english
 *  Deprecated, please use -occupantsCount instead. The total number of members in the chat room.
 */
@property (nonatomic, readonly) NSInteger membersCount EM_DEPRECATED_IOS(3_1_0, 3_3_0, "Use -occupantsCount instead");

/**
 *  \~chinese
 *  该方法已废弃，用 {@link -maxOccupantsCount} 代替。聊天室的最大人数，如果没有获取聊天室详情将返回 0。
 *
 *  \~english
 *  Deprecated, please use -maxOccupantsCount instead.The maximum member number of the chat room.
 */
@property (nonatomic, readonly) NSInteger maxMembersCount EM_DEPRECATED_IOS(3_1_0, 3_3_0, "Use -maxOccupantsCount instead");

#pragma mark - EM_DEPRECATED_IOS < 3.2.3

/**
 *  \~chinese
 *  该方法已废弃，请用 {@link -members} 代替。聊天室的成员列表。
 *
 *  \~english
 *  Deprecated, please use - members instead. The list of members in the chat room.
 */
@property (nonatomic, copy, readonly) NSArray *occupants __deprecated_msg("Use -members instead");

/**
 *  \~chinese
 *  该方法已废弃，请使用 {@link +chatroomWithId:} 方法代替。初始化聊天室实例。
 *
 *  
 *
 *  @result nil
 *
 *  \~english
 *  Deprecated, please use  {@link +chatroomWithId:}  instead.Initializes chatroom instance.
 *
 *   
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +chatroomWithId: instead");

@end

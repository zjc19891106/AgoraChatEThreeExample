/**
 *  \~chinese
 *  @header AgoraChatroomManagerDelegate.h
 *  @abstract 聊天室相关的代理协议
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatroomManagerDelegate.h
 *  @abstract This protocol defined the callbacks of chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/**
 *  \~chinese
 *  被踢出聊天室的枚举类型。
 *
 *  \~english
 *  The casuse type for kicking out from a chatroom.
 */
typedef enum
{
    AgoraChatroomBeKickedReasonBeRemoved = 0, /** \~chinese 被管理员移出聊天室类型 \~english Removed by chatroom owner type */
    AgoraChatroomBeKickedReasonDestroyed,     /** \~chinese 聊天室被销毁类型 \~english Chatroom has been destroyed type*/
    AgoraChatroomBeKickedReasonOffline,       /** \~chinese 当前账号离线类型 \~english Account offline type*/
} AgoraChatroomBeKickedReason;

@class AgoraChatroom;

/**
 *  \~chinese
 *  聊天室相关的代理协议。
 *
 *  \~english
 *  The callbacks of chatroom.
 */
@protocol AgoraChatroomManagerDelegate <NSObject>

@optional

/**
 *  \~chinese
 *  有用户加入聊天室。
 *
 *  @param aChatroom    加入的聊天室。
 *  @param aUsername    加入者。
 *
 *  \~english
 *  A user joined a chatroom.
 *
 *  @param aChatroom    The chatroom user joined.
 *  @param aUsername    The user who joined chatroom.
 */
- (void)userDidJoinChatroom:(AgoraChatroom *)aChatroom
                       user:(NSString *)aUsername;

/**
 *  \~chinese
 *  有用户离开聊天室。
 *
 *  @param aChatroom    离开的聊天室。
 *  @param aUsername    离开者。
 *
 *  \~english
 *  Occurs when a user leaves a chatroom.
 *
 *  @param aChatroom    The chatroom user left.
 *  @param aUsername    The user who leaved chatroom
 */
- (void)userDidLeaveChatroom:(AgoraChatroom *)aChatroom
                        user:(NSString *)aUsername;

/**
 *  \~chinese
 *  被踢出聊天室。
 *
 *  @param aChatroom    被踢出的聊天室。
 *  @param aReason      被踢出的原因。
 *
 *  \~english
 *  Occurs when a user is dismissed from a chat room.
 *
 *  @param aChatroom    The chatroom user is dismissed from.
 *  @param aReason      The reason of the user was kicked out.
 */
- (void)didDismissFromChatroom:(AgoraChatroom *)aChatroom
                        reason:(AgoraChatroomBeKickedReason)aReason;

/**
 *  \~chinese
 *  有成员被加入禁言列表。
 *
 *  @param aChatroom        聊天室。
 *  @param aMutes           被禁言的成员。
 *  @param aMuteExpire      禁言失效时间，暂时不可用。
 *
 *  \~english
 *  Users are added to the mute list.
 *
 *  @param aChatroom        The Chatroom.
 *  @param aMutes           The users who are muted.
 *  @param aMuteExpire      The mute expire duration, not available at this time.
 */
- (void)chatroomMuteListDidUpdate:(AgoraChatroom *)aChatroom
                addedMutedMembers:(NSArray *)aMutes
                       muteExpire:(NSInteger)aMuteExpire;

/**
 *  \~chinese
 *  有成员被移出禁言列表。
 *
 *  @param aChatroom        聊天室。
 *  @param aMutedMembers    被移出禁言列表的成员。
 *
 *  \~english
 *  Users are removed from the mute list.
 *
 *  @param aChatroom        The Chatroom.
 *  @param aMutedMembers    The users who are removed from MutedList.
 */
- (void)chatroomMuteListDidUpdate:(AgoraChatroom *)aChatroom
              removedMutedMembers:(NSArray *)aMutes;

/**
 *  \~chinese
 *  有成员被加入白名单。
 *
 *  @param aChatroom        聊天室。
 *  @param aMembers         被加入白名单的成员。
 *
 *  \~english
 *  Users are added to the allowlist.
 *
 *  @param aChatroom        The Chatroom.
 *  @param aMutedMembers    The users who are added to allowlist.
 */
- (void)chatroomWhiteListDidUpdate:(AgoraChatroom *)aChatroom
             addedWhiteListMembers:(NSArray *)aMembers;

/**
 *  \~chinese
 *  有成员被移出白名单。
 *
 *  @param aChatroom        聊天室。
 *  @param aMembers         被移出白名单的成员。
 *
 *  \~english
 *  Users are removed from the allowlist.
 *
 *  @param aChatroom        The Chatroom.
 *  @param aMembers    The users who are removed from the allowlist.
 */
- (void)chatroomWhiteListDidUpdate:(AgoraChatroom *)aChatroom
           removedWhiteListMembers:(NSArray *)aMembers;

/**
 *  \~chinese
 *  聊天室全部禁言状态变化。
 *
 *  @param aChatroom        聊天室。
 *  @param aMuted           是否被全部禁言。
 *
 *  \~english
 *  Whether group members are all muted.
 *
 *  @param aChatroom      The Chatroom.
 *  @param aMuted         Whether all members are muted.
 */
- (void)chatroomAllMemberMuteChanged:(AgoraChatroom *)aChatroom
                    isAllMemberMuted:(BOOL)aMuted;

/**
 *  \~chinese
 *  有成员被加入管理员列表。
 *
 *  @param aChatroom    聊天室。
 *  @param aAdmin       加入管理员列表的成员。
 *
 *  \~english
 *  A user is added to the admin list.
 *
 *  @param aChatroom    The Chatroom
 *  @param aAdmin       The user who is added to the admin list.
 */
- (void)chatroomAdminListDidUpdate:(AgoraChatroom *)aChatroom
                        addedAdmin:(NSString *)aAdmin;

/**
 *  \~chinese
 *  有成员被移出管理员列表。
 *
 *  @param aChatroom    聊天室。
 *  @param aAdmin       移出管理员列表的成员。
 *
 *  \~english
 *  A user is removed from the admin list.
 *
 *  @param aChatroom    The Chatroom.
 *  @param aAdmin       The user who is removed from adminList.
 */
- (void)chatroomAdminListDidUpdate:(AgoraChatroom *)aChatroom
                      removedAdmin:(NSString *)aAdmin;

/**
 *  \~chinese
 *  聊天室所有者有更新。
 *
 *  @param aChatroom    聊天室。
 *  @param aNewOwner    新群主。
 *  @param aOldOwner    旧群主。
 *
 *  \~english
 *  The owner is updated.
 *
 *  @param aChatroom    The Chatroom
 *  @param aNewOwner    The New Owner
 *  @param aOldOwner    The Old Owner
 */
- (void)chatroomOwnerDidUpdate:(AgoraChatroom *)aChatroom
                      newOwner:(NSString *)aNewOwner
                      oldOwner:(NSString *)aOldOwner;

/**
 *  \~chinese
 *  聊天室公告有更新。
 *
 *  @param aChatroom        聊天室。
 *  @param aAnnouncement    公告内容。
 *
 *  \~english
 *  The announcement is updated.
 *
 *  @param aChatroom        The Chatroom
 *  @param aAnnouncement    The Announcement content.
 */
- (void)chatroomAnnouncementDidUpdate:(AgoraChatroom *)aChatroom
                         announcement:(NSString *)aAnnouncement;

#pragma mark - Deprecated methods

/**
 *  \~chinese
 *  有用户加入聊天室。
 *
 *  已废弃，请用 {@link userDidJoinChatroom:user:} 代替。
 *
 *  @param aChatroom    加入的聊天室。
 *  @param aUsername    加入者。
 *
 *  \~english
 *  Occurs when a user joins a chat room
 *
 *  Deprecated, please use  {@link userDidJoinChatroom:user:}  instead.
 *
 *  @param aChatroom    Joined chatroom
 *  @param aUsername    The user who joined chatroom
 */
- (void)didReceiveUserJoinedChatroom:(AgoraChatroom *)aChatroom
                            username:(NSString *)aUsername __deprecated_msg("Use -userDidJoinChatroom:user: instead");

/**
 *  \~chinese
 *  有用户离开聊天室。
 *
 *  已废弃，请用 {@link userDidLeaveChatroom:reason:} 代替。
 *
 *  @param aChatroom    离开的聊天室。
 *  @param aUsername    离开者。
 *
 *  \~english
 *  A user leaved the chatroom.
 *
 *  Deprecated, please use  {@link userDidLeaveChatroom:reason:}  instead.
 *
 *  @param aChatroom    The chatroom which the user Leaved from.
 *  @param aUsername    The user who leaved chatroom.
 */
- (void)didReceiveUserLeavedChatroom:(AgoraChatroom *)aChatroom
                            username:(NSString *)aUsername __deprecated_msg("Use -userDidLeaveChatroom:reason: instead");

/**
 *  \~chinese
 *  被踢出聊天室。
 *
 *  已废弃，请用 {@link didDismissFromChatroom:reason:} 代替。
 *
 *  @param aChatroom    被踢出的聊天室。
 *  @param aReason      被踢出聊天室的原因。
 *
 *  \~english
 *  User was kicked out from the chatroom.
 *
 *  Deprecated, please use  {@link didDismissFromChatroom:reason:}  instead.
 *
 *  @param aChatroom    The chatroom which the user was kicked out from.
 *  @param aReason      The reason of kicked out.
 */
- (void)didReceiveKickedFromChatroom:(AgoraChatroom *)aChatroom
                              reason:(AgoraChatroomBeKickedReason)aReason __deprecated_msg("Use -didDismissFromChatroom:reason: instead");
@end

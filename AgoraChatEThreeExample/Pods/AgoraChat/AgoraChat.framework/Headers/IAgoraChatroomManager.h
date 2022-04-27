/**
 *  \~chinese
 *  @header IAgoraChatroomManager.h
 *  @abstract 聊天室相关操作协议类。
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header IAgoraChatroomManager.h
 *  @abstract This protocol defines the chat room operations.
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "AgoraChatCommonDefs.h"
#import "AgoraChatroomManagerDelegate.h"
#import "AgoraChatroomOptions.h"
#import "AgoraChatroom.h"
#import "AgoraChatPageResult.h"

#import "AgoraChatCursorResult.h"

@class AgoraChatError;

/**
 *  \~chinese
 *  管理聊天室的类。
 *
 *  \~english
 *  A class that manages the chatrooms.
 */
@protocol IAgoraChatroomManager <NSObject>

@required

#pragma mark - Delegate

/**
 *  \~chinese
 *  添加回调代理。
 *
 *  @param aDelegate  要添加的代理。
 *  @param aQueue     代理执行的队列。
 *
 *  \~english
 *  Adds the SDK delegate.
 *
 *  @param aDelegate  The delegate that you want to add: ChatroomManagerDelegate.
 *  @param aQueue     (Optional) The queue of calling the delegate methods. To run the app on the main thread, set this parameter as nil.
 */
- (void)addDelegate:(id<AgoraChatroomManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/**
 *  \~chinese
 *  移除回调代理。
 *
 *  @param aDelegate  要移除的代理。
 *
 *  \~english
 *  Removes the delegate.
 *
 *  @param aDelegate  The delegate that you want to remove.
 */
- (void)removeDelegate:(id<AgoraChatroomManagerDelegate>)aDelegate;

#pragma mark - Fetch Chatrooms

/**
 *  \~chinese
 *  从服务器获取指定数目的聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aPageNum         获取第几页。
 *  @param aPageSize        获取多少条。
 *  @param pError           出错信息。
 *
 *  @result 获取的聊天室列表，详见 AgoraChatPageResult。
 *
 *  \~english
 *  Gets the specified number of chat rooms from the server.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result The chat room list. See AgoraChatPageResult.
 */
- (AgoraChatPageResult *)getChatroomsFromServerWithPage:(NSInteger)aPageNum
                                        pageSize:(NSInteger)aPageSize
                                           error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  从服务器获取指定数目的聊天室。
 * 
 *  异步方法。
 *
 *  @param aPageNum             获取第几页。
 *  @param aPageSize            获取多少条。
 *  @param aCompletionBlock      该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Gets the specified number of chat rooms from the server.
 * 
 *  This is an asynchronous method.
 *
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param aCompletionBlock     The completion block, which contains the error message if the method call fails.
 *
 */

- (void)getChatroomsFromServerWithPage:(NSInteger)aPageNum
                              pageSize:(NSInteger)aPageSize
                            completion:(void (^)(AgoraChatPageResult *aResult, AgoraChatError *aError))aCompletionBlock;

#pragma mark - Create

/**
 *  \~chinese
 *  创建聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aSubject             聊天室主题。
 *  @param aDescription         聊天室描述。
 *  @param aInvitees            聊天室的成员，不包括聊天室创建者自己。
 *  @param aMessage             加入聊天室的邀请内容。
 *  @param aMaxMembersCount     聊天室最大成员数。
 *  @param pError               出错信息。
 *
 *  @result    创建的聊天室，详见 AgoraChatroom。
 *
 *  \~english
 *  Creates a chatroom.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aSubject             The subject of the chatroom.
 *  @param aDescription         The description of the chatroom.
 *  @param aInvitees            The members of the chatroom. Do not include the creator.
 *  @param aMessage             The invitation message.
 *  @param aMaxMembersCount     The maximum number of members in the chatroom.
 *  @param pError               The error information if the method fails: Error.
 *
 *  @result    The create chatroom. See AgoraChatroom.
 */
- (AgoraChatroom *)createChatroomWithSubject:(NSString *)aSubject
                              description:(NSString *)aDescription
                                 invitees:(NSArray *)aInvitees
                                  message:(NSString *)aMessage
                          maxMembersCount:(NSInteger)aMaxMembersCount
                                    error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  创建一个聊天室。
 * 
 *  异步方法。
 *
 *  @param aSubject                 聊天室主题。
 *  @param aDescription             聊天室描述。
 *  @param aInvitees                聊天室的成员，不包括聊天室创建者自己。
 *  @param aMessage                 加入聊天室的邀请内容。
 *  @param aMaxMembersCount         聊天室最大成员数。
 *  @param aCompletionBlock         该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Creates a chatroom.
 * 
 *  This is an asynchronous method.
 *
 *  @param aSubject                 The subject of the chatroom.
 *  @param aDescription             The description of the chatroom.
 *  @param aInvitees                The members of the chatroom. Do not include the creator.
 *  @param aMessage                 The invitation message.
 *  @param aMaxMembersCount         The maximum number of members in the chatroom.
 *  @param aCompletionBlock         The completion block, which contains the error message if the method call fails.
 *
 */
- (void)createChatroomWithSubject:(NSString *)aSubject
                      description:(NSString *)aDescription
                         invitees:(NSArray *)aInvitees
                          message:(NSString *)aMessage
                  maxMembersCount:(NSInteger)aMaxMembersCount
                       completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

#pragma mark - Edit Chatroom

/**
 *  \~chinese
 *  加入一个聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId  聊天室的 ID。
 *  @param pError       返回的错误信息。
 *
 *  @result  所加入的聊天室，详见 AgoraChatroom。
 *
 *  \~english
 *  Joins a chatroom.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result  The chatroom instance.
 */
- (AgoraChatroom *)joinChatroom:(NSString *)aChatroomId
                       error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  加入聊天室。
 * 
 *  异步方法。
 *
 *  @param aChatroomId           聊天室的 ID。
 *  @param aCompletionBlock      该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Joins a chatroom.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId          The chatroom ID.
 *  @param aCompletionBlock     The completion block, which contains the error message if the method call fails.
 *
 */
- (void)joinChatroom:(NSString *)aChatroomId
          completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  退出聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *
 *  \~english
 *  Leaves a chatroom.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 */
- (void)leaveChatroom:(NSString *)aChatroomId
                error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  退出聊天室。
 * 
 *  异步方法。
 *
 *  @param aChatroomId          聊天室 ID。
 *  @param aCompletionBlock     该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Leaves a chatroom.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId          The chatroom ID.
 *  @param aCompletionBlock     The completion block, which contains the error message if the method call fails.
 *
 */
- (void)leaveChatroom:(NSString *)aChatroomId
           completion:(void (^)(AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  解散聊天室。
 * 
 *  仅聊天室所有者可以解散聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId  聊天室 ID。
 *
 *  @result   - 如果方法调用成功，返回 nil。
 *            - 如果方法调用失败，返回错误信息。详见 AgoraChatError。
 *
 *  \~english
 *  Dismisses a chatroom. 
 * 
 *  Only the owner of a chatroom has the privilege to dismiss it.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId  The chatroom ID.
 *
 *  @result  - `nil` if the method call succeeds. 
 *           - Error information if the method call fails. See AgoraChatError.
 */
- (AgoraChatError *)destroyChatroom:(NSString *)aChatroomId;

/**
 *  \~chinese
 *  解散聊天室。
 * 
 *  仅聊天室所有者可以解散聊天室。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Dismisses a chatroom.
 * 
 *  Only the owner of a chatroom has the privilege to dismiss it.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)destroyChatroom:(NSString *)aChatroomId
             completion:(void (^)(AgoraChatError *aError))aCompletionBlock;

#pragma mark - Fetch

/**
 *  \~chinese
 *  获取指定的聊天室。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId           聊天室 ID。
 *  @param pError                错误信息。
 *
 *  @result  聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Fetches the specific chatroom.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId           The chatroom ID.
 *  @param pError                The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)getChatroomSpecificationFromServerWithId:(NSString *)aChatroomId
                                                   error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  获取聊天室详情。
 *
 *  异步方法。
 * 
 *  @param aChatroomId           聊天室 ID
 *  @param aCompletionBlock      该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Fetches the chat room specifications.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId           The chatroom ID.
 *  @param aCompletionBlock      The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomSpecificationFromServerWithId:(NSString *)aChatroomId
                                      completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  获取聊天室成员列表。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCursor          游标，首次调用传空。
 *  @param aPageSize        获取多少条。
 *  @param pError           错误信息。
 *
 *  @result   聊天室成员列表和游标。
 *
 *  \~english
 *  Gets the list of chatroom members from the server.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCursor          The cursor. Set this parameter as nil when you call this method for the first time.
 *  @param aPageSize        The page size.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result    The list of chatroom members and the cursor.
 *
 */
- (AgoraChatCursorResult *)getChatroomMemberListFromServerWithId:(NSString *)aChatroomId
                                                   cursor:(NSString *)aCursor
                                                 pageSize:(NSInteger)aPageSize
                                                    error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  获取聊天室成员列表。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCursor          游标，首次调用传空。
 *  @param aPageSize        获取多少条。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Gets the list of chatroom members from the server.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCursor          The cursor. Set this parameter as nil when you call this method for the first time.
 *  @param aPageSize        The page size.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomMemberListFromServerWithId:(NSString *)aChatroomId
                                       cursor:(NSString *)aCursor
                                     pageSize:(NSInteger)aPageSize
                                   completion:(void (^)(AgoraChatCursorResult *aResult, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  获取聊天室黑名单列表。
 * 
 *  仅聊天室所有者或者管理员可以获取黑名单。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aPageNum         获取第几页。
 *  @param aPageSize        获取多少条。
 *  @param pError           错误信息。
 *
 *
 *  \~english
 *  Gets the blocklist of chatroom from the server. 
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param pError           The error information if the method fails: Error.
 *
 */
- (NSArray *)getChatroomBlacklistFromServerWithId:(NSString *)aChatroomId
                                       pageNumber:(NSInteger)aPageNum
                                         pageSize:(NSInteger)aPageSize
                                            error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  获取聊天室黑名单列表。
 * 
 *  仅聊天室所有者或者管理员可以获取黑名单。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aPageNum         获取第几页。
 *  @param aPageSize        获取多少条。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Gets the chatroom's blocklist. 
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomBlacklistFromServerWithId:(NSString *)aChatroomId
                                  pageNumber:(NSInteger)aPageNum
                                    pageSize:(NSInteger)aPageSize
                                  completion:(void (^)(NSArray *aList, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  获取聊天室被禁言列表。
 *
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aPageNum         获取第几页。
 *  @param aPageSize        获取多少条。
 *  @param pError           错误信息。
 *
 *
 *  \~english
 *  Gets the list of members who are muted in the chatroom from the server.
 *
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param pError           The error information if the method fails: Error.
 *
 */
- (NSArray *)getChatroomMuteListFromServerWithId:(NSString *)aChatroomId
                                      pageNumber:(NSInteger)aPageNum
                                        pageSize:(NSInteger)aPageSize
                                           error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  获取聊天室被禁言列表。
 *
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aPageNum         获取第几页。
 *  @param aPageSize        获取多少条。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Gets the list of members who were muted in the chatroom from the server.
 *
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aPageNum         The page number.
 *  @param aPageSize        The page size.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomMuteListFromServerWithId:(NSString *)aChatroomId
                                 pageNumber:(NSInteger)aPageNum
                                   pageSize:(NSInteger)aPageSize
                                 completion:(void (^)(NSArray *aList, AgoraChatError *aError))aCompletionBlock;


/**
 *  \~chinese
 *  获取聊天室白名单列表。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息。
 *
 *
 *  \~english
 *  Gets the allowlist of a chatroom from the server.
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 */
- (NSArray *)getChatroomWhiteListFromServerWithId:(NSString *)aChatroomId
                                            error:(AgoraChatError **)pError;


/**
 *  \~chinese
 *  获取聊天室白名单列表。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Gets the allowlist of a chatroom from the server.
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomWhiteListFromServerWithId:(NSString *)aChatroomId
                                  completion:(void (^)(NSArray *aList, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  查看当前用户是否在聊天室白名单中。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息。
 *
 *
 *  \~english
 *  Checks whether the current user is on the allowlist.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 */
- (BOOL)isMemberInWhiteListFromServerWithChatroomId:(NSString *)aChatroomId
                                              error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  查看当前用户是否在聊天室白名单中。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Checks whether the current user is on the allowlist.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)isMemberInWhiteListFromServerWithChatroomId:(NSString *)aChatroomId
                                         completion:(void (^)(BOOL inWhiteList, AgoraChatError *aError))aCompletionBlock;
/**
 *  \~chinese
 *  获取聊天室公告。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息。
 *
 *  @result    聊天室公告。
 *
 *  \~english
 *  Gets the announcement of a chatroom from the server.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result    The announcement of chatroom.
 */
- (NSString *)getChatroomAnnouncementWithId:(NSString *)aChatroomId
                                      error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  获取聊天室公告。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Gets the announcement of a chatroom from the server.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomAnnouncementWithId:(NSString *)aChatroomId
                           completion:(void (^)(NSString *aAnnouncement, AgoraChatError *aError))aCompletionBlock;

#pragma mark - Edit

/**
 *  \~chinese
 *  更改聊天室主题。
 * 
 *  仅聊天室所有者有权限调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aSubject     新聊天室主题。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Changes the chatroom‘s subject. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aSubject     The new subject of the chatroom.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result    The chatroom instance.
 */
- (AgoraChatroom *)updateSubject:(NSString *)aSubject
                  forChatroom:(NSString *)aChatroomId
                        error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  更改聊天室主题。
 * 
 *  仅聊天室所有者有权限调用此方法。
 * 
 *  异步方法。
 *
 *  @param aSubject         聊天室新主题。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Changes the chatroom subject. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aSubject         The new subject of the chatroom.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)updateSubject:(NSString *)aSubject
          forChatroom:(NSString *)aChatroomId
           completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  更改聊天室说明信息。
 * 
 *  仅聊天室所有者有权限调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aDescription 说明信息。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Changes chatroom description. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aDescription The new description.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result    The chatroom instance.
 */
- (AgoraChatroom *)updateDescription:(NSString *)aDescription
                      forChatroom:(NSString *)aChatroomId
                            error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  更改聊天室说明信息。
 * 
 *  仅聊天室所有者有权限调用此方法。
 * 
 *  异步方法。
 *
 *  @param aDescription     说明信息。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Changes the chatroom's description. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aDescription     The new description.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)updateDescription:(NSString *)aDescription
              forChatroom:(NSString *)aChatroomId
               completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  将成员移出聊天室。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMembers     要移出的用户列表。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Removes members from a chatroom. 
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers     The users to be removed from the chatroom.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result    The chatroom instance.
 */
- (AgoraChatroom *)removeMembers:(NSArray *)aMembers
                 fromChatroom:(NSString *)aChatroomId
                        error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  将成员移出聊天室。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMembers         要移出的用户列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Removes members from a chatroom. 
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method. 
 *
 *  @param aMembers         The users to be removed from the chatroom.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)removeMembers:(NSArray *)aMembers
         fromChatroom:(NSString *)aChatroomId
           completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  将用户加入聊天室黑名单。
 * 
 *  仅聊天室所有者有权限调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMembers     要加入黑名单的用户。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Adds users to the chatroom's blocklist. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers     The users to be added to the blocklist.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result    The chatroom instance.
 */
- (AgoraChatroom *)blockMembers:(NSArray *)aMembers
                fromChatroom:(NSString *)aChatroomId
                       error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  将用户加入聊天室黑名单。
 * 
 *  仅聊天室所有者有权限调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMembers         要加入黑名单的用户。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Adds users to the chatroom's blocklist. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aMembers         The users to be added to the chatroom.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)blockMembers:(NSArray *)aMembers
        fromChatroom:(NSString *)aChatroomId
          completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;


/**
 *  \~chinese
 *  从聊天室黑名单中移除用户。
 * 
 *  仅聊天室所有者有权限调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMembers     要从黑名单中移除的用户名列表。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Removes users from chatroom blocklist.
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers     The users to be removed from the blocklist.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result    The chatroom instance.
 */
- (AgoraChatroom *)unblockMembers:(NSArray *)aMembers
                  fromChatroom:(NSString *)aChatroomId
                         error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  从聊天室黑名单中移除。
 * 
 *  仅聊天室所有者有权限调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMembers         要从黑名单中移除的用户名列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Removes users from the chatroom blocklist. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 * 
 *  @param aMembers         The users to be removed from the blocklist.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)unblockMembers:(NSArray *)aMembers
          fromChatroom:(NSString *)aChatroomId
            completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  变更聊天室所有者。
 * 
 *  仅聊天室所有者可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId  聊天室 ID。
 *  @param aNewOwner    新聊天室所有者。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例。
 *
 *  \~english
 *  Changes the chatroom owner. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId  The chatroom ID.
 *  @param aNewOwner    The new owner.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)updateChatroomOwner:(NSString *)aChatroomId
                           newOwner:(NSString *)aNewOwner
                              error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  变更聊天室所有者。
 * 
 *  仅聊天室所有者可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aNewOwner        新聊天室所有者。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Changes the chatroom owner. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aNewOwner        The new owner.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)updateChatroomOwner:(NSString *)aChatroomId
                   newOwner:(NSString *)aNewOwner
                 completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  添加聊天室管理员。
 * 
 *  仅聊天室所有者可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aAdmin       要添加的管理员。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息。
 *
 *  @result    聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Adds a chatroom admin. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aAdmin       The new admin.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result  The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)addAdmin:(NSString *)aAdmin
              toChatroom:(NSString *)aChatroomId
                   error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  添加聊天室管理员。
 * 
 *  仅聊天室所有者可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aAdmin           要添加的聊天室管理员。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Adds a chatroom admin. 
 * 
 *  Only the chatroom owner can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aAdmin           The new admin.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)addAdmin:(NSString *)aAdmin
      toChatroom:(NSString *)aChatroomId
      completion:(void (^)(AgoraChatroom *aChatroomp, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  移除聊天室管理员。
 * 
 *  仅聊天室所有者可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aAdmin       要移除的聊天室管理员。
 *  @param aChatroomId  聊天室 ID。
 *  @param pError       错误信息
 *
 *  @result  聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Removes a chatroom admin. 
 * 
 *  Only the chatroom owner can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aAdmin       The admin to be removed.
 *  @param aChatroomId  The chatroom ID.
 *  @param pError       The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)removeAdmin:(NSString *)aAdmin
               fromChatroom:(NSString *)aChatroomId
                      error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  移除聊天室管理员。
 * 
 *  仅聊天室所有者可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aAdmin           要添加的聊天室管理员。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *
 *  \~english
 *  Removes a chatroom admin. 
 * 
 *  Only the chatroom owner and admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aAdmin           The admin to be removed.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)removeAdmin:(NSString *)aAdmin
       fromChatroom:(NSString *)aChatroomId
         completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;


/**
 *  \~chinese
 *  将一组成员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMuteMembers         要禁言的成员列表。
 *  @param aMuteMilliseconds    禁言时长
 *  @param aChatroomId          聊天室 ID。
 *  @param pError               错误信息
 *
 *  @result  聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Mutes chatroom members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMuteMembers         The list of members to mute.
 *  @param aMuteMilliseconds    Muted time duration in millisecond.
 *  @param aChatroomId          The chatroom ID.
 *  @param pError               The error information if the method fails: Error.
 *
 *  @result  The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)muteMembers:(NSArray *)aMuteMembers
           muteMilliseconds:(NSInteger)aMuteMilliseconds
               fromChatroom:(NSString *)aChatroomId
                      error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  将一组成员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMuteMembers         要禁言的成员列表。
 *  @param aMuteMilliseconds    禁言时长
 *  @param aChatroomId          聊天室 ID。
 *  @param aCompletionBlock     该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Mutes chatroom members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is an asynchronous method.
 *
 *  @param aMuteMembers         The list of mute.
 *  @param aMuteMilliseconds    Muted time duration in millisecond
 *  @param aChatroomId          The chatroom ID.
 *  @param aCompletionBlock     The completion block, which contains the error message if the method call fails.
 *
 */
- (void)muteMembers:(NSArray *)aMuteMembers
   muteMilliseconds:(NSInteger)aMuteMilliseconds
       fromChatroom:(NSString *)aChatroomId
         completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  解除禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMuteMembers     解除禁言的用户列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Unmutes chatroom members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers         The list of members to unmute.
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)unmuteMembers:(NSArray *)aMembers
                 fromChatroom:(NSString *)aChatroomId
                        error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  解除禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMuteMembers     被解除的列表
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Unmutes chatroom members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is an asynchronous method.
 *
 *  @param aMembers         The list of unmute.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)unmuteMembers:(NSArray *)aMembers
         fromChatroom:(NSString *)aChatroomId
           completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;



/**
 *  \~chinese
 *  设置全员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Mutes all members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)muteAllMembersFromChatroom:(NSString *)aChatroomId
                                     error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  设置全员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Mutes all members. 
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 * 
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)muteAllMembersFromChatroom:(NSString *)aChatroomId
                        completion:(void(^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;


/**
 *  \~chinese
 *  解除全员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Unmute all members.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)unmuteAllMembersFromChatroom:(NSString *)aChatroomId
                                       error:(AgoraChatError **)pError;


/**
 *  \~chinese
 *  解除全员禁言。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Unmute all members.
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)unmuteAllMembersFromChatroom:(NSString *)aChatroomId
                          completion:(void(^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;


/**
 *  \~chinese
 *  添加白名单。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMembers         被添加的列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Adds users to the allowlist.
 * 
 *  Only the chatroom owner and admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers         The members to be added to the allowlist.
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)addWhiteListMembers:(NSArray *)aMembers
                       fromChatroom:(NSString *)aChatroomId
                              error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  添加白名单。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMembers         被添加的列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Adds members to the allowlist.
 * 
 *  Only the chatroom owner and admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aMembers         The members to be added to the allowlist.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)addWhiteListMembers:(NSArray *)aMembers
               fromChatroom:(NSString *)aChatroomId
                 completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  移除白名单。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aMuteMembers     被移除的列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param pError           错误信息。
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Removes the members of the allowlist.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aMembers         The members to be removed from the allowlist.
 *  @param aChatroomId      The chatroom ID.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result   The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)removeWhiteListMembers:(NSArray *)aMembers
                          fromChatroom:(NSString *)aChatroomId
                                 error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  移除白名单。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aMembers         被移除的列表。
 *  @param aChatroomId      聊天室 ID。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Removes members from the allowlist.
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aMembers         The members to be removed from the allowlist.
 *  @param aChatroomId      The chatroom ID.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)removeWhiteListMembers:(NSArray *)aMembers
                  fromChatroom:(NSString *)aChatroomId
                    completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

/**
 *  \~chinese
 *  修改聊天室公告。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aAnnouncement    群公告。
 *  @param pError           错误信息。
 *
 *  @result   聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Changes the announcement of the chatroom.
 * 
 *  Only the chatroom owner or admin can call this method.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aAnnouncement    The announcement of the chatroom.
 *  @param pError           The error information if the method fails: Error.
 *
 *  @result  The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)updateChatroomAnnouncementWithId:(NSString *)aChatroomId
                                    announcement:(NSString *)aAnnouncement
                                           error:(AgoraChatError **)pError;

/**
 *  \~chinese
 *  修改聊天室公告。
 * 
 *  仅聊天室所有者和管理员可调用此方法。
 * 
 *  异步方法。
 *
 *  @param aChatroomId      聊天室 ID。
 *  @param aAnnouncement    群公告。
 *  @param aCompletionBlock 该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Changes the announcement of chatroom.
 * 
 *  Only the chatroom owner or admin can call this method.
 * 
 *  This is an asynchronous method.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aAnnouncement    The announcement of the chatroom.
 *  @param aCompletionBlock The completion block, which contains the error message if the method call fails.
 *
 */
- (void)updateChatroomAnnouncementWithId:(NSString *)aChatroomId
                            announcement:(NSString *)aAnnouncement
                              completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock;

#pragma mark - EM_DEPRECATED_IOS 3.3.0

/**
 *  \~chinese
 *  获取聊天室详情。
 * 
 *  已废弃，请用 {@link IAgoraChatroomManager getChatroomSpecificationFromServerWithId:error:} 代替。
 *
 *  同步方法，会阻塞当前线程。
 *
 *  @param aChatroomId           聊天室 ID。
 *  @param aIncludeMembersList   是否获取成员列表，为 YES 时，一次性返回 200 个以内成员。
 *  @param pError                错误信息。
 *
 *  @result 聊天室实例，详见 AgoraChatroom。
 *
 *  \~english
 *  Fetches the chatroom's specification.
 * 
 *  Deprecated, please use  {@link IAgoraChatroomManager getChatroomSpecificationFromServerWithId:error:}  instead.
 *
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param aChatroomId           The chatroom ID.
 *  @param aIncludeMembersList   Whether to get the member list. If you set the parameter as YES, it will return no more than 200 members. 
 *  @param pError                The error information if the method fails: Error.
 *
 *  @result The chatroom instance. See AgoraChatroom.
 */
- (AgoraChatroom *)fetchChatroomInfo:(NSString *)aChatroomId
               includeMembersList:(BOOL)aIncludeMembersList
                            error:(AgoraChatError **)pError EM_DEPRECATED_IOS(3_1_0, 3_3_0, "Use -IAgoraChatroomManager getChatroomSpecificationFromServerWithId:error: instead");

/**
 *  \~chinese
 *  获取聊天室详情。
 * 
 *  已废弃，请用 {@link IAgoraChatroomManager getChatroomSpecificationFromServerWithId:completion:} 代替。
 *
 *  @param aChatroomId           聊天室 ID。
 *  @param aIncludeMembersList   是否获取成员列表，为 YES 时，返回 200 个成员
 *  @param aCompletionBlock      该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Fetches chat room specifications.
 * 
 *  Deprecated, please use  {@link IAgoraChatroomManager getChatroomSpecificationFromServerWithId:completion:}  instead.
 *
 *  @param aChatroomId           The chatroom ID.
 *  @param aIncludeMembersList   Whether to get the member list. If you set the parameter as YES, it will return 200 members.
 *  @param aCompletionBlock      The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getChatroomSpecificationFromServerByID:(NSString *)aChatroomId
                            includeMembersList:(BOOL)aIncludeMembersList
                                    completion:(void (^)(AgoraChatroom *aChatroom, AgoraChatError *aError))aCompletionBlock EM_DEPRECATED_IOS(3_1_0, 3_3_0, "Use -IAgoraChatroomManager getChatroomSpecificationFromServerWithId:completion: instead");

#pragma mark - EM_DEPRECATED_IOS 3.2.3

/**
 *  \~chinese
 *  添加回调代理。
 *
 *  已废弃，请用 {@link IAgoraChatroomManager addDelegate:delegateQueue:} 代替。
 * 
 *  @param aDelegate  要添加的代理。
 *
 *  \~english
 *  Adds delegate.
 * 
 *  Deprecated, please use  {@link IAgoraChatroomManager addDelegate:delegateQueue:}  instead.
 *
 *  @param aDelegate  The delegate you want to add.
 */
- (void)addDelegate:(id<AgoraChatroomManagerDelegate>)aDelegate EM_DEPRECATED_IOS(3_1_0, 3_2_2, "Use -IAgoraChatroomManager addDelegate:delegateQueue: instead");

#pragma mark - EM_DEPRECATED_IOS < 3.2.3

/**
 *  \~chinese
 *  从服务器获取所有的聊天室。
 *
 *  已废弃，请用 {@link getChatroomsFromServerWithPage} 代替。
 * 
 *  同步方法，会阻塞当前线程。
 *
 *  @param pError   出错信息。
 *
 *  @result 聊天室列表，详见 <AgoraChatroom>。
 *
 *  \~english
 *  Gets all the chatrooms from the server.
 *
 *  Deprecated, please use  {@link getChatroomsFromServerWithPage}  instead.
 * 
 *  This is a synchronous method and blocks the current thread.
 *
 *  @param pError   The error information if the method fails: Error.
 *
 *  @result         The chat room list.
 */
- (NSArray *)getAllChatroomsFromServerWithError:(AgoraChatError **)pError __deprecated_msg("Use -getChatroomsFromServerWithPage instead");

/**
 *  \~chinese
 *  从服务器获取所有的聊天室。
 * 
 *  已废弃，请用 {@link getChatroomsFromServerWithPage} 代替。
 *
 *  @param aCompletionBlock      该方法完成调用的回调。如果该方法调用失败，会包含调用失败的原因。
 *
 *  \~english
 *  Gets all the chatrooms from server.
 * 
 *  Deprecated, please use  {@link getChatroomsFromServerWithPage}  instead.
 *
 *  @param aCompletionBlock     The completion block, which contains the error message if the method call fails.
 *
 */
- (void)getAllChatroomsFromServerWithCompletion:(void (^)(NSArray *aList, AgoraChatError *aError))aCompletionBlock __deprecated_msg("Use -getChatroomsFromServerWithPage instead");

/**
 *  \~chinese
 *  从服务器获取所有的聊天室。
 * 
 *  已废弃，请用 {@link getAllChatroomsFromServerWithCompletion} 代替。
 *
 *  @param aSuccessBlock         成功的回调。
 *  @param aFailureBlock         失败的回调。
 *
 *  \~english
 *  Gets all the chatrooms from the server.
 *
 *  Deprecated, please use  {@link getAllChatroomsFromServerWithCompletion}  instead.
 * 
 *  @param aSuccessBlock         The callback block of success.
 *  @param aFailureBlock         The callback block of failure, which contains the error message if the method fails.
 *
 */
- (void)asyncGetAllChatroomsFromServer:(void (^)(NSArray *aList))aSuccessBlock
                               failure:(void (^)(AgoraChatError *aError))aFailureBlock __deprecated_msg("Use -getAllChatroomsFromServerWithCompletion: instead");

/**
 *  \~chinese
 *  加入一个聊天室。
 * 
 *  已废弃，请用 {@link joinChatroom:completion:} 代替。
 *
 *  @param aChatroomId      聊天室的 ID。
 *  @param aSuccessBlock    成功的回调。
 *  @param aFailureBlock    失败的回调。
 *
 *
 *  \~english
 *  Joins a chatroom.
 * 
 *  Deprecated, please use  {@link joinChatroom:completion:}  instead.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aSuccessBlock    The callback block of success.
 *  @param aFailureBlock    The callback block of failure, which contains the error message if the method fails.
 *
 */
- (void)asyncJoinChatroom:(NSString *)aChatroomId
                  success:(void (^)(AgoraChatroom *aRoom))aSuccessBlock
                  failure:(void (^)(AgoraChatError *aError))aFailureBlock __deprecated_msg("Use -joinChatroom:completion: instead");

/**
 *  \~chinese
 *  退出聊天室。
 * 
 *  已废弃，请用 {@link leaveChatroom:completion:} 代替。
 *
 *  @param aChatroomId          聊天室 ID。
 *  @param aSuccessBlock        成功的回调。
 *  @param aFailureBlock        失败的回调。
 *
 *  @result 退出的聊天室。
 *
 *  \~english
 *  Leaves a chatroom.
 * 
 *  Deprecated, please use  {@link leaveChatroom:completion:}  instead.
 *
 *  @param aChatroomId      The chatroom ID.
 *  @param aSuccessBlock    The callback block of success.
 *  @param aFailureBlock    The callback block of failure, which contains the error message if the method fails.
 *
 *  @result Leaved chatroom
 */
- (void)asyncLeaveChatroom:(NSString *)aChatroomId
                   success:(void (^)(AgoraChatroom *aRoom))aSuccessBlock
                   failure:(void (^)(AgoraChatError *aError))aFailureBlock __deprecated_msg("Use -leaveChatroom:completion: instead");

/**
 *  \~chinese
 *  获取聊天室详情。
 * 
 *  已废弃，请用 {@link getChatroomSpecificationFromServerByID:includeMembersList:completion:} 代替。
 *
 *  @param aChatroomId           聊天室 ID。
 *  @param aIncludeMembersList   是否获取成员列表。
 *  @param aSuccessBlock         成功的回调。
 *  @param aFailureBlock         失败的回调。
 *
 *  \~english
 *  Fetches chatroom's specification.
 * 
 *  Deprecated, please use  {@link getChatroomSpecificationFromServerByID:includeMembersList:completion:}  instead.
 *
 *  @param aChatroomId           The chatroom ID.
 *  @param aIncludeMembersList   Whether to get member list.
 *  @param aSuccessBlock         The callback block of success.
 *  @param aFailureBlock         The callback block of failure, which contains the error message if the method fails.
 *
 */
- (void)asyncFetchChatroomInfo:(NSString *)aChatroomId
            includeMembersList:(BOOL)aIncludeMembersList
                       success:(void (^)(AgoraChatroom *aChatroom))aSuccessBlock
                       failure:(void (^)(AgoraChatError *aError))aFailureBlock __deprecated_msg("Use -getChatroomSpecificationFromServerByID:includeMembersList:completion: instead");
@end

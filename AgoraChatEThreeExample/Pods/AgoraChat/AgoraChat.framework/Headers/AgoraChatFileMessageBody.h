/**
 *  \~chinese
 *  @header AgoraChatFileMessageBody.h
 *  @abstract 文件消息体。
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatFileMessageBody.h
 *  @abstract The file message body.
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "AgoraChatMessageBody.h"

/**
 *  \~chinese
 *  附件下载状态枚举类型。
 *
 *  \~english
 *  The status types for downloading the file message.
 */
typedef enum {
    AgoraChatDownloadStatusDownloading   = 0,  /** \~chinese 正在下载文件消息。  \~english The SDK is downloading the file message. */
    AgoraChatDownloadStatusSucceed,            /** \~chinese 下载文件消息成功。 \~english The SDK successfully downloads the file message. */
    AgoraChatDownloadStatusFailed,             /** \~chinese 下载文件消息失败。  \~english The SDK fails to download the file message.*/
    AgoraChatDownloadStatusPending,            /** \~chinese 文件消息下载正在等待中。  \~english File message download is pending.*/
    AgoraChatDownloadStatusSuccessed=AgoraChatDownloadStatusSucceed,   /** \~chinese 该状态已废弃。请改用 AgoraChatDownloadStatusSucceed。  \~english This state is deprecated. Use AgoraChatDownloadStatusSucceed instead.*/
} AgoraChatDownloadStatus;

/**
 *  \~chinese
 *  文件消息体。
 *
 *  \~english
 *  The file message body.
 */
@interface AgoraChatFileMessageBody : AgoraChatMessageBody

/**
 *  \~chinese
 *  附件的显示名称。
 *
 *  \~english
 *  The display name of the attachment.
 */
@property (nonatomic, copy) NSString *displayName;

/**
 *  \~chinese
 *  附件的本地路径。
 *
 *  \~english
 *  The path of the attachment on the local device.
 */
@property (nonatomic, copy) NSString *localPath;

/**
 *  \~chinese
 *  附件在服务器上的路径。
 *
 *  \~english
 *  The path of the attachment in the server.
 */
@property (nonatomic, copy) NSString *remotePath;

/**
 *  \~chinese
 *  附件的密钥, 下载附件时需要密匙做校验。
 *
 *  \~english
 *  The secret key for downloading the message attachment.
 */
@property (nonatomic, copy) NSString *secretKey;

/**
 *  \~chinese
 *  附件的大小, 以字节为单位。
 *
 *  \~english
 *  The data length (bytes) of the attachment.
 */
@property (nonatomic) long long fileLength;

/**
 *  \~chinese
 *  附件的下载状态。
 *
 *  \~english
 *  The downloading status of the attachment.
 */
@property (nonatomic) AgoraChatDownloadStatus downloadStatus;

/**
 *  \~chinese
 *  初始化文件消息体。
 *
 *  @param aLocalPath   附件本地路径。
 *  @param aDisplayName 附件显示名称（不包含路径）。
 *
 *  @result 消息体实例。
 *
 *  \~english
 *  Initializes a file message instance.
 *
 *  @param aLocalPath   The path of the file attachment in the local device.
 *  @param aDisplayName The display name of the file attachment.
 *
 *  @result The file message instance.
 */
- (instancetype)initWithLocalPath:(NSString *)aLocalPath
                      displayName:(NSString *)aDisplayName;

/**
 *  \~chinese
 *  初始化文件消息体。
 *
 *  @param aData        附件内容数据。
 *  @param aDisplayName 附件显示名（不包含路径）。
 *
 *  @result 消息体实例。
 *
 *  \~english
 *  Initializes a file message instance.
 * 
 *  @param aData        The data of the attachment file.
 *  @param aDisplayName The display name of the attachment.
 * 
 *  @Result The file message instance.
 */
- (instancetype)initWithData:(NSData *)aData
                 displayName:(NSString *)aDisplayName;


@end

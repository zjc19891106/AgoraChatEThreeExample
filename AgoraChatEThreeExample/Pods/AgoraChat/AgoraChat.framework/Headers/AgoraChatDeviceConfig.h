/**
 *  \~chinese
 *  @header AgoraChatDeviceConfig.h
 *  @abstract 已登录设备的信息类。
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraChatDeviceConfig.h
 *  @abstract The information of the device.
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/**
 *  \~chinese
 *  登录设备配置信息。
 *
 *  \~english
 *  The configurations of the device that the user logs into.
 */
@interface AgoraChatDeviceConfig : NSObject

/**
 *  \~chinese
 *  设备资源描述。
 *
 *  \~english
 *  The device resources.
 */
@property (nonatomic, readonly) NSString *resource;

/**
 *  \~chinese
 *  设备的 UUID。
 *
 *  \~english
 *  The device UUID.
 */
@property (nonatomic, readonly) NSString *deviceUUID;

/**
 *  \~chinese
 *  设备名称。
 *
 *  \~english
 *  The device name.
 */
@property (nonatomic, readonly) NSString *deviceName;

@end

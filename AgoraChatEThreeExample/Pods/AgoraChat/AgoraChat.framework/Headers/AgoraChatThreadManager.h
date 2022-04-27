//
//  AgoraChatThreadManager.h
//  AgoraChat
//
//  Created by 朱继超 on 2022/3/1.
//  Copyright © 2022 easemob.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AgoraChatBaseManager.h"
#import "AgoraChatThreadManagerListener.h"
#import "IAgoraChatThreadManager.h"
@class AgoraChatThread;
NS_ASSUME_NONNULL_BEGIN
@interface AgoraChatThreadManager : AgoraChatBaseManager<IAgoraChatThreadManager>
{
    easemob::EMCallbackObserverHandle handle_;
    emsdk::AgoraChatThreadManagerListener *threadListener_;
}
@property (strong, nonatomic, readonly) AgoraChatMulticastDelegate<AgoraChatThreadManagerDelegate> *delegates;

- (void)removeThreadListener;

- (AgoraChatThread *)_getChatThreadWithId:(NSString *)aGroupId;
NS_ASSUME_NONNULL_END
@end


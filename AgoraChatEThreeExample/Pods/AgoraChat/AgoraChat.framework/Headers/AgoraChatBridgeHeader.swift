//
//  BridgeHeader.swift
//
//  Created by 杜洁鹏 on 2021/9/27.
//


public extension AgoraChatClient {

    static var share: AgoraChatClient {
        return AgoraChatClient.shared()
    }
}


public extension AgoraChatConversationType {
    static var chat:AgoraChatConversationType {
        return AgoraChatConversationTypeChat
    }

    static var groupChat:AgoraChatConversationType {
        return AgoraChatConversationTypeGroupChat
    }

    static var chatRoom:AgoraChatConversationType {
        return AgoraChatConversationTypeChatRoom
    }
}


public extension AgoraChatMessageBodyType {
    static var text:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeText
    }

    static var image:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeImage
    }

    static var video:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeVideo
    }
    
    static var location:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeLocation
    }
    
    static var voice:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeVoice
    }
    
    static var file:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeFile
    }
    
    static var cmd:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeCmd
    }
    
    static var custom:AgoraChatMessageBodyType {
        return AgoraChatMessageBodyTypeCustom
    }
    
}



public enum EMMessageBaseBody {
    case text(_ text: String)
    case image(_ localPath: String, _ displayName: String)
    case video(_ localPath: String, _ displayName: String)
    case location(_ latitude: Double, _ longitude: Double, _ address: NSString, _ buildingName: NSString)
    case voice(_ localPath: String, _ displayName: String)
    case file(_ localPath: String, _ displayName: String)
    case cmd(_ action: String)
    case custom(_ event: NSString, customExt:NSDictionary)
}


public extension AgoraChatMessage {

    var swiftBody:EMMessageBaseBody {
        let  tBody:AgoraChatMessageBody = self.body
        switch  self.body.type {
        case AgoraChatMessageBodyTypeText:
            let textBody = tBody as! AgoraChatTextMessageBody
            return .text(textBody.text)
        case AgoraChatMessageBodyTypeImage:
            let imageBody = tBody as! AgoraChatImageMessageBody
            return .image(imageBody.localPath, imageBody.displayName)
        case AgoraChatMessageBodyTypeVideo:
            let videoBody = tBody as! AgoraChatVideoMessageBody
            return .video(videoBody.localPath, videoBody.displayName)
        case AgoraChatMessageBodyTypeLocation:
            let locationBody = tBody as! AgoraChatLocationMessageBody
            return .location(locationBody.latitude, locationBody.longitude, locationBody.address! as NSString,locationBody.buildingName! as NSString)
        case AgoraChatMessageBodyTypeVoice:
            let voiceBody = tBody as! AgoraChatVoiceMessageBody
            return .voice(voiceBody.localPath, voiceBody.displayName)
        case AgoraChatMessageBodyTypeFile:
            let fileBody = tBody as! AgoraChatFileMessageBody
            return .file(fileBody.localPath, fileBody.displayName)
        case AgoraChatMessageBodyTypeCmd:
            let cmdBody = tBody as! AgoraChatCmdMessageBody
            return .cmd(cmdBody.action)
        case AgoraChatMessageBodyTypeCustom:
            let customBody = tBody as! AgoraChatCustomMessageBody
            return .custom(customBody.event! as NSString, customExt: customBody.customExt! as NSDictionary)
        default:
            let textBody = tBody as! AgoraChatTextMessageBody
            return .text(textBody.text)
        }
        
    }

    
    convenience init(conversationId: String, from: String, to: String,body: EMMessageBaseBody!, ext: [AnyHashable: Any]!) {

        var msgBody : AgoraChatMessageBody
        switch body {
        case .text(let msg):
            msgBody = AgoraChatTextMessageBody(text: msg)
            break
        case .image(let path, let displayName):
            msgBody = AgoraChatImageMessageBody(localPath: path, displayName: displayName)
            break
        case .video(let path, let displayName):
            msgBody = AgoraChatVideoMessageBody(localPath: path, displayName: displayName)
            break
        case .location(let latitude, let longitude, let address, let buildingName):
            msgBody = AgoraChatLocationMessageBody(latitude: latitude, longitude: longitude, address: address as String, buildingName: buildingName as String)
            break
        case .voice(let path, let displayName):
            msgBody = AgoraChatVoiceMessageBody(localPath: path, displayName: displayName)
            break
        case .file(let path, let displayName):
            msgBody = AgoraChatFileMessageBody(localPath: path, displayName: displayName)
            break
        case .cmd(let action):
            msgBody = AgoraChatCmdMessageBody(action: action)
            break
        case .custom(let event, let customExt):
            msgBody = AgoraChatCustomMessageBody(event: event as String, ext: customExt as? [AnyHashable : Any])
            break
        case .none:
            msgBody = AgoraChatTextMessageBody(text: "a")
            break
        }
        self.init(conversationID: conversationId, from: from, to: to, body: msgBody, ext: ext)
    }
}




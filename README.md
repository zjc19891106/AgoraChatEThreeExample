# AgoraChatEThreeExample
A chat demo based on AgoraChatSDK (basic chat) and VirgilE3Kit (encryption)

-----------------------------------------------------------------------

## Demo structure

The AgoraChatEThreeExample folder contains an AgoraChatEThreeExample project folder.Contains functions related to registration, login and logout and session list encryption session.

The AgoraChatRequest class is used to initiate network requests, and the E3EncryptoManager is used to save and create the current user's VirgilE3KitSDK object and save some information.

## What is encryption chat?

An encrypted session means that only users on both sides of the chat can see the specific content of the current message after receiving the message (the server does not know the content of the message). It protects the privacy of user chat content very well.

## How to implement encrypted sessions

### We use the group encryption function of VirgilE3Kit to ensure that users can see the historical messages in the local database.

1. We use our own login and registration and then use the token generator of VirgilE3Kit to generate a jwt and then generate the VirgilE3KitSDK object according to the jwt.

`
    func e3Authenticate(userName: String,callBack:@escaping ((String?,Error?) -> Void)) {
        do {
            try self.constructRequest(method: .post, uri: "/authenticate", params: ["identity":userName], headers: ["Content-Type":"application/json"]) { data,response,error in
                let token = data?.z.toDictionary()?["authToken"] as? String
                DispatchQueue.main.async {
                    callBack(token,nil)
                }
            }
        } catch {
            assert(false, "register error:\(error.localizedDescription)")
        }
    }
    
    func virgilToken(token: String,callBack:@escaping ((String?,Error?) -> Void)) {
        do {
            try self.constructRequest(method: .post, uri: "/virgil-jwt", params: ["identity":AgoraChatClient.shared().currentUsername ?? ""], headers: ["Content-Type":"application/json","Authorization": "Bearer " + token]) { data,response,error in
                let token = data?.z.toDictionary()?["virgilToken"] as? String
                DispatchQueue.main.async {
                    callBack(token,nil)
                }
            }
        } catch {
            assert(false, "register error:\(error.localizedDescription)")
        }
    }
    
    try EThree(identity: userName, tokenCallback: tokenCallback)
`

2. Use this E3 object to register the current user with VirgilE3Kit.

`
    E3EncryptoManager.shared.e3?.register(completion: { error in
        ProgressHUD.dismiss()
        DispatchQueue.main.async {
            self.handleRegister(userName, error)
        }
    })
`
3. Get the current user's Card object.

`
    try E3EncryptoManager.shared.card = E3EncryptoManager.shared.e3?.findUser(with: userName.lowercased()).startSync(timeout: 3).get()
`
4. Use the E3 object to create a VirgilE3Kit.Group object based on the session creator's Card object and the sessionId(This group id is a string sorted by the id of the message sender and the message receiver plus the AgoraChat string).

`
    cards = try E3EncryptoManager.shared.e3?.findUsers(with: [self.toChatId.lowercased()]).startSync(timeout: 5).get()
    var groupId = E3EncryptoManager.shared.e3!.identity + self.toChatId + "AgoraChat"
    groupId = groupId.lowercased()
    groupId = String(groupId.sorted())
    group = try E3EncryptoManager.shared.e3?.createGroup(id: groupId, with: cards!).startSync(timeout: 5).get()
    E3EncryptoManager.shared.e3GroupMap[groupId.lowercased()] = group
`
5. Use the Group object to encrypt and decrypt the corresponding message.

#### Encrypt
`
    guard var text = textField.text else { return false }
    do {
        text = try self.group?.encrypt(text: text) ?? ""
    } catch {
        ProgressHUD.showError("chat send message error:\(error.localizedDescription)")
    }
`
#### Decrypt
`
    content = try self.group?.decrypt(text: body.text, from: (E3EncryptoManager.shared.cards?[message.from])!, date: DateUtils.dateFromMilliTimestamp(message.timestamp)) ?? "decrypt error"
`

## Using

After downloading the code, enter the AgoraChatEThreeExample folder in the terminal, and open the workspace after pod install.

`cd AgoraChatEThreeExample`

`pod install`

## Quote

> [Virgil Security document](https://developer.virgilsecurity.com/docs/e3kit/fundamentals/cryptography/)
> [Virgil Security github](https://github.com/VirgilSecurity)

## Extension

At present, this demo function supports single chat. If you want to support the group, you can replace the two parameters of the session created in the demo with the group id and the group creator.

## ios push

### Remote push

to register remote push:

##### From ios8:

<pre>
- registerForRemoteNotifications
</pre>

it has callback for success and failure. To perform some user-facing actions, you must call the:

<pre>
- registerUserNotificationSettings:
</pre>

The first time your app launches and calls this method, the system asks the user whether your app should be allowed to deliver notifications and stores the response. Thereafter, the system uses the stored response to determine the actual types of notifications you may use. The callback is always called:

<pre>
-  application:didRegisterUserNotificationSettings: 
</pre>

##### Before ios8:

<pre>
- registerForRemoteNotificationTypes
</pre>

#### Loud Push

##### From ios8:

When clicking the remote notification to start the app, the notification is wrapped in the 'UIApplicationLaunchOptionsRemoteNotificationKey' of 'launchOptions' passed from launchApp:withLaunchOptions:, and 'didReceiveRemoteNotification' is also called.

##### Before ios8:

When app is started due to push, the 'launchApp:withLaunchOptions:' is called without the notification. Followed by 'didReceiveRemoteNotification'.

#### Silent push

The payload has 'content-available: 1'. 

The app can be automatically launched if the user didn't kill the app. Moreover, 'didReceiveRemoteNotification' is called when the push is received.

### Voip push

https://developer.apple.com/library/prerelease/ios/documentation/Performance/Conceptual/EnergyGuide-iOS/OptimizeVoIP.html

## Server

- Payload:

For the remote pushes, the payload is a dictionary that contains at least one item, “aps”, which itself is also a dictionary.

- Cert:

Digital certificates are based on public-private key cryptography.

The certificate(.cer) is the public part of this key pair. 

Whenever you apply for a digital certificate(.cer), you need to provide a Certificate Signing Request(CSR). When you create the CSR, a new private key(p12) is made that is put into your keychain.

3 of the files: .cer, .p12, .pem are used to send the push.
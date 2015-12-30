# VoiceIt SDK for iOS

A library that gives you out of the box access to the VoiceIt's Voice Authentication API right from your iOS app.
For more information on VoiceIt and its features, see [the website](http://voiceit.tech) and [getting started docs](https://siv.voiceprintportal.com/getstarted.jsp)

* [Getting Started](#getting-started)
* [Installation](#installation)
* [Setup](#setup)
  * [The Parameters](#the-parameters)
  * [Swift](#swift)
  * [Objective-C](#objective-c)
* [Preview](#preview)
* [Attributions](#attributions)


## Getting Started

To use the VoiceIt in your iOS app, if you haven't already, please Sign Up for a free **Developer Id** at [http://voiceit.tech](https://siv.voiceprintportal.com/getDeveloperID.jsp). Then either fork this repository and try the [DemoStarterProjectSwift](https://github.com/voiceittech/voiceit-sdk-iOS/tree/master/DemoStarterProjectSwift) or [DemoStarterProjectObjectiveC](https://github.com/voiceittech/voiceit-sdk-iOS/tree/master/DemoStarterProjectObjectiveC) , then when ready you can download the [VoiceIt iOS SDK Zip](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/VoiceIt-iOS-SDK.zip?raw=true) and follow the installation instructions below.

## Installation

Once you have downloaded the [VoiceIt iOS SDK Zip](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/VoiceIt-iOS-SDK.zip?raw=true) simply drag and drop both the VoiceItResources.bundle and VoiceItSDK.framework file into your project.

After successfully adding the framework and resources bundle  you will need to add some built in iOS frameworks that are required by the iOS SDK. You are required to add the following frameworks:

```
1. SystemConfiguration.framework
2. AVFoundation.framework
3. MediaPlayer.framework
```
To do so please follows these steps:

* In the project editor, select the target to which you want to add a library or framework.
* Click Build Phases at the top of the project editor.
* Open the Link Binary With Libraries section.
* Click the Add button (+) to add a library or framework.
* Select a library or framework from the list and click Add.

![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/frameworks.png "Preview")

**Congratulations** you now have the SDK Installed and can start programming with it, please follow the **Setup** instructions below to continue.

## Setup
### The Parameters
First lets introduce you to some vocabulary(parameters) that is needed to setup this SDK in your app
  1. **DeveloperId** : Your unique Developer Id that you can obtain at [voiceit.tech](https://siv.voiceprintportal.com/getDeveloperID.jsp)
  2. **UserToken** : A unique user token(with no spaces) that ties the VoiceIt user enrollments to the user in your own database ex. *johndoe123*
  3. **vpPhrase** : The phrase you would like the user to enroll and authenticate with chosen from [this list](https://siv.voiceprintportal.com/att/en-US-grammar.grxml)
  4. **textConfidence** : Text confidence usually set between 20.0 and 50.0 to make sure the user's are using the right phrase
  5. **confidence** : The authentication confidence level between 85.0 - 100.0, our recommended value is 85.0 for best results
  6. **accuracy** : The accuracy in evaluating the authentication between 0-5, 0 being the most strict and 5 the most lax.  Our recommended value is 5.  
  7. **accuracy passes** : Number of times a recording will be run through our engine, but will return upon first successful authentication (between 1-10). Our recommended value is 10.
  8. **accuracy pass increment** : Amount by which accuracy parameter is increased with every pass (between 1-5).  Our recommended value is 5.

* If using Objective-C please [skip](#objective-c)

### Swift
If you are programming in Swift then you need to first setup an Objective-C bridging header before starting. You can follow [this guide](http://www.learnswiftonline.com/getting-started/adding-swift-bridging-header/) to create a bridging header. Then add the following to the top of the bridging-header file:
```objc
#import <VoiceItSDK/VoiceItSDK.h>
```
After importing the library in the file we can initialize the VoiceItLogin View Controller by adding the following code snippet wherever we like, in our code.

```swift
let vc = VoiceItLogin(
  DEVELOPER_ID_HERE,
  userToken: USER_TOKEN_HERE,
  vpPhrase: "Never forget tomorrow is a new day",
  textConfidence: "30.0",
  accuracy: "5",
  accuracyPasses: "10",
  accuracyPassIncrement: "5",
  confidence: "85" ,
  callback: { (result) -> Void in
    if result == "Success"
    {
        //DO SOMETHING IF SUCCESSFULLY AUTHENTICATED
    }
    else if result == "Failed"
    {
        //DO SOMETHING IF AUTHENTICATION FAILED
    }
})
self.presentViewController(vc, animated: true, completion: nil)
```

### Objective-C
If you are programming in Objective-C then you can simply import the SDK into whichever .h or .m file you would like to use it, with the import statement.
```objc
#import <VoiceItSDK/VoiceItSDK.h>
```
After importing the library in the file we can initialize the VoiceItLogin View Controller by adding the following code snippet wherever we like, in our code.

```objc
VoiceItLogin * vc =
 [[VoiceItLogin alloc] init:DEVELOPER_ID_HERE
 userToken:USER_TOKEN_HERE
 vpPhrase:@"Never forget tomorrow is a new day"
 textConfidence:@"30.0"
 accuracy:@"5"
 accuracyPasses:@"10"
 accuracyPassIncrement:@"5"
 confidence:@"85"
 callback:^(NSString *result) {
       if ([result isEqualToString:@"Success"]) {
           //DO STUFF WHEN AUTHENTICATED SUCCESSFULLY
       }
       else{
           //DO STUFF IF AUTHENTICATION FAILED
       }
       }];
[self presentViewController:vc animated:YES completion:nil];
```
##Preview
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot1.png "Preview1")
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot2.png "Preview2")
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot3.png "Preview3")
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot4.png "Preview4")
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot5.png "Preview5")
![alt text](https://github.com/voiceittech/voiceit-sdk-iOS/blob/master/images/iOS-SDK-ScreenShot6.png "Preview5")

##Attributions
Thanks to [Mohd Iftekhar Qurashi](https://github.com/hackiftekhar) for his awesome [IQAudioRecorderController](https://github.com/hackiftekhar/IQAudioRecorderController) library.

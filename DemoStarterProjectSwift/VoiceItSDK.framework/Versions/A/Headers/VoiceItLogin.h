//
//  VoiceItLogin.h
//  IQAudioRecorderController Demo

#import <UIKit/UIKit.h>
#import "IQAudioRecorderController.h"
#import "MBProgressHUD.h"
#import "VoiceIt.h"

typedef void (^Return_Result_Block)(NSString *);
@interface VoiceItLogin : UIViewController <IQAudioRecorderControllerDelegate,
                                            MBProgressHUDDelegate>

- (void)viewDidLoad;

- (IBAction)clickedRecord:(UIButton *)sender;

- (void)audioRecorderController:(IQAudioRecorderController *)controller
       didFinishWithAudioAtPath:(NSString *)filePath;

- (void)audioRecorderControllerDidCancel:
    (IQAudioRecorderController *)controller;

- (id)init:(NSString *)developerId
 userToken:(NSString *)userToken
  vpPhrase:(NSString *)vpPhrase
textConfidence:(NSString *)textConfidence
confidence:(NSString *)confidence
  callback:(void (^)(NSString *))callback;

- (id)init:(NSString *)developerId
         userToken:(NSString *)userToken
          vpPhrase:(NSString *)vpPhrase
    textConfidence:(NSString *)textConfidence
        confidence:(NSString *)confidence
   contentLanguage:(NSString *)contentLanguage
          callback:(void (^)(NSString *))callback;

- (IBAction)playAction:(UIButton *)sender;
@property (nonatomic, strong) NSString *audioFilePath;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *vppPhrase;
@property (nonatomic, strong) NSString *developerId;
@property (nonatomic, strong) NSString *FirstName;
@property (nonatomic, strong) NSString *LastName;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *userToken;
@property (nonatomic, strong) NSString *textConfidence;
@property (nonatomic, strong) NSString *confidence;
@property (nonatomic, strong) NSString *contentLanguage;
@property (nonatomic, strong) UIButton *recordingButton;
@property int userExists;
@property (nonatomic, strong) UILabel *messageDisplay;
@property (nonatomic, copy) Return_Result_Block returnResults;
@property int tempNumEnrollments;
//@property int currentAction;
@property MBProgressHUD *HUD;
@property IQAudioRecorderController *controller;
@property VoiceIt *myVoiceIt;
/*

*/
@end

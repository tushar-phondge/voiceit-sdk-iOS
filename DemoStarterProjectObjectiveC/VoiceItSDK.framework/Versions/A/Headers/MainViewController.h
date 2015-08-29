//
//  MainViewController.h
//  IQAudioRecorderController Demo


#import <UIKit/UIKit.h>
#import "IQAudioRecorderController.h"
#import "MBProgressHUD.h"

@interface MainViewController : UIViewController <IQAudioRecorderControllerDelegate>

- (void)viewDidLoad;

- (IBAction)clickedRecord:(UIButton *)sender;

-(void)audioRecorderController:(IQAudioRecorderController *)controller didFinishWithAudioAtPath:(NSString *)filePath;

-(void)audioRecorderControllerDidCancel:(IQAudioRecorderController *)controller;
- (id) init:(NSString *)developerId;

- (IBAction)playAction:(UIButton *)sender;
@property (nonatomic,weak) NSString * audioFilePath;
@property (nonatomic,weak) NSString * email;
@property (nonatomic,weak) NSString * developerId;
@property (nonatomic,weak) NSString * FirstName;
@property (nonatomic,weak) NSString * LastName;
@property (nonatomic,weak) NSString * password;
@property (nonatomic,weak) NSString * userToken;
@property (nonatomic,strong) UILabel *messageDisplay;
@property int tempNumEnrollments;
//@property int currentAction;
@property MBProgressHUD * HUD;
@property IQAudioRecorderController* controller;
/*

*/
@end

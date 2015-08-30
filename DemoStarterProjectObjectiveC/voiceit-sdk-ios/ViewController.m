//
//  ViewController.m
//  voiceit-sdk-ios
//
//  Created by Armaan Bindra on 8/28/15.
//  Copyright (c) 2015 VoiceIt Technologies LLC. All rights reserved.
//

#import "ViewController.h"
#import <VoiceItSDK/VoiceItSDK.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *userTokenField;
@property (weak, nonatomic) IBOutlet UILabel *resultLabel;
@end

@implementation ViewController
NSString * DEVELOPER_ID;

- (void)viewDidLoad {
    [super viewDidLoad];
    //ADD YOUR VoiceIt DEVELOPER ID HERE for Example: 123456, If you do not already have a DEVELOPER ID get one
    //at https://siv.voiceprintportal.com/getDeveloperID.jsp
    DEVELOPER_ID = @"DEVELOPER_ID_HERE";
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)clickedLogin:(id)sender {
    VoiceItLogin * vc = [[VoiceItLogin alloc] init:DEVELOPER_ID userToken:[[self userTokenField] text] vpPhrase:@"Never forget tomorrow is a new day" textConfidence:@"30.0" confidence:@"87" callback:^(NSString *result) {
        if ([result isEqualToString:@"Success"]) {
            //DO STUFF WHEN AUTHENTICATED SUCCESSFULLY
        }
        else{
            //DO STUFF IF AUTHENTICATION FAILED
        }
        }];
    
    [self presentViewController:vc animated:YES completion:nil];
}

@end

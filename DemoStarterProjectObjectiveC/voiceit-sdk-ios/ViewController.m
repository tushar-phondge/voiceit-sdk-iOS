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
@property (weak, nonatomic) IBOutlet UIPickerView *contentLangPicker;
@property (weak, nonatomic) IBOutlet UILabel *resultLabel;
@property (weak, nonatomic) IBOutlet UITextField *phraseField;
@property NSMutableArray *allLanguages;
@property NSString *selectedLanguage;
@end

@implementation ViewController
NSString * DEVELOPER_ID;

- (void)viewDidLoad {
    [super viewDidLoad];
    //ADD YOUR VoiceIt DEVELOPER ID HERE for Example: 123456, If you do not already have a DEVELOPER ID get one
    //at https://siv.voiceprintportal.com/getDeveloperID.jsp
    DEVELOPER_ID = @"200035";
    
    self.allLanguages = [[NSMutableArray alloc] initWithObjects:@"en-US", @"en-GB", @"zh-CN", @"es-ES", @"fr-FR", @"ko-KR", nil];
    self.contentLangPicker.delegate = self;
    self.selectedLanguage = @"en-US";
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)clickedLogin:(id)sender {
    VoiceItLogin * vc = [[VoiceItLogin alloc] init:DEVELOPER_ID userToken:[[self userTokenField] text] vpPhrase:[[self phraseField] text] textConfidence:@"30.0" confidence:@"85" callback:^(NSString *result) {
        if ([result isEqualToString:@"Success"]) {
            //DO STUFF WHEN AUTHENTICATED SUCCESSFULLY
     [self.resultLabel setText:@"Success"];
        }
        else{
            //DO STUFF IF AUTHENTICATION FAILED
     [self.resultLabel setText:@"Failed"];
        }
        }];
    /*
    VoiceItLogin * vc  = [[VoiceItLogin alloc] init:DEVELOPER_ID userToken:[[self userTokenField] text] vpPhrase:[[self phraseField] text] textConfidence:@"30.0" confidence:@"85" contentLanguage:self.selectedLanguage callback:^(NSString *result) {
        if ([result isEqualToString:@"Success"]) {
        //DO STUFF WHEN AUTHENTICATED SUCCESSFULLY
            [self.resultLabel setText:@"Success"];
        }
        else{
            [self.resultLabel setText:@"Failed"];
            }
                          }];*/
    
    [self presentViewController:vc animated:YES completion:nil];
}

- (NSInteger)pickerView:(UIPickerView *)pickerView
numberOfRowsInComponent:(NSInteger)component
{
    return [self.allLanguages count];
}

- (NSString *)pickerView:(UIPickerView *)pickerView
             titleForRow:(NSInteger)row
            forComponent:(NSInteger)component
{
    return [self.allLanguages objectAtIndex:row];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView{
    return 1;
}

-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row
      inComponent:(NSInteger)component
{
    self.selectedLanguage = [self.allLanguages objectAtIndex:row];
    //    NSLog(@"%@", [source objectAtIndex:row]);
}


-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}




@end

//
//  VILogin.h
//  VoiceItLogin
//
//  Created by Armaan Bindra on 4/29/15.
//  Copyright (c) 2015 VoiceIt Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VILogin : NSObject <UIAlertViewDelegate>

+(void)buildResponseJSON:(NSDictionary*)responseObj;
+(void)sendResponse;
+(void)sendDetails:(NSString*)appKey userToken:(NSString*)userToken vpPhrase:(NSString*)vpPhrase developerId:(NSString*)developerId confidence:(NSString*)confidence textConfidence:(NSString*)textConfidence;
+ (void)getResponse:(NSURL *)theURL callback:(void (^)(NSString*))callback;
+ (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex;
@end
static NSString* responseJSON;
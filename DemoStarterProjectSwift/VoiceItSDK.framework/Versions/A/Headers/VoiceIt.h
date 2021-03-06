//
//  VoiceIt.h
//  TestSDK
//
//  Created by Armaan Bindra on 6/29/15.
//  Copyright (c) 2015 Armaan Bindra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Encryption.h"

@interface VoiceIt : NSObject
- (NSString *)sha256:(NSString *)input;

// Properties
@property (nonatomic, strong) NSString *developerId;
@property (nonatomic, strong) NSString *platformID;

// Constructor
- (id)init:(NSString *)developerId;
- (id)init:(NSString *)developerId thePlatformId:(NSString *)thePlatformId;

// User API Calls
- (void)getUser:(NSString *)email
         passwd:(NSString *)passwd
       callback:(void (^)(NSString *))callback;
- (void)createUser:(NSString *)email
            passwd:(NSString *)passwd
         firstName:(NSString *)firstName
          lastName:(NSString *)lastName
          callback:(void (^)(NSString *))callback;
- (void)setUser:(NSString *)email
         passwd:(NSString *)passwd
      firstName:(NSString *)firstName
       lastName:(NSString *)lastName
       callback:(void (^)(NSString *))callback;
- (void)deleteUser:(NSString *)email
            passwd:(NSString *)passwd
          callback:(void (^)(NSString *))callback;

// Enrollments API Calls
- (void)getEnrollments:(NSString *)email
                passwd:(NSString *)passwd
              callback:(void (^)(NSString *))callback;

- (void)createEnrollment:(NSString *)email
                  passwd:(NSString *)passwd
     pathToEnrollmentWav:(NSString *)pathToEnrollmentWav
                callback:(void (^)(NSString *))callback;

- (void)createEnrollment:(NSString *)email
                  passwd:(NSString *)passwd
     pathToEnrollmentWav:(NSString *)pathToEnrollmentWav
         contentLanguage:(NSString *)contentLanguage
                callback:(void (^)(NSString *))callback;

- (void)createEnrollmentByWavURL:(NSString *)email
                          passwd:(NSString *)passwd
              urlToEnrollmentWav:(NSString *)urlToEnrollmentWav
                        callback:(void (^)(NSString *))callback;

- (void)createEnrollmentByWavURL:(NSString *)email
                          passwd:(NSString *)passwd
              urlToEnrollmentWav:(NSString *)urlToEnrollmentWav
                 contentLanguage:(NSString *)contentLanguage
                        callback:(void (^)(NSString *))callback;

- (void)getEnrollmentsCount:(NSString *)email
                     passwd:(NSString *)passwd
                    vppText:(NSString *)vppText
                   callback:(void (^)(NSString *))callback;

- (void)getEnrollmentsCount:(NSString *)email
                     passwd:(NSString *)passwd
                    vppText:(NSString *)vppText
            contentLanguage:(NSString *)contentLanguage
                   callback:(void (^)(NSString *))callback;

- (void)deleteEnrollment:(NSString *)email
                  passwd:(NSString *)passwd
            enrollmentId:(NSString *)enrollmentId
                callback:(void (^)(NSString *))callback;

// Authentication API Calls
- (void)authentication:(NSString *)email
                passwd:(NSString *)passwd
pathToAuthenticationWav:(NSString *)pathToAuthenticationWav
            confidence:(NSString *)confidence
              callback:(void (^)(NSString *))callback;

- (void)authentication:(NSString *)email
                     passwd:(NSString *)passwd
    pathToAuthenticationWav:(NSString *)pathToAuthenticationWav
                 confidence:(NSString *)confidence
            contentLanguage:(NSString *)contentLanguage
                   callback:(void (^)(NSString *))callback;

- (void)authenticationByWavURL:(NSString *)email
                        passwd:(NSString *)passwd
        urlToAuthenticationWav:(NSString *)urlToAuthenticationWav
                    confidence:(NSString *)confidence
                      callback:(void (^)(NSString *))callback;

- (void)authenticationByWavURL:(NSString *)email
                        passwd:(NSString *)passwd
        urlToAuthenticationWav:(NSString *)urlToAuthenticationWav
                    confidence:(NSString *)confidence
               contentLanguage:(NSString *)contentLanguage
                      callback:(void (^)(NSString *))callback;
@end

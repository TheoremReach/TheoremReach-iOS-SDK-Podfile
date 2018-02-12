//
//  TheoremReach.h
//
//  Created by TheoremReach on 11/22/15.
//  Copyright (c) 2017 TheoremReach. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRSurveyViewController.h"
#import "TRUtils.h"

@class TheoremReach;

@protocol TheoremReachSurveyDelegate <NSObject>

-(void)onRewardCenterOpened;

-(void)onRewardCenterClosed;

@end

@protocol TheoremReachRewardDelegate <NSObject>

@required
- (void)onReward: (NSNumber* )quantity;

@end

@protocol TheoremReachSurveyAvailableDelegate <NSObject>

@required
-(void)theoremreachSurveyAvailable: (BOOL) surveyAvailable;

@end

@protocol TheoremReachMomentDelegate <NSObject>

-(void)onMomentSurveyOpened;

-(void)onMomentSurveyClosed;

-(void)onMomentSurveyReceived: (NSNumber*) surveyLength;

-(void)onMomentSurveyCompleted;

-(void)onMomentSurveyNotEligible;

@end
@interface TheoremReach : NSObject

@property NSString *appuserId;
@property NSString *idfa;
@property NSString *carrier;
@property NSString *os_version;
@property NSString *app_device;
@property NSString *connection_type;
@property NSString *userId;
@property NSString *apiKey;
@property NSString *sdkVersion;
@property NSString *momentEntryURL;
@property NSNumber *momentSurveyLength;
@property BOOL momentsEnabled;
@property BOOL rewardCenterOpen;
@property BOOL momentSurveyOpen;
@property BOOL isSurveyAvailable;
@property BOOL momentSurveyAvailable;
@property BOOL isProfiled;
@property BOOL debug;
@property BOOL resetProfiler;

@property (weak, nonatomic) id<TheoremReachRewardDelegate> rewardListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyDelegate> surveyListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyAvailableDelegate> surveyAvailableDelegate;
@property (weak, nonatomic) id<TheoremReachMomentDelegate> momentDelegate;

// gets the only instance of TheoremReach
+ (TheoremReach*)getInstance;

// initialize call with the API key of your app from the theoremreach.com dashboard and your user's unique ID that will be passed back to you via the server side reward notification
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey userId: (NSString *) userId;
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey;

// set the delegate that you want to receive the client side reward callback if you aren't doing server side reward notifications
+ (void) setRewardDelegate: (id) delegate;

// receive notifications when the reward center opens/closes
+ (void) setSurveyDelegate: (id) delegate;
//
// receive notifications for single survey mode
+ (void) setTheoremReachMomentDelegate:(id)delegate;

// opens available single survey
+ (void)showMomentSurvey;

+ (void) checkForMomentSurvey;

// checks if a survey is available with a max length
- (BOOL)isSurveyAvailable: (NSNumber*)maxLength;

// launches the reward center where the user can complete surveys for in app rewards
+ (void)showRewardCenter;

// returns true if a survey is available for a user in their current country
-(int) unityIsSurveyAvailable;

-(int) unityIsSurveyAvailable: (NSNumber*) maxLength;

// returns true if a user hasn't completed their profile yet. When a user is profiled you can retrieve their demographic information via API. For details and access reach out to admin@theoremreach.com
-(int) unityIsAppuserProfiled;

- (void)enableDebugMode: (BOOL) debug;
- (BOOL)isDebug;

- (void)resetProfiler: (BOOL) reset;

- (void)closeRewardCenter;

- (void)enableMoments: (BOOL) enabled;

@end

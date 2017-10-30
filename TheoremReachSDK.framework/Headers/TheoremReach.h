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
@property BOOL rewardCenterOpen;
@property BOOL isSurveyAvailable;
@property BOOL isProfiled;
@property BOOL debug;
@property(nonatomic, setter = setClearCookies: ) BOOL clearCookies;

@property (weak, nonatomic) id<TheoremReachRewardDelegate> rewardListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyDelegate> surveyListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyAvailableDelegate> surveyAvailableDelegate;

// gets the only instance of TheoremReach
+ (TheoremReach*)getInstance;

// initialize call with the API key of your app from the theoremreach.com dashboard and your user's unique ID that will be passed back to you via the server side reward notification
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey userId: (NSString *) userId;
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey;

// set the delegate that you want to receive the client side reward callback if you aren't doing server side reward notifications
+ (void) setRewardDelegate: (id) delegate;

// receive notifications when the reward center opens/closes
+ (void) setSurveyDelegate: (id) delegate;

// launches the reward center where the user can complete surveys for in app rewards
+ (void)showRewardCenter;

// returns true if a survey is available for a user in their current country
-(int) unityIsSurveyAvailable;

// returns true if a user hasn't completed their profile yet. When a user is profiled you can retrieve their demographic information via API. For details and access reach out to admin@theoremreach.com
-(int) unityIsAppuserProfiled;

- (void)enableDebugMode: (BOOL) debug;
- (BOOL)isDebug;
- (void)closeRewardCenter;



@end

//
//  TheoremReach.h
//
//  Created by TheoremReach on 11/22/15.
//  Copyright (c) 2016 TheoremReach. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRSurveyViewController.h"
#import "TRUtils.h"
#import "TRVSEventSourceDelegate.h"

@class TheoremReach;

@protocol TheoremReachDelegate <NSObject>

-(void)rewardCenterDismissed;

-(void)onRewardCenterClosed;

@required
- (void)userEarnedReward: (NSNumber* )quantity;

@end

@interface TheoremReach : NSObject <TRVSEventSourceDelegate>

@property NSString *appuserId;
@property NSString *idfa;
@property NSString *carrier;
@property NSString *os_version;
@property NSString *app_device;
@property NSString *connection_type;
@property NSString *userId;
@property NSString *apiKey;
@property BOOL surveyAvailable;
@property(nonatomic, setter = setClearCookies: ) BOOL clearCookies;

@property (weak, nonatomic) id<TheoremReachDelegate> delegate;

// gets the only instance of TheoremReach
+ (TheoremReach*)getInstance;

// initialize call with the API key of your app from the theoremreach.com dashboard and your user's unique ID that will be passed back to you via the server side reward notification
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey userId: (NSString *) userId;
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey;

// set the delegate that you want to receive the client side reward callback if you aren't doing server side reward notifications
+ (void) setDelegate: (id) delegate;

// launches the reward center where the user can complete surveys for in app rewards
+ (void)displayRewardCenter;

@end

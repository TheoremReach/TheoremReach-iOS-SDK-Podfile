//
//  TheoremReach.h
//
//  Created by TheoremReach on 11/22/15.
//  Copyright (c) 2018 TheoremReach. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <netinet/in.h>
#import <CommonCrypto/CommonDigest.h>

#import "NSString+MD5String.h"
#import "TRSurveyViewController.h"
#import "TRUtils.h"

@class TheoremReach;

@protocol TheoremReachSurveyDelegate <NSObject>
-(void)onRewardCenterOpened;
-(void)onRewardCenterClosed;
-(void)onRewardCenterViewSet;
-(void)onSessionIdSet;
@end

@protocol TheoremReachRewardDelegate <NSObject>
@required - (void)onReward: (NSNumber* )quantity;
@end

@protocol TheoremReachSurveyAvailableDelegate <NSObject>
@required -(void)theoremreachSurveyAvailable: (BOOL) surveyAvailable;
@end

@protocol TheoremReachGoogleSignInDelegate <NSObject>
-(void)onGoogleSignIn;
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
@property BOOL doNotFetchAppuser;
@property NSString *apiKey;
@property NSString *sdkVersion;
@property NSString *momentEntryURL;
@property NSNumber *momentSurveyLength;
@property NSString *overrideRefreshButtonURL;
@property NSString *overrideCloseButtonURL;
@property BOOL momentsEnabled;
@property BOOL rewardCenterOpen;
@property BOOL momentSurveyOpen;
@property BOOL momentsTitleBarEnabled;
@property BOOL isSurveyAvailable;
@property BOOL momentSurveyAvailable;
@property BOOL isProfiled;
@property BOOL resetProfiler;
@property BOOL landscapeOnly;
@property BOOL hideAppButtons;
@property BOOL _adjoePlaytimeEnabled;
@property NSString *trAppuserId;
@property NSString *trAppuserSessionId;
@property NSString *trBirthday;
@property NSString *trGender;
@property NSString *_adjustNetwork;
@property NSString *_adjustCampaign;
@property NSString *_playtimePlacement;
@property NSString *_playtimeSubPublisherCleartext;
@property NSString *_playtimeSubPublisherEncrypted;
@property NSString *_playtimeSdkHash;
@property NSString *navigationBarColor;
@property NSString *bottomBarColor;
@property NSString *navigationBarText;
@property NSString *navigationBarTextColor;
@property TRSurveyViewController *rewardCenterViewController;

@property (weak, nonatomic) id<TheoremReachRewardDelegate> rewardListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyDelegate> surveyListenerDelegate;
@property (weak, nonatomic) id<TheoremReachSurveyAvailableDelegate> surveyAvailableDelegate;
@property (weak, nonatomic) id<TheoremReachMomentDelegate> momentDelegate;
@property (weak, nonatomic) id<TheoremReachGoogleSignInDelegate> googleSignInDelegate;

// gets the only instance of TheoremReach
+ (TheoremReach*)getInstance;

// initialize call with the API key of your app from the theoremreach.com dashboard and your user's unique ID that will be passed back to you via the server side reward notification
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey userId: (NSString *) userId;
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey userId: (NSString *) userId doNotFetchAppuser: (BOOL) doNotFetchAppuser;
+ (TheoremReach*)initWithApiKey: (NSString *)apiKey;

// set the delegate that you want to receive the client side reward callback if you aren't doing server side reward notifications
+ (void) setRewardDelegate: (id) delegate;

// receive notifications when the reward center opens/closes
+ (void) setSurveyDelegate: (id) delegate;
//
// receive notifications for single survey mode
+ (void) setTheoremReachMomentDelegate:(id)delegate;

+ (void) setGoogleSignInDelegate: (id) delegate;
- (void) googleSignInResult: (NSString *)idToken;
- (void) triggerGoogleSignInDelegate;

// opens available single survey
+ (void)showMomentSurvey;

+ (void) checkForMomentSurvey;

+ (BOOL) getIsSurveyAvailable;

// checks if a survey is available with a max length
//- (BOOL)isSurveyAvailable: (NSNumber*)maxLength;

// launches the reward center where the user can complete surveys for in app rewards
+ (void)showRewardCenter;

// launches the reward center for a particular placement
+ (void)showRewardCenter: (NSString *)placementId;

// returns true if a survey is available for a user in their current country
-(int) unityIsSurveyAvailable;

-(int) unityIsSurveyAvailable: (NSNumber*) maxLength;

// returns true if a user hasn't completed their profile yet. When a user is profiled you can retrieve their demographic information via API. For details and access reach out to admin@theoremreach.com
-(int) unityIsAppuserProfiled;

- (void)resetProfiler: (BOOL) reset;

- (void)closeRewardCenter;

- (void)enableMoments: (BOOL) enabled;

- (void)enableTitleBarInMoments: (BOOL) enabled;

- (void)disableAppButtons: (BOOL) disabled;

- (void)setAdjoePlaytimeEnabled: (BOOL) enabled;
- (BOOL)isAdjoePlaytimeEnabled;

- (void)sendPlaytimeTeaserEvent: (NSString *)appuser_id appuser_session_id: (NSString *)appuser_session_id birthday: (NSString *)birthday gender: (NSString *)gender;

- (void)launchPlaytime: (NSString *)appuser_id appuser_session_id: (NSString *)appuser_session_id birthday: (NSString *)birthday gender: (NSString *)gender;

- (void)setAdid: (NSString *)adid;
- (void)setAttributionInfo: (NSString *)attributionInfo;
- (void)setAdjustNetwork: (NSString *)network;
- (NSString*)getAdjustNetwork;
- (void)setAdjustCampaign: (NSString *)campaign;
- (NSString*)getAdjustCampaign;
- (void)setPlaytimePlacement: (NSString *)placement;
- (NSString*)getPlaytimePlacement;
- (void)setPlaytimeSubPublisherCleartext: (NSString *)cleartext;
- (NSString*)getPlaytimeSubPublisherCleartext;
- (void)setPlaytimeSubPublisherEncrypted: (NSString *)encrypted;
- (NSString*)getPlaytimeSubPublisherEncrypted;
- (void)setPlaytimeSdkHash: (NSString *)sdkHash;
- (NSString*)getPlaytimeSdkHash;

//customize the navigation bar
- (void)setNavigationBarColor: (NSString *)navigationBarColor;
- (void)setNavigationBarText: (NSString *)navigationBarText;
- (void)setNavigationBarTextColor: (NSString *)navigationBarTextColor;

+ (UIColor*)colorWithHexString: (NSString*)hexString;

- (NSString*)getHostName;

@end

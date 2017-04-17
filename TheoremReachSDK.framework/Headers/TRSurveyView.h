//
//  TRSurveyView.h
//
//  Created by TheoremReach on 11/22/15.
//  Copyright (c) 2016 TheoremReach. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TRSurveyView;

@protocol TRSurveyViewDelegate<NSObject>

- (void)TRSurveyView:(TRSurveyView *)trSurveyView donePushed:(id)sender;

@end

@interface TRSurveyView : UIView <UIWebViewDelegate>

@property NSString *baseUrl;

@property (strong, nonatomic) IBOutlet UIView *containerView;
@property (strong, nonatomic) IBOutlet UIToolbar *navBar;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *doneButton;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *rewardsCenterButton;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *flex;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *toolbarTitle;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *backButton;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *forwardButton;
@property (strong, nonatomic) IBOutlet UILabel *toolbarTitleLabel;
@property (strong, nonatomic) IBOutlet UIWebView *iframeView;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (strong, nonatomic) IBOutlet UIView *overlay;

@property (strong, nonatomic) id<TRSurveyViewDelegate> delegate;

- (UIToolbar *)buildNavBarWithY:(float)y width:(float)width height:(float)height;
- (void)setupNavBarButtons;
- (void)resizeRewardsCenterView;

@end

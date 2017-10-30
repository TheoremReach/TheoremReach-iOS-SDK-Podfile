//
//  TRUtils.h
//
//  Created by TheoremReach on 11/22/15.
//  Copyright (c) 2017 TheoremReach. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifdef DEBUG

#define TR_Log( s, ... ) NSLog( @"<%@:%d> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__,  [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#define TR_LogFunction TR_Log(@"%s called", __FUNCTION__)

#else

#define TR_Log( s, ... )
#define TR_LogFunction

#endif

#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

#define IS_PHONE_DEVICE() UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone

@interface TRUtils : NSObject
+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
@end

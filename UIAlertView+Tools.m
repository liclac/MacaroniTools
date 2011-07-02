//
//  UIAlertView+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-15.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIAlertView+Tools.h"

@implementation UIAlertView(Tools)

+ (void)alertWithTitle:(NSString *)title message:(NSString *)message
{
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:message delegate:nil
										  cancelButtonTitle:MT_ALERT_DEFAULT_BUTTON_TITLE otherButtonTitles:nil];
	[alert show];
	[alert release];
}

+ (void)alertWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle
{
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:message delegate:nil
										  cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
	[alert show];
	[alert release];
}

+ (void)alertWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate cancelButtonTitle:(NSString *)cancelButtonTitle
{
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:message delegate:delegate
										  cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
	[alert show];
	[alert release];
}

@end
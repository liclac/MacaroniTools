//
//  UIAlertView+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-15.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MT_ALERT_DEFAULT_BUTTON_TITLE @"OK" ///< Default Button Title for Quick UIAlertViews

/**
 * Extensions for the UIAlertView class.
 * Added Features:
 * <ul>
 * <li>Quick Alerts - show an alert with just one command</li>
 * </ul>
 */
@interface UIAlertView(Tools)

/**
 * Displays an alert without a Delegate containing with the specified information
 * @param title The Title for the alert
 * @param message The Message to display
 */
+ (void)alertWithTitle:(NSString *)title message:(NSString *)message;

/**
 * Displays an alert without a Delegate containing with the specified information
 * @param title The Title for the alert
 * @param message The Message to display
 * @param cancelButtonTitle Text for the Cancel Button (default: OK)
 */
+ (void)alertWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle;

/**
 * Displays an Alert.
 * Due to the complexity of Objective-C's nil-terminated list-management, it is currently impossible to implement the otherButtonTitles: parameter... Once I figure out how, it will be implemented.
 * @param title Title
 * @param message Message
 * @param delegate Delegate (should implement UIAlertViewDelegate) or nil
 * @param cancelButtonTitle Title for the Cancel Button
 */
+ (void)alertWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate cancelButtonTitle:(NSString *)cancelButtonTitle;

@end

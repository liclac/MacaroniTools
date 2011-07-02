//
//  UIViewController+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-04.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the UIViewController class.
 * Added Features:
 * <ul>
 * <li>Initialization with an iPad Suffix</li>
 * <li>Auto-creation of Navigation Controllers</li>
 * </ul>
 */
@interface UIViewController(Tools)

/**
 * Initializes an UIViewController with a Nib and an iPad Suffix.
 * If the current device is an iPhone, the nib is loaded normally, but if it's an iPad, the Suffix is added to the end of the filename.
 * 
 * For example, a Nib of "TestViewController" and a Suffix of "~iPad" would load "TestViewController.xib" on an iPhone, but
 * "TestViewController~iPad.xib" on an iPad.
 */
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil iPadSuffix:(NSString *)ipad;

/**
 * Message sent by an MTNavigationController, override to handle.
 * The view controller will receive this message if either <code>-[popViewControllerAnimated:]</code>, <code>-[popToViewController:animated:]</code> or <code>-[popToRootViewControllerAnimated:]</code> was called on the Navigation Controller or the user pressed the Back Button.
 */
- (void)viewDidPopAnimated:(BOOL)animated;

/**
 * Presents a Modal View Controller, optionally also creating a Navigation Controller for it.
 * This method calls <code>-[self presentModalViewController:animated:]</code> for presentation.
 * The Navigation Controller will copy the view controller's modalPresentationStyle and modalTransitionStyle,
 * so you don't have to specify these explicitly on the NavController.
 * 
 * @returns The Created Navigation Controller or nil if nav is NO
 * @param modalViewController The Modal Controller to present
 * @param animated Werther the presentation should be Animated
 * @param createNC If this is YES, a Navigation Controller will be created with the modal controller as rootViewController
 */
- (MTNavigationController *)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated createNavigationController:(BOOL)createNC;

@end

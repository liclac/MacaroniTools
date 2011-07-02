//
//  MTNavigationController.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-10-01.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "MTNavigationController.h"

@implementation MTNavigationController

- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated
{
	[[self.viewControllers lastObject] viewDidPopAnimated:animated];
	return [super popToRootViewControllerAnimated:animated];
}

- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated
{
	[[self.viewControllers lastObject] viewDidPopAnimated:animated];
	return [super popToViewController:viewController animated:animated];
}

- (UIViewController *)popViewControllerAnimated:(BOOL)animated
{
	[[self.viewControllers lastObject] viewDidPopAnimated:animated];
	return [super popViewControllerAnimated:animated];
}

@end

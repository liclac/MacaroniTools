//
//  UIViewController+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-04.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIViewController+Tools.h"
#import "MTDevice.h"
#import "MTNavigationController.h"

@implementation UIViewController(Tools)

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil iPadSuffix:(NSString *)ipad
{
	if([[MTDevice currentDevice] isPad] && nibNameOrNil != nil)
		nibNameOrNil = [nibNameOrNil stringByAppendingString:ipad];
	
	self = [self initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	
	return self;
}

- (void)viewDidPopAnimated:(BOOL)animated
{
	//Override to handle
}

- (void)viewDidPushAnimated:(BOOL)animated
{
	//Override to handle
}

- (MTNavigationController *)presentModalViewController:(UIViewController *)vc animated:(BOOL)animated createNavigationController:(BOOL)cNC
{
	if(vc == nil) return nil;
	if(!cNC)
	{
		[self presentModalViewController:vc animated:animated];
		return nil;
	}
	
	MTNavigationController *nc = [[MTNavigationController alloc] initWithRootViewController:vc];
	nc.modalInPopover = vc.modalInPopover;
	nc.modalTransitionStyle = vc.modalTransitionStyle;
	nc.modalPresentationStyle = vc.modalPresentationStyle;
	[self presentModalViewController:nc animated:animated];
	
	return [nc autorelease];
}

@end
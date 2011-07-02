//
//  UITableView+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-02-16.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import "UITableView+Tools.h"


@implementation UITableView(Tools)

- (void)deselectAnimated:(BOOL)animated
{
	[self deselectRowAtIndexPath:[self indexPathForSelectedRow] animated:animated];
}

@end
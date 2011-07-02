//
//  UIDevice+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-04.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIDevice+Tools.h"

@implementation UIDevice(Tools)

- (BOOL)isPhone
{
	return ([self userInterfaceIdiom] == UIUserInterfaceIdiomPhone);//([[self model] hasPrefix:@"iPhone"]);
}

- (BOOL)isPad
{
	return ([self userInterfaceIdiom] == UIUserInterfaceIdiomPad);//([[self model] hasPrefix:@"iPad"]);
}

- (BOOL)isOS4
{
	return [self respondsToSelector:@selector(isMultitaskingSupported)];
}

- (BOOL)isHighRes
{
	return ([UIScreen instancesRespondToSelector:@selector(scale)] && [[UIScreen mainScreen] scale] > 1.0);
}

@end
//
//  MTDevice.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-06.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import "MTDevice.h"


@implementation MTDevice

- (BOOL)isPhone
{
	if(!deviceChecked) isPhone = [super isPhone];
	return isPhone;
}

- (BOOL)isPad
{
	if(!deviceChecked) isPad = [super isPad];
	return isPad;
}

- (BOOL)isPod
{
	if(!deviceChecked) isPod = [super isPod];
	return isPod;
}

- (BOOL)isHighRes
{
	if(!resChecked) isHighRes = ([UIScreen instancesRespondToSelector:@selector(scale)] && [[UIScreen mainScreen] scale] > 1.0);
	return isHighRes;
}

@end

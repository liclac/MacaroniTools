//
//  NSDictionary+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-11.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSDictionary+Tools.h"


@implementation NSDictionary(Tools)

- (BOOL)boolForKey:(id)aKey
{
	return [[self objectForKey:aKey] boolValue];
}

- (NSInteger)integerForKey:(id)aKey
{
	return [[self objectForKey:aKey] intValue];
}

- (float)floatForKey:(id)aKey
{
	return [[self objectForKey:aKey] floatValue];
}

@end

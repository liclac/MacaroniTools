//
//  MTSingleton.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-27.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import "MTSingleton.h"

static id singletonInstance = nil;

@implementation MTSingleton

+ (id)sharedInstance
{
    if (singletonInstance == nil)
		singletonInstance = [[super allocWithZone:NULL] init];
	
    return singletonInstance;
}

+ (id)allocWithZone:(NSZone *)zone
{
    return [[self sharedInstance] retain];
}

- (id)copyWithZone:(NSZone *)zone
{
    return self;
}

- (id)retain
{
    return self;
}

- (NSUInteger)retainCount
{
    return NSUIntegerMax;
}

- (void)release
{
	
}

- (id)autorelease
{
    return self;
}

@end

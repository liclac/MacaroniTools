//
//  NSObject+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-10-09.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSObject+Tools.h"


@implementation NSObject(Tools)

- (BOOL)isNotNull
{
	return YES;
}

- (id)performSelectorIfAvailable:(SEL)aSelector
{
	return ([self respondsToSelector:aSelector] ? [self performSelector:aSelector] : nil);
}

- (BOOL)performSelectorIfAvailable:(SEL)aSelector onThread:(NSThread *)thr withObject:(id)arg waitUntilDone:(BOOL)wait
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelector:aSelector onThread:thr withObject:arg waitUntilDone:wait];
		return YES;
	}
	else return NO;
}

- (BOOL)performSelectorIfAvailable:(SEL)aSelector onThread:(NSThread *)thr withObject:(id)arg waitUntilDone:(BOOL)wait modes:(NSArray *)array
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelector:aSelector onThread:thr withObject:arg waitUntilDone:wait modes:array];
		return YES;
	}
	else return NO;
}

- (id)performSelectorIfAvailable:(SEL)aSelector withObject:(id)object
{
	if([self respondsToSelector:aSelector])
	{
		return [self performSelector:aSelector withObject:object];
	}
	else return nil;
}

- (BOOL)performSelectorIfAvailable:(SEL)aSelector withObject:(id)anArgument afterDelay:(NSTimeInterval)delay
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelector:aSelector withObject:anArgument afterDelay:delay];
		return YES;
	}
	else return NO;
}

- (BOOL)performSelectorIfAvailable:(SEL)aSelector withObject:(id)anArgument afterDelay:(NSTimeInterval)delay inModes:(NSArray *)modes
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelector:aSelector withObject:anArgument afterDelay:delay inModes:modes];
		return YES;
	}
	else return NO;
}

- (id)performSelectorIfAvailable:(SEL)aSelector withObject:(id)object1 withObject:(id)object2
{
	if([self respondsToSelector:aSelector])
	{
		return [self performSelector:aSelector withObject:object1 withObject:object2];
	}
	else return nil;
}

- (BOOL)performSelectorInBackgroundIfAvailable:(SEL)aSelector withObject:(id)arg
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelectorInBackground:aSelector withObject:arg];
		return YES;
	}
	else return NO;
}

- (BOOL)performSelectorOnMainThreadIfAvailable:(SEL)aSelector withObject:(id)arg waitUntilDone:(BOOL)wait
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelectorOnMainThread:aSelector withObject:arg waitUntilDone:wait];
		return YES;
	}
	else return NO;
}

- (BOOL)performSelectorOnMainThreadIfAvailable:(SEL)aSelector withObject:(id)arg waitUntilDone:(BOOL)wait modes:(NSArray *)array
{
	if([self respondsToSelector:aSelector])
	{
		[self performSelectorOnMainThread:aSelector withObject:arg waitUntilDone:wait modes:array];
		return YES;
	}
	else return NO;
}


@end

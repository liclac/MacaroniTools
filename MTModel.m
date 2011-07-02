//
//  MTModel.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-27.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import "MTModel.h"


@implementation MTModel
@synthesize objects;


#pragma mark Access
- (BOOL)containsObject:(id)anObject
{
	return [objects containsObject:anObject];
}

- (void)addObject:(id)anObject
{
	
}

- (void)removeObject:(id)anObject
{
	
}


#pragma mark Accessors
- (NSMutableSet *)objects
{
	if(objects == nil)
		objects = [[NSMutableSet alloc] init];
	
	return objects;
}

@end

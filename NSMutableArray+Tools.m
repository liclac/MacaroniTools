//
//  NSMutableArray+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSMutableArray+Tools.h"

@implementation NSMutableArray(Tools)

- (void)moveObjectFromIndex:(NSInteger)from toIndex:(NSInteger)to
{
	if(to == from) return; //It's pointless to move the object to it's own position, right?
	
	id obj = [self objectAtIndex:from]; //Get the object...
	[obj retain]; //...and retain it since we don't want it to disappear on us
	[self removeObjectAtIndex:from]; //Remove the object...
	
	if(to >= [self count]) [self addObject:obj]; //...and if we're adding it to the end, just add it...
	else [self insertObject:obj atIndex:to]; //...or insert it at the specific index if we're not
	
	[obj release]; //Release the object since we don't want a memory leak
}

@end

//
//  NSURL+Extraction.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSURL+Tools.h"

@implementation NSURL(Tools)

//Returns the URL Query as a Dictionary
- (NSDictionary *)queryAsDictionary
{
	NSArray *split = [[self query] componentsSeparatedByString:@"&"]; //Split the attributes by "&" to separate them
	NSMutableArray *keys = [NSMutableArray array]; //Initially empty array of Keys
	NSMutableArray *values = [NSMutableArray array]; //Corresponding Values
	
	for(NSString *tmp in split) //Loop using an NSString
	{
		NSArray *ta = [tmp componentsSeparatedByString:@"="]; //Separate the current part by "=" to get the value
		
		[keys addObject:[ta objectAtIndex:0]]; //Add the Key
		[values addObject:([ta count] != 1 ? [ta objectAtIndex:1] : @"")]; //Add the Value or an empty string
	}
	
	return [NSDictionary dictionaryWithObjects:values forKeys:keys]; //Return an NSDictionary with the values and keys
}

@end

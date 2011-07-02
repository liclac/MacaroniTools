//
//  MTError.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "MTError.h"

@implementation MTError

+ (void)errorWithName:(NSString *)name message:(NSString *)message
{
	NSLog(@"%@: %@", name, message);
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:name message:message delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
	[alert show];
	[alert release];
}

@end

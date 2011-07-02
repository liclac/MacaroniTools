//
//  MTError.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

///Allows you to quickly throw errors
@interface MTError : NSObject
{
	
}

///Throws an error with the specified name and message
+ (void)errorWithName:(NSString *)name message:(NSString *)message;

@end

//
//  MTSingleton.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-27.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An abstract class for creating Singleton objects.
 * This class handles the basic behavior expected of a singleton object,
 * including rejection of Reference Counting.
 * 
 * Subclass this class instead of NSObject to easily make your object a Singleton.
 */
@interface MTSingleton : NSObject
{
	
}

/**
 * Returns the Shared Instance of the class.
 * If there is no instance of the class, it is created and the new instance is returned.
 * @returns the Global Shared Instace
 */
+ (id)sharedInstance;

@end

//
//  NSDictionary+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-11.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the NSDictionary class.
 * Added Features:
 * <ul>
 * <li>Quick Primitive Type-access - get BOOLs, NSIntegers or floats directly</li>
 * </ul>
 */
@interface NSDictionary(Tools)

/**
 * Turns an object into a BOOL.
 * @param aKey The Desired Object's Key
 */
- (BOOL)boolForKey:(id)aKey;

/**
 * Turns an object into an NSInteger.
 * @param aKey The Desired Object's Key
 */
- (NSInteger)integerForKey:(id)aKey;

/**
 * Turns an object into a float.
 * @param aKey The Desired Object's Key
 */
- (float)floatForKey:(id)aKey;

@end

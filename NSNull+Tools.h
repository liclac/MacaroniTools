//
//  NSNull+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-11-01.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extension for the NSNull class.
 * Causes NSNull objects to respond NO to <code>-[isNotNull]</code> instead of crashing.
 */
@interface NSNull(Tools)

///Returns NO if the object is NSNull or nil (from NSObject+Tools.h)
- (BOOL)isNotNull;

@end

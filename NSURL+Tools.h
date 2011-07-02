//
//  NSURL+Extraction.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the NSURL class
 * Added Features:
 * <ul>
 * <li>Query to Dictionary</li>
 * </ul>
 */
@interface NSURL(Tools)

/**
 * Returns the Query part of the URL as an NSDictionary object
 * @return An NSDictionary containing the query components
 */
- (NSDictionary *)queryAsDictionary;

@end

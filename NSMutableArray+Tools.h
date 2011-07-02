//
//  NSMutableArray+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the NSMutableArray class.
 * Added Features:
 * <ul>
 * <li>Move Objects</li>
 * </ul>
 */
@interface NSMutableArray(Tools)

/**
 * Moves an object.
 * @param from Index to move from
 * @param to Index to move to
 * @throws NSRangeException
 */
- (void)moveObjectFromIndex:(NSInteger)from toIndex:(NSInteger)to;

@end

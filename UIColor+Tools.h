//
//  UIColor+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-12-22.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Extensions for the UIColor class.
 * Added Features:
 * <ul>
 * <li>Parsing of Hex(RRGGBB)-strings</li>
 * </ul>
 */
@interface UIColor(Tools)

/**
 * Returns a color from the given string.
 * The string must contain a color in either "#RRGGBB" or "RRGGBB" format.
 * Note that the short hand form "#RGB" or "RGB" will not work.
 * @param str The given Hex String
 * @param alpha The Alpha (Opacity) of the resulting color
 * @returns A Color from the given string or nil if it's not a valid string
 */
+ (UIColor *)colorWithHexString:(NSString *)str alpha:(float)alpha;

@end
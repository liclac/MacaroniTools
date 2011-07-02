//
//  UIDevice+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-09-04.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the UIDevice class
 * Added Features:
 * <ul>
 * <li>Quickly determine if the current device is an iPhone, an iPod Touch or an iPad</li>
 * </ul>
 */
@interface UIDevice(Tools)

/// Checks werther the current device is an iPhone
- (BOOL)isPhone;
/// Checks werther the current device is an iPod Touch
- (BOOL)isPod;
/// Checks werther the current device is an iPad
- (BOOL)isPad;
/// Checks werther the current device is running on iOS4
- (BOOL)isOS4;
/// Checks werther the current device is using a High-Res Screen
- (BOOL)isHighRes;


@end

//
//  MTDevice.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-06.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UIDevice+Tools.h"

/**
 * Subclass of UIDevice that provides better performance for the MacaroniTools additions.
 * Aside from caching calls to -[isPhone], -[isPad] and -[isPod], this class is identical to UIDevice.
 * If possible, you should always use MTDevice for testing device model.
 */
@interface MTDevice : UIDevice
{
	BOOL deviceChecked; ///<\private YES if the device has been checked (eg. if -[isPhone], -[isPad] or -[isPod] has been called before)
	BOOL isPhone; ///<Is the current device an iPhone?
	BOOL isPad; ///<Is the current device an iPad?
	
	BOOL resChecked; ///<\private YES if the resolution has been checked (eg. if -[isHighRes] has been called)
	BOOL isHighRes; ///< Is the current device equipped with a Retina (Hi-Res) Display?
}

@property (nonatomic, readonly) BOOL isPhone, isPad, isHighRes;

@end
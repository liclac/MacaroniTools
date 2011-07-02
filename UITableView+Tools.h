//
//  UITableView+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-02-16.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Extensions for the UITableView class.
 * Features Added:
 * <ul>
 * <li>Deselect without knowing the selected Index Path</li>
 * </ul>
 */
@interface UITableView(Tools)

/**
 * Deselects the current selection.
 * @param animated Werther the change should be animated
 */
- (void)deselectAnimated:(BOOL)animated;

@end
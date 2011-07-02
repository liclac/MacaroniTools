//
//  UIImageView+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-18.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the UIImageView class.
 * Features Added:
 * <ul>
 * <li>Load Images directly from a filename</li>
 * </ul>
 */
@interface UIImageView(Tools)

/**
 * Loads an image directly from a filename.
 * Essentially a shortcut to calling [&lt;ImageView&gt; setImage:[UIImage imageNamed:]]
 */
- (void)setImageNamed:(NSString *)name;

@end

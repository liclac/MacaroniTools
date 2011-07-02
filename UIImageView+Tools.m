//
//  UIImageView+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-18.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIImageView+Tools.h"

@implementation UIImageView(Tools)

- (void)setImageNamed:(NSString *)name
{
	[self setImage:[UIImage imageNamed:name]];
}

@end
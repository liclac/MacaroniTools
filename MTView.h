//
//  MTView.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-04-21.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface MTView : NSView
{
    NSColor *backgroundColor;
	BOOL flipped;
}

@property (nonatomic, retain) NSColor *backgroundColor;
@property (nonatomic, assign, getter=isFlipped) BOOL flipped;

@end
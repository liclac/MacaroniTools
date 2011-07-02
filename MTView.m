//
//  MTView.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-04-21.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import "MTView.h"


@implementation MTView
@synthesize backgroundColor, flipped;

- (id)initWithFrame:(NSRect)frame
{
    if ((self = [super initWithFrame:frame]))
	{
		flipped = YES; //Default to flipped coordinate system (the one that makes sense, á la iOS)
    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (void)drawRect:(NSRect)dirtyRect
{
	if(self.backgroundColor != nil)
	{
		[self.backgroundColor setFill];
		NSRectFill(dirtyRect);
	}
}

@end
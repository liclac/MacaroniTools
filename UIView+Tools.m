//
//  UIView+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-17.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIView+Tools.h"


@implementation UIView(Tools)

//Fade Out
- (void)fadeOut
{
	[self fadeOutWithDuration:MT_ANIMATIONS_DEFAULT_DURATION andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)fadeOutWithWait:(NSTimeInterval)wait
{
	[self fadeOutWithDuration:MT_ANIMATIONS_DEFAULT_DURATION andWait:wait];
}

- (void)fadeOutWithDuration:(NSTimeInterval)duration
{
	[self fadeOutWithDuration:duration andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)fadeOutWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait
{
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FADE_OUT context:nil]; //Start and animation called "MT:FadeOut"
	[UIView setAnimationDuration:duration]; //Set the Animation Duration
	[UIView setAnimationDelay:wait]; //Set the Animation Delay
	self.alpha = 0.0; //Make the view invisible
	[UIView commitAnimations]; //Animate it
}

//Fade In
- (void)fadeIn
{
	[self fadeInWithDuration:MT_ANIMATIONS_DEFAULT_DURATION	andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)fadeInWithWait:(NSTimeInterval)wait
{
	[self fadeInWithDuration:MT_ANIMATIONS_DEFAULT_DURATION andWait:wait];
}

- (void)fadeInWithDuration:(NSTimeInterval)duration
{
	[self fadeInWithDuration:duration andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)fadeInWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait
{
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FADE_IN context:nil]; //Start and animation called "MT:FadeIn"
	[UIView setAnimationDuration:duration]; //Set the Animation Duration
	[UIView setAnimationDelay:wait]; //Set the Animation Delay
	self.alpha = 1.0; //Make the view visible
	[UIView commitAnimations]; //Animate it
}

//Flash
- (void)flash
{
	[self flashWithDuration:MT_ANIMATIONS_DEFAULT_DURATION andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)flashWithWait:(NSTimeInterval)wait
{
	[self flashWithDuration:MT_ANIMATIONS_DEFAULT_DURATION andWait:wait];
}

- (void)flashWithDuration:(NSTimeInterval)duration
{
	[self flashWithDuration:duration andWait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)flashWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait
{
	float a = self.alpha; //Store a copy of the current alpha (for resetting)
	float t = (a < 0.5 ? 1.0 : 0.0); //Check werther to flash in or out, and store the Target Alpha
	
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FLASH_IN context:nil];
	[UIView setAnimationDuration:duration];
	[UIView setAnimationDelay:wait];
	self.alpha = t; //Fade to the Target Alpha
	[UIView commitAnimations];
	
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FLASH_OUT context:nil];
	[UIView setAnimationDuration:duration];
	[UIView setAnimationDelay:wait];
	self.alpha = a; //Fade back to the old alpha value
	[UIView commitAnimations];
}

//Flash with Color
- (void)flashWithColor:(UIColor *)color
{
	[self flashWithColor:color duration:MT_ANIMATIONS_DEFAULT_DURATION wait:MT_ANIMATIONS_DEFAULT_DELAY];
}

- (void)flashWithColor:(UIColor *)color andWait:(NSTimeInterval)wait
{
	[self flashWithColor:color duration:MT_ANIMATIONS_DEFAULT_DURATION wait:wait];
}

- (void)flashWithColor:(UIColor *)color andDuration:(NSTimeInterval)duration
{
	[self flashWithColor:color duration:duration wait:MT_ANIMATIONS_DEFAULT_DURATION];
}

- (void)flashWithColor:(UIColor *)color duration:(NSTimeInterval)duration wait:(NSTimeInterval)wait
{
	UIColor *oldColor = [UIColor colorWithCGColor:[self.backgroundColor CGColor]]; //Copy of self's Background Color
	float a = self.alpha; //Old Alpha
	
	//In Phase
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FLASH_COLOR_IN context:nil];
	[UIView setAnimationDuration:duration];
	[UIView setAnimationDelay:wait];
	self.alpha = 1.0;
	self.backgroundColor = color; //Set the Background Color to the new value
	[UIView commitAnimations];
	
	//Out Phase
	[UIView beginAnimations:MT_ANIMATIONS_NAME_FLASH_COLOR_OUT context:nil];
	[UIView setAnimationDuration:duration];
	[UIView setAnimationDelay:wait];
	self.backgroundColor = oldColor; //Reset the Background
	self.alpha = a; //Reset the Alpha
	[UIView commitAnimations];
}

//Background Image
- (void)setBackgroundImage:(UIImage *)image
{
	[self setBackgroundColor:[UIColor colorWithPatternImage:image]];
}

- (void)setBackgroundImageNamed:(NSString *)filename
{
	[self setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:filename]]];
}


//Show/Hide
- (void)show
{
	[self setHidden:NO];
}

- (void)hide
{
	[self setHidden:YES];
}

@end
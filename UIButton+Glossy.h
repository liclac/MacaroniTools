/*
 * Not written by me, all credits goes to Michael Heyeck (http://www.mlsite.net/blog/?page_id=372).
 * Big thanks to him for this code!
 */

#import <UIKit/UIKit.h>

/**
 * Enables drawing of glossy backgrounds on UIButtons
 * This is not written by me, all credits goes to <a href="http://www.mlsite.net/blog/?page_id=372">Michael Heyeck</a>
 */
@interface UIButton(Glossy)

/**
 * Set Path to Rounded Rect.
 * This is called by the setBackgroundToGlossyRectOfColor:withBorder:forState function and you don't have to call it directly
 * @param rect A CGRect containing a rounded rectangle
 * @param inset Insets
 * @param context The CGContextRef object to use
 */
+ (void)setPathToRoundedRect:(CGRect)rect forInset:(NSUInteger)inset inContext:(CGContextRef)context;

/**
 * Draw a Glossy Rectangle.
 * This is called by the setBackgroundToGlossyRectOfColor:withBorder:forState function and you don't have to call it directly
 * @param rect A CGRect to draw in
 * @param color The color of the resulting glossy rectangle
 * @param context The CGContextRef object to use
 */
+ (void)drawGlossyRect:(CGRect)rect withColor:(UIColor*)color inContext:(CGContextRef)context;

/**
 * Set the Button's background to a glossy hue.
 * This is essentially the only function you have to call yourself.
 * @param color The color in which the hue will be
 * @param border Werther to draw a UIActionSheet-style border around the button
 * @param state The state to affect (Generally UIControlStateNormal)
 */
- (void)setBackgroundToGlossyRectOfColor:(UIColor*)color withBorder:(BOOL)border forState:(UIControlState)state;

@end


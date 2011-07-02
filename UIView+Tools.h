//
//  UIView+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-17.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MacaroniTypes.h"

#define MT_ANIMATIONS_DEFAULT_DURATION 0.25 ///< Default Duration for all animations
#define MT_ANIMATIONS_DEFAULT_DELAY 0.0 ///< Default Delay for all animations
#define MT_ANIMATIONS_NAME_FADE_IN @"MT:FadeIn" ///< Name for Fade In animaton
#define MT_ANIMATIONS_NAME_FADE_OUT @"MT:FadeOut" ///< Name for Fade Out animaton
#define MT_ANIMATIONS_NAME_FLASH_IN @"MT:FlashIn" ///< Name for Flash animaton's In phase
#define MT_ANIMATIONS_NAME_FLASH_OUT @"MT:FlashOut" ///< Name for Flash animaton's Out phase
#define MT_ANIMATIONS_NAME_FLASH_COLOR_IN @"MT:FlashColorIn" ///< Name for Color Flash animaton's In phase
#define MT_ANIMATIONS_NAME_FLASH_COLOR_OUT @"MT:FlashColorOut" ///< Name for Color Flash animaton's Out phase

/**
 * Extensions for the UIView class.
 * Added Features:
 * <ul>
 * <li>Quick CoreAnimation Effects</li>
 * </ul>
 */
@interface UIView(Tools)

/**
 * Fade out and disappear.
 * This will cause the view to fade out with a duration of 0.25 and no delay.
 */
- (void)fadeOut;
/**
 * Fade out and disappear after a specified delay.
 * This will cause the view to fade out with a duration of 0.25 and a specified delay.
 * @param wait Animation Delay
 */
- (void)fadeOutWithWait:(NSTimeInterval)wait;
/**
 * Fade out and disappear with a specified duration.
 * This will cause the view to fade out with a specified duration and no delay.
 * @param duration Animation Duration
 */
- (void)fadeOutWithDuration:(NSTimeInterval)duration;
/**
 * Fade out and disappear with a specified duration and delay.
 * @param duration Animation Duration
 * @param wait Animation Delay
 */
- (void)fadeOutWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait;



/**
 * Fade in and appear.
 * This will cause the view to appear with a duration of 0.25 and no delay.
 */
- (void)fadeIn;
/**
 * Fade in and appear after a specified delay.
 * This will cause the view to appear with a duration of 0.25 and a specified delay.
 * @param wait Animation Delay
 */
- (void)fadeInWithWait:(NSTimeInterval)wait;
/**
 * Fade in and appear with a specified duration.
 * This will cause the view to appear with a specified duration and no delay.
 * @param duration Animation Duration
 */
- (void)fadeInWithDuration:(NSTimeInterval)duration;
/**
 * Fade in and appear with a specified duration and delay.
 * @param duration Animation Duration
 * @param wait Animation Delay
 */
- (void)fadeInWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait;



/**
 * Flash briefly.
 * This will cause the view to flash with a duration of 0.25 and no delay.
 */
- (void)flash;
/**
 * Flash and appear after a specified delay.
 * This will cause the view to flash with a duration of 0.25 and a specified delay.
 * @param wait Animation Delay
 */
- (void)flashWithWait:(NSTimeInterval)wait;
/**
 * Flash with a specified duration.
 * This will cause the view to flash with a specified duration and no delay.
 * @param duration Animation Duration
 */
- (void)flashWithDuration:(NSTimeInterval)duration;
/**
 * Flash with a specified duration and delay.
 * @param duration Animation Duration
 * @param wait Animation Delay
 */
- (void)flashWithDuration:(NSTimeInterval)duration andWait:(NSTimeInterval)wait;


/**
 * Flash with a specified color.
 * This will cause the view to flash with a duration of 0.25 and no delay.
 * @param color Color to Flash With
 */
- (void)flashWithColor:(UIColor *)color;
/**
 * Flash with a specified color after a specified delay.
 * This will cause the view to flash with a duration of 0.25 and a specified delay.
 * @param color Color to Flash With
 * @param wait Animation Delay
 */
- (void)flashWithColor:(UIColor *)color andWait:(NSTimeInterval)wait;
/**
 * Flash with a specified color and duration.
 * This will cause the view to flash with a specified duration and no delay.
 * @param color Color to Flash With
 * @param duration Animation Duration
 */
- (void)flashWithColor:(UIColor *)color andDuration:(NSTimeInterval)duration;
/**
 * Flash with a specified color, duration and delay.
 * @param color Color to Flash With
 * @param duration Animation Duration
 * @param wait Animation Delay
 */
- (void)flashWithColor:(UIColor *)color duration:(NSTimeInterval)duration wait:(NSTimeInterval)wait;


/**
 * Sets the view's Background to a specified image.
 * @param image Image to use for Background
 */
- (void)setBackgroundImage:(UIImage *)image;

/**
 * Sets the view's Background to an image with the specified name.
 * @param filename Filename to load
 */
- (void)setBackgroundImageNamed:(NSString *)filename;


/**
 * Shows the View (useful with -[performSeletor:])
 */
- (void)show;

/**
 * Hides the View (useful with -[performSeletor:])
 */
- (void)hide;


/**
 * Performs a Zoom In-transition.
 */
- (void)zoomInWithDuration:(NSTimeInterval)duration targetScale:(CGFloat)scale fade:(BOOL)fade;

@end

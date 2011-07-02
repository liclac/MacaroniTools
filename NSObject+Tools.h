//
//  NSObject+Tools.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-10-09.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the NSObject class.
 * Added Features:
 * <ul>
 * <li>Perform Selectors only if they exist</li>
 * </ul>
 */
@interface NSObject(Tools)

///Returns NO if the object is NSNull or nil
- (BOOL)isNotNull;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (id)performSelectorIfAvailable:(SEL)aSelector;

///Performs a Selector if the object responds to it. Returns werther the selector was executed.
- (BOOL)performSelectorIfAvailable:(SEL)aSelector onThread:(NSThread *)thr withObject:(id)arg waitUntilDone:(BOOL)wait;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorIfAvailable:(SEL)aSelector onThread:(NSThread *)thr withObject:(id)arg waitUntilDone:(BOOL)wait modes:(NSArray *)array;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (id)performSelectorIfAvailable:(SEL)aSelector withObject:(id)object;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorIfAvailable:(SEL)aSelector withObject:(id)anArgument afterDelay:(NSTimeInterval)delay;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorIfAvailable:(SEL)aSelector withObject:(id)anArgument afterDelay:(NSTimeInterval)delay inModes:(NSArray *)modes;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (id)performSelectorIfAvailable:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorInBackgroundIfAvailable:(SEL)aSelector withObject:(id)arg;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorOnMainThreadIfAvailable:(SEL)aSelector withObject:(id)arg waitUntilDone:(BOOL)wait;

///Performs a Selector if the object responds to it. Returns the result or nil.
- (BOOL)performSelectorOnMainThreadIfAvailable:(SEL)aSelector withObject:(id)arg waitUntilDone:(BOOL)wait modes:(NSArray *)array;

@end

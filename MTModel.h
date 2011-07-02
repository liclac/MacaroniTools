//
//  MTModel.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2011-01-27.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An abstract class for Collection-type Model objects.
 * The base class only features the *objects* set typical for all MTModel classes.
 * 
 * There are two provided subclasses of this class: MTDictionaryModel and MTArrayModel.
 * These classes provides support for collection models based on a Dictionary and an Array respectively.
 * 
 * Subclass this class to use your own storage model. Your custom subclass will need to provide
 * custom implementations of <code>-[addObject]</code> and <code>-[removeObject:]</code>.
 */
@interface MTModel : NSObject
{
	/**
	 * The set of all objects included in the collection.
	 * If you subclass MTModel, you must make sure to either keep all your managed objects in this set,
	 * or override <code>-[containsObject]</code>, <code>-[addObject:]</code> and <code>-[removeObject]</code> to
	 * use your own collection.
	 * 
	 * This object is automatically instantiated by it's accessor, meaning if you try to access it without using the
	 * self keyword you may get nil back. It is NOT instantiated in init for overridability purposes.
	 */
	NSMutableSet *objects;
}

@property (nonatomic, retain) NSMutableSet *objects;

/**
 * Returns YES if the collection contains the specified object.
 * @param anObject The object to be checked
 */
- (BOOL)containsObject:(id)anObject;

/**
 * Adds the object to the collection.
 * @param anObject The object to be added
 */
- (void)addObject:(id)anObject;

/**
 * Removes the object from the collection.
 * @param anObject The object to be removed
 */
- (void)removeObject:(id)anObject;

@end

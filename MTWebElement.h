//
//  MTWebElement.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Defines a single element on a website.
 * An MTWebElement object can be created with the "getElement(s)By..." functions added to UIWebView.
 * Although you can instantiate MTWebElement-objects yourself, there is not much point in doing so, since MTWebElement is a
 * datatype meant for data transfer not actual use.
 */
@interface MTWebElement : NSObject
{
	NSString *innerHTML; ///< The "innerHTML" property of the represented object
	NSString *outerHTML; ///< The "outerHTML" property of the represented object
	NSString *textContent; ///< The "textContent" property of the represented object
	NSDictionary *attributes; ///< A Dictionary of all the attributes of the selected object
}

@property (nonatomic, retain) NSString *innerHTML;
@property (nonatomic, retain) NSString *outerHTML;
@property (nonatomic, retain) NSString *textContent;
@property (nonatomic, retain) NSDictionary *attributes;

/**
 * Initializes an MTWebElement object with the specified content.
 * @param ihtml The innerHTML attribute of the element
 * @param ohtml The outerHTML attribute of the element
 * @param tcontent The textContent attribute of the element
 * @param attribs The Attributes associated with the Element
 * @return an MTWebElement object
 */
- (id)initWithInnerHTML:(NSString *)ihtml outerHTML:(NSString *)ohtml textContent:(NSString *)tcontent attributes:(NSDictionary *)attribs;

/**
 * Initializes an empty MTWebElement object.
 * @return an empty MTWebElement object
 */
- (id)init;

/**
 * Creates an autoreleased MTWebElement object with the specified content.
 * Use this if you only need to use the element briefly or just want to throw it somewhere else.
 * @param ihtml The innerHTML attribute of the element
 * @param ohtml The outerHTML attribute of the element
 * @param tcontent The textContent attribute of the element
 * @param attribs The Attributes associated with the Element
 * @return an MTWebElement object
 */
+ (id)elementWithInnerHTML:(NSString *)ihtml outerHTML:(NSString *)ohtml textContent:(NSString *)tcontent attributes:(NSDictionary *)attribs;

/**
 * Creates an empty autoreleased MTWebElement object.
 * @return an empty autoreleased MTWebElement object
 */
+ (id)element;

/**
 * Returns the value of a specific attribute.
 * It is essentially a shortcut to calling [&lt;element&gt;.attributes valueForKey:key]
 * @return an NSString containing the attribute value or nil
 */
- (NSString *)attribute:(NSString *)key;

/**
 * Sets the specified attribute.
 */
- (void)setAttribute:(NSString *)key to:(NSString *)value;

@end

//
//  UIWebView+OpenAdress.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
@class MTWebElement;

/**
 * Extensions for the UIWebView class
 * Added Features:
 * <ul>
 * <li>Quick Loading of NSStrings or Local Files</li>
 * <li>Getting Page Information</li>
 * <li>Getting Page Elements as MTWebElement Objects</li>
 * <li>Parsing HTML Tags into Attribute Dictionaries</li>
 * </ul>
 */
@interface UIWebView(Tools)

/**
 * Load a Web Adress from an NSString.
 * @param adress The Web Adress to load
 */
- (void)loadAdress:(NSString *)adress;
/**
 * Load a Local File from an NSString.
 * Does nothing if the file does not exist.
 * @param path The absolute path for the file
 */
- (void)loadFile:(NSString *)path;
/**
 * Load a Local File from the Application Bundle
 * @param name The Filename without extension
 * @param ext The File Extension
 * @param bundle The Bundle in which to search (pass [NSBundle mainBundle])
 */
- (void)loadFile:(NSString *)name ofType:(NSString *)ext inBundle:(NSBundle *)bundle;

/**
 * Get the Current Page's Title
 * @return The Current Page's Title
 */
- (NSString *)pageTitle;
/**
 * Get the Current Page's Source
 * @return The Current Page's Source
 */
- (NSString *)pageSource;

/**
 * Get an Element from the current page by it's ID
 * @return An MTWebElement Object
 */
- (MTWebElement *)getElementById:(NSString *)eid;
/**
 * Get all elements from the current page with the specified class name
 * @return An NSArray of MTWebElement Objects
 */
- (NSArray *)getElementsByClassName:(NSString *)className;
/**
 * Get all elements from the current page with the specified tag name
 * @return An NSArray of MTWebElement Objects
 */
- (NSArray *)getElementsByTagName:(NSString *)tagName;

/**
 * Returns an NSDictionary with the attributes extracted from an OuterHTML-string
 * @return An NSDictionary
 */
- (NSDictionary *)dictionaryByParsingAttributesFromOuterHTML:(NSString *)html;

@end

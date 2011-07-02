//
//  NSBundle+UserData.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Extensions for the NSBundle class.
 * Added Features:
 * <ul>
 * <li>Easier management of User Data</li>
 * </ul>
 */
@interface NSBundle(Tools)

/**
 * Fetch an User Data file.
 * If the specified file does not exist, it first attempts to copy an identically named file from the Application Bundle, and, failing that,
 * attempts to create an empty new file in the specified location.
 * Returns the path to the resulting file.
 * @param name Filename without extension
 * @param ext File Extension
 * @return The path to the User Data-version of the specified document
 */
- (NSString *)pathForDocument:(NSString *)name ofType:(NSString *)ext;

/**
 * Same as above, but if the "allowCreate" parameter is NO, it will instead return nil if the file can not be copied.
 * The only logical reason why you would ever want to do this is if you want to create the new file manually or something like that.
 * @param name Filename without extension
 * @param ext File Extension
 * @param create Werther to create an empty file if the file could not be fetched from the bundle
 * @return The path to the User Data-version of the specified document or nil
 */
- (NSString *)pathForDocument:(NSString *)name ofType:(NSString *)ext allowCreate:(BOOL)create;

/**
 * Checks the existence of a file in the Documents folder.
 * @param name Filename
 * @return Werther the file exists or not
 */
- (BOOL)documentExists:(NSString *)name;

/**
 * Checks the existence of a Bundle Resource.
 * @param name Filename
 * @return Werther the file exists or not
 */
- (BOOL)resourceExists:(NSString *)name;

/**
 * Checks the existence of a file in the bundle regardless of if it's a Resource or a Document.
 * @param name Filename
 * @return Werther a Resource, a Document or Both with this name exists
 */
- (BOOL)documentOrResourceExists:(NSString *)name;

/**
 * Returns the location of your Documents Folder.
 * @return an absolute path to the current &lt;Application&gt;/Documents/ directory
 */
- (NSString *)documentsPath;

@end

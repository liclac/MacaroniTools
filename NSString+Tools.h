//
//  NSString+URL.h
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MT_URL_ENCODING NSUTF8StringEncoding ///< Encoding for URLs

/**
 * Extensions for the NSString class
 * Added Features:
 * <ul>
 * <li>NSData Casting</li>
 * <li>URL Conversion</li>
 * <li>Hash Generation</li>
 * </ul>
 */
@interface NSString(Tools)

/**
 * Returns itself. Fixes a frequent bug where you call -[stringValue] on an object and the application crashes if you do so on an NSString.
 * @returns itself
 */
- (NSString *)stringValue;

/**
 * Creates an NSString with the specified data.
 * Assumes that the encoding is UTF8.
 * @param data Data to Convert
 * @return An NSString from the supplied data
 */
+ (NSString *)stringWithData:(NSData *)data;

/**
 * Creates an NSString with the specified data and encoding.
 * @param data Data to convert
 * @param encoding Character Encoding (typically NSUTF8StringEncoding)
 * @return An NSString from the supplied data
 */
+ (NSString *)stringWithData:(NSData *)data encoding:(NSStringEncoding)encoding;

/**
 * Gets the string as an URL.
 * @return The string as an NSURL
 */
- (NSURL *)URLValue;

/**
 * Gets the string as a Local URL.
 * Useful if used in combination with NSBundle's <code>pathForResource:ofType</code> and <code>pathForDocument:ofType:</code> functions.
 * @return a Local URL to the file whose path the string contains
 */
- (NSURL *)fileURLValue;

/**
 * Returns an URL-Safe version of the string.
 * Adds Percent Escapes using NSUTF8StringEncoding.
 * @return The string with Percent Escapes added
 */
- (NSString *)URLString;

/**
 * Returns the MD5-hash of the string
 * @return An MD5-hash
 */
- (NSString *)md5;

/**
 * Returns a Capitalized String but without words like "and", "the", "of", etc. capitalized.
 * By default it works with English words, but you can specify a custom set of words if you'd like
 * (see -[smartCapitalizeWithArray:] and -[smartCapitalizeWithAdditionalWordsFromArray:])
 * @return A Capitalized String
 */
- (NSString *)smartCapitalize;

/**
 * Returns a Capitalized String where the words specified in the array are not capitalized.
 * @param array An Array of words not to be capitalized
 * @return A Capitalized String
 */
- (NSString *)smartCapitalizeWithArray:(NSArray *)array;

/**
 * Returns a Capitalized String where the words specified in the array and the default words are not capitalized.
 * Useful for capitalizing strings containing foreign words.
 * @param array An Array of additional words not to be capitalized
 * @return A Capitalized String
 */
- (NSString *)smartCapitalizeWithAdditionalWordsFromArray:(NSArray *)array;
 
@end

//
//  NSString+URL.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSString+Tools.h"
#import <CommonCrypto/CommonDigest.h>

///Extensions for the NSString class
@implementation NSString(Tools)

- (NSString *)stringValue
{
	return self;
}

+ (NSString *)stringWithData:(NSData *)data
{
	return [NSString stringWithData:data encoding:NSUTF8StringEncoding];
}

//Returns an NSString from the supplied Data
+ (NSString *)stringWithData:(NSData *)data encoding:(NSStringEncoding)encoding
{
	return [[[NSString alloc] initWithData:data encoding:encoding] autorelease];
}

//Returns the string as an URL (Make sure the String is actually an URL Adress before using this!)
- (NSURL *)URLValue
{
	return [NSURL URLWithString:[self URLString]];
}

//Returns a Local URL
- (NSURL *)fileURLValue
{
	return [NSURL fileURLWithPath:self];
}

//Returns the string encoded as an URL
- (NSString *)URLString
{
	return [self stringByAddingPercentEscapesUsingEncoding:MT_URL_ENCODING];
}

//MD5-hashes the string
- (NSString *)md5
{
	const char *cStr = [self UTF8String];
	unsigned char result[16];
	CC_MD5( cStr, strlen(cStr), result );
	return [[NSString stringWithFormat:
			@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
			result[0], result[1], result[2], result[3], 
			result[4], result[5], result[6], result[7],
			result[8], result[9], result[10], result[11],
			result[12], result[13], result[14], result[15]
			] lowercaseString];
}

//Replace
- (NSString *)stringByReplacingOccurrencesOfStringsInArray:(NSArray *)targets withStrings:(NSArray *)replacements
{
	NSString *str = [NSString stringWithString:self];
	for(NSInteger i = 0; i < [targets count]; i++)
	{
		str = [str stringByReplacingOccurrencesOfString:[targets objectAtIndex:i] withString:[replacements objectAtIndex:i]];
	}
	
	return str;
}

//Capitalize
- (NSString *)smartCapitalize
{
	return [self smartCapitalizeWithAdditionalWordsFromArray:[NSArray array]];
}

- (NSString *)smartCapitalizeWithArray:(NSArray *)array
{
	NSString *str = [self capitalizedString];
	
	for(NSInteger i = 0; i < [array count]; i++)
	{
		str = [str stringByReplacingOccurrencesOfString:[[array objectAtIndex:i] capitalizedString] withString:[array objectAtIndex:i]];
	}
	
	return str;
}

- (NSString *)smartCapitalizeWithAdditionalWordsFromArray:(NSArray *)array
{
	//Standard Words
	NSArray *s = [NSArray arrayWithObjects:@"a", @"the", @"of", @"and", @"with", @"in", @"to", @"iPhone", @"iPad", @"iPod", @"iMac", @"iBook", nil];
	NSMutableArray *a = [NSMutableArray arrayWithArray:s];
	[a addObjectsFromArray:s];
	
	return [self smartCapitalizeWithArray:a];
}

@end

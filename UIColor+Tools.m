//
//  UIColor+Tools.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-12-22.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIColor+Tools.h"


@implementation UIColor(Tools)

+ (UIColor *)colorWithHexString:(NSString *)str alpha:(float)alpha
{
	str = [[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
	if([str hasPrefix:@"#"]) str = [str substringFromIndex:1]; //Remove the "#" prefix if there is one
	if([str length] != 6) return nil; //If there aren't 6 characters (RRGGBB) it's not valid
	
	NSString *rString = [str substringWithRange:NSMakeRange(0, 2)]; //Get Red
	NSString *gString = [str substringWithRange:NSMakeRange(2, 2)]; //Get Green
	NSString *bString = [str substringWithRange:NSMakeRange(4, 2)]; //Get Blue
	
	NSUInteger r, g, b; //Placeholders for the Red, Green and Blue components
	[[NSScanner scannerWithString:rString] scanHexInt:&r]; //Scan Red
	[[NSScanner scannerWithString:gString] scanHexInt:&g]; //Scan Green
	[[NSScanner scannerWithString:bString] scanHexInt:&b]; //Scan Blue
	
	return MTRGBAColor(r, g, b, alpha);
}

@end

//
//  UIWebView+OpenAdress.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "UIWebView+Tools.h"
#import "MTWebElement.h"

///Extensions for the UIWebView class
@implementation UIWebView(Tools)

//Quickly load the adress specified in the parameter, without having to use NSURLRequest directly
- (void)loadAdress:(NSString *)adress
{
	[self loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:adress]]];
}

//Quickly load a file from the given path
- (void)loadFile:(NSString *)path
{
	[self loadRequest:[NSURLRequest requestWithURL:[NSURL fileURLWithPath:path]]];
}

//Quickly load a file from the application bundle
- (void)loadFile:(NSString *)name ofType:(NSString *)ext inBundle:(NSBundle *)bundle
{
	[self loadFile:[bundle pathForResource:name ofType:ext]];
}

//Gets the page title
- (NSString *)pageTitle
{
	return [self stringByEvaluatingJavaScriptFromString:@"document.getElementsByTagName('title')[0].textContent"];
}

//Gets the page source
- (NSString *)pageSource
{
	return [self stringByEvaluatingJavaScriptFromString:@"document.documentElement.outerHTML"];
}



//Get Specified Elements
- (MTWebElement *)getElementById:(NSString *)eid
{
	//Outer and Inner HTML strings
	NSString *html = [self stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:
																   @"document.getElementById('%@').outerHTML", eid]];
	NSString *inner = [self stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:
																	@"document.getElementById('%@').innerHTML", eid]];
	NSString *text = [self stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:
																   @"document.getElementById('%@').textContent", eid]];
	
	//Split Attributes out of the Outer one
	NSDictionary *dict = [self dictionaryByParsingAttributesFromOuterHTML:html];
	
	//Make it an MTWebElement object
	MTWebElement *element = [[MTWebElement alloc] initWithInnerHTML:inner outerHTML:html textContent:text attributes:dict];
	
	//Return the result
	return [element autorelease];
}

- (NSArray *)getElementsByClassName:(NSString *)className
{
	NSString *raw = [self stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"var r = ''; var c = document.getElementsByClassName('%@'); for(var i = 0; i < c.length; i++) { r += c[i].outerHTML + '|!#|' + c[i].innerHTML + '|!#|' + c[i].textContent + '\\n'; } r", className]];
	NSArray *split = [raw componentsSeparatedByString:@"\n"];
	NSMutableArray *array = [NSMutableArray array];
	for(NSString *tmp in split)
	{
		if([tmp isEqualToString:@""]) break;
		NSArray *sp = [tmp componentsSeparatedByString:@"|!#|"];
		NSDictionary *dict = [self dictionaryByParsingAttributesFromOuterHTML:[sp objectAtIndex:0]];
		[array addObject:[MTWebElement elementWithInnerHTML:[sp objectAtIndex:1]
												  outerHTML:[sp objectAtIndex:0]
												textContent:[sp objectAtIndex:2]
												 attributes:dict]];
	}
	
	return [NSArray arrayWithArray:array];
}

- (NSArray *)getElementsByTagName:(NSString *)tagName
{
	NSString *raw = [self stringByEvaluatingJavaScriptFromString:[NSString stringWithFormat:@"var r = ''; var c = document.getElementsByTagName('%@'); for(var i = 0; i < c.length; i++) { r += c[i].outerHTML + '|!#|' + c[i].innerHTML + '|!#|' + c[i].textContent + '\\n'; } r", tagName]];
	NSArray *split = [raw componentsSeparatedByString:@"\n"];
	NSMutableArray *array = [NSMutableArray array];
	for(NSString *tmp in split)
	{
		if([tmp isEqualToString:@""]) break;
		NSArray *sp = [tmp componentsSeparatedByString:@"|!#|"];
		NSDictionary *dict = [self dictionaryByParsingAttributesFromOuterHTML:[sp objectAtIndex:0]];
		[array addObject:[MTWebElement elementWithInnerHTML:[sp objectAtIndex:1]
												  outerHTML:[sp objectAtIndex:0]
												textContent:[sp objectAtIndex:2]
												 attributes:dict]];
	}
	
	return [NSArray arrayWithArray:array];
}

#pragma mark -
#pragma mark Private Methods
- (NSDictionary *)dictionaryByParsingAttributesFromOuterHTML:(NSString *)html
{
	NSMutableDictionary *dict = [NSMutableDictionary dictionary];
	NSArray *tagSplit = [[[html componentsSeparatedByString:@">"] objectAtIndex:0] componentsSeparatedByString:@" "];
	for(int i = 1; i < [tagSplit count]; i++)
	{
		NSArray *split = [[tagSplit objectAtIndex:i] componentsSeparatedByString:@"="];
		@try
		{
			[dict setObject:[[split objectAtIndex:0] stringByReplacingOccurrencesOfString:@"\"" withString:@""]
					 forKey:[split objectAtIndex:0]];
		}
		@catch (NSException * e)
		{
			@try
			{
				[dict setObject:@"" forKey:[split objectAtIndex:0]];
			}
			@catch (NSException * e)
			{
				//Do nothing
				//...
			}
		}
	}
	
	return [NSDictionary dictionaryWithDictionary:dict];
}

@end

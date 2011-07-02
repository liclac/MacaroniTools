//
//  MTWebElement.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "MTWebElement.h"

@implementation MTWebElement
@synthesize innerHTML, outerHTML, textContent, attributes;

//Constructors
- (id)init
{
	if(self = [super init])
	{
		self.innerHTML = @"";
		self.outerHTML = @"";
		self.textContent = @"";
		self.attributes = [NSDictionary dictionary];
	}
	
	return self;
}

- (id)initWithInnerHTML:(NSString *)ihtml outerHTML:(NSString *)ohtml textContent:(NSString *)tcontent attributes:(NSDictionary *)attribs
{
	if(self = [super init])
	{
		self.innerHTML = ihtml;
		self.outerHTML = ohtml;
		self.textContent = tcontent;
		self.attributes = attribs;
	}
	
	return self;
}

+ (id)elementWithInnerHTML:(NSString *)ihtml outerHTML:(NSString *)ohtml textContent:(NSString *)tcontent attributes:(NSDictionary *)attribs
{
	return [[[MTWebElement alloc] initWithInnerHTML:ihtml outerHTML:ohtml textContent:tcontent attributes:attribs] autorelease];
}

+ (id)element
{
	return [[[MTWebElement alloc] init] autorelease];
}



//Attribute Management
- (NSString *)attribute:(NSString *)key
{
	return [self.attributes objectForKey:key];
}

- (void)setAttribute:(NSString *)key to:(NSString *)value
{
	NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithDictionary:attributes];
	[dict setValue:value forKey:key];
	self.attributes = [NSDictionary dictionaryWithDictionary:dict];
}

@end

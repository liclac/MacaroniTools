//
//  NSBundle+UserData.m
//  MacaroniTools
//
//  Created by Johannes Ekberg on 2010-08-14.
//  Copyright 2010 MacaroniCode Software. All rights reserved.
//

#import "NSBundle+Tools.h"

///Extensions for the NSBundle class
@implementation NSBundle(Tools)

//Get the path for a file in the Documents directory.
//If the file does not exist, it is copied from the bundle, and if a bundled version is not supplied, an empty file is created instead
- (NSString *)pathForDocument:(NSString *)name ofType:(NSString *)ext
{
	return [self pathForDocument:name ofType:ext allowCreate:YES];
}

//Same as above, but allows you to optionally disallow creation of a new file and return nil
- (NSString *)pathForDocument:(NSString *)name ofType:(NSString *)ext allowCreate:(BOOL)create
{
	if(name == nil) return nil;
	NSString *fullName = (ext != nil ? [NSString stringWithFormat:@"%@.%@", name, ext] : name);
	NSString *docsDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
	NSString *resPath = [docsDir stringByAppendingPathComponent:fullName];
	NSString *bundlePath = [[NSBundle mainBundle] pathForResource:name ofType:ext];
	NSError *error;
	NSFileManager *fileManager = [[[NSFileManager alloc] init] autorelease];
	
	if(![fileManager fileExistsAtPath:bundlePath] && ![fileManager fileExistsAtPath:resPath])
	{
		if(!create) return nil;
		else if(![fileManager createFileAtPath:resPath contents:[NSData data] attributes:nil]) return nil;
	}
	else if(![fileManager fileExistsAtPath:resPath])
	{
		if(![fileManager copyItemAtPath:bundlePath toPath:resPath error:&error])
		{
			if(!create) return nil;
			else if (![fileManager createFileAtPath:resPath contents:[NSData data] attributes:nil]) return nil;
		}
	}
	
	return resPath;
}

//Checks the existence of a document
- (BOOL)documentExists:(NSString *)name
{
	NSString *path = [[self documentsPath] stringByAppendingPathComponent:name];
	return [[NSFileManager defaultManager] fileExistsAtPath:path];
}

//Checks the existence of a bundle file
- (BOOL)resourceExists:(NSString *)name
{
	NSString *path = [[self resourcePath] stringByAppendingPathComponent:name];
	return [[NSFileManager defaultManager] fileExistsAtPath:path];
}

//Checks the existence of a file regardless of type
- (BOOL)documentOrResourceExists:(NSString *)name
{
	return ([self documentExists:name] || [self resourceExists:name]);
}

//Returns the path to your Documents Folder
- (NSString *)documentsPath
{
	return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
}

@end

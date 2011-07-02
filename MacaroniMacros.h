/*
 *  MacaroniMacros.h
 *  MacaroniTools
 *  
 *  Created by Johannes Ekberg on 2010-10-03.
 *  Copyright 2010 MacaroniCode Software. All rights reserved.
 *  
 *  
 *  
 *  Some of these macros are based on macros from the net.
 *
 *  The base for the logging and assertation macros are taken partially from http://www.cimgf.com/2010/05/02/my-current-prefix-pch-file/
 *  The benchmarking macros are based on code from http://blog.coriolis.ch/2009/01/05/macros-for-xcode/
 */

#import "MacaroniCommons.h"
#import <TargetConditionals.h>

//Safely release an object by also nillifying it's pointer
#define MTSafeRelease(obj) [obj release], obj = nil;

//Convert RGB colors in to NSColor/UIColor-values
#if TARGET_OS_IPHONE
	#define MTRGBAColor(redC, greenC, blueC, alphaC) [UIColor colorWithRed:redC/255.0f green:greenC/255.0f\
																	  blue:blueC/255.0f alpha:alphaC]
#else
	#define MTRGBAColor(redC, greenC, blueC, alphaC) [NSColor colorWithCalibratedRed:redC/255.0f green:greenC/255.0f\
																				blue:blueC/255.0f alpha:alphaC]
#endif
#define MTRGBColor(redC, greenC, blueC) MTRGBAColor(redC, greenC, blueC, 1.0f)

//Convert scalar numerics into NSNumbers
#define MTNumber(input)					[NSNumber numberWithInteger:(NSInteger)input]
#define MTUNumber(input)				[NSNumber numberWithUnsignedInt:(int)input]

#define MTBoolNumber(input)				[NSNumber numberWithBool:input]
#define MTCharNumber(input)				[NSNumber numberWithChar:input]
#define MTDoubleNumber(input)			[NSNumber numberWithDouble:input]
#define MTFloatNumber(input)			[NSNumber numberWithFloat:input]
#define MTIntNumber(input)				[NSNumber numberWithInt:input]
#define MTIntegerNumber(input)			[NSNumber numberWithInteger:input]
#define MTLongNumber(input)				[NSNumber numberWithLong:input]
#define MTLongLongNumber(input)			[NSNumber numberWithLongLong:input]
#define MTShortNumber(input)			[NSNumber numberWithShort:input]
#define MTUCharNumber(input)			[NSNumber numberWithUnsignedChar:input]
#define MTUIntNumber(input)				[NSNumber numberWithUnsignedInt:input]
#define MTUIntegerNumber(input)			[NSNumber numberWithUnsignedInteger:input]
#define MTULongNumber(input)			[NSNumber numberWithUnsignedLong:input]
#define MTULongLongNumber(input)		[NSNumber numberWithUnsignedLongLong:input]
#define MTUShortNumber(input)			[NSNumber numberWithUnsignedShort:input]

//Strings from BOOL values
#define MTStringWithBool(input)			(input ? @"YES" : @"NO")

//Logging
//MTLog is an NSLog that will become a NO-OP in Release-code
//MTALog crashes your application if in Debug mode but only logs in Release (useful for "This should never happen"-logging)
//MTMark prints the current function name to the console. Becomes a NO-OP in Release-code
//MTAssertReturn is an assertation that becomes a "return"-statement in release code, eventual return value should follow before the ";"
#ifdef DEBUG
	#define MTLog(...) NSLog(@"%s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
	#define MTALog(...) [[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] lineNumber:__LINE__ description:__VA_ARGS__]
	#define MTMark() NSLog(@"%s", __PRETTY_FUNCTION__);
	#define MTAssertReturn(condition, ...) if(!(condition)) MTALog(__VA_ARGS__)
#else
	#define MTLog(...) do { } while (0)
	#define MTALog(...) NSLog(@"%s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
	#define MTMark() do { } while(0)
	#define MTAssertReturn(condition, ...) if(!(condition)) return
#endif

//Assertation - if the Condition is false an error is logged and if the app is in Debug mode it crashes
#define MTAssert(condition, ...) do { if(!(condition)) { MTALog(__VA_ARGS__); }} while(0)

//Non-Fatal Assertation - if the Condition is false an error is logged but the app never crashes (useful for outputting warnings)
#define MTNAssert(condition, ...) do { if(!(condition)) { MTLog(__VA_ARGS__); }} while(0)

//Benchmarking - Logs the time passed between the start and the end of the benchmarked block. Becomes NO-OPs in Release code.
#ifdef DEBUG
	#define MTBenchStart() NSTimeInterval _mtBenchStartTime = [NSDate timeIntervalSinceReferenceDate] //For the first benchmark in the scope
	#define MTBenchStart2() _mtBenchStartTime = [NSDate timeIntervalSinceReferenceDate] //For all later benchmarks (reuses the old variable)
	#define MTBenchEnd() MTLog(@"MacaroniTools: Benchmarking took %f seconds", [NSDate timeIntervalSinceReferenceDate] - _mtBenchStartTime)
	#define MTBenchEndMsg(msg) MTLog(@"MacaroniTools: Benchmarking of label \"%@\" took %f seconds", \
										msg, [NSDate timeIntervalSinceReferenceDate] - _mtBenchStartTime)
#else
	#define MTBenchStart() do{ } while(0)
	#define MTBenchStart2() do{ } while(0)
	#define MTBenchEnd() do{ } while(0)
	#define MTBenchEndMsg(msg) do { } while(0)
#endif


//Conversion between Degrees and Radians
#define MTDegreesToRadians(_degrees_) (_degrees_ * M_PI / 180)
#define MTRadiansToDegrees(_radians_) (_radians_ * 180 / M_PI)


//[NSString stringWithFormat:] shortcuts
#define MTSTR(...) [NSString stringWithFormat:__VA_ARGS__]
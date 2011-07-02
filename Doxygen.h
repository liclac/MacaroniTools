//---
// NOTE:
// This file does not contain any code or usable functions, it provides styling for the Doxygen Documentation.
// Please do no edit this file.
// 
// The Doxygen Documentation can be viewed by opening the file "docs/index.html" in your preferred web browser.
//---


/** \mainpage MacaroniTools Documentation
 *  
 *  \section about About MacaroniTools
 *  
 *  MacaroniTools is a Static Library meant to make development of iPhone Applications easier by providing categories and help-classes that provides a lot of functionality that would be re-inventing the weel to write yourself, as well as help classes that makes life easier.
 *  
 *  You can use this library in your own project, no matter if it's commercial or not, and you don't have to give credit, but if you want to wouldn't mind. You may do almost anything with the library, but you may not sell it or claim it to be your own work.
 *  
 *  MacaroniTools is developed by <a href="http://macaronicode.se/">MacaroniCode Software</a> and DESPERAiOS.
 *  
 *  \section installation Installation
 *  To use MacaroniTools in your own project, you only need to follow these 6 steps:
 *  <ol>
 *  <li>
 *    Place the MacaroniTools folder somewhere where it doesn't get moved, such as in your development workspace (I place all my development-related files in <code>&lt;home&gt;/Applications/</code> for example)
 *  </li>
 *  <li>
 *	  Add "MacaroniTools.xcodeproj" and "MacaroniTools.h" to your project by either right-clicking in the sidebar and selecting "Add->Existing Files..." or by dragging them from Finder. Make sure you DO NOT check "Copy Files" in the dialog that follows.
 *  </li>
 *  <li>
 *    Go to the &quot;Project->Edit Active Target&quot; dialog, and on the General tab, add <code>libMacaroniTools.a</code> to the &quot;Linked Libraries&quot; box by pressing the &quot;+&quot;-button below it, and add the "MacaroniTools" (not Deploy) target to "Direct Depencies"
 *  </li>
 *  <li>
 *    Open the &quot;Build&quot; tab, search for &quot;Other Linker Flags&quot;, and add <code>-ObjC -all_load</code> to that variable.
 *  </li>
 *  <li>
 *    Open Project->Edit Project Settings, open the "Build" tab, in the "Configuration"-box, select "Debug". In "Preprocessor Definitions", add "DEBUG" to enable Debug-only Macros
 *  </li>
 *  <li>
 *    Import the <code>MacaroniTools.h</code> file in your <code>&lt;AppName&gt;_Prefix.pch</code> file ( <code>\#import "MacaroniTools.h"</code> )
 *  </li>
 *  <li>
 *    <small>(Optional)</small> Move the <code>MacaroniTools.xcodeproj</code> and <code>MacaroniTools.h</code> files to the &quot;Frameworks&quot; group in your project for better organization.
 *  </li>
 *  </ol>
 *  
 *  \section usage Usage
 *  If you have "installed" MacaroniTools by following the steps above, all features it provides should become available right away (assuming the import is in the Application Prefix). Just go ahead and call some of the new features to try it out! With a few exceptions, all the features adds themselves as Categories to existing classes and thus just adds features to them, they don't subclass anything - you can just go ahead and use the functions on your existing objects. The exceptions are such classes as MTNavigationController and MTDevice which subclass to provide better performance and more information, and custom classes such as MTModel which don't add to another class.
 *  
 *  \section Troubleshooting
 *  <b>Q: My App doesn't compile and/or crashes with an &quot;<code>Unrecognized Selector Sent to Instance (...)</code>&quot;-error when I run it, what's wrong!?</b><br />
 *  A: You most likely didn't include the &quot;<code>-ObjC</code>&quot; and &quot;<code>-all_load</code>&quot; flags to the linker. "-ObjC" is required to use functions from libraries (why isn't this enabled by default?), and "-all_load" prevents functions from accidentally getting caught in the compiler's Optimization features which removes unused functions to shrink the Executable Size, but sometimes it seems to remove actually used functions... It is especially prone to removing used functions from external libraries for some reason
 *	
 *	<b>Q: What does "Becomes a NO-OP in Release-code" mean?</b><br />
 *	A: This means that if the DEBUG constant isn't defined, these macros are replaced by "NO-OP" commands, eg. commands that do nothing and thus are ignored. In the MacaroniTools Macros' case, they are replaced by the code <code>do { } while(0)</code>, which means that they'll do nothing while 0 == 1 (eg. it won't loop, since 1 and 0 are very rarely the same thing). To enable these macros, define DEBUG in your Debug Configuration.
 *  
 *  <b>Q: I have a different question, where can I ask it?</b><br />
 *  A: Email it to <a href="mailto:support@macaronicode.se">support@macaronicode.se</a>
 *  
 *  <b>Q: I have found a bug, where do I report it?</b><br />
 *  A: Email it to <a href="mailto:bugs@macaronicode.se">bugs@macaronicode.se</a>
 */
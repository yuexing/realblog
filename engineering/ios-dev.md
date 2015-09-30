# IOS DEV

## The spotlight

Simple commands can lead to unexpected result because of the 'mdworker'.

<pre>
$ rm -rf repo
$ svn co <repo-svn-path>
</pre>

Thus, when a lot of filesystem work is involved, disable spotlight for a moment. http://osxdaily.com/2007/03/22/how-to-completely-disable-spotlight/.

## The ARM

Apple uses arm from ARMv6 to ARMv8, but they do have their own ARMv7s.

Thumb is a shorthand version of ARM code, 16-bit instead of regular 32-bit. 
ARM and Thumb instructions cannot be freely intermixed, the processor needs to 
switch mode when going from one to the other; this can only occur when calling 
or returning from a function. So a function has to either be Thumb or ARM as a whole.

For simulator, it is using x86 instead.

Moreover, ARM requires alignment.

Reference: http://wanderingcoder.net/2010/07/19/ought-arm/

## How to install app to device

* connect the device
* xcode->window->devices 
* drag into installed apps

## How to install app to simulator

* Locate the simulator

For <= xcode 5.0: 

<pre>
  Library/Application\ Support/iPhone\ Simulator/7.1
</pre>

For xcode 6.0:

<pre>
  Library/Developer/CoreSimulator/Devices/<the simulator id>/
</pre>

* right click the xcode -> Open Developer Tools -> IOS simulator
* xcrun simctl install booted <location of .app file>


## Profile an .app 

### for memory leak

* name the .m to .mm, then you are able to code in cpp
* create a sub-project as a static library, add as 'Build Phases' -> 'Target dependencies',
  also add its .a to 'Build Phases' -> 'Link Binary With Libraries'
* It is able to detect leaks and cycle reference

Moreover, currently apple store reject dynamic library due to security.

### for ...

http://jimkubicek.com/blog/2013/04/23/debugging-memory-smashers/


## How to clean up Xcode

- clean up the settings

<pre>
$ defaults delete com.apple.dt.Xcode
$ rm -rf ~/Library/Developer/Xcode
$ find  ~/Library/Preferences -name '*code*'  
</pre>

- clean up the command lines

<pre>
$ rm -rf /Library/Developer/CommandLineTools
</pre>

- clean up the cache

<pre>
$ rm -rf ~/Library/Developer/Xcode/DerivedData
$ rm -rf "$(getconf DARWIN_USER_CACHE_DIR)/org.llvm.clang/ModuleCache"
$ rm -rf ~/Library/Caches/com.apple.dt.Xcode
</pre>

- iOS Simulator > Reset Content and Settings.

## Desymbolize

For a crash report:

<pre>
1   Tango 0x1006e84a0 0x10009c000 + 6603936
2   Tango 0x1006e8258 0x10009c000 + 6603352
3   Tango 0x10022a1dc 0x10009c000 + 1630684
4   Tango 0x10022a514 0x10009c000 + 1631508
...
</pre>

Notice that: 0x1006e84a0(runtime address) == 0x10009c000(runtime load address) + 6603936(offset). This is so-called [Address space layout randomization](https://en.wikipedia.org/wiki/Address_space_layout_randomization).

- use the XXX.app.dSYM to desymbolize

	- dwarfdump --uuid XXX.app.dSYM

- find the start_address of the 'segname __TEXT' 

	- otool -arch arm64 -l XXX.app.dSYM/Contents/Resources/DWARF/XXX | less

- address_to_lookup = hex(offset) + start_address

	- for i in $(grep 'XXX' stacktrace | cut -d '+' -f 2); do printf "0x%x " $(( i+0x100000000 )); done

- decode now
	
	- atos -arch arm64 -o XXX.app.dSYM/Contents/Resources/DWARF/XXX <address_to_lookup>[ <address_to_lookup>]

## Mach-O and FAT

Mach-O contains only one arch, while FAT contains more.

xcrun allows us to:

- have multiple versions of Xcode and use the tools from a specific Xcode version, considering have both Xcode 4.5 and Xcode 5, with xcode-select and xcrun you can choose to use the tools 

Inspect the segment/section:

<pre>
% xcrun size -x -l -m a.out
</pre>

Inspect the Section Content:

<pre>
% xcrun otool -s __TEXT __text a.out 
</pre>

Inspect the referred library:

<pre>
% xcrun otool -L a.out
</pre>

Display symbols:

<pre>
% xcrun nm -nm a.out 
</pre>


## Inspect the logs of simulator:

<pre>
% tail -f ~/Library/Logs/CoreSimulator/{hash}/system.log
</pre>


## iOS app size

http://binvis.io/#/

http://corte.si/%2Fposts/visualisation/entropy/index.html

http://corte.si/%2Fposts/visualisation/binvis/index.html
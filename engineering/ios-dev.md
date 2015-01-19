# IOS DEV

## The spotlight

Simple commands can lead to unexpected result because of the 'mdworker'.

<pre>
$ rm -rf repo
$ svn co <repo-svn-path>
</pre>

Thus, when a lot of filesystem work is involved, disable spotlight for a moment. http://osxdaily.com/2007/03/22/how-to-completely-disable-spotlight/.

## Compile and Linker Issues

http://forums.xamarin.com/discussion/14802/error-mt5309-when-building-for-device-but-not-on-simulator

## The ARM

Apple uses arm from ARMv6 to ARMv8, but they do have their own ARMv7s.

Thumb is a shorthand version of ARM code, 16-bit instead of regular 32-bit. 
ARM and Thumb instructions cannot be freely intermixed, the processor needs to 
switch mode when going from one to the other; this can only occur when calling 
or returning from a function. So a function has to either be Thumb or ARM as a whole.

ARMv8 is applied from IOS 5s. (http://iossupportmatrix.com/)

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

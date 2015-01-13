# IOS DEV

## The spotlight

Simple commands can lead to unexpected result because of the 'mdworker'.

<pre>
$ rm -rf repo
$ svn co <repo-svn-path>
</pre>

Thus, when a lot of filesystem work is involved, disable spotlight for a moment. http://osxdaily.com/2007/03/22/how-to-completely-disable-spotlight/.

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

### for ...

# IOS DEV

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

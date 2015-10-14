# Android DEV

## Basic

* Tools:

http://blog.frals.se/2014/07/02/building-and-running-valgrind-on-android/

* Platform Tools:

* Eclipse ADT plugin:

* Android Studio

* Gradle

* Proguard

## Pitfalls

* When importing an library, check "Build Path" -> "Order and Export"

* When creating an activity, also add to "AndroidManifest.xml"
  - the 'android:name', when starting with a period, means to append to 'manifest->package'

* When using android v7 support, add to "Properties" -> "Android" -> "Library(Split DEX file)"

* ListView and ListAdapter: a view has an adapter to getView so that layoutChildren. When
the underlying of the adapter changes, adapter.notifyDataSetChanged() should be called to
notify the datasetObserver.onChanged(), which will update the mItemCount = adapter.getCount().

## Test

* monkey test:

<pre>
adb shell monkey --throttle 500 -s 25 -p com.sgiggle.staging --ignore-crashes --ignore-timeouts --ignore-native-crashes --ignore-security-exceptions --pct-anyevent 5 --pct-syskeys 0 -v -v 150000 >monkey.log 2>&1
</pre>

## Tips

* all the activities

<pre>
adb shell dumpsys activity
</pre>

if there are multiple devices:

<pre>
$ adb devices
$ adb -s device_name logcat
$ adb -s device_name logcat -c # clear the log buffer
$ adb -s device_name logcat -d # dump the log buffer
$ adb -s device_name shell am start -a "android.intent.action.VIEW" -d "tango://logenable/q?contacts=trace"
</pre>

* Service

	- A Service is running in the main thread and thus should not do anything expensive;
	- IntentService 
	- onTaskRemoved

* HandlerThread

	- Looper and Handler

* Notification 

	- PendingIntent
	- has to setSmallIcon which is required, otherwise the notification doesnot show

* PendingIntent VS. Intent

 - Intent

	- perform action on data
	- The primary pieces of information are: action, data
	- It can also contains: type (of the data), component, extra, category

 - PendingIntent

	- give to system (NotificationManager, AlarmManager, etc.) to execute code later as yourself

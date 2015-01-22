# Android DEV

## Basic

* Tools:

* Platform Tools:

* Eclipse ADT plugin:

* Android Studio

* Gradle

* Proguard

## Pitfalls

* When importing an library, check "Build Path" -> "Order and Export"
* When creating an activity, also add to "AndroidManifest.xml"
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

adb shell dumpsys activity

* Service

- A Service is running in the main thread and thus should not do anything expensive;
- IntentService 
- onTaskRemoved

* HandlerThread

- Looper and Handler

* Notification 

- Intent

* PendingIntent


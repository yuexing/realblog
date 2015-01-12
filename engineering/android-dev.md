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

## Test

* monkey test:

<pre>
adb shell monkey --throttle 500 -s 25 -p com.sgiggle.staging --ignore-crashes --ignore-timeouts --ignore-native-crashes --ignore-security-exceptions --pct-anyevent 5 --pct-syskeys 0 -v -v 150000 >monkey.log 2>&1
</pre>

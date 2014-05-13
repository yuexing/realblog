# Java

## Background

- JRE: Java Runtime Environment. The java vm where java program runs on.
- JDK: Java Development Kit, including JRE, compilers and tools. When using
  tomcat, an application server, it needs JDK because the converted Servlet
  from the JSPs needs to be compiled.
- Env Vars
  - JAVA_HOME: path to the JDK
  - JRE_HOME: path to the JRE
  - Some applications expect these environment variables, such as eclipse,
    tomcat.

## Install

### Windows

- install jdk 
  - download the installer
  - click 
  - by default will be installed under C:/Program Files/Java
- Computer -> Properties -> Advanced system settings -> Environment Variables:
  - set JAVA_HOME=path/to/jdk
  - append $JAVA_HOME/bin to PATH
  
### Ubuntu(Linux)

- install jdk
  - download the tar.gz 
  - extract it in some directory
- edit ~/.bashrc
  - export JAVA_HOME=path/to/jdk
  - export PATH=$JAVA_HOME/bin:$PATH
- inform the OS
  - sudo update-alternatives --install /usr/bin/java java path/to/java 1
  - the same for javac, javaws

  - sudo update-alternatives --set java path/to/java
  - the same for javac, javaws

### Mac

- install jdk
  - download the .dmg 
  - click 
  - by default will be installed under /Library/Java/JavaVirtualMachines
- edit ~/.bashrc
  - export JAVA_HOME=$(/usr/libexec/java_home)
  - export PATH=$JAVA_HOME/bin:$PATH

## Jar Helloword

- javac Test.java
- vi manifest.txt
  <pre>
    Main-Class: Test
  </pre>
- jar -cfm Test.jar manifest.txt Test.class
- java -jar Test.jar

## Assembler code

- Make sure your java support PrintAssembly first by checking the output:
  <pre>
    java -XX:+AggressiveOpts -XX:+UnlockDiagnosticVMOptions
-XX:+UnlockExperimentalVMOptions -XX:+PrintFlagsFinal -version
  </pre>  

- Then [download|https://kenai.com/projects/base-hsdis/downloads] or
  [build|http://hg.openjdk.java.net/jdk7u/jdk7u2/hotspot/file/0744602f85c6/src/share/tools/hsdis/README] 
  the hsdis plugin

- edit ~/.bahsrc
  <pre>
    export LD_LIBRARY_PATH=/nfs/yxing/libs:$LD_LIBRARY_PATH
  </pre>

- you should be able to run:
  <pre>
    java -XX:+UnlockDiagnosticVMOptions -XX:+PrintAssembly <class-file>
  </pre>

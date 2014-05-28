# File System

## tmpfs

To mount some small amount of RAM as a filesystem. It is useful for stress
test. Moreover, it is easy to set up on Linux distribution using the following
command:

<pre>

$ mkdir /tmp/ramdisk
$ chmod 777 /tmp/ramdisk
$ mount -t tmpfs -o size=2M tmpfs /tmp/ramdisk

</pre>

To see the amount of free memory, use:

<pre>

$ free 0m

</pre>

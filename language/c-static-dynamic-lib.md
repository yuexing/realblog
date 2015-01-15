# Static and Dynamic lib

<pre>
cc -c foo.cc
</pre>

## -L

GCC first searches for libraries(.a or .so) in /usr/local/lib, then in /usr/lib. Following
that, it searches for libraries in the directories specified by the -L parameter,
in the order specified on the command line.

## Static lib

<pre>
  ar -r libfoo.a foo.o
  cc prog.cc -L. -lfoo
  ./a.out
</pre>

## Dynamic lib
  
<pre>
  cc -shared -o libfoo.so foo.o
  cc prog.cc -L. -lfoo
  LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH ./a.out
</pre>

### rpath

<pre>
  cc prog.cc -L -lfoo -rpath=`pwd`
</pre>

'rpath' encodes the path to the dynamic library in the program so that no need to
specify $LD_LIBRARY_PATH. However, it 1) asks for fixed location; 2) degrade
performance if the so is in NFS.

### install the so

<pre>
  cp libfoo.so /usr/lib
  chmod 0755 /usr/lib/libfoo.so
</pre>

We need to tell the loader it is available for use by updating the cache:

<pre>
  ldconfig

  ldconfig -p | grep foo
</pre>

## How GNU loader work:

The default GNU loader, ld.so, looks for libraries in the following order:

* It looks in the DT_RPATH section of the executable, unless there is a DT_RUNPATH
section.
* It looks in LD_LIBRARY_PATH. This is skipped if the executable is setuid/setgid
for security reasons.
* It looks in the DT_RUNPATH section of the executable unless the setuid/setgid
bits are set (for security reasons).
* It looks in the cache file /etc/ld/so/cache (disabled with the ‘-z nodeflib’
linker option).
* It looks in the default directories /lib then /usr/lib (disabled with the ‘-z 
nodeflib’ linker option).

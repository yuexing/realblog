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


## How does the linker work?

- read: http://eli.thegreenplace.net/2013/07/09/library-order-in-static-linking

- the gcc and its equivalent tools will invoke linker. You can see by '-###'

- the linker's algorithm:

  - the linker keeps 2 list: import(undefined) list and export list

  - once encounters a new object:

    - symbols it exports: solve undefined, and reports 'multiple definition', add to exports

    - symbols it imports: add to imports

  - once encounters a new lib, for each obj:

    - if it solves undefined: link as an object

    - if any of the objects is linked, the lib is rescanned

- based on the algorithm, to solve the circular dependency:

  - order matters

  - --start-group -lbar_dep -lfunc_dep -Wl,--end-group

  - --undefined=bar


## tools

http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html

- nm: symbols
Symbol Type, Description
A,The symbol’s value is absolute, and will not be changed by further linking.
B,Un-initialized data section
D,Initialized data section
T,Normal code section
U,Undefined symbol used but not defined. Dependency on another library.
W,Doubly defined symbol. If found, allow definition in another library to resolve dependency.

- ar: ar t libxxx.a display achieved items

- readelf -s: ready .so (dynamic lib)


## -rpath=dir

Add a directory to the runtime library search path. This is used when linking an ELF executable with shared objects. All -rpath arguments are concatenated and passed to the runtime linker, which uses them to locate shared objects at runtime. The -rpath option is also used when locating shared objects which are needed by shared objects explicitly included in the link;

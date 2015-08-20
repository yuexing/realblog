<pre>
 #include <execinfo.h>
 #include <stdio.h>

 void foo()
 {
 	void *array[128];
  	size_t size;
  	size = backtrace(array, 128);
  	backtrace_symbols_fd(array, size, STDERR_FILENO);
 }
</pre>
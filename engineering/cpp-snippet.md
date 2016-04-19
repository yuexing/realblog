
## Print BT

<pre>
 #include &lt;execinfo.h&gt;
 #include &lt;stdio.h&gt;

 void print_bt()
 {
 	void *array[128];
  	size_t size;
  	size = backtrace(array, 128);
  	backtrace_symbols_fd(array, size, STDERR_FILENO);
 }
</pre>

## Expand Macro

<pre>
#define aname name
#define QUOTE_STRING(x) #x
#define EXPAND_AND_QUOTE_STRING(x) QUOTE_STRING(x)

{
	QUOTE_STRING(aname)            // aname
	EXPAND_AND_QUOTE_STRING(aname) // name
}
</pre>
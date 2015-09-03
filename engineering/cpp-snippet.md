
## Print BT

<pre>
 #include <execinfo.h>
 #include <stdio.h>

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

## Pack binary data into a string
<pre>
  char *PackData(char *c, void *ptr, size_t sz) {
      static const char hex[17] = "0123456789abcdef";
      const unsigned char *u = (unsigned char *) ptr;
      const unsigned char *eu =  u + sz;
      for (; u != eu; ++u) {
        unsigned char uu = *u;
        *(c++) = hex[(uu & 0xf0) >> 4];
        *(c++) = hex[uu & 0xf];
      }
      return c;
    }
</pre>


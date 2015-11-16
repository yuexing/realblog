## Python Note

### decorator

Decorator generates a wrapper which auguments the func.
<pre>
def p_decorate(func):
	print "p_decorate"
	def func_wrapper(name):
		print "func_wrapper"
		return "<p>{0}</p>".format(func(name))
	return func_wrapper

</pre>


If arguments are required, then a decorator generator (synchronized_function) is needed. _wrap is the decorator.

<pre>
def synchronized_function(lock):
	print "synchronized_function ", lock
	def _wrap(f):
		print "_wrap ", f
		def _synchronizer(*args, **kw):
			print "_synchronizer"
			return f(*args, **kw)
		return _synchronizer
	return _wrap
</pre>

To use:

<pre>
@p_decorate
@synchronized_function("hi")
def get_text(name):
	return "lorem ipsum, {0} dolor sit amet".format(name)


print get_text("xxx");
</pre>

### import

<pre>
	sys.path.append(os.path.abspath(os.path.join(__file__, '../lib'))
	from module import class
</pre>

### os.path

- abspath: normpath(join(os.getcwd(), path)).
- normpath: collapsing redundant separators and up-level references
- realpath: eliminating symbolic link
- dirname, basename: split()

### class

only extends object can get real type

class method

static method

### Metaprogramming


### utils

- lxml
- bs4: BeautifulSoup
- 
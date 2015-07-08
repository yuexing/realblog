## Python Note

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
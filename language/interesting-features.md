## Interesting Features in Language 

### Go

### Erlang

### Groovy

- closure

	- this, owner, delegate

- coercion

<pre>
interface Predicate<T> {
    boolean accept(T obj)
}

Predicate filter = { it.contains 'G' } as Predicate
assert filter.accept('Groovy') == true
</pre>

<pre>
def map
map = [
  i: 10,
  hasNext: { map.i > 0 },
  next: { map.i-- },
]
def iter = map as Iterator
</pre>

- optional typing

- DSL
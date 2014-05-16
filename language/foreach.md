# Foreach

or the so called S_enhancedFor.

This article displays the difference in the implementation of S_enhancedFor
between Java and CSharp and the foreach oddity in CSharp.

## CSharp

<pre>
- S_enhancedFor
    - elem
    - container
    - foreachData = FD_enumerable:
        - getEnumerator = function_t:
              name =
System.Collections.Generic.IEnumerable`1::GetEnumerator()System.Collections.Generic.IEnumerator`1<T>
        - getEnumberatorTypeArguments = {
            ...
        }
        - moveNext = function_t:
              name = System.Collections.IEnumerator::MoveNext()System.Boolean
        - moveNextTypeArguments = {
            ...
        }
        - current = function_t:
              name = System.Collections.Generic.IEnumerator`1::get_Current()T
        - currentTypeArguments = {
            ...
        }
        - body
</pre>

## Java

<pre>
- S_enhancedFor:
    - elem
    - container
    - foreachData = FD_iterable:
        - iteratorMethod = function_t:
            name = java.util.<the collection you use>.iterator()java.util.Iterator
        - hasNextMethod = function_t:
            name = java.util.<the collection you use>.hasNext()boolean
        - nextMethod = function_t:
            name = java.util.<the collection you use>.next()java.lang.Object
    - body
</pre>

## CSharp Foreach Oddity

### Oddity 1

There is a form of "duck typing" in use in the foreach loop.

If we say:

<pre>
IEnumerable<int> sequence = whatever;
foreach(int item in sequence) {...}
</pre>

Then CSharp compiler generates the code as though you had written (eliminating
those additional cleanup and error handling code):

<pre>
IEnumerable<int> sequence = whatever;
IEnumerator<int> enumerator = sequence.GetEnumerator();
while(enumerator.MoveNext()) {
    int item = enumerator.Current;
    ...
}
</pre>

Now suppose we have:
<pre>
class C {
    public CEnumerator GetEnumerator() {return new CEnumerator();}
    public class CEnumerator {
        public bool MoveNext() {}
        public int Current { get {} }
    }
}

Even though class C does not implement IEnumerable and CEnumerator does not
implement IEnumerator, C is still treated as a collection!
</pre>

Moreover, if we have the following code, in which C implements the interface
and provides a public method with a different signature:
<pre>
class C : IEnumerable {
    public CEnumerator GetEnumerator() {return new CEnumerator(); }
    public IEnumerator IEnumerable.GetEnumerator() { return this.GetEnumerator(); }
    public class CEnumerator : IEnumerator {
        public bool MoveNext() {}
        public object IEnumerator.Current { get {...} }
        public int Current { get {} }
    }
}
</pre>

In this case, CSharp compiler will generate the code:
<pre>
C sequence = whatever;
CEnumerator enumerator = sequence.GetEnumerator();
while(enumerator.MoveNext())
{
  int item = enumerator.Current;
  { ... }
}
</pre>

Note, CEnumerator is used no IEnumerator. The reason is that this code
generation system was created before generics; this is the way that a CSharp
1.0 programmer could generate a collection of integers without taking on the
penalty of boxing each integer to object.

### Oddity 2

A string implements IEnumerable<char>, so this is legal:

<pre>
foreach(char ch in str) { ... }
</pre>

Now, having read that first oddity, you would probably look at GetEnumerator on
string and see that it says:

<pre>
public CharEnumerator GetEnumerator()
</pre>

and say aha, this must generate:

<pre>
CharEnumerator enumerator = str.GetEnumerator();
while(enumerator.MoveNext()) ... and so on.
</pre>

However, you would be wrong. The C# compiler detects that the foreach loop is
iterating over a string and simply generates

<pre>
for(int index = 0; index < str.Length; ++index) {
  char ch = str[index];
  { ... }
}
</pre>

Because that turns out to be faster; the jitter recognizes this pattern and
optimizes it further.

### Oddity 3

The same is true of arrays. 

<pre>
Frob[] array = whatever;
foreach(Frob item in array) { ... }
</pre>

is generated as
<pre>
for(int index = 0; index < array.Length; ++index) {
  Frob item = array[index];
  { ... }
}
</pre>

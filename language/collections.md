# Collections

## Java collections framework (JCF)

### Background

Pre-JDK1.2, Java included several data structure classes but did not have a
collections framework. The JCF was designed and developed primarily by Joshua
Bloch and was introduced in JDK 1.2.

Later in JDK 5.0, Java had a concurrency package comprising new collection
related classes.

### Architecture

#### java.util.Collection

- inherits java.lang.Iterable to for-each
- add(E), addAll(Collection), remove(E), removeAll(Collection),
  retainAll(Collection), clear()
- size(), isEmpty()
- toArray()

#### java.util.List

- interface
- java.util.ArrayList
- java.util.LinkedList
- java.util.Vector
    - pre-JDK1.2
    - synchronize. If a thread-safe implementation is not needed, ArrayList is
      recommended

#### java.util.Stack

- *class*, inherits java.util.Vector
- push(), pop(), peek()

#### java.util.Queue

- interface
- java.util.LinkedList
- java.util.ArrayDeque
- java.util.PriorityQueue 
    - using compareTo
- java.util.concurrent.BlockingQueue 
- provides additional insertion, extraction, and inspection operations. Each
  of these methods exsits in two forms: throws and exception or return a
  special value on failure. The later case is designed specially for use with
  capacity-restricted Queue implementation.

#### java.util.Deque

- interface, inherits java.util.Queue
- java.util.LinkedList
- java.util.ArrayDeque
- java.util.concurrent.BlockingDeque 

#### java.util.Set

- interface
- java.util.HashSet
    - uses java.util.HashMap
- java.util.LinkedHashSet
    - uses java.util.LinkedHashMap
- java.util.TreeSet 
    - implements java.util.SortedSet
    - use java.util.TreeMap
- further extended by java.util.SortedSet, which is then extended by
  java.util.NavigableSet, in order to take its floor(), ceiling(), lower(),
  higher()

#### java.util.Map

- java.util.HashMap
- java.util.LinkedHashMap
    - extends by creating a doubly linked list that links the elements by
      their insertion order
- java.util.TreeMap
    - the keys are used as values for the nodes in the tree and the nodes
      points to the values of the map

## CSharp collection framework

Most collection types inherits from System.Collections.IEnumerable, and most
iterator types inherits from System.Collections.IEnumerator. 

Also, if you have a class containing the GetEnumerator, then it can be
considered as a collection type. See [foreach](foreach.md) for details.

Moreover, for an iterator block:

<pre>
class Program
{
  static void Main() {}
  IEnumerable<int> M() { yield return 123; } 
}
</pre>

And we compile it:

<pre>
Csc foo.cs
</pre>

And then disassemble it:

<pre>
ildasm foo.exe /text
</pre>

<pre>
...

.class private auto ansi beforefieldinit Program
       extends [mscorlib]System.Object
{
  .class auto ansi sealed nested private beforefieldinit '<M>d__0'
         extends [mscorlib]System.Object
         implements class
[mscorlib]System.Collections.Generic.IEnumerable`1<int32>,
                    [mscorlib]System.Collections.IEnumerable,
                    class
[mscorlib]System.Collections.Generic.IEnumerator`1<int32>,
                    [mscorlib]System.Collections.IEnumerator,
                    [mscorlib]System.IDisposable
  {
}
</pre>



Class Program has a private sealed nested class with a compiler-generated name
"<M>d__0" -- chosen because this is impossible to use in C#.  This class
implements IEnumerable<int> AND IEnumerator<int>!

Why should a class be *both* a sequence and *a moving position in a sequence* ?

The reason is: 99.9999% of the time that the *sequence* is alive, there will
be either zero or one *enumerators* over that sequence, and *most* of the time
there will be exactly one; you do not make a sequence that you do not intend to
enumerate, and when you are done enumerating it, you do not enumerate it again.

It is legal to have two enumerators over the same sequence at the same time?
Sure. Does it ever happen in practice? Almost never.

Therefore the compiler team generated the code to optimize for this case. When
you call GetEnumerator on the object for the first time, it hands out a
reference to itself. If you call GetEnumerator a second time, it makes an
independent enumerator object that talks to the original sequence. 

This way we guarantee that in the common case, the sequence and the enumerator
have the exactly same lifetime, because they are the same object. We also
guarantee that in the common case creating an enumerating a sequence only
creates one new object, not two, and thereby avoids putting pressure on the
garbage collector.

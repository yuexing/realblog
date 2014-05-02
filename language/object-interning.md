# Object Interning

## Description

There is a formal definition for string interning, which states:

<pre>
string interning is a method of storing only one copy of each distinct
string value, which must be immutable. The distinct values are stored in a
string intern pool. 

The single copy of each string is called its 'intern'.
</pre>

In Java, all compile-time constant strings are automatically interned. While
in C#, the string literals in one compilation unit is 'intern'ed within that
assembly. But for the special String.Empty, which is obviously not a string
literal in the compilation unit you are writting, some versions of .NET
runtime automatcally intern it while some do not.

Moreover, objects other than strings can also be interned. For example, in
Java, when primitive values are boxed into a wrapped object, certain
value(boolean, byte, char from 0 to 127, and any short or int between -128 to
127) are interned.

## Pros

- obvious space efficiency
- speed up string comparison, hash-tables

## Cons (There Aint No Such Thing As A Free Lunch)

- search and then allocate new string
- search based on hash? computing/storing hash is expensive
- when to GC?
- lock on 'intern'...hmmm...

## Usage

- solving comparison puzzles, especially in the context of C# in which '=='
  can be reference comparison or value comparison
- apply the idea of 'intern'

<pre>
flyweight is a software design pattern which is to share as much data as
possible. Examples are string interning and has consing.

A flyweight object is by definition immutable value objects. Equality and Hash
are decided by the value.
</pre>

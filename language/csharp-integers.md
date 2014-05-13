# CSharp integers

## Backgroud

CSharp has the (U)IntPtr so that the programmer can cast an integer to a
pointer and manipulate it 'unsafe' blocks. This article discussed a little
about how integer system works in CSharp.

## Code

<pre>
namespace System
{
    public struct Int32: IComparable... 
    {
        internal int m_value;
    }
}
</pre>

Though this appears that “System.Int32” is a wrapper around a primitive type
“int”, this is actually not true.  From the perspective of the CLR,
“System.Int32” is the fundamental type. One of the rules of C# is that the
keyword “int” always means the same thing as the canonical System.Int32 type.
This is simply a choice of the C# language designers; there is logically no
difference whatsoever between “int” and “System.Int32”.  Though there are a couple 
places where the language requires the token “int” and rejects “System.Int32”, 
but these are simply due to questionable choices in the grammar of the language. 
From a semantic analysis point of view they are identical.

Thus the code is just the same as:
<pre>
namespace System
{
    public struct Int32: IComparable... 
    {
        internal System.Int32 m_value;
    }
}
</pre>

A struct contains itself!

These types are an exception to the rule that a struct type must not contain
an instance of itself because you need to start *somewhere*. Since the size
of an int is known a priori by the CLR there is no problem in computing the
size of a struct that contains only an int, even if that struct is *itself* an
int.  Thus C# compiler normally rejects a struct that contains a field of its own type, 
but that error is suppressed in the case of System.Int32.

Now what about IntPtr?  Similarly to Int32 it would seem that we want:
 
<pre>
    public struct IntPtr : ISerializable
    {

        private native_integer m_value;
    }
</pre>

what is native_integer then?

The CLR’s type system does have a mechanism for expressing “native sized integer”, 
but what it does is whenever it sees an object of type “native sized integer” in 
a Portable Executable, it simply replaces that type with either System.Int32 or
System.Int64 at JIT time, depending on what the processor word width is!
Essentially this would be sort of like:

<pre>
#if WIN32
    public struct IntPtr : ISerializable
    {

        private Int32 m_value;
    }
#else
    public struct IntPtr : ISerializable
    {
        private Int64 m_value;
    }
#endif
</pre>

And in fact the code could have been written this way, but there would then be
a lot of duplicated code.  What the authors of the type decided to do instead
was simply take advantage of the fact that a pointer and an native-width
integer can be freely converted back and forth between each other and wrote
the code we saw before and then converted to and from int or long as necessary.

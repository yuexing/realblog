# Struct and Generated Code

## Introduction

Among the popular languages, CSharp and CPP have struct. But only CSharp has
generated code if we do not consider the lambda.

This article is going to discuss how the generated code in CSharp affects the
usage of the struct.

## Scenarios

Suppose you have immutable struct whose 'Handler' is only mutatable in
Dispose:

<pre>
struct MyHandle : IDisposable
{
    public MyHandle(int handle): this() {
        this.Handle = handle;
    }
    public int Handle {get; private set;}
    public void Dispose()
    {
        if(this.Handle != 0) {
            Close(Handle);
        }
        this.Handle = 0;
    }
}
</pre>

See the following usage:

<pre>
var m1 = new MyHandle(1);
try {
} finally {
    m1.Dispose(); 
}

// m1.Handle == 0
</pre>

The following casting boxes m1 and boxing makes a copy. Thus it is the copy
that Dispose is called on:

<pre>
var m1 = new MyHandle(1);
try {
} finally {
    ((IDisposable)m1).Dispose(); 
}

// m1.Handle == 1
</pre>

According to the spec, the 'using' will be expanded to
'((IDisposable)resource).Dispose' for non-nullable type, eg. value type.
However, this is not true in the implementation, which just call 'Dispose'
directly.

<pre>
var m1 = new MyHandle(1);
using(m1) {
} 
// m1.Handle == 1
</pre>

What happens is that the 'using' makes the resource variable inaccessible in
and invisible to the embeded statement. So the above is equivalent to:

<pre>
var m1 = new MyHandle(1);
using(MyHandle invisible = m1)
{
    
}
// m1.Handle == 1
</pre>

which is equivalent to:

<pre>
var m1 = new MyHandle(1);
{
    var invisible = m1;
    try {
    } finally {
        invisible.Dispose;
    }
}
// m1.Handle == 1
</pre>


# Cpp Exceptions

## Rethrow

Catch the exception and throw it again.

In cpp, if you do:

<pre>
catch(exception &e)
{
    // some log 
    throw e;
}
</pre>

it will throw away the stack trace from the original exception and replace it
with the current stack trace.

Thus, you may want to do:
<pre>
catch(exception &e) 
{
    // some log;
    throw;
}
</pre>

This version will perserve the exception exactly as it was caught.

One more practice, you may want to try yourself:

<pre>
struct A {
};

struct B : public A {
};

int main()
{
    try {
        try {
            throw B();
        } catch(A &a) {
            cout &lt;&lt; "Caught an A" &lt;&lt; endl;
            throw a;
        }
    } catch(B &b) {
        cout &lt;&lt; "Caught a B" &lt;&lt; endl;
    } catch(A &a) {
        cout &lt;&lt; "Caught an A again" &lt;&lt; endl;
    }
}
</pre>

## try...catch... and destructors

Compile the following code:

<pre>
struct S {
    ~S() {  }
};
void throws() {
    S s;
    throw 0;
}
int main() {
    try {
        throws();
    } catch (int &) {

    }
}
</pre>

with:

<pre>
g++ -m32 -S test.cc
</pre>

You will see the line:

<pre>
call    __cxa_throw
</pre>

which will:

- walk the stack with the help of the exception tables until it finds a
  handler for the exception;
- unwind the stack (call destructors on the way) until it gets to that handler
- call the handler

- if no handler, std::terminate() is automatically called. Terminate is actually 
a pointer to a function and default value is the Standard C library function std::abort().
abort() can generate a core dump to understand why.

- in multi-thread, the thread throwing exception would 'std::terminate()'.

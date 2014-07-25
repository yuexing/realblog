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
            cout << "Caught an A" << endl;
            throw a;
        }
    } catch(B &b) {
        cout << "Caught a B" << endl;
    } catch(A &a) {
        cout << "Caught an A again" << endl;
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

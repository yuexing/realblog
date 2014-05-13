# Rethrow

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

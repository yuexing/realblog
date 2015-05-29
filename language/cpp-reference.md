# Reference in CPP

According to the standard:

<pre>
A reference shall be initialized to refer to a valid object or function.
[Note: in particular, a null reference cannot exist in a well-defined program,
because the only way to create such a reference would be to bind it to the
“object” obtained by dereferencing a null pointer, which causes undefined
behavior. As described in 9.6, a reference cannot be bound directly to a
bit-field. ]
</pre>


The following examples can compile, but may leads to unexpected result:

Case 1: The compiler optimize '&r == 0' to 'false':

<pre>
void test1() {
    int &r = *(int*)0;
    if( &r == 0) {
        cout &lt;&lt; "NULL" &lt;&lt; endl;
    } else {
        cout &lt;&lt; "Not NULL" &lt;&lt; endl;
    }
}
</pre>

Case 2: It will output '0x4' instead of '0x0':

<pre>
$ cat test.cc 
struct A {
    int a;
};

struct B {
    int b;
};

struct C: public A, public B
{

};

void test2() {
    C *c = 0;
    C &cr = *c;
    B *b = &cr;
    cout &lt;&lt; "b = " &lt;&lt; (void *)b &lt;&lt; endl;
}
</pre>

Case 3: you have no way to initialize a reference as 'default' in a
constructor;

Case 4: you can not return a reference to 'NULL' from a function.

Finally, keep it in mind that it is true that reference is a pointer whose kind is
'ref' but there is a lot of differnce.

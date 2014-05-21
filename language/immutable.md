# Immutable

## C/C++

The keyword 'const' is guaranteed to achieve this.

Some arguments about it:

The callee is free to cast away the const and mutate the object, this is due
to the weak type system. Good system means we donot want the type system to be
a lie. The type system is strong enough that you can reason correctly about
your code. 

Const in C is a *guideline*; it basically means 'you can trust me not try to
mutate the arg.'. That should not be in a type system because the type system
should be a *fact*.

## Java

There is a keyword 'final' but it is not really equivalent to C/C++. 

- you may delay initialization:
<pre>
final int x;
x = 0;
x = 1;      // NOT OK
</pre>

- But, the final field must be initialized by the time the constructor exits;

- If it is an object reference, then the *reference* cannot be changed, but
  the object itsef can still be modified if it provides a means:
<pre>
final A a = new A();
a.x = 0;
a = new A();        // NOT OK
</pre>

- Solutions for read-only access on an object
    - wrapper
    - the sub-class have public set-accessor, the parameter is super-class
    - the sub-class replace the method-body with UnsupporteOperationException,
      the parameter is sub-class
    - l = Collections.unmodifiableList()

## CSharp
- The const keyword can only be used for local variables and fields.
- The readonly keyword can only be used on fields.

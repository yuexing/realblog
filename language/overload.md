# Overload

## Description

Compiler choose which function is actually called based on the type of the
arguments.

People are arguing: Overloading is needed when a language does not support
default argument. Interestingly, C++ supports both.

## C

C does not support overfload because the function signature is only based on
the name. However, you can fake it by using the variable-length argument list.

The following is an example of doing so:

<pre>
void func_1(double);
void func_2(int);

void func(int type, ...)
{
    va_list ap;
    va_start(ap, usage);

    switch(usage) 
    {
        case 1: 
            func_1(va_arg(ap, double));
            break;
        case 2:
            func_2(va_arg(ap, int));
            break;
        default:
            assert(false);
    }
}
</pre>

## C++ 

Support.

Overload is allowed for function, base-template function (not
fully-specialized function). As to template, both classes and functions can be
templated, but functions can only be fully-specialized. Classes can be fully
and partially specialized. Consider:

<pre>
// base
template&lt;class T&gt; class X {}
// partially
template&lt;class T&gt; class X&lt;T*&gt; {}
// fully
template&lt;&gt; class X&lt;int&gt; {}


//base
template&lt;class T&gt; void f(T) {}
//base, overload
template&lt;class T&gt; void f(T*) {}
// fully
template&lt;&gt; void f&lt;int&gt;(int)

//plain, old
void f(double)
</pre>

When resolving overloading, only care about first-class non-template functions
and base-template functions. Once a base-template function is selected, we
then look for any specialized can be used.

## Java

Support.

## Javascript

Does not support but it can be faked easily because the function arguments are
like va_list. 

## Perl

Does not support.

# PHP

Does not support. However you can fake with variadic function, func_num_args
and func_get_arg, or using call_user_func_array.

Note: the overloading in PHP is misused which is actually "interpreter hooks".

## Python

Does not support.

## Ruby

Dost not support.

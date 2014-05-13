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

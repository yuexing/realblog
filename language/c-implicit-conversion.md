# C Implicit Conversion  

## Background

### Order of Implicit Conversion

- zero or one standard conversion sequence
- zero or one user-defined conversion
- zero or one standard conversion sequence

Only one standard conversion sequence is allowed when considering the argument 
to a constructor or to a user-defined conversion function, or considering
conversion between 2 built-in types.

NB: contextually convertible to bool is different from implicit conversion.

### Order of Standard Conversion Sequence

- zero or one lvalue transformation
- zero or one numberic promotion or numberic conversion
- zero or one qualification adjustment

#### Lvalue Transformation

lvalue -> rvalue

Unless encountered in unevaluated context (eg. sizeof, typeid, noexcept or
decltype), a temporary object will be created.

A lvalue of 'array' will be converted to a prvalue of type 'pointer to T'.

A lvaule of function type T will be converted to a prvalue pointer to that
function.

#### Numeric Promotion

- integral promotion

In particular, arithmetic operators do not accept types smaller than int as
argument and integral promotions are automatically applied. The promoted type
is the first type from the list able to hold the entire value range: int, 
unsigned int, long, unsigned long, long long, unsigned long long.

- float promotion

#### Numeric Conversions

- integral conversions

If the destination is _unsigned_, the resulting value is the smallest unsigned
value equal to the source value modulo 2^n where n is the number of bits used
to represent the destionation type.

As we take the residue(with the same sign with the modulus), the signed
integer may be sign-extended and the unsigned integer may be zero-extended.

If the destionation is _signed_, the value does not change if the source integer
can be represented in the destionation type; otherwise, the result is
implementation-defined.

- float conversions
- float-integral conversions
- pointer conversion
- pointer-to-member conversions

#### Boolean Conversion

#### Qualification Conversion

const and volatile

### User-defined Conversion

1 zero or one non-explicit single-argument constructor or non-explicit 
conversion function call

## Usage

- bug of SIGN_EXTENSION

The following method intends to read p[0...3] as an unsigned integer in 
little-endian format, however, due to integral-promotion-to-int and
int-to-unsigned-long-signed-extension, the result is wrong:

<pre>
unsigned long readLittleEndian(unsigned char *p)
{
   return p[0] | 
          (p[1] &lt;&lt; 8) |
          (p[2] &lt;&lt; 16) |
          (p[3] &lt;&lt; 24);
}

</pre>

- bug of INTEGER_OVERFLOW

<pre>
void test(int fd)
{
    int y;
    read(fd, &y, 4);
    MyStruct *arr = new MyStruct[y]; // y * sizeof(MyStruct) can overflow
}
</pre>

- bug of OVERFLOW_BEFORE_WIDEN

in which the value of arithmetic expression might overflow before the result
is widen to a larger data type, which is actually due to casting too late and
can be fixed by casting before the operation.

# C Implicit Conversion  

## Background

### Order of Implicit Conversion

1 zero or one standard conversion sequence
2 zero or one user-defined conversion
3 zero or one standard conversion sequence

Only one standard conversion sequence is allowed when considering the argument 
to a constructor or to a user-defined conversion function, or considering
conversion between 2 built-in types.

NB: contextually convertible to bool is different from implicit conversion.

### Order of Standard Conversion Sequence

1 zero or one lvalue transformation
2 zero or one numberic promotion or numberic conversion
3 zero or one qualification adjustment

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

If the destination is unsigned, the resulting value is the smallest unsigned
value equal to the source value modulo 2^n where n is the number of bits used
to represent the destionation type.

Formally, we take the residue the same sign with the modulus. If the destination 
type is wider, signed integer are sign-extended and unsigned integer are
zero-extended.

If the destionation is signed, the value does not change if the source integer
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

The following method intends to read p[0...3] as an unsigned integer in 
little-endian format, however, due to integral-promotion-to-int and
int-to-unsigned-long-signed-extension, the result is wrong:

<pre>
unsigned long readLittleEndian(unsigned char *p)
{
   return p[0] | 
          (p[1] << 8) |
          (p[2] << 16) |
          (p[3] << 24);
}

</pre>

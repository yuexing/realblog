# Pattern-based Approach

## Intro

As we all know to make a type able in 'using', it has to implement the
interface IDisposable. However, to make a type able for 'foreach', you just
need a GetEnumerator() method returning some type that has a public property getter
'Current' and a public method 'MoveNext()' returning a bool. If the compiler can
determine that all of these requirements are met then the code is generated to
use those methods. Otherwise, the compiler will check to see whether the
object implements IEumerable.


This is also known as 'duck typing', which is to say we treat a type as a
'duck' if it has a method 'Quack()' even if it does not implement 'IDuck'.


## Benefit

- avoid 'object' in a world without generic types
- make 'MyEnumerator' possible to be a mutable struct, which is generally a
  bad programming practice. However, 'foreach' will never expose the struct
- For LINQ, because LINQ came out later...

## Tradeoff

- But CSharp does not want to take 'duck typing' too far because it is not as
  safe as type system.

# CSharp Constructors

This is to talk about csharp constructors, but the main idea may be used to
all the constructors.

## instance variable initializers

execute even before base() after this(). This ordering ensures that all
instance fields are initialized by their variable initializers before any
statements that have access to that instance are executed.

## constructor initializer

called before the constructor body.

- base
- this

## object initializers

- assign value directly to accessible fields or properties of an object at
  creation time

<p>
    new Cat() {Age = 1}
</p>

## collection initializers 

- specify one or more element initializers when you initialize a collection
  class that implements IEnumerable.

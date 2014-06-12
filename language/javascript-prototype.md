# Javascript Prototype

## Important points

- every Function object has an associated object 'prototype' which is *only* useful for the
  instances created from it; Also the 'prototype.constructor' points back to the object;

<pre>
function A() {
    this.name = "a";
}
A.prototype.constructor == A
</pre>

- every object(read: instance) has a (maybe-hidden) property '__proto__' pointing to the
  'prototype' of the constructor object;

<pre>
a = new A();
a.__proto__ == A.prototype;
A.__proto__ == Function.prototype;
Function.__proto__ == Function.prototype;   // Interesting!
Function.constructor == Function;
Object.__proto__ == Function.prototype;
</pre>

- Each prototype object itself is created (by default) with the Object()
  constructor, hence 'prototype.__proto__ == Object.prototype' and
  'Object.prototype.__proto__ == null';

- the default 'prototype' can be set to something else, but needs to set the
  'constructor' correctly;

- instanceof is to check 'prototype.constructor', and thus:

<pre>
Object instanceof Object
a instanceof A
a instanceof Object
! A instance of A
A instance of Function
</pre>

## Usage

- simulate instance inheritance by set the 'prototype' as well as
  'prototype.constructor'; thus we are able to add/override methods as well as inherits
  methods;

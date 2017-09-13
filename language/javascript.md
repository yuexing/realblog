## Javascript Prototype

### Important points

- every Function object has an associated object 'prototype' which is *only* useful for the
  instances created from it; Also the 'prototype.constructor' points back to the object;

<pre>
function A() {
    this.name = "a";
}
A.prototype.constructor == A
</pre>

- every object(read: instance) has a (maybe-hidden) property '__proto__' {point, link}ing to the
  'prototype' of the constructor object;

<pre>
a = new A();
a.__proto__ == A.prototype;
A.__proto__ == Function.prototype;
Object.__proto__ == Function.prototype;
Function.__proto__ == Function.prototype;   // Interesting!
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

- prototype inheritance

<pre>
  // http://javascript.crockford.com/inheritance.html
  Object.prototype.extend(B) {
    this.prototype = new B();
    this.prototype.constructor = this;
  }
  
  // what if
  this.prototype = {
    constructor: this,
    __proto__: B.prototype,
  }
</pre>

## Javascript channels

<pre>
  var channel = new MessageChannel();
  var otherWindow = ifr.contentWindow;
  otherWindow.postMessage('Hello from the main page!', '*', [channel.port2]);
  channel.port1.onmessage = function (e) {
    para.innerHTML = e.data;
  }
</pre>

## Javascript coroutine

<pre>
  function coroutine(f) {
    var o = f();
    return function(arg) {
      o.next(arg);
    }
  }
  
  function* ident(arg) {
    while(true) {
      console.log(arg);
      yield;              <= hang and resume after next()
    }
  }
</pre>

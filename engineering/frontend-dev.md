## Front-End

### Purpose

Summarize the front-end tricks and the frameworks I have used or touched.

### Tricks

#### async without thread

- because javascript execute in block, thus

<pre>
function async(func)
{
setTimeout(func, 0);
}

console.log("before");
async(function() {
	console.log("in");
});
console.log("after");
</pre>

#### dropdown

<pre>
  ul (1st-level)
  |- ul (2end-level)


 ul.1st-level::hover ul {
    display: block
 } 
</pre>

#### clock

- circle: border-radius

- hands: border

- movement: keyframe, rotate

### Frameworks

#### React

- JSX: xml like extension to EcmaScript
- EcmaScript: class, call spread, rest arguments, destructuring, etc.

#### RequireJS

- data-main

<pre>
<script data-main="first/loaded.js" src="scripts/require.js"></script>
</pre>

 **Note**: the script tag require.js generates for your data-main module includes the async attribute. This means that you cannot assume that the load and execution of your data-main script will finish prior to other scripts referenced later in the same page.

- config

<pre>
requirejs.config({
    //By default load any module IDs from js/lib
    baseUrl: 'js/lib',
    //except, if the module ID starts with "app",
    //load it from the js/app directory. paths
    //config is relative to the baseUrl, and
    //never includes a ".js" extension since
    //the paths config could be for a directory.
    paths: {
        app: '../app'
    }
});
</pre>

- require

<pre>
require(['scripts/config'], function() {
    // Configuration loaded now, safe to do other require calls
    // that depend on that config.
    require(['foo'], function(foo) {

    });
});
</pre>

- define a module

<pre>
//my/shirt.js now has some dependencies, a cart and inventory
//module in the same directory as shirt.js
define(["./cart", "./inventory"], function(cart, inventory) {
        //return an object to define the "my/shirt" module.
        return {
        }
    }
);
</pre>

- Relative module names inside define(): For require("./relative/name") calls that can happen inside a define() function call, be sure to ask for "require" as a dependency, so that the relative name is resolved correctly:

<pre>
define(["require", "./relative/name"], function(require) {
    var mod = require("./relative/name");
});
</pre>

#### NodeJS

- A browser tab handles the IO/Timer event, javascript runs in a thread

- each instance wraps a EventEmitter to listen/callback

- the web framework: express

- jxcore for packaging code
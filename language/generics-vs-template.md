# Generics vs Templates 

## C++

C++ has the template, which works as a fancy macro machanism.
When you call func&lt;mytype&gt; (or through [template argument decuction](http://en.cppreference.com/w/cpp/language/template_argument_deduction)), 
the compiler with search all uses of 'T' inside
func and replace them with 'mytype', then compiles the resulting source code.

Note:
- instantiation can happen during link time. Linker calls compiler to compile the generated code;
- whether the implementation can eliminate multiple instantiation is not defined;

<pre>
template &lt;class T&gt; struct A { }
</pre>

### specialization

* explicit/fully:

<pre>
template&lt;&gt; struct A&lt;int&gt; {}
</pre>

* partial:

<pre>
template&lt;class T&gt; struct A&lt;T*&gt; {}
</pre>

### instantiation

* implicit

<pre>
template&lt;class T=float&gt;
struct A {}
</pre>

* explicit:

<pre>
template A&lt;char&gt;;
</pre>

## Java

Java generics were originally designed so that the .class file format would
not need to be changed due to historical reason.

At the AST level, there is no 'E' but java.lang.Object in place in both class
and method scope, box/cast are inserted. In all, the compiler is saving you the key-presses.

This implies you can do nothing with generic type parameters that rely in any
way on runtime information, including:

- new T()       : type creation
- new T[size]   : array creation
- T.class       : class quering
- instanceof List&lt;String&gt;


### Function
    - fn = function_t:
       * name  = 
       * id    =
       * dflags=
       * memberOfClass = 
       * access=
       * type  = function_type_t:
            - return    = 
            - parameter =
        ...
    - inits:
    - body:

### Declaration
     - var = local_variable_t:
        * name    = 
        * dflags  =
        * type    =
    - init = IN_expr:
        * expr    =

### E_new
    - type = <pointer to the type of the created obj>
    - info = JavaNewInfo
        * init = IN_ctor
            - ctorVar = function_t:
            - args    =
            - capturedLocalArgs = 
        * objType = class_type_t:

### E_funcCall
    - type = <return type>
    - func = E_variable:
        * type = function_type_t:
        * var  = function_t:
    - args

### E_box
    - type      = 
    - expr      = 
    - boxData   = JavaBoxData:
        * boxMethod = function_t:
            - name = java.lang.Integer.valueOf(int)java.lang.Integer

## CSharp

Generics actually extends the IL to carry the type arguments in the runtime, thus 
CSharp does not allow raw type and permits those limitations(in Java) in runtime.

### Function

### Declaration
    - var   = local_variable_t:
        * name    = 
        * dflags  =
        * type    = pointer_type_t:
            - pointed_to = generic_instance_type_t:
                * class = class_type_t:
                    - name = System.Collections.Generic.List`1
                    - typeParameterCount = 1
                * arguments = {
                    arg = ...
                }
    - init = IN_expr:
        * expr    = 

### E_new
    - type = pointer_type_t:
        * pointed_to = generic_instance_type_t:
            ...
    - info = CSharpNewInfo:
        * init = IN_ctor
            - ctorVar = function_t:
            - args    =
            - capturedLocalArgs = 
        * objType = generic_instance_type_t

### E_funcCall
    - type = <return type>
    - func = E_variable
        * type = function_type_t (with instantialized type):
        * var  = function_t (with generic_parameter_Type_t indexed to typeArguments):
        * typeArguments = 
    - args 

# Generics vs Templates 

## C++

C++ has the template, which works as a fancy search-and-replace machanism.
When you call func<mytype>, the compiler with search all uses of 'T' inside
func and replace them with 'string', then compiles the resulting source code.

<pre>
template <class T> struct A { }
</pre>

### specialization

* explicit/fully:

<pre>
template<> struct A<int> {}
</pre>

* partial:

<pre>
template<class T> struct A<T*> {}
</pre>

### instantiation

* implicit

<pre>
template<class T=float>
struct A {}
</pre>

* explicit:

<pre>
template A<char>;
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

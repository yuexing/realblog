# Foreach

or the so called S_enhancedFor.

This article displays the difference in the implementation of S_enhancedFor
between Java and CSharp. 

## CSharp

<pre>
- S_enhancedFor
    - elem
    - container
    - foreachData = FD_enumerable:
        - getEnumerator = function_t:
              name =
System.Collections.Generic.IEnumerable`1::GetEnumerator()System.Collections.Generic.IEnumerator`1<T>
        - getEnumberatorTypeArguments = {
            ...
        }
        - moveNext = function_t:
              name = System.Collections.IEnumerator::MoveNext()System.Boolean
        - moveNextTypeArguments = {
            ...
        }
        - current = function_t:
              name = System.Collections.Generic.IEnumerator`1::get_Current()T
        - currentTypeArguments = {
            ...
        }
        - body
</pre>

## Java

<pre>
- S_enhancedFor:
    - elem
    - container
    - foreachData = FD_iterable:
        - iteratorMethod = function_t:
            name = java.util.<the collection you use>.iterator()java.util.Iterator
        - hasNextMethod = function_t:
            name = java.util.<the collection you use>.hasNext()boolean
        - nextMethod = function_t:
            name = java.util.<the collection you use>.next()java.lang.Object
    - body
</pre>

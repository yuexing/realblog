# CSharp Conversion

CSharp has the conversion operator as CPP:

<pre>
public static implicit operator bool(C c)
</pre>

which is to answer "is this thing logically true or false?". 

And the somewhat more rare technique of overloaded "truth" operator, which is to answer "do I need
to evaluate the right hand side of || or not ?"

<pre>
public static bool operator true(C c) 
</pre>

It is possible that the answer to those questions are unequal in some cases
and therefore we nedd two different mechanisms.

For more about operator overload in CSharp, please refer to [Operator
Overloading Tutorial|http://msdn.microsoft.com/en-us/library/aa288467%28v=vs.71%29.aspx]

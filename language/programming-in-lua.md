## Programming in Lua

### function is first-class 

A function has a constructor: function() ... end, and has a name, and can be used as a variable.

### Loops

A Loop has: a iterator function, an invariant state, and a control variable. 

The invariant state and the control variable are passed into the iterator function, to get the control variable, etc.. eg.

<pre>
	function myiter (a, i)
      i = i + 1
      local v = a[i]
      if v then
        return i, v
      end
    end
    
	function mypairs (a)
      return myiter, a, 0
	end


	a = {"one", "two", "three"}
	for i, v in mypairs(a) do
    	print(i, v)
	end
</pre>

a is the invariant, i is the control variable, and myiter is the iterator function.

### Error or Exception

<cite>
	There are no fixed rules for choosing between those two options, but we can provide a general guideline: An exception that is easily avoided should raise an error; otherwise, it should return an error code.
</cite>

### Coroutines

turn upside-down the relationship between caller and callee.

calling 'resume', runs another function; calling 'yield', runs another function.
## How does return work

<pre>
	class s_t {
	public:
		s_t() {cout &lt;&lt; "s_t()" &lt;&lt; endl;}
		~s_t() {cout &lt;&lt; "~s_t()" &lt;&lt; endl;}
		s_t(const s_t& ) {cout &lt;&lt; "s_t(s_t)" &lt;&lt; endl;}

		s_t& bar() {cout &lt;&lt; "bar" &lt;&lt; endl; return *this;}
	};

	s_t foo(const s_t& s)
	{
		cout &lt;&lt; "before return" &lt;&lt; endl;
		return s;
	}
</pre>


Example1:

<pre>
	cout &lt;&lt; "call foo" &lt;&lt; endl;
	foo(s);
	cout &lt;&lt; "end call foo" &lt;&lt; endl;
</pre>

outputs:

<pre>
call foo
before return
s_t(s_t)          // create temporary
~s_t()            // destroy temporary
end call foo
</pre>


Example2:

<pre>
cout &lt;&lt; "call foo" &lt;&lt; endl;
s_t s1 = foo(s);
cout &lt;&lt; "end call foo" &lt;&lt; endl;
</pre>

outputs:

<pre>
call foo
before return
s_t(s_t)        // create s1
end call foo
~s_t()          // destory s1
</pre>


Example3:

<pre>
cout &lt;&lt; "call foo" &lt;&lt; endl;
s_t s1 = foo(s).bar();
cout &lt;&lt; "end call foo" &lt;&lt; endl;
</pre>

outputs:

<pre>
call foo
before return
s_t(s_t)	   // create tempory
bar
s_t(s_t)       // create s1
~s_t()         // destroy temporary
end call foo
~s_t()         // destory s1
</pre>



Summary:

The Return value optimization, is the compiler optimization technique that help eliminate the 
temporary object created to hold the function's return value as much as possible. Note: the compiler
may ellide as much as it can for the copy.




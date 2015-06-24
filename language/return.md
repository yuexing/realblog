## How does return work

<pre>
	class s_t {
	public:
		s_t() {cout << "s_t()" << endl;}
		~s_t() {cout << "~s_t()" << endl;}
		s_t(const s_t& ) {cout << "s_t(s_t)" << endl;}

		s_t& bar() {cout << "bar" << endl; return *this;}
	};

	s_t foo(const s_t& s)
	{
		cout << "before return" << endl;
		return s;
	}
</pre>


Example1:

<pre>
	cout << "call foo" << endl;
	foo(s);
	cout << "end call foo" << endl;
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
cout << "call foo" << endl;
s_t s1 = foo(s);
cout << "end call foo" << endl;
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
cout << "call foo" << endl;
s_t s1 = foo(s).bar();
cout << "end call foo" << endl;
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




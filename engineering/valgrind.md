# Valgrind Practice

<pre>
valgrind --leak-check=full --trace-children=yes --undef-value-errors=no --show-reachable=yes --error-limit=no --log-file=log ./a.out
</pre>

valgrind probably gives false positive, thus use:

<pre>
--gen-suppressions=all
</pre>

to see the cases to suppress.

For the wildscard suppression file:

<pre>
{
  Memcheck:Cond
  ...
  fun:xxx
}
</pre>

<pre>
{
  Memcheck:Leak
  ...
  obj:/usr/*lib*/libpango*
}
</pre>

Finally, you are able to create a ~/.valgrindrc

<pre>
--memcheck:leak-check=full
--show-reachable=yes
--error-limit=no
--suppressions=xxx.supp
</pre>

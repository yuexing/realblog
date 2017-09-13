- Practical Extraction and Report Language

- Perl does not allow punctuation characters such as @(list), $ (scalar), and %(hash) within identifiers

- list

<pre>
  @ages = (25, 30, 40);  
  
  // unpack and list
  @months = qw( Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec );
  @days = qw(Sun Mon Tue Wed Thu Fri Sat Sun);
  ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime();
  print "$mday $months[$mon] $days[$wday]\n";
</pre>

- hash

<pre>
  %data = ('John Paul', 45, 'Lisa', 30, 'Kumar', 40);
</pre>

- variable context

<pre>
  @names = ('John Paul', 'Lisa', 'Kumar');
  @copy = @names;
  $size = @names;
</pre>

- reference

<pre>
  // create a reference for any variable, subroutine or value by prefixing it with a backslash
  $hashref   = \%ENV;
  $coderef   = \&handler;
</pre>

- datetime

<pre>
  // Greenwich  time
  gmtime();
  // epoch time, i.e., the numbers of seconds that have elapsed since a given date, in Unix is January 1, 1970.
  time();
</pre>

- IO

<pre>
  // readonly
  open(DATA, "&lt;file.txt") or die "Couldn't open file file.txt, $!";
  // writeonly
  open(DATA, "&gt;file.txt") or die "Couldn't open file file.txt, $!";
  // append
  open(DATA,"&gt;&gt;file.txt") || die "Couldn't open file file.txt, $!";
  //
  while(&lt;&gt;) {
  }
</pre>

<pre>
  // dir traversal
  sub readDir {
    foreach $file (glob($_[0])) {
      if (-f $file) {}
      elif (-d $file && $file ne '.' && $file ne '..') { readDir($file); }
    }
  }
</pre>

- error handling
 - useful error message (where)
 - stack trace
 
- cgi (server contract): https://www.tutorialspoint.com/perl/perl_cgi_programming.htm

- OO: 
  Perl provides a bless() function, which is used to return a reference which ultimately becomes an object.

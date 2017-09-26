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
  
  
  
  
  ## old notes

Ch2
numbers are all double
string is literal
use warning; use strict;
print “”.””  print “”, “”
if elsif else
while(<>) or while(<STDIN>) or open FD “file”; while(<FD>);
chomp
while, foreach (for), $_

Ch3
@arr[] = (1..2); @arr = qw(1 2 3); @arr=split; 
@arr[1, -1]
@arr = @arrb
@#arr
print “@arr”
reverse sort cmp @arr

Ch4
sub {}
@_[0], @_[1]
my
return

Ch5
IO
say (no need to add “\n”)

Ch6
%hash=(1=>1)
$hash{1}; delete %hash{1}; keys %hash; values %hash; 
%ENV

Ch7, Ch8, Ch9
regex
meta-character: .; numbers: *, +, ? , {}; set: [], \w, \s, \h, \v, \d; select: |; group: (), \1,\2, (:?), (:<label>); position: ^ $ \b
binding: =~
m//, s///gism
split, join

Ch 10
unless, until, elsif, {}

Ch 11
modules

Ch 12
file -r -w_(virtual file handler) stat
`date`, localtime timestamp

Ch 13 Too... Unix

Ch14 
index
substr
sort

Ch15
~~
given-when
 
Ch16
system
exec
%ENV
open in “date|program”; open out “program|mail”
fork
signal

Ch17
eval and $@
grep
map
splice!


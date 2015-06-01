## Important Concept in Regex

- meta-charactors
	- ., +, ?, *, {}
	- ^, $
	- |, []
	- \
	- () 

- more on 'dot'
	- matches everything except for line breaks
	- single line mode, is to consider in a line, thus match line-break

- charactor class: 
	- match any charator in the set
	- [a-z] [ae] [^a]
	-  the only special characters or metacharacters inside a character class are the closing bracket (]), the backslash (\), the caret (^), and the hyphen (-). They can be included by escaping them with a backslash, or by placing them in a position where they do not take on their special meaning, eg. [a^]
	- The usual metacharacters are normal characters inside a character class

- shorthand charactor set
	- \d, \w, \s, \b and their nagated class

- grouping and capturing
	- ()
	- non-capturing group: (?:)
	- named group(?P)
	- branch reset group (?|)
	- atomic group(?>):  when the regex engine exits from it, automatically throws away all backtracking positions remembered by any tokens inside the group. Used for regex optimization.

- Backtraces
	- match the same text as previously matched by a capturing group, eg. match html tag pair

- mode modifier
	- /s, /m
	- /i, /c
	- /x, /t (free space)
	- /g

- greedy/lazy/possessive
	- *
	- *?
	- *+

- lookbehind
	- (?<!a)b, (?<=a)b

- lookahead

	-  q(?!u),  q(??u)

- conditional
	- (?(?=regex)then|else)

- recursion
	- (?R) means "paste the entire regular expression right here, replacing the "(?R)".

## Regex Flavors

### GNU

#### Basic Reg Exp ([BRE](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_03))

- most metacharacters require a backslash to give the metacharacter its flavor
- alternation is not supported
- no shorthand charactor class
- backreferences are the usual \1 through \9

#### Extended Reg Exp ([ERE](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_04))

- metacharactor
- alernation, moreover returns the longest match
- shorthand
- in some implementation, backreferences are the usual \1 through \9

### ECMAScript (or Javascript)

almost perl, except:

- no lookbehind
- no atomic group, possessive qualifier
- no unicode
- no named capturing group
- only /gim
- no conditional

### Perl

- Practical Extraction and Reporting Language, for text-processing
- an integral part 

### Cpp

- [Boost](http://www.boost.org/doc/libs/1_53_0/libs/regex/doc/html/boost_regex/), defaults to Perl
- [std::regex](http://en.cppreference.com/w/cpp/regex), defaults to [ECMAScript](http://en.cppreference.com/w/cpp/regex/ecmascript)

## Regex tools

- [RegexBuddy](http://www.regexbuddy.com/)

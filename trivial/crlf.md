# CRLF

## Description

### CR

Known as carriage return or carrier return, is derived from typewriter. Now as
a control character in ASCII(or a compatible character set), it commands a printer, 
or other output system to move the position of the cursor to the first position on 
the same line.

It is separated from LF for several practical reasons:

- overprint a line to get fancy display
- carriage return is slower compared to processing one character, thus LF is
  sent after it 

### LF

Known as line feed. Now as a control charater in ASCII(or a compatible
charater set), it commands that one line of paper should feed out of the
printer which instructs the printer to advance the paper one line.

## Usage

### New Line

Known as line ending, end of line or line break, can have two understandings:
line seperator or line terminator. The difference will be seen when processing
the last line.

- LF        Unix-like
- CR        Apple II family, Mac OS up to version 9 and OS-9
- CR-LF     Microsoft Windows
- NL(0x15)  

Also, most textual Internet protocols mandate the use of ASCII CR-LF, but
recommend that tolerant applications recognize lone LF as well.

### Programming Languages

To facilitate the creation of portable programs, programming languages provide
some abstrction to deal with the different type of newline sequences used in
different environments. 

The C programming language provides the '\n' and '\r', and they are not
required to be equivalent to the ASCII LF and CR control characters. The C
standard only guarantees:

- Each of these escape sequences maps to a unique implementation-defined
  number that can be stored in a single char value
- When writing a file in text mode, '\n' is transparently translated to the
  native newline sequence used by the system which may be longer than one
  char. When reading in text mode, the native newline sequence is translated
  back to '\n'

Note: This can cause misread the file created on a platform using different
sequence.

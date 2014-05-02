# Java misleading methods

# Description

Some API functions/methods looks obivious but behaves surprisely, for example,
Boolean.getBoolean, which is to read the value a system property and
interpret/return it as Boolean. Programmers may misuse them.

# List

- java.lang.Boolean.getBoolean
- java.lang.Integer.getInteger
- java.lang.Long.getLong
- java.awt.Color.getColor
- java.awt.Font.getFont

The first argument is treated as the name for a system property, then the
value of the system property is retrieved and interpreted as an object for the 
corresponding type, which will be returned.

- java.net.URL.equals

Two URL objects are euqal iff they have the same protocal, reference
equivalent hosts, have the same port number on the host, and the same file and
fragment of the file. Moreover, two hosts are considered equivalent if both
host names can be resolved into the same IP address, else if the names are
qual without regard to case and can not be resolved, or both names are equal
to null. The name resolution is a blocking operation.

- <collection>.add
- <collection>.remove

When adding a primitive type value, it has to be removed by a object of the
boxed-type with the same value.

- java.lang.String.getBytes

Returns a sequence of bytes using the platform default charset. Note: What you
want may be toCharArray.

- java.lang.String.substring

Interesting one. Some are arguing that this contributes to memory leak and
unsafety because it actually copies the begin/end pointers.

- java.util.Calendar.before
- java.util.Calendar.after

The class Calendar serves the wrap the calendar fields such as year, month,
day-of-month, etc. and manipulates on those fields. 
The above two methods return true iff this Calendar represents a time before/after 
the time represented by the specific object.
NB: if the object is not an instance of Calendar, the method returns false.

- java.lang.Thread.interrupted
- java.lang.Thread.isInterruped

The first method is to consult the current thread and the second one is to
consult this Thread.


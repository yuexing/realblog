## Program Loader

In computer science, loader is part of an operating system responsible to load
programs including: validation, copy program, copy command-line to stack,
initialize register, and return to the user mode with _start. In Unix,
the loader is the handler for execve().

Note, we do not always copy if with virtual memory.

## Dynamic Loading

The dl, dlsym, etc. are the api to dynamic load libs and change the pointers
so that you can use the functions and variables.

### Java Classloader

#### rules

- each java class must be loaded by a class loader
- a class with a given name can only be loaded once by a given classloader

#### 3 types

- Bootstrap classloader: needs to be implemented in the naive code
- Extension classloader: java
- Application classloader: java


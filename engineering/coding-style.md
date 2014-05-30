# Coding Style

## Background

Bad coding style introduces/propagates errors, increases global cost, and
decreases readability. This article means to communicate best practices.

Also, this article was somewhat inspired by some sentense seen from javadoc:

<pre>
In java, the local-sensitive classes provide a class method, getInstace, for
getting a generally useful object of the type, for example,
java.util.Calendar.getInstance returns a Calendar object whose calendar fields
have been initialized with the current date and time.
</pre>

## Syntax

### No physical tabs

Except for where it is necessary, eg. Makefile.

Tab key stands for tabulate charactor and is derived from making tables with
typewriter by moving the assembly to the next stop with some width. Nowadays,
tabs are used for indentation. However, physical tabs shows differently (in
width) across systems. Thus use soft tabs, which is spaces-made-virtual-tab,
instead.

### Indentation

Indentation is used for represent the program visually logically by reflecting
its structure. Some programming language, eg. Python, mandate indentation.

### Line length

Use hard-break instead of soft-break as wrapping long lines is not a common
default setting in most editors.

### Naming conventions

under_score or CamelCase, but not mixed. There are cases for
underscored_CamelCase, which is for very special thing.

### Include and Import

### Function (Constructor) Definitions

### Blank lines

Blank lines shows relatedness.

### Braces

Another way for both Indentation and Relatedness.

## File naming

No whitespace character and uppercases, prefer dash to underscore which is hard to type.
Use dot only for extension.

## Exception Handling

### Exception Or Return-error

General Rule: For common or expected cases, avoid using exceptions; they are
slow, can be difficult to follow in a debugger and are a potential portability
problem. When the afterthought decision is to use exceptions, consider how the 
support engineer will live with it.

### Writing exception handlers

Eric Lippert divides exception into four categories:

- Fatal: If thrown, the world is about to the end. Out of memory, out of
  stack, thread aborted. Nothing you can do about. Run the finally block and
  hope for the best
- Boneheaded: Thrown means a bug. Never happens in a correct program so never
  catch it
- Vexing: A badly-designed API gives the caller no way to validate the
  arguments and prevent the exception. Whether the exception should be caught
  or not depends on the calling context, eg. no way to validate Json unless
  you call the parse function and it throws
- Exogenous: Indicate the surprise hard to determine in the first place, eg. the 
  network cable is unplugged, the disk is full, etc. These are almost always
  handled

It is common for Vexing and Exogenous to be caught directly instead of many
levels far.

Moreover, 

- comment exception handler with context and reason for the action because there 
  is a gap between being thrown and being caught
- never use an empty exception handler
- write some debug-assisting functions: 
  - _breakpoint_: a simple function printing out the context (catch, rethrow, 
     fail, etc.)

For an exception, either wrap/throw it or log it, but never do both; take care
not to lose stacktrace.

### Assertions

Use assertion as much as possible to state your certainty. However, original assert 
always leads to abort. Thus write a helpful suppressible assert function.

## Comments

### Do not copy and past comments

## Class

### Sections

- types
- data
- methods
- static/non-static
- access control
- ctor/dtor

### Do not mix overloading and overriding

- overloading: in the scope there are multiple functions with the same name
  and the compiler chooses based on the type of arguments
- overriding: when a virtual function is defined in a base class and is then
  defined again in a dericed class, then the program chooses at the runtime
  based on the dynamic type of receiver object
- That is, in a given class scope, it should not happen that there are
  functions with the same name and at least one of them is either implicit or
  explicit virtual

### Overload

- Do not overload just based on the constness
- Do not make it too confused and difficult to argue which function it is called

## Third-party Library

## Exit Code

- 0: success
- 1: everything is alright but the result may be unexpected
- 2: user error
- 4:(application) unexpected error

## Testing

See in testsuite.

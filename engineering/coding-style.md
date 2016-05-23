# Coding Style

## Background

Bad coding style introduces/propagates errors, increases global cost, and
decreases readability. This article means to communicate best practices.

## What's good code?

- correct: hard to err, easy to argue; hygiene: conservative 
- good performance
- code should carry intention (not commenting)
- open-close, grep-able, test-able, trace-able(think when you're debugging cluster),
 assertive, scalable
- err gracefully (recover, not fail)
- tool-ing: learn once, apply/check everywhere

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

### Lines

Use hard-break instead of soft-break as wrapping long lines is not a common
default setting in most editors.

### Naming conventions

For under_score or CamelCase, but not mixed. There are cases for
underscored_CamelCase, which is for very special thing.

For file, no whitespace character and uppercases, prefer dash to underscore 
which is hard to type. Use dot only for extension.

Semantically: 

- Structural:

  - Adaptor: Through indirection, allows an existing interface to be used from Adapter interface. 
Then whatever the existing interfaces changes, the code dependent on Adapter won't change.

  - Bridge: two orthogonal can vary independently, eg. abstraction(ThreadScheduler->ByTime, ByPriority) 
and implementation (platform-oriented) 

  - Proxy: indirection allows controll

  - Decorator: attach additional functionality at runtime

  - Composite:  treat individual objects and compositions of objects uniformly. eg. Component -> Leaf/Composite.

- Behavior:
  
  - Mediator: Presenter can be the Mediator btw View(Activity/ViewController) and Model. 
  Decouple by 'Required'/'Provider' and injection, for furthur test

    - Controllers in MVC can also be shared between multiple Views. In MVP, the View and the Presenter have a one-to-one relationship.

    - A Repository mediates between the domain and data mapping layers, acting like an in-memory domain object collection

  - Visitor

  - Strategy

  - Observor: Subject(controller) and Observer(view)

  - State: Context wraps State

  - Chain(pipeline): Handler::nextHandler, Handler::handle

  - Command: 'execute' an 'action' on 'receiver'. 

  - Iterator: generic programming

- Context, Manager, Service

### Include and Import

- For intra-module interfaces, use relative path, eg. '../module_helper.h';

- For inter-module interfaces, link to a directory and specify in '-I'.

### Class/Function Declarations/Definitions

Open to extend, close to change.

### Blank lines/ Braces

- relatedness

- try not to eliminate 'Braces' for readers and writers. eg. '{}' in branches,
'()' in expressions

## Coding Practice

### Variable Definition

Definition requires proper initialization.

<pre>
std::vector&lt;int&gt;::const_iterator = v.end(); // default constructor can err
</pre>

<pre>
template&lt;typename T&gt;
void do() {
  T a{};                                          // don't ever forget any local variable
}
</pre>

### Launch Optimization

- static data initialization takes time: eg. const string/ const char* const

### Concurrency programming

- post as much as possible to a thread
- group lock

### Callback

- add/remove vs trigger; trigger has to be lock-free, thus copy needs trade-off if 
not posted to the same thread
- callback with diff: track updated, or calculate diff on-the-fly
- batch callbacks

- boilerplate code for Event, poller, batch-notify

### Algorithms

- base64: when binary string is not allowed, base64 can help, but always 1/3 larger(6*4 == 8*3).
- backtrace(nice brute-force): move a step so that can revert. 
- backpack(partial, 0/1, unlimited, k-limited)
- palindrome

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

See Testsuite.
See Singleton.

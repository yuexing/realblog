# Concurrency

Consider we are living in a multi-thread world...

## Atomicity

Two critical sesions should be merged into a single critical secion because
the latter uses data computed in the former, but probably invalidated in
between.

<pre>
void capitalizeFirstC(string &shared_string) 
{
  lock();
  int index = shared_string.indexOf('c');
  unlock();
  // Now another thread can change shared_string.
  lock();
  shared_string[index] = 'C'; // Now index might be invalid.
  unlock();
}
</pre>

### Servlet Atomicity

Session, Context and Application are shared. 

## Guarded-by-violation

If there are cases that 'f' is accessed(read/write) guarded by 'g', then
probably every case should do so.

## Lock

Lock can be divided into by whether it can not acquired recursively:

- exclusive 
- recursive

## Lock-eversion

The code evades the acquisition or sufficient holding of a lock that is
protecting against modification of thread-shared data by checking a piece of
that thread-shared data.

Obivious ones:

<pre>
if(resource == null) {
    lock(myLock) {
        resource = new SomeClass(x, y);
    }
}
</pre>

<pre>
lock(myLock) {
    if(resource != null) { 
        return;
    }
}
resource = new SomeClass(x, y);
</pre>

Non-obivious ones:
<pre>
if(resource == null) { 
    lock(myLock) {
        if(resource == null) {
            resource = new SomeClass(x, y);
        }
    }
}
use(resource);          // Note, resource may have not been fully-initialized
</pre>

<pre>
lock(myLock) {
    if(resource == null) {
        resource = new SomeClass(x, y);
        resource1 = new SomeClass(x, y);
    }
}
use(resource1);         // Note, resource1 may have not been fully-initialized
</pre>


## Lock-inversion

The typical deadlock pattern: mutual-exclusive; hold-and-wait-for-each-other.

## Non-static-guard-static

As if there is no lock.


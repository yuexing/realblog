# Resource Leak

## java.lang.AutoCloseable

A resource that must be closed when it is no longer needed.  This method close is
invoked automatically on objects managed by the try-with-resources statement. 

## java.io.Closeable extends java.lang.AutoClosable

A Closeable is a source or destination of data that can be closed. The close
method is invoked to release resources that the object is holding (such as
open files).

## System.IDisposable
You should implement IDisposable only if your type uses unmanaged resources
directly. The consumers of your type can call your IDisposable.Dispose
implementation to free resources when the instance is no longer needed. To
handle cases in which they fail to call Dispose, you should either use a class
derived from SafeHandle to wrap the unmanaged resources, or you should
override the Object.Finalize method for a reference type. In either case, you
use the Dispose method to perform whatever cleanup is necessary after using
the unmanaged resources, such as freeing, releasing, or resetting the
unmanaged resources.

A base class with subclasses that should be disposable must implement
IDisposable as follows. .
   - It should provide one public, non-virtual Dispose() method and a protected
virtual Dispose(Boolean disposing) method.
   - The Dispose() method must call Dispose(true) and should suppress
finalization for performance.
   - The base type should not include any finalizers. 

The following code does not override the Object.Finalize():

<pre>
class BaseClass : IDisposable
{
   // Flag: Has Dispose already been called? 
   bool disposed = false;

   // Public implementation of Dispose pattern callable by consumers. 
   public void Dispose()
   { 
      Dispose(true);
      GC.SuppressFinalize(this);           
   }

   // Protected implementation of Dispose pattern. 
   protected virtual void Dispose(bool disposing)
   {
      if (disposed)
         return; 

      if (disposing) {
         // Free any other managed objects here. 
         //
      }

      // Free any unmanaged objects here. 
      //
      disposed = true;
   }
}
</pre>

If you do overried the Object.Finalize():

<pre>
class BaseClass : IDisposable
{
   // Flag: Has Dispose already been called? 
   bool disposed = false;

   // Public implementation of Dispose pattern callable by consumers. 
   public void Dispose()
   { 
      Dispose(true);
      GC.SuppressFinalize(this);           
   }

   // Protected implementation of Dispose pattern. 
   protected virtual void Dispose(bool disposing)
   {
      if (disposed)
         return; 

      if (disposing) {
         // Free any other managed objects here. 
         //
      }

      // Free any unmanaged objects here. 
      //
      disposed = true;
   }

   ~BaseClass()
   {
      Dispose(false);
   }
}
</pre>

If you have a derived class:
<pre>
class DerivedClass : BaseClass
{
   // Flag: Has Dispose already been called? 
   bool disposed = false;

   // Protected implementation of Dispose pattern. 
   protected override void Dispose(bool disposing)
   {
      if (disposed)
         return; 

      if (disposing) {
         // Free any other managed objects here. 
         //
      }

      // Free any unmanaged objects here. 
      //
      disposed = true;
      // Call base class implementation. 
      base.Dispose(disposing);
   }
}
</pre>

A common pattern of implementation for Dispose() is such that Close() calls
Dispose(), and Dispose() eventually sets a Boolean (isDisposed) that causes
another call to Dispose() to throw an exception (ObjectDisposedException more
than likely) or to be ignored all together.

## How C# finalizer works?

The Object class provides no implementation for the Finalize method, and the
garbage collector does not mark types derived from Object for finalization
unless they override the Finalize method.

If a type does override the Finalize method, the garbage collector adds an
entry for each instance of the type to an internal structure called the
finalization queue. The finalization queue contains entries for all the
objects in the managed heap whose finalization code must run before the
garbage collector can reclaim their memory. The garbage collector then calls
the Finalize method automatically under the following conditions:

    - After the garbage collector has discovered that an object is inaccessible,
unless the object has been exempted from finalization by a call to the
GC.SuppressFinalize method.

    - During shutdown of an application domain, unless the object is exempt from
finalization. During shutdown, even objects that are still accessible are
finalized. 

Finalize is automatically called only once on a given instance, unless the
object is re-registered by using a mechanism such as GC.ReRegisterForFinalize
and the GC.SuppressFinalize method has not been subsequently called.

Finalize operations have the following limitations:

    - The exact time when the finalizer executes is undefined. To ensure
deterministic release of resources for instances of your class, implement a
Close method or provide a IDisposable.Dispose implementation.

    - The finalizers of two objects are not guaranteed to run in any specific
order, even if one object refers to the other. That is, if Object A has a
reference to Object B and both have finalizers, Object B might have already
been finalized when the finalizer of Object A starts.

    - The thread on which the finalizer runs is unspecified. 

The Finalize method might not run to completion or might not run at all under
the following exceptional circumstances:

    - If another finalizer blocks indefinitely (goes into an infinite loop,
tries to obtain a lock it can never obtain, and so on). Because the runtime
tries to run finalizers to completion, other finalizers might not be called if
a finalizer blocks indefinitely.

    - If the process terminates without giving the runtime a chance to clean up.
In this case, the runtime first notification of process termination is a
DLL_PROCESS_DETACH notification.

The runtime continues to finalize objects during shutdown only while the
number of finalizable objects continues to decrease.

If Finalize or an override of Finalize throws an exception, and the runtime is
not hosted by an application that overrides the default policy, the runtime
terminates the process and no active try/finally blocks or finalizers are
executed. This behavior ensures process integrity if the finalizer cannot free
or destroy resources. 

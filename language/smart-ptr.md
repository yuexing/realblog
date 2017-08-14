## Shared_ptr

According to the GNU shared_ptr implementation, a shared_ptr is made up of <b>the raw pointer</b> and <b>the control block</b>. 

### control block

The control block is implemented thread safe by combining the atomic and memory barrior(?). The control block holds
reference count of shared_ptrs, reference count of weak_ptrs, deleter, allocator, and the raw_ptr. Upon shared_relase 
or weak_release, the control block will atomically decrease, compare to decide dispose and destory.

#### dispose

free the resource referenced by the raw ptr

#### destroy

free the counter itself

### Usage Summary

The copies of the shared_ptr can be manipulated thread-safely, becase the method assignment/reset/etc. can be considered a read to
the share_ptr object but write to control block. 

Read/write the non thread-safe shared_ptr needs to be synchronized.

### Usage Example

The callback controller may have a lot more callback than registry, in this case, a shared_ptr&it;handler_t&gt; is used.

<pre>
// consider register are dispatched to one thread
register(h) {
  auto new_handlers = make_share(handlers).push_back(h); // read
  lock {
    handlers.swap(new_handlers); // write
  }
}

callback(e) {
  auto handlers_copy; 
  lock {
    handlers_copy = handlers; // read
  }
  for (auto h : handlers_copy) {
    h(e);
  }
}
</pre>

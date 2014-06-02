# The std:: library of CPP

## std::set, std::map, etc.

These are to store unique elements by sorting them following a strict weak
ordering criterion indicated by Compare. They are typically implemented by
RB-tree.

Note: pointer-comparason may probably be a bad idea, since the pointer is
assgined non-deterministic, which causes the structure of RB-tree changes
non-deterministic and possibly leads to intermitten out-of-memory.

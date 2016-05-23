## Common Knowledge

### Square

- Lagrange's four-square theorem, also known as Bachet's conjecture, states that every natural number can be represented as the sum of four integer squares.

### Prime Number

- theorem:
	- any integer greater than 1 can be expressed as a product of primes that is unique up to ordering. 
 no known simple formula that separates prime numbers from composite numbers

	- There are infinitely many prime numbers

	- prime number theorem: randomly chosen number n is prime is inversely proportional to the logarithm of n

- primality testing

	- trial division(sqr(n))

	- Sieves (prime-only trial division)

	- Fermat's little theorem: n^(p-1) = 1(mod p)


### Hash Function

- used to verify/ fingerprint/ find similar strings/ Bloom Filter

- property
	- Determinism
	- Uniformity
	- Defined range
		- hash chunks iteratively

- concerns
	- N vs n
	- N is not even-distributed

- some implementation
	- Hashing by nonlinear table lookup
	- Rabin–Karp (rolling hash)
	  - hs(i+1, k) = (hs(i, k) - s[i] * p^(k-1)) * p + s[i+k] 

### Hash Table

- size: large prime (otherwise, the common divior of key and hash is cancelled thus easy to collide on a smaller range), N/load_factor.

- load factor: avoid the collision

- upon collision:

  - open-address: quadratic probe, h(k,i) = h(k) + c1*i^2 + c2*i
  - chaining

- extensible hash:

  - directory (hash the key to long bit string, keep as many as needed) 

### Cycle Detection

- hare and tortoise

### Convex Hull

- the line btw a and b is also in the Convex
- can use multiply of vectors to decide whether a,b,c should evict b

### Parallel

### Cache

- write-through/write-back

#### L1 Cache

- set/line/blocks(in bytes)
- map to set in the size of the block, to avoid evict, use line

- Core i7 L1 Cache: 32k 8-way set associative
  - E=8, e=3
  - B=64, b=6
  - S=2^15/2^9=2^6, s=6

- Application: matrix multiply

#### TLB (translation lookaside buffer)

#### Paging Swap

- rough LRU => not-recently-used by dirty flag

#### Memcache

- memcached
- radis (twitter has central proxy)
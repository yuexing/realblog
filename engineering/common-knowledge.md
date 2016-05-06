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

- size: large prime to avoid open-address failure

- load factor: avoid the collision

- upon collision: list or open-address

  - open-address: quadratic probe, h(k,i) = h(k) + c1*i^2 + c2*i

### Cycle Detection

- hare and tortoise

### Convex Hull

### Parallel
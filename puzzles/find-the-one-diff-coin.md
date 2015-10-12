### Description

Given N coin, N-1 are the same and there's only 1 is ligher/heavior. Find the one using least times of weigh.

### Hint

a unit of 3 costs only 1 weigh to find a diff unit.

consider 9 coins: 9 -> (3,3,3) -> (1,1,1). so that 2 times.

### Solution

3^(n-1) <= N <= 3^n (n > 1), then n is the answer.
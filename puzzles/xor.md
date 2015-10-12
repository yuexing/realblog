## XOR

### what is the result of 1 ^ 2 ^ 3 ^ ... ^ n

n % 4 == 1, suppose 1, 1 = 1

n % 4 == 2, 1 ^ ... ^ n = n + 1

n % 4 == 3, 1 ^ ... ^ n = ((n-1) + 1) ^ ((n-1) + 1) = 0

n % 4 == 0, 1 ^ ... ^ n = 0 ^ n = n

...

then the (n + 1) following the n, (n + 1) ^ n = 1
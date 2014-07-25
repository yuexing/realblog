# Bit manipulation

## Introduction

Bit manipulation has been popular as with binary system.

- Bit testing
  - bit_all & my_flag == bit_all (all is on)
  - bit_all & my_flag != 0       (any is on)
  - bit_all & my_flag == 0       (none is on) 

- Bit calculation
  - addition without plus
  <pre>
    add(a, b):
        while(b) {
            new_a = a | b;
            b = (a & b);
            a = new_a;
        }
  </pre>
  - subtraction without minus
  <pre>
    neg(b):
        add((~b), 1)
    sub(a, b):
        add(a, neg(b))
  </pre>
 - mutiplication without times
 <pre>
    multi(a, b):
        if(!b || !a) return 0;
        while(b) {
            if( b&1 ) {
                res += a
            }
            a <<= 1
            b <<= 1
        }
 </pre>
 - (quotient, residue)
 <pre>
    div(a, b):
        while(a > b){
            while(a >= (b << 1)) {
                b <<= 1
                sub_res <<= 1
            }
            a = a - b
            res += sub_res;
        }
 </pre>
 - power
 <pre>
    power(a, b):
        while(b) {
            if( b&1 ) {
                res *= a
            }
            a = a * a;
            b <<= 1;
        }
 </pre>
 - sqrt
 <pre>
    sqrt(a):
        left = 0, right = a;
        while(left < right) {
            mid = left + (right - left)/2
            if(mid * mid == a)
            if(mid * mid < a) left = mid+1
            if(mid * mid > a) right = mid
        }
 </pre>
Or for sqrt, you may use Newton method, x = (a/x + x) / 2.
 - round{up/down}
 <pre>
    roundup(a, b):
        (a + (1<<b) -1) >> b << b
    rounddown(a, b):
        (a - (1<<b) +1) >> b << b
 </pre>

- a^b
    a = (a & (~b)) 
    (a | b)

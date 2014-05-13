# Floor

## Background

I recently saw the following code in mediaportal (C#):

<pre>
    DataTime now = DataTime.Now;
    byte[] buffer = new byte[8];
    buffer[0] = 0x1b;
    buffer[2] = (byte)now.Minute;
    buffer[3] = (byte)now.Hour;
    buffer[4] = (byte)now.Month;
    buffer[5] = (byte)now.Day;
    buffer[6] = (byte)Math.Floor((double)(now.Year/100))
</pre>

## Any difference between:
- a/b
- floor((double)(a/b))
- floor((double)a/b)

## Euclidean division

Given a dividend 'a' and a divisor 'd' (d!=0), there exists unique q and r
such that a = dq + r and 0 <= r <= |d|.

### kinds of remainder

- least positive remainder, or the remainder
- least absolute remainder

## In programming languages

- C99, Java, C#: operator %, remainder with the same sign as the dividend,
  consider the word 'left-over'
- Perl, Python: remainder with the same sign as the divisor

## Conclusion

- (a/b) is the same as floor((doule)(a/b))
- In C/C++, Java, C#, if a and b are of the same sign, then (a/b) is the same
  as floor((double)a/b); Otherwise, (a/b) is bigger than floor((double)a/b)

## More

- How to implement a Euclidean division without operator div?
- How to implement the division in programming languages without operator div?

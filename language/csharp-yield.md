# Yield

Yield is a contextual keyword used in iterator methods in CSharp and has two
use cases:

- yield return: returns the next item in the sequence
- yied break: stops returning the sequence element and this happens
  automatically if control reaches the end of the iterator method body.

An example with try-catch, the finally will be called after yield-break to
make sure the resource freed.

<pre>
class Program
{
    static IEnumerable<int> GetValues()
    {
        try
        {
            for (int i = 0; i < 10; i++)
            {
                yield return i;
            }
            yield break;
        }
        finally
        {
            Console.WriteLine("Finally!");
        }
    }
}
</pre>

## Benefits

- spread out the calculation time
- no need to buffer

## Shortcomings

- you will have to hold the resource longer

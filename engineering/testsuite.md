# Testsuite

## Miscellaneous

- using tee can help keep the output, but it will replace the exit code of the
  real test with that of tee. If you really want to run tee, you should do it:
    <pre>
        foo | tee file; exit $${PIPESTATUS[0]}
    </pre>

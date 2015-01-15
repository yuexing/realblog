# Curl Practice

## Command Usage

http://www.slashroot.in/curl-command-tutorial-linux-example-usage

## As a programmer

Curl handles sockets level, open, read, write, ssl, etc.. Moreover, Curl multi
enables to have multiple easy-handlers and use select/poll to make efficient program.

### Curl memory leak

- check out the repository
- open Curl release table (http://curl.haxx.se/docs/releases.html)
- git log --after='-the-date- 00:00' --before='-the-date- 23:59' and find the revision
- follow instruction to build, especially ./configure --enable-debug; make CFLAGS=-DCURLDEBUG

Write your test program:

- g++ -I -L -l
- LD_LIBRARY_PATH=-path-to-the-shared-lib;$LD_LIBRARY_PATH 

### Selete

### Poll

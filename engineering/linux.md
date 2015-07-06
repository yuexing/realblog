### Find out the distribution

<pre>
$ cat /etc/*-release
</pre>

<pre>
$ lsb_release -a
</pre>

### Find out the kernel version

<pre>
$ uname -a
</pre>

### Red Hat Linux package management system

eg. Fedora, Centos, etc.

<pre>
yum install [program]
</pre>

<pre>
rpm -i [program].rpm
</pre>

### Debian package manager

<pre>
apt-get install [program]
</pre>

<pre>
dpkg
</pre>

### Run command

<pre>
$ my_command || { echo 'my_command failed' ; exit 1; }
</pre>

Note:
-  && and || in scripts work based on success not on the return value
- to group use '{}', '()' execute commands in a sub-shell


### Useful command

- lsof: open sockets and files.
- set -/+x: for debug
- uniq: -u: only not repeated lines, -d: only repeated lines
- cut/join
- To replace all occurrences of a string in place, in one or more files:

<pre>
      perl -pi.bak -e 's/old-string/new-string/g' $files
</pre>

- diff/patch/diffstat
- strings
- grep: -o: only the matching part
- sort: -n: by numberic value, -r: reverse
- tr


### Install from scratch

- when ./configure fails, try:

<pre>
	./autogen.sh && ./configure && make
</pre>
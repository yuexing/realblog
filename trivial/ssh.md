# SSH

## Set up ssh

so that you can ssh to a machine without having to type your password.

First, make sure you can ssh to the _destination_ machine and the machine has a
.ssh directory for you.

<pre>
$ ssh <username>@<host>
$ mkdir .ssh
$ chmod 711 .ssh
</pre>

Then, generate a key-pair on the _source_ machine. The generated files will be
~/.ssh/id_dsa and ~/.ssh/id_dsa.pub. 

<pre>
$ ssh-keygen -t dsa
</pre>

Finally, copy the content of public keys to the ~/.ssh/authorized_keys file on
the _destination_ machine

<pre>
scp ~/.ssh/id_dsa.pub <username>@<host>:~
ssh <username>@<host>
cat id_dsa.pub >> .ssh/authorized_keys
</pre>

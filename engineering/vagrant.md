I use vagrant to get a clean virtual machine quickly.

<pre>
$ vagrant box add {title} {url}
$ vagrant init {title}
$ vagrant up

$ vagrant ssh
$ vagrant ssh-config

Host default
  HostName 127.0.0.1
  User vagrant
  Port 2222
  UserKnownHostsFile /dev/null
  StrictHostKeyChecking no
  PasswordAuthentication no
  IdentityFile /Users/lorinhochstein/.vagrant.d/insecure_private_key
  IdentitiesOnly yes
  LogLevel FATAL

ssh vagrant@127.0.0.1 -p 2222 -i /Users/yxing/.vagrant.d/insecure_private_key

scp -i  /Users/yxing/.vagrant.d/insecure_private_key -P 2222 vagrant@127.0.0.1:~/libTango.so .
</pre>
### Mac Dev Setup

- install xcode and run 'xcode-select --install'

- use zsh

<pre>
$ zsh --version
$ chsh -s /bin/zsh 
( install oh-my-zsh )
</pre>

- use brew

- use subl

<pre>

ln -s /Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl /usr/local/bin/subl

</pre> 

- python

<pre>
$ sudo easy_install pip
$ sudo pip install ipython
</pre>

- enable coredump

<pre>
$ ulimit -c unlimited
$ sudo mkdir /cores && sudo chown yxing /cores
</pre>

- gdb / lldb

<pre>
bt; thread apply all bt
</pre>

<pre>
bt; bt all
</pre>
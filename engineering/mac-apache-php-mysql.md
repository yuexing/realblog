# Set up Apache PHP Mysql on Mac

## Apache

$ sudo apachectl restart

and test "http://localhost".

If you see the 403 error, it is probably due to that vhost is enabled by default
but the 'localhost' is not specified in /etc/apache2/extra/httpd-vhosts.conf. Solution:

Add the following lines to the extra/httpd-vhosts.conf:

<pre>
  <VirtualHost *:80>                                                              
    ServerName localhost                                                                                              
    DocumentRoot /Library/WebServer/Documents/                                      
  </VirtualHost>   
</pre>

## PHP

edit the /etc/apache2/httpd.conf and uncomment:

  LoadModule php5_module libexec/apache2/libphp5.so

## Mysql

* Download and install

* Edit PATH:
  
  export PATH=/usr/local/mysql/bin:$PATH

* set up password for root 

<pre>
  $ mysql -u root
  mysql> use mysql;
  mysql> update user set password=PASSWORD("NEWPASSWORD") where User='root';
  mysql> flush privileges;
  mysql> quit
</pre>

* probably need to solve the problem that mysql on OS X get the location of the 
required socket file wrong: http://stackoverflow.com/questions/4219970/warning-mysql-connect-2002-no-such-file-or-directory-trying-to-connect-vi

* basical usage

<pre>
create user 'user'@'localhost' identified by 'password';
create database test;
grant all privileges on test.* to user@localhost;
</pre>

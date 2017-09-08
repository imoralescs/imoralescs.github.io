
## Local Enviroment Notes

* **No application encryption key has been specified. New Laravel app**

```
$ php artisan key:generate
```

* **Permission denied**

```
$ sudo chmod -R 777 /path/to/directory
```

* **Restart, Start, Stop MySQL from the Command Line Linux**

On Linux start/stop/restart from the command line:

```
 /etc/init.d/mysqld start
 /etc/init.d/mysqld stop
 /etc/init.d/mysqld restart
```

Some Linux flavours offer the service command too

```
 service mysqld start
 service mysqld stop
 service mysqld restart
```

or

```
service mysql start
service mysql stop
service mysql restart
```

* **Requested PHP extension dom is missing from your system**

Installing xml-extension (php7.0-xml in my case) solved the problem

```
sudo apt-get install php-xml
```

Managed to fix it with a php version 5.6*

```
$ sudo apt-get install php5.6-xml
```

* **Requested PHP extension mbstring is missing from your system**

```
sudo apt-get install php-mbstring 
```

* **Laravel 5 Failed opening required bootstrap/../vendor/autoload.php**

```
composer update --no-scripts
```

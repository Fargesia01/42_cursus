#!/bin/bash

sleep 10

if [ -e "/var/www/wordpress/wp-condig.php" ]
	exit 1
fi

wp config create --allow-root \
	--dbname=$SQL_DATABASE \
	--dbuser=$SQL_USER \
	--dbpass=$SQL_PASSWORD \
	--dbhost=mariadb:3306 --path='/var/www/wordpress'

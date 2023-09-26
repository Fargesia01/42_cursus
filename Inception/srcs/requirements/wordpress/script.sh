#!/bin/bash

sleep 10

if [ -e "/var/www/wordpress/wp-condig.php" ]; then
	exit 1
fi

cd /var/www/html

if [ ! -f "/var/www/html/wp-config.php" ]; then

	wp core download --allow-root
	
	wp config create --allow-root \
		--dbname=$SQL_DATABASE \
		--dbuser=$SQL_USER \
		--dbpass=$SQL_PASSWORD \
		--dbhost=mariadb --path='/var/www/html' \
		--locale=en_US --skip-check
fi

/usr/sbin/php-fpm7.3 -F -O

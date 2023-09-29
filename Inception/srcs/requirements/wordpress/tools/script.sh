#!/bin/bash

sleep 10

cd /var/www/html

if [ ! -f "/var/www/html/wp-config.php" ]; then

	wp core download --allow-root
	
	wp config create --allow-root \
		--dbname=$SQL_DATABASE \
		--dbuser=$SQL_USER \
		--dbpass=$SQL_PASSWORD \
		--dbhost=mariadb --path='/var/www/html' \
		--locale=en_US

	wp core install --url="${WP_URL}" --title="${TITLE}" --admin_user="${WP_ADMIN}" --admin_password="${WP_ADMIN_PASS}" --admin_email="${WP_ADMIN_EMAIL}" --locale=en_US --skip-email --allow-root

	wp user create "${WP_USER}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASS}" --role=author --allow-root


fi

/usr/sbin/php-fpm7.3 -F -O

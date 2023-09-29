#!/bin/bash

service mysql start

echo "test"

if [ -f "/tmp/bool.txt" ]; then
	echo "Database already exists!\n"
else
	echo "Creating new database..."
	/tmp/secure.expect
	/tmp/mysql.expect
	touch /tmp/bool.txt
fi

exec /usr/bin/mysqld --user=mysql --console

#!/bin/bash

cat .exist 2> /dev/null
if [ $? -ne 0 ]; then

	mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal
	chown -R mysql:mysql /var/lib/mysql
	chown -R mysql:mysql /run/mysqld
	
	/usr/bin/mysqld_safe --datadir=/var/lib/mysql &

	while ! mysqladmin ping -h "localhost" --silent; do
    	sleep 1
	done

	eval "echo \"$(cat /tmp/setup.sql)\"" | mariadb -u root -p${SQL_ROOT_PASSWORD}
	touch .exist
	exit
fi

exec /usr/bin/mysqld_safe --datadir=/var/lib/mysql

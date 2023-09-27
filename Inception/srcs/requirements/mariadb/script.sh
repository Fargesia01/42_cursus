#!/bin/bash

service mysql start

ls /var/run/mysqld
eval "echo \"$(cat /tmp/setup.sql)\"" | mariadb -u root -p${SQL_ROOT_PASSWORD}

mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

ls /var/run/mysqld

exec mysqld

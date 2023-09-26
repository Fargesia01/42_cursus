#!/bin/bash

service mysql start;

eval "echo \"$(cat /tmp/setup.sql)\"" | mariadb -u root -p${SQL_ROOT_PASSWORD}

mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

exec mysqld_safe

from debian:buster

ARG SQL_USER
ARG SQL_PASSWORD
ARG SQL_DATABASE
ARG SQL_ROOT_PASSWORD

RUN apt update -y \
	&& apt upgrade -y \
	&& apt install -y mariadb-server \
	&& apt install -y expect \
	&& apt clean \
	&& rm -rf /var/lib/apt/lists/*

COPY 50-server.cnf /etc/mysql/my.cnf
COPY script.sh /tmp/script.sh
COPY secure.expect /tmp/secure.expect
COPY mysql.expect /tmp/mysql.expect

RUN chmod +x /tmp/mysql.expect
RUN chmod +x /tmp/script.sh
RUN chmod +x /tmp/secure.expect

RUN service mysql start && SQL_USER="$SQL_USER" SQL_PASSWORD="$SQL_PASSWORD" SQL_DATABASE="$SQL_DATABASE" SQL_ROOT_PASSWORD="$SQL_ROOT_PASSWORD" /tmp/secure.expect && /tmp/mysql.expect


EXPOSE 3306

VOLUME /var/lib/mysql

ENTRYPOINT ["mysqld", "-u", "mysql"]

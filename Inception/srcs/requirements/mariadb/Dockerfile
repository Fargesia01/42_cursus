from debian:buster

RUN apt update -y \
	&& apt upgrade -y \
	&& apt install -y mariadb-server \
	&& apt clean \
	&& rm -rf /var/lib/apt/lists/*

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY script.sh /etc/mysql/script.sh
COPY setup.sql /tmp/setup.sql

RUN chmod +x /etc/mysql/script.sh

EXPOSE 3306

VOLUME /var/lib/mysql

ENTRYPOINT ["/etc/mysql/script.sh"]

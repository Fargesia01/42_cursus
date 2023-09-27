from debian:buster

RUN apt-get update -y \
	&& apt-get upgrade -y \
	&& apt-get install -y mariadb-server \
	&& apt-get install -y mariadb-client \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*

COPY 50-server.cnf /etc/my.cnf
COPY script.sh /etc/mysql/script.sh
COPY setup.sql /tmp/setup.sql

RUN chmod +x /etc/mysql/script.sh

EXPOSE 3306

VOLUME /var/lib/mysql

ENTRYPOINT ["/etc/mysql/script.sh"]

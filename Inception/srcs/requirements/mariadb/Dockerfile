from debian:buster

RUN apt update -y \
	&& apt upgrade -y \
	&& apt-get install -y mariadb-server \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY script.sh /etc/mysql/script.sh

RUN chmod +x /etc/mysql/script.sh

ENTRYPOINT ["/etc/mysql/script.sh"]

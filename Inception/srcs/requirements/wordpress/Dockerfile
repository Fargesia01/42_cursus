from debian:buster

RUN apt-get update -y && apt-get upgrade -y \
	&& apt-get install -y wget \
	php \
	php-fpm \
	php-mysql \
	mariadb-client
	
RUN wget https://fr.wordpress.org/wordpress-6.2.2-fr_FR.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.2.2-fr_FR.tar.gz && rm wordpress-6.2.2-fr_FR.tar.gz

RUN mkdir -p /var/www/html
RUN chown -R root:root /var/www/html

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod  +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

COPY tools/script.sh /tmp/script.sh

EXPOSE 9000

ENTRYPOINT ["sh", "/tmp/script.sh"]

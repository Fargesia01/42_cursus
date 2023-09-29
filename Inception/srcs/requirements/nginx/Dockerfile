from debian:buster

RUN apt update -y && apt upgrade -y && apt-get install -y nginx openssl
RUN apt clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=CH/ST=VD/L=Renens/O=42/OU=42/CN=slott.42.fr/UID=slott"

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 80 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]

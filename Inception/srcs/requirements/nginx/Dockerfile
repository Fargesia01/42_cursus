from debian:buster

RUN apt-get update && apt-get install -y nginx openssl
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir /etc/nginx/ssl

COPY nginx.conf /etc/nginx/conf.d/default.conf

EXPOSE 80 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]

FROM alpine:3.19

RUN apk update && apk add --no-cache nginx openssl

RUN mkdir /var/www/two && chown -R nginx:www-data /var/www/two
RUN mkdir /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/server.key \
	-out /etc/nginx/ssl/server.crt -subj "/C=PT/ST=Lisbon/L=Lisbon/O=42Portugal/CN=rvaz" && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/server2.key \
	-out /etc/nginx/ssl/server2.crt -subj "/C=PT/ST=Lisbon/L=Lisbon/O=42Portugal/CN=rvaz" 

COPY ./conf/nginx.conf /etc/nginx/http.d/default.conf
COPY ./index.html /var/www/two

CMD ["nginx", "-g", "daemon off;"]

EXPOSE 443

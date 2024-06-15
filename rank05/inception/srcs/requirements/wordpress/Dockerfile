FROM alpine:3.19

RUN apk update && apk add --no-cache php82 php82-fpm php82-mysqli php82-cgi php-phar php-mbstring php-gd php-pdo fcgi wget curl mysql-client

RUN adduser -S -G www-data www-data

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

RUN mkdir /run/php && chmod 755 /run/php

COPY ./tools/setup.sh /home
RUN chmod +x /home/setup.sh

COPY ./conf/www.conf /etc/php82/php-fpm.d/www.conf

WORKDIR /var/www/html

RUN chown -R www-data:www-data /var/www/html

ENTRYPOINT ["/home/setup.sh"]

CMD ["php-fpm82", "-F", "R"]

EXPOSE 9000

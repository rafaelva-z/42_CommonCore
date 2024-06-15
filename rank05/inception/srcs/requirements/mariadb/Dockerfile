FROM alpine:3.19

RUN apk update && apk add --no-cache mariadb mariadb-client

COPY ./tools/setup.sh /home
RUN chmod +x /home/setup.sh

RUN mkdir /run/mysqld && chown -R mysql:mysql /run/mysqld

ENTRYPOINT ["/home/setup.sh"]
CMD ["mysqld", "--user=mysql"]

EXPOSE 3306

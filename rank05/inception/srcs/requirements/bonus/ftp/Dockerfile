FROM alpine:3.19

RUN apk update && apk add --no-cache vsftpd

RUN adduser -D -h /home/vsftpd ftpuser && echo "ftpuser:banana" | chpasswd

COPY ./conf/vsftpd.conf /etc/vsftpd/vsftpd.conf 
#RUN chown ftp:ftp /etc/vsftpd.conf

RUN mkdir -p /wordpress && chmod -R 777 /wordpress

CMD [ "/usr/sbin/vsftpd", "/etc/vsftpd/vsftpd.conf"]

EXPOSE 20 21 21100

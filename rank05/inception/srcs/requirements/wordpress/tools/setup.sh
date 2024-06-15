#!/bin/sh

echo "[wordpress:setup.sh] Script start!"

sleep 5

conf_file="/var/www/html/wp-config.php"
cd /var/www/html

if [ ! -e "/var/www/html/wp-config.php" ]; then
	echo "[wordpress:setup.sh] Initializing wordpress"
	wp core download --allow-root
	sleep 10
	wp config create --allow-root --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$WORDPRESS_DB_HOST
	wp core install --allow-root --url="$DOMAIN_NAME" --title="$WORDPRESS_SITE_TITLE" \
	--admin_user="$WORDPRESS_ADMIN_USER" --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
	--admin_email="$WORDPRESS_ADMIN_EMAIL" --skip-email
	wp user create $WORDPRESS_USER2_USER $WORDPRESS_USER2_EMAIL --user_pass=$WORDPRESS_USER2_PASSWORD
	chown -R www-data:www-data /var/www/html/wp-content
else
	echo "[wordpress:setup.sh] worpdress has already been set up!"

fi

exec /usr/sbin/php-fpm82 --nodaemonize

echo "[wordpress:setup.sh] Script end."


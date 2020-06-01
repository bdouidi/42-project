FROM debian:buster

RUN apt-get update && apt-get install -y systemd nginx vim wget 
RUN apt-get update && apt-get install -y mariadb-server mariadb-client
RUN apt install -y php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod -R 755 /var/www/html/wordpress/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpMyAdmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz latest-fr_FR.tar.gz
RUN rm var/www/html/index.nginx-debian.html && rm /var/www/html/wordpress/wp-config-sample.php

ADD ./srcs/php.ini ./etc/php/7.3/fpm/php.ini
ADD ./srcs/default ./etc/nginx/sites-available/default
ADD ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
ADD ./srcs/db db
ADD ./srcs/init.sh init.sh
RUN sh init.sh


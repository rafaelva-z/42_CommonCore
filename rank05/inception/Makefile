.PHONY: build up down fclean clean re

all: create_volumes up

up:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
	docker-compose -f ./srcs/docker-compose.yml stop

create_volumes:
	mkdir -p /home/rvaz/data/wp-data
	mkdir -p /home/rvaz/data/db-data

delete_volumes:
	sudo rm -rf /home/rvaz/data

clean:
	docker-compose -f ./srcs/docker-compose.yml down

fclean: stop delete_volumes
	docker-compose -f ./srcs/docker-compose.yml down --rmi all -v
	# docker volume rm -f srcs_db-data srcs_wp-data

re: fclean all

all:
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

re: clean build
build:
	docker-compose -f srcs/docker-compose.yml up -d --build

clean:
	docker-compose -f srcs/docker-compose.yml down -v; \
	docker system prune -af; \
	sudo rm -Rf /home/slott/Desktop/data/mariadb/*; \
	sudo rm -Rf /home/slott/Desktop/data/wordpress/*; \
	
.PHONY: all re down clean build

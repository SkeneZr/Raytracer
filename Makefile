##
## Makefile for Makefile in /home/roulle_a//afs/local/projets_group/Raytracer
## 
## Made by alban roulle
## Login   <roulle_a@epitech.net>
## 
## Started on  Wed May  1 18:37:09 2013 alban roulle
## Last update Thu May 30 11:24:33 2013 alban roulle
##

NAME		= 	rt

SRC =	main.c			\
	src/init.c		\
	src/image.c 		\
	src/cam.c		\
	src/list.c		\
	src/hook.c 		\
	src/rotation.c 		\
	src/sphere.c 		\
	src/plan.c		\
	src/fill_img.c 		\
	lib/my_putchar.c	\
	lib/my_putstr.c 	\
	lib/get_next_line.c 	\
	lib/my_strncmp.c	\
	lib/my_strlen.c		\
	lib/xlib/xmalloc.c	\
	lib/xlib/xopen.c

OBJ     	= 	$(SRC:.c=.o)

CC      	= 	gcc

CFLAGS  	= 	-W -Wall -g3 -ggdb3

LIB     	= 	-L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

conf.txt: all
	./$(NAME) conf.txt

cafe: clear
	@echo
	@echo "   (    (     (     ("
	@echo "    )    )     )     )"
	@echo "  _(____(_____(_____(___"
	@echo " |                      |"	
	@echo " |                      |____"
	@echo " |                       ___ |"
	@echo " |                      |   | |  "
	@echo " |                      |   | | "
	@echo " |                      |__| |"
	@echo " |                    ______|"
	@echo "  \__________________/"
	@echo
	@echo

raytracer:
	@echo
	@echo "  _____        ___  __    __  _____   _____        ___    _____   _____   _____   "
	@echo " |  _  \      /   | \ \  / / |_   _| |  _  \      /   |  / ____| |  ___| |  _  \  "
	@echo " | |_|  |    / /| |  \ \/ /    | |   | |_|  |    / /| | | |      | |__   | |_|  |  "
	@echo " |  _  /    / /_| |   \  /     | |   |  _  /    / /_| | | |      |  __|  |  _  /  "
	@echo " | | \ \   / /  | |   / /      | |   | | \ \   / /  | | | |____  | |___  | | \ \  "
	@echo " |_|  \_\ /_/   |_|  /_/       |_|   |_|  \_\ /_/   |_|  \_____| |_____| |_|  \_\ " 
	@echo
	@echo

clear:
	clear

clean:
	rm -f $(OBJ)
	clean

fclean: clean
	rm -f $(NAME)

re: cafe fclean all raytracer
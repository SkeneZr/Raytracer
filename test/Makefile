##
## Makefile for Makefil in /home/roulle_a//afs/local/projets_group/Raytracer/test
## 
## Made by alban roulle
## Login   <roulle_a@epitech.net>
## 
## Started on  Fri May 31 11:02:59 2013 alban roulle
## Last update Fri May 31 11:34:55 2013 alban roulle
##

NAME            =       rt

SRC =   main.c                  \
        lib/get_next_line.c     \
	lib/my_str_to_wordtab.c \
	lib/my_strdup.c		\
	lib/creat_list.c

OBJ             =       $(SRC:.c=.o)

CC              =       gcc

CFLAGS          =       -W -Wall -g3 -ggdb3

LIB             =       -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

conf.txt: all
	./$(NAME) conf.txt

clean:
	rm -f $(OBJ)
	clean

fclean: clean
	rm -f $(NAME)

re: fclean all

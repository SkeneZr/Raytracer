/*
** my.h for my.h in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May  6 11:28:20 2013 alban roulle
** Last update Thu May 30 11:26:59 2013 alban roulle
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MEM_SIZE        10000
#define NOERRNO		0x08

int     my_getnbr(char *);
void    my_putchar(char);
void    my_putstr(char *);
void    my_put_nbr(int);
int     my_strlen(char *);
char    *get_next_line(const int);
void	*xmalloc(size_t);
int     xopen(const char *, unsigned int);
int     my_strncmp( char *,  char *, int);


#endif /* _MY_H_ */

/*
** my_putchar.c for my_putchar in /home/roulle_a//afs/local2/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed Oct 10 10:02:06 2012 alban roulle
** Last update Mon May  6 11:34:27 2013 alban roulle
*/

#include "../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

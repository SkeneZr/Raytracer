/*
** my_putstr.c for my_putstr in /home/roulle_a//afs/local/piscine/Jour_03
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Thu Oct  4 16:46:25 2012 alban roulle
** Last update Mon May  6 11:35:20 2013 alban roulle
*/

#include "../include/my.h"

void	my_putstr(char *str)
{
  int a;
  
  a = 0;
  while(str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}

/*
** my_strlen.c for my_strlen in /home/roulle_a//afs/local/projets_group/Raytracer/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:39:52 2013 alban roulle
** Last update Mon May  6 15:15:41 2013 alban roulle
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

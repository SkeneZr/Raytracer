/*
** my_strncmp.c for my_strncmp in /home/roulle_a//afs/local/projets_group/Raytracer/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May  6 14:55:55 2013 alban roulle
** Last update Mon May  6 15:15:56 2013 alban roulle
*/

#include "../include/my.h"

int     my_strncmp(char *s1, char *s2, int n)
{
  int   j;
  int	i;

  i = 0;
  j = 0;
  while (s1[i] != n && s2[j] != n)
    {
      i = i + 1;
      j = j + 1;
      if (s1[i] >  s2[j])
        return (1);
      if (s1[i] < s2[j])
        return (-1);
    }
  if (s1[i] >  s2[j])
    return (1);
  if (s1[i] < s2[j])
    return (-1);
  return (0);
}

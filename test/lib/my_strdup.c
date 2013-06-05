/*
** my_strdup.c for my_strdup in /home/roulle_a//afs/local/projets_group/Raytracer/test
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May 31 11:06:19 2013 alban roulle
** Last update Fri May 31 11:14:11 2013 alban roulle
*/

#include "../rt.h"

char    *my_strdup(char *src)
{
  int   i;
  int   i2;
  char  *src2;

  i = 0;
  i2 = 0;
  while (src[i] != '\0')
    i++;
  i++;
  src2 = malloc(i);
  src2[i + 1] = '\0';
  while (src[i2] != '\0')
    {
      src2[i2] = src[i2];
      i2++;
    }
  return src2;
}

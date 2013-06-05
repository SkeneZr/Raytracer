/*
** get_next_line.c for get_next_line in /home/roulle_a//afs/local/projets_group/Raytracer/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May  6 12:43:42 2013 alban roulle
** Last update Mon May 27 15:01:59 2013 alban roulle
*/

#include "../include/my.h"

char            *get_next_line(const int fd)
{
  char          *str;
  static  char  buffer[MEM_SIZE];
  static  int   i = 0;
  int   j;
  static  int   k = 0;

  j = 0;
  str = xmalloc(MEM_SIZE * sizeof(char));
  if (k == 0)
    k = read(fd, buffer, MEM_SIZE);
  if (i == k)
    return (NULL);
  while (i < k && buffer[i] != '\n')
    {
      str[j] = buffer[i];
      i = i + 1;
      j = j + 1;
    }
  if (buffer[i] == '\n')
    i = i + 1;
  str[j] = '\0';
  free(str);
  return (str);
}


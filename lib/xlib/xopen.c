/*
** xopen.c for xopen in /home/roulle_a//afs/local/projets_group/Raytracer/lib/xlib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Thu May 30 11:20:20 2013 alban roulle
** Last update Thu May 30 11:27:20 2013 alban roulle
*/

#include "../../include/env.h"
#include "../../include/my.h"

int     xopen(const char *file, unsigned int flags)
{
  int   fd;

  if ((fd = open(file, flags)) == -1)
    {
      my_putstr(": No such file or directory.\n");
      exit(EXIT_FAILURE);
    }
  return (fd);
}

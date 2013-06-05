/*
** xmalloc.c for xmalloc in /home/roulle_a//afs/local/projets_group/Raytracer/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May  6 12:51:29 2013 alban roulle
** Last update Wed May 29 16:33:51 2013 alban roulle
*/

#include "../../include/my.h"

void            *xmalloc(size_t size)
{
  void          *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return (ptr);
}

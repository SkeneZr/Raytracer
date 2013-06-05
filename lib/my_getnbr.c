/*
** my_getnbr.c for my_getnbr in /home/roulle_a//afs/local/projets_group/Raytracer/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:48:27 2013 alban roulle
** Last update Mon May  6 11:33:32 2013 alban roulle
*/

#include "../include/my.h"

int     get_number(char *str, int i, int neg)
{
  int   nb;
  int   save;

  nb = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      save = nb;
      if (save > (nb * 10 + (str[i] - '0')))
        return (0);
      nb = nb * 10 + (str[i++] - '0');
    }
  if (neg % 2 == 1)
    nb = nb * -1;
  return (nb);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   neg;

  i = 0;
  neg = 0;
  while (str[i])
    {
      if (str[i] == '-')
        neg++;
      if (str[i] >= '0' && str[i] <= '9')
        {
          nb = get_number(str, i, neg);
          return (nb);
        }
      i++;
    }
  return (0);
}

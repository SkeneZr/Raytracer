/*
** my_put_nbr.c for my_put_nbr in /home/roulle_a//afs/local2/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed Oct 10 10:24:15 2012 alban roulle
** Last update Mon May  6 11:33:10 2013 alban roulle
*/

#include "../include/my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 9)
    my_put_nbr(nb/10);
  my_putchar((nb % 10) + 48);
}

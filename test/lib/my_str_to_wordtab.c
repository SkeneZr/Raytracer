/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/roulle_a//afs/local/piscine/Jour_11/ex_03
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon Oct 22 17:38:11 2012 alban roulle
** Last update Mon Jun  3 15:06:06 2013 alban roulle
*/

#include "../rt.h"

int     count_word(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int     countchar(char *str)
{
  int   c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  tab = malloc(sizeof(*tab) * ((count_word(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i] == ' ')
            i++;
          a = a + 1;
          b = 0;
        }
      tab[a] = malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}

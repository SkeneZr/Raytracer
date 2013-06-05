/*
** creat_list.c for creat_list in /home/roulle_a//afs/local/projets_group/Raytracer/test/lib
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May 31 11:24:02 2013 alban roulle
** Last update Mon Jun  3 14:04:12 2013 alban roulle
*/

#include "../rt.h"

t_list *list_new(void)
{
  t_list *new;
  
  new = malloc(sizeof(t_list));
  if (new != NULL)
    {
      new->length = 0;
      new->start = NULL;
      new->end = NULL;
    }
  return new;
}

t_list *list_append(t_list *list, char *data)
{
  t_node *new;

  if (list != NULL)
    {
      new = malloc(sizeof(t_node));
      new->data = data;
      new->next = NULL;
      if (list->end == NULL)
	{
	  new->prev = NULL;
	  list->start = new;
	  list->end = new;
	}
      else
	{
	  list->end->next = new;
	  new->prev = list->end;
	  list->end = new;
	}
      list->length++;
    }
  return (list);
}

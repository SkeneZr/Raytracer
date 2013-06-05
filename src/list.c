/*
** list.c for list in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 16:00:15 2013 alban roulle
** Last update Mon May 13 20:51:41 2013 alban roulle
*/

#include "../include/list.h"
#include "../include/my.h"

void	push_front(t_list **begin, void *data)
{
  t_list	*new_elem;

  if (data == NULL)
    return;
  new_elem = xmalloc(sizeof(t_list));
  new_elem->data = data;
  new_elem->next = *begin;
  *begin = new_elem;
}

void	free_list(t_list **begin)
{
  t_list	*prev;
  t_list	*tmp;

  if (*begin == NULL)
    return;
  prev = *begin;
  tmp = (*begin)->next;
  while (tmp)
    {
      free(prev->data);
      free(prev);
      prev = tmp;
      tmp = tmp->next;
    }
  free(prev->data);
  free(prev);
}

void	add_sort(t_list **begin, t_intersection *data)
{
  t_list	*new_elem;
  t_list	*tmp;

  new_elem = xmalloc(sizeof(t_list));
  new_elem->data = data;
  if (*begin == NULL || ((t_intersection*)((*begin)->data))->distance > data->distance)
    {
      new_elem->next = *begin;
      *begin = new_elem;
      return;
    }
  tmp = *begin;
  while (tmp->next)
    {
      if (((t_intersection*)((tmp->next)->data))->distance > data->distance)
	break;
      tmp = tmp->next;
    }
  new_elem->next = tmp->next;
  tmp->next = new_elem;
}

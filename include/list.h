/*
** list.h for list in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:56:42 2013 alban roulle
** Last update Thu May  9 18:18:45 2013 alban roulle
*/

#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

#include "intersection.h"

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

void	push_front(t_list **begin, void *data);
void	free_list(t_list **begin);

/* only for intersection */
void	add_sort(t_list **begin, t_intersection *data);

#endif /*__LIST_H__*/

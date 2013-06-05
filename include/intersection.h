/*
** intersection.h for interception in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:55:16 2013 alban roulle
** Last update Mon May 13 17:00:48 2013 alban roulle
*/

#ifndef	_INTERSECTION_H_
#define	_INTERSECTION_H_

#include "vec.h"

typedef struct	s_intersection
{
  t_vec		position;
  float		distance;
  unsigned int	color;
}		t_intersection;

#endif	/*__INTERSECTION_H__*/

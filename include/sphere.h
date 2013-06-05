/*
** sphere.h for sphere in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:58:24 2013 alban roulle
** Last update Mon Jun  3 17:58:01 2013 alban roulle
*/

#ifndef	_SPHERE_H_
#define	_SPHERE_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "cam.h"
#include "list.h"

#ifndef POV
#define POW(X)	((X)*(X))
#endif /*POV*/

typedef struct	s_sphere
{
  t_vec		position;
  float		rayon;
  int		color;
}		t_sphere;

void		*init_sphere(const char *arg);
void		inter_sphere(t_list** inter, void *object, t_cam cam);

#endif /*__SPHERE_H__*/

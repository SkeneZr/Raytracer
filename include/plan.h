/*
** plan.h for plan in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May 27 14:54:19 2013 alban roulle
** Last update Thu May 30 10:37:17 2013 alban roulle
*/

#ifndef _PLAN_H__
#define _PLAN_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "cam.h"
#include "list.h"

#ifndef POV
#define POV(X)  ((X)*(X))
#endif /*POV*/

typedef struct  s_plan
{
  t_vec         position;
  int           color;
}               t_plan;

void            *init_plan(t_plan *, const char *);
void            inter_plan(t_list** , void *, t_cam);
void		new_intersection_plan(t_intersection *, t_plan *, t_list **, float);

#endif /*__PLAN_H__*/

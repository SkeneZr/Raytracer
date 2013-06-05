/*
** rotation.h for rotation in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:57:44 2013 alban roulle
** Last update Thu May  9 18:19:07 2013 alban roulle
*/

#ifndef _ROTATION_H_
#define _ROTATION_H_

#include <math.h>

#include "vec.h"

void	rotX(t_vec *vec, float angle);
void	rotY(t_vec *vec, float angle);
void	rotZ(t_vec *vec, float angle);

#endif /*__ROTATION_H__*/

/*
** rotation.c for rotation in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 16:02:33 2013 alban roulle
** Last update Thu May  9 18:19:14 2013 alban roulle
*/

#include "../include/rotation.h"

void	rotX(t_vec *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;

  vec->y = cosf(angle) * tmp[1] - sinf(angle) * tmp[2];
  vec->z = sinf(angle) * tmp[1] + cosf(angle) * tmp[2];
}

void	rotY(t_vec *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;

  vec->x = cosf(angle) * tmp[0] + sinf(angle) * tmp[2];
  vec->z = -sinf(angle) * tmp[0] + cosf(angle) * tmp[2];
}

void	rotZ(t_vec *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;

  vec->x = cosf(angle) * tmp[0] - sinf(angle) * tmp[1];
  vec->y = sinf(angle) * tmp[0] + cosf(angle) * tmp[1];
}

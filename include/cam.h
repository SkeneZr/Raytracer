/*
** cam.h for cam in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:52:15 2013 alban roulle
** Last update Mon May 13 17:23:51 2013 alban roulle
*/

#ifndef	_CAM_H_
#define	_CAM_H_

#include <math.h>
#include <stdio.h>

#include "vec.h"

typedef struct	s_cam
{
  t_vec		position;
  t_vec		orientation;
  t_vec		vecteur_cam;
  float		distance;
}		t_cam;

void	init_default_cam(t_cam *cam);
void	init_cam(t_cam *cam, const char *arg);
void	calc_vecteur_cam(t_cam *cam, int x, int y);

#endif	/*__CAM_H__*/

/*
** cam.c for cam in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 15:53:53 2013 alban roulle
** Last update Mon May 13 20:44:11 2013 alban roulle
*/

#include "../include/env.h"
#include "../include/cam.h"

void	init_default_cam(t_cam *cam)
{
  cam->position.x = 0;
  cam->position.y = 0;
  cam->position.z = 0;
  cam->orientation.x = 0;
  cam->orientation.y = 0;
  cam->orientation.z = 0;
  cam->distance = 100;
}

void	init_cam(t_cam *cam, const char *arg)
{
  t_vec	position;
  t_vec	orientation;
  float distance;

  init_default_cam(cam);
  if (sscanf(arg, "camera %f %f %f %f %f %f %f", &position.x, &position.y, &position.z, &orientation.x, &orientation.y, &orientation.z, &distance) == 7)
    {
      cam->position.x = position.x;
      cam->position.y = position.y;
      cam->position.z = position.z;
      cam->orientation.x = orientation.x;
      cam->orientation.y = orientation.y;
      cam->orientation.z = orientation.z;
      cam->distance = distance;
    }
}

void	calc_vecteur_cam(t_cam *cam, int x, int y)
{
  cam->vecteur_cam.x = cam->distance;
  cam->vecteur_cam.y = (float) (WIDTH) / 2 - (float) x;
  cam->vecteur_cam.z = (float) (HEIGHT) / 2 - (float) y;

  /*rotation*/
}

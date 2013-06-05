/*
** sphere.c for sphere in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 16:04:11 2013 alban roulle
** Last update Mon Jun  3 17:58:52 2013 alban roulle
*/

#include "../include/intersection.h"
#include "../include/sphere.h"
#include "../include/my.h"

void	*init_sphere(const char *arg)
{
  t_sphere	*new_sphere;
  t_vec		position;
  float		rayon;
  unsigned int	color;

  if (sscanf(arg, "sphere %f %f %f %f %X", &position.x, &position.y, &position.z, &rayon, &color) == 5)
    {
      new_sphere = xmalloc(sizeof(t_sphere));
      new_sphere->position.x = position.x;
      new_sphere->position.y = position.y;
      new_sphere->position.z = position.z;
      new_sphere->rayon = rayon;
      new_sphere->color = color;
      return new_sphere;
    }
  return NULL;
}

static void    new_intersection(t_intersection *new_inter,
			 unsigned int color, t_list **inter, float k)
{
  new_inter = xmalloc(sizeof(t_intersection));
  new_inter->distance = k;
  new_inter->color = color;
  add_sort(inter, new_inter);
}

void	calc_k(t_list **inter, t_intersection *new_inter, unsigned int color, t_res calc, float delta)
{
  float	k;

  k = 0;
  if ((k = (-calc.b + sqrtf(delta)) / (2 * calc.a)) > 1.3)
    new_intersection(new_inter, color, inter, k);
}

void	inter_sphere(t_list **inter, void *object, t_cam cam)
{
  t_intersection	*new_inter;
  t_sphere		*sphere;
  t_res			calc;
  float			delta;

  new_inter = NULL;
  sphere = (t_sphere*)object;
  cam.position.x -= sphere->position.x;
  cam.position.y -= sphere->position.y;
  cam.position.z -= sphere->position.z;
  calc.a = POW(cam.vecteur_cam.x) + POW(cam.vecteur_cam.y) + POW(cam.vecteur_cam.z);
  calc.b = 2 * ((cam.position.x * cam.vecteur_cam.x) + (cam.position.y * cam.vecteur_cam.y) + (cam.position.z * cam.vecteur_cam.z));
  calc.c = POW(cam.position.x) + POW(cam.position.y) + POW(cam.position.z) - POW(sphere->rayon);
  if ((delta = POW(calc.b) - 4 * calc.a * calc.c) >= 0)
    calc_k(inter, new_inter, sphere->color, calc, delta);
}

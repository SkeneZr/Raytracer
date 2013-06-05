/*
** plan.c for plan in /home/roulle_a//afs/local/projets_group/Raytracer/src
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Mon May 27 14:44:46 2013 alban roulle
** Last update Mon Jun  3 17:57:33 2013 alban roulle
*/

#include "../include/intersection.h"
#include "../include/plan.h"
#include "../include/my.h"

void    *init_plan(t_plan *plan, const char *arg)
{
  t_vec         position;
  unsigned int  color;

  if (sscanf(arg, "plan %f %f %f %X", &position.x, &position.y, &position.z, &color) == 4)
    {
      printf("plan %f %f %f %X\n", position.x, position.y, position.z, color);
      plan = xmalloc(sizeof(t_plan));
      plan->position.x = position.x;
      plan->position.y = position.y;
      plan->position.z = position.z;
      plan->color = color;
      return (plan);
    }
  printf("plan %f %f %f %X\n", position.x, position.y, position.z, color);
  return (NULL);
}

static void    new_intersection(t_intersection *new_inter,
                         t_plan *plan, t_list **inter, float k)
{
  new_inter = xmalloc(sizeof(t_intersection));
  new_inter->distance = k;
  new_inter->color = plan->color;
  add_sort(inter, new_inter);
}

void    inter_plan(t_list **inter, void *object, t_cam cam)
{
  t_intersection        *new_inter;
  t_plan		*plan;
  t_vec                 calc;
  float                 k;
  float                 delta;

  new_inter = NULL;
  plan = (t_plan*)object;
  cam.position.x -= plan->position.x;
  cam.position.y -= plan->position.y;
  cam.position.z -= plan->position.z;
  calc.x = POW(cam.vecteur_cam.x) + POW(cam.vecteur_cam.y) + POW(cam.vecteur_cam.z);
  calc.y = 2 * ((cam.position.x * cam.vecteur_cam.x) + (cam.position.y * cam.vecteur_cam.y) 
		+ (cam.position.z * cam.vecteur_cam.z));
  calc.z = POW(cam.position.x) + POW(cam.position.y) + POW(cam.position.z);
  if ((delta = POW(calc.y) - 4 * calc.x * calc.z) >= 0)
    {
      if ((k = (-calc.y - sqrtf(delta)) / (2.0f * calc.x)) > 1.3f)
        new_intersection(new_inter, plan, inter, k);
      if ((k = (-calc.y + sqrtf(delta)) / (2.0f * calc.x)) > 1.3f)
        new_intersection(new_inter, plan, inter, k);
    }
}

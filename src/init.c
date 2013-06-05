/*
** init.c for init in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:43:58 2013 alban roulle
** Last update Mon Jun  3 17:56:05 2013 alban roulle
*/

#include "../include/event.h"
#include "../include/sphere.h"
#include "../include/plan.h"
#include "../include/env.h"
#include "../include/my.h"

static t_function	functions[MAX] =
  {
    {"sphere", init_sphere, inter_sphere}
  };

void	init(t_env *raytracer, const char *file)
{
  int	i;

  i = -1;
  while (++i < MAX)
    raytracer->objects[i] = NULL;
  init_object(raytracer, file);
  raytracer->mlx_ptr = mlx_init();
  raytracer->win_ptr = mlx_new_window(raytracer->mlx_ptr, WIDTH, HEIGHT, "RAYTRACER");
  mlx_clear_window(raytracer->mlx_ptr, raytracer->win_ptr);
  raytracer->screen = create_new_image(raytracer->mlx_ptr, WIDTH, HEIGHT);
  mlx_key_hook(raytracer->win_ptr, key_hook, raytracer);
  mlx_expose_hook(raytracer->win_ptr, expose_hook, raytracer);
}

void	init_object(t_env *raytracer, const char *file)
{
  int	elem;
  char	*tmp;
  int	i;

  elem = xopen(file, O_RDONLY);
  while ((tmp = get_next_line(elem)))
    {
      i = -1;
      while (++i < MAX && my_strncmp(tmp, functions[i].object_name, my_strlen(functions[i].object_name)) != 1);
      if (i < MAX)
	push_front(&(raytracer->objects[i]), (*(functions[i].init_func))(tmp));
      else if (my_strncmp(tmp, "camera", 6) != 0)
	init_cam(&raytracer->camera, tmp);
      else if (my_strncmp(tmp, "plan", 4) != 0)
	init_plan(&raytracer->plan, tmp);
      printf("%s\n", tmp);
    }
}

unsigned int	calc(t_env *raytracer, int x, int y)
{
  int		i;
  unsigned int	color;
  t_list	*object;
  t_list	*inter;

  color = 0;
  inter = NULL;
  calc_vecteur_cam(&raytracer->camera, x, y);
  i = -1;
  while (++i < MAX)
    {
      object = raytracer->objects[i];
      while (object != NULL)
	{
	  (*(functions[i].inter_func))(&inter, object->data, raytracer->camera);
	  object = object->next;
	}
    }
  if (inter != NULL)
    color = ((t_intersection*)(inter->data))->color;
  free_list(&inter);
  return (mlx_get_color_value(raytracer->mlx_ptr, color));
}

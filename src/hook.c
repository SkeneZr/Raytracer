/*
** hook.c for hook in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:43:32 2013 alban roulle
** Last update Fri May 10 22:20:46 2013 alban roulle
*/

#include "mlx.h"

#include "../include/env.h"
#include "../include/event.h"

int	expose_hook(void *param)
{
  t_env	*raytracer;

  raytracer = (t_env*)param;
  mlx_put_image_to_window(raytracer->mlx_ptr,
			  raytracer->win_ptr, raytracer->screen.img_ptr, 0, 0);
  return (0);
}

int	key_hook(int keycode, void *param)
{
  t_env	*raytracer;

  raytracer = (t_env*)param;
  if (keycode == ESCAPE)
    {
      mlx_destroy_window(raytracer->mlx_ptr, raytracer->win_ptr);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

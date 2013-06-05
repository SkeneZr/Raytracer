/*
** fill_img.c for fill_img in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  8 12:28:37 2013 alban roulle
** Last update Mon May 13 17:54:38 2013 alban roulle
*/

#include "../include/env.h"
#include "../include/my.h"

void    fill_img(t_env *raytracer)
{
  int   x;
  int   y;

  y = 0;
  while (y < HEIGHT)
    {
      x = 0;
      while (x++ < WIDTH)
        put_pixel_to_image(&raytracer->screen, x, y, calc(raytracer, x, y));
      ++y;
    }
  mlx_put_image_to_window(raytracer->mlx_ptr, raytracer->win_ptr, raytracer->screen.img_ptr, 0, 0);
}

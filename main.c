/*
** main.c for main in /home/roulle_a//afs/local/projets_group/Raytracer
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:33:45 2013 alban roulle
** Last update Wed May 29 18:53:56 2013 alban roulle
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "include/env.h"
#include "include/my.h"

int	main(int ac, char **av)
{
  t_env	raytracer;

  if (ac != 2)
    {

      my_putstr("Usage: Raytracer conf.txt\n");
      return (EXIT_FAILURE);
    }
  init(&raytracer, av[1]);
  fill_img(&raytracer);
  mlx_loop(raytracer.mlx_ptr);
  return (0);
}

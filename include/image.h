/*
** image.h for image in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 11:51:47 2013 alban roulle
** Last update Mon May 13 17:36:42 2013 alban roulle
*/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct	s_img
{
  unsigned int	width;
  unsigned int	height;
  int		opp;
  int		size_line;
  int		endian;
  void		*img_ptr;
  char		*data;
}		t_img;

t_img	create_new_image(void *mlx_ptr, int width, int height);
void	put_pixel_to_image(t_img *img, unsigned int x, unsigned int y, unsigned int color);

#endif /*__IMAGE_H__*/

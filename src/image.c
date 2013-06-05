/*
** image.c for image in /home/roulle_a//afs/local/projets_group/Raytracer/fonction
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 15:58:43 2013 alban roulle
** Last update Tue May 14 17:29:49 2013 alban roulle
*/

#include "../include/image.h"

t_img	create_new_image(void *mlx_ptr, int width, int height)
{
  t_img	img;

  img.img_ptr = mlx_new_image(mlx_ptr, width, height);
  img.width = width;
  img.height = height;
  img.data = mlx_get_data_addr(img.img_ptr, &img.opp, &img.size_line, &img.endian);
  img.opp /= 8;
  return (img);
}

void	put_pixel_to_image(t_img *img, unsigned int x, unsigned int y, unsigned int color)
{
  int	i;
  int	position;

  i = 0;
  if (x < img->width || y < img->height)
    {
      position = y * img->size_line + x * img->opp - 1;
      while (i < img->opp)
	{
	  if (!img->endian)
	    img->data[position + i + 1] = (color >> (i * 8)) & 0xFF;
	  else
	    img->data[position + img->opp - i] = (color >> (i * 8)) & 0xFF;
	  ++i;
	}
    }
}

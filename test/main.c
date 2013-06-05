/*
** main.c for main.c in /home/roulle_a//afs/local/projets_group/Raytracer/test
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Thu May 30 10:47:19 2013 alban roulle
** Last update Mon Jun  3 17:52:41 2013 alban roulle
*/

#include "rt.h"

int     expose_hook(void *param)
{
  t_env *rt;

  rt = (t_env*)param;
  mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img.img_ptr, 0, 0);
  return (0);
}

int     key_hook(int keycode, void *param)
{
  t_env *rt;

  rt = (t_env*)param;
  if (keycode == ESCAPE)
    {
      mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

t_img   create_new_image(void *mlx_ptr, int width, int height)
{
  t_img img;

  img.img_ptr = mlx_new_image(mlx_ptr, width, height);
  img.width = width;
  img.height = height;
  img.data = mlx_get_data_addr(img.img_ptr, &img.opp, &img.size_line, &img.endian);
  img.opp /= 8;
  return (img);
}

void    free_objects(char **data, char *tmp)
{
  int i;

  i = 0;
  while (data[i] != NULL)
    {
      free(data[i]);
      i++;
    }
  free(data);
  free(tmp);
}

void	init_objects(const char *fd, t_env *rt)
{
  int	elem;
  int	i;
  char	*tmp;
  char	**data;

  list = NULL;
  elem = open(fd, O_RDONLY);
  data = malloc(sizeof(char *) * 1024);
  while ((tmp = get_next_line(elem)))
    {
      i = 0;
      data = my_str_to_wordtab(tmp);
      while (data[i])
	{
	  if (my_strncmp(data[i], "camera", 5) == 0)
	    rt->cam = init_cam(data[i]);
	  if (my_strncmp(data[i], "sphere", 6) == 0)
	    rt->sphere = init_sphere(data[i]);
	  if (my_strncmp(data[i], "plan", 4) == 0)
            rt->plan = init_plan(data[i]);
	  i++;
	}
      free_objects(data, tmp);
      my_put_in_list(&list, &objects);
    }
  my_show_list(list);
  return (0);
}

void	init_rt(const char *fd, t_env *rt)
{
  unsigned int	width;
  unsigned int	height;

  width = 800;
  height = 600;
  init_objects(fd, rt);
  rt->mlx_ptr = mlx_init();
  rt->win_ptr = mlx_new_window(rt->mlx_ptr, width, height, "RAYTRACER");
  rt->img = create_new_image(rt->mlx_ptr, width, height);
  mlx_key_hook(rt->win_ptr, key_hook, rt);
  mlx_expose_hook(rt->win_ptr, expose_hook, rt);
}

int	main(int ac, char **av)
{
  t_env	rt;

  if (ac != 2)
    {
      printf("Usage = ./rt conf.txt\n");
      return (EXIT_FAILURE);
    }
  init_rt(av[1], &rt);
  return (0);
}

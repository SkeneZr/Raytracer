/*
** rt.h for rt in /home/roulle_a//afs/local/projets_group/Raytracer/test
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Thu May 30 11:01:36 2013 alban roulle
** Last update Mon Jun  3 15:37:51 2013 alban roulle
*/

#ifndef _ENV_H_
#define _ENV_H_

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <string.h>

#include "mlx.h"

#define MEM_SIZE	1024
#define ESCAPE		65307

typedef struct  s_img
{
  unsigned int  width;
  unsigned int  height;
  int           opp;
  int           size_line;
  int           endian;
  void          *img_ptr;
  char          *data;
}               t_img;

typedef struct  s_node
{
  char          *data;
  struct s_node	*next;
  struct s_node	*prev;
}               t_node;

typedef struct	s_list
{
  size_t        length;
  t_node	*start;
  t_node	*end;
}		t_list;

typedef struct  s_env
{
  void          *mlx_ptr;
  void          *win_ptr;
  t_img         img;
  t_sphere	*sphere;
  t_cam		*cam;
  t_plan	*plan;
}               t_env;

void            init(t_env *raytracer, const char *file);
void            init_object(t_env *raytracer, const char *file);

/*LIB*/
char    *my_strdup(char *src);
char    **my_str_to_wordtab(char *str);
char    *get_next_line(const int fd);
void    fill_list(t_list *objects, char **data);

#endif    /*__ENV_H__*/


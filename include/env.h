/*
** raytracer.h for raytracer in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Wed May  1 18:40:57 2013 alban roulle
** Last update Thu May 30 10:35:07 2013 alban roulle
*/

#ifndef _ENV_H_
#define _ENV_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mlx.h"

#include "list.h"
#include "image.h"
#include "cam.h"
#include "plan.h"

#define WIDTH		1024
#define	HEIGHT		768
#define	BUFFSIZE	512

typedef enum	e_type
{
  SPHERE,
  MAX
}		t_type;

typedef struct  s_env
{
  void          *mlx_ptr;
  void          *win_ptr;
  t_img         screen;
  t_cam		camera;
  t_list	*objects[MAX];
  t_plan	plan;
}               t_env;

typedef struct    s_function
{
  char		*object_name;
  void          *(*init_func)(const char *);
  void          (*inter_func)(t_list **, void *, t_cam);
}               t_function;

void		init(t_env *raytracer, const char *file);
void            init_object(t_env *raytracer, const char *file);
void            fill_img(t_env *raytracer);
unsigned int    calc(t_env *raytracer, int x, int y);

#endif    /*__ENV_H__*/

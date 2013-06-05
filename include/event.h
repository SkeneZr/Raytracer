/*
** event.h for event in /home/roulle_a//afs/local/projets_group/Raytracer/include
** 
** Made by alban roulle
** Login   <roulle_a@epitech.net>
** 
** Started on  Fri May  3 13:53:56 2013 alban roulle
** Last update Thu May  9 18:15:21 2013 alban roulle
*/

#ifndef _EVENT_H_
#define	_EVENT_H_

#include <stdlib.h>

#define	ESCAPE	65307

int	expose_hook(void *param);
int	key_hook(int keycode, void *param);

#endif	/*__EVENT_H__*/

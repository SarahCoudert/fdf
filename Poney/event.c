/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:22:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/12 18:03:48 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
/*
   static int		aux(t_sdl *sdl)
   {
   int		speed;

   speed = 10;
   speed_x = 0;

   if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
   return (0);
   if (sdl->event.key.keysym.sym == SDLK_q)
   return (0);
   if (sdl->event.key.keysym.sym == SDLK_RIGHT)
//		if (sdl->pos_poney.x + PONEY_LAR <= WIDTH_SCREEN)
{
if (KEY_DOWN )
speed_x_avant = speed;
if (KEY_UP)
speed_x_avant = 0;
}
if (sdl->event.key.keysym.sym == SDLK_LEFT)
if (sdl->pos_poney.x >= 0)
sdl->pos_poney.x -= speed;
if (sdl->event.key.keysym.sym == SDLK_UP)
if (sdl->pos_poney.y >= 0)
sdl->pos_poney.y -= speed;
if (sdl->event.key.keysym.sym == SDLK_DOWN)
if (sdl->pos_poney.y + PONEY_HAU <= HEIGHT_SCREEN)
sdl->pos_poney.y += speed;
if (speed_x != 0)
i++;
sdl->pos_poney.x += speed_x_avant + speed_x_arrier;
sdl->pos_poney.y += speed_y;
return (1);
}*/
static int		aux(t_sdl *sdl)
{
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)// press escape quit the game
		return (0);
	if (sdl->event.key.keysym.sym == SDLK_q)// pressing q too
		return (0);
	if (sdl->event.key.keysym.sym == SDLK_RIGHT)// move poney to the right
		if (sdl->pos_poney.x + 7 <= WIDTH_SCREEN)
			sdl->pos_poney.x += 7;//				we move 3px by 3px to make it faster
	if (sdl->event.key.keysym.sym == SDLK_LEFT)// to the left
		if (sdl->pos_poney.x - 7 >= 0)
			sdl->pos_poney.x -= 7;
	if (sdl->event.key.keysym.sym == SDLK_UP) 		//to the top
		if (sdl->pos_poney.y - 7 >= 0)
			sdl->pos_poney.y -= 7;
	if (sdl->event.key.keysym.sym == SDLK_DOWN)//to		 the bottom
		if (sdl->pos_poney.y + 7 <= HEIGHT_SCREEN)
			sdl->pos_poney.y += 7;
	return (1);
}

void			loop(t_sdl sdl)
{
		int		continuer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	continuer = 1;
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.type)
			{
				if (sdl.event.type == SDL_QUIT)
					continuer = 0;
				else if (sdl.event.type == SDL_KEYDOWN)
					continuer = aux(&sdl);
				i++;
				if (i % 4 == 1)
				{
					sdl.poney = sdl.sprite[j];
					if (j < 6)
						j++;
					else
						j = 0;
				}
			}
			else
				sdl.poney = sdl.sprite[7];
		}
			sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
			sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
			sdl_flip(sdl.screen);
	}
}

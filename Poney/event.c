/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:22:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/12 20:12:10 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		aux(t_sdl *sdl, Uint8 *keystate)
{
	if (keystate[SDLK_ESCAPE])// press escape quit the game
		return (0);
	if (keystate[SDLK_q])// pressing q too
		return (0);
	if (keystate[SDLK_RIGHT])// move poney to the right
	{
		if (sdl->pos_poney.x + 7 <= WIDTH_SCREEN)
			sdl->pos_poney.x += 7;				//we move 3px by 3px to make it faster
	}
	if (keystate[SDLK_LEFT])// to the left
		if (sdl->pos_poney.x - 7 >= 0)
			sdl->pos_poney.x -= 7;
	if (keystate[SDLK_UP]) 		//to the top
	{
		if (sdl->pos_poney.y - 7 >= 0)
			sdl->pos_poney.y -= 7;

	}
//	if (keystate[SDLK_DOWN])//to		 the bottom
//		if (sdl->pos_poney.y + 7 <= HEIGHT_SCREEN)
//			sdl->pos_poney.y += 7;
	return (1);
}

void			loop(t_sdl sdl)
{
	int		continuer;
	int		i;
	int		j;
	int		debut;
	Uint8	*keystate;

	debut = 1;
	j = 0;
	i = 0;
	continuer = 1;
	keystate = SDL_GetKeyState(NULL);
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.type)
			{
				if (sdl.event.type == SDL_QUIT)
					continuer = 0;
				else if (sdl.event.type == SDL_KEYDOWN)
					continuer = aux(&sdl, keystate);
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
		}
			if (debut)
				{
					sdl.poney = sdl.sprite[7];
					debut--;
				}
			sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
			sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
			sdl_flip(sdl.screen);
	}
}

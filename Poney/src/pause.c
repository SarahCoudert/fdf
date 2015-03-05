/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:16:02 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/05 09:51:33 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return 42 if "retry"
**
**
*/

#include "includes/game.h"

int		gameover(t_sdl *sdl)
{
	Uint8			*keystate;
	int				continuer;
	int				what_choice;
	SDL_Rect		pos_menu;
	SDL_Event		ev_men;
	SDL_Surface		*menu;

	what_choice = 0;
	continuer = 1;
	pos_menu.x = 0;
	pos_menu.y = 0;
	while (continuer)
	{
		menu = sdl->sprite[what_choice + 15];
		sdl_blit(menu, NULL, sdl->screen, &pos_menu);
		sdl_flip(sdl->screen);
		SDL_WaitEvent(&ev_men);
		keystate = SDL_GetKeyState(NULL);
		if (ev_men.type == SDL_QUIT)
			return (3);
		else if (ev_men.type == SDL_KEYDOWN)
		{
			if (keystate[SDLK_ESCAPE])
				return (42);
			if (keystate[SDLK_RIGHT])
			{
				if (what_choice < 3)
				{
					what_choice++;
				}
			}
			if (keystate[SDLK_LEFT])
			{
				if (what_choice > 0)
				{
					what_choice--;
				}
			}
			if (keystate[SDLK_RETURN] || keystate[SDLK_KP_ENTER])
			{
				if (what_choice == 1)
					return (0);
				if (what_choice == 2)
					return (42);
				if (what_choice == 3)
					return (3);
			}
		}
	}
	return (42);
}

int		titlescreen(t_sdl *sdl)
{
	int				i;
	Uint8			*keystate;
	int				continuer;
	SDL_Event		event;
	SDL_Color		rgb;
	TTF_Font		*font;
	SDL_Surface		*message[10];
	SDL_Rect		pos[3];
	int				what_choice;
	SDL_Color		choice;

	what_choice = 0;
	font = TTF_OpenFont("../img_src/font/BEBAS___.ttf", 30);
	continuer = 1;
	i = 0;
	pos[0].y = 170;
	pos[1].y = 170;
	pos[2].y = 170;
	pos[0].x = 300;
	pos[1].x = 460;
	pos[2].x = 580;
	choice.r = 60;
	choice.g = 210;
	choice.b = 220;
	rgb.r = 0;
	rgb.b = 0;
	rgb.g = 0;
	message[0] = TTF_RenderText_Solid(font, "Resume", rgb);
	message[3] = TTF_RenderText_Solid(font, "Resume", choice);
	message[1] = TTF_RenderText_Solid(font, "Menu", rgb);
	message[4] = TTF_RenderText_Solid(font, "Menu", choice);
	message[2] = TTF_RenderText_Solid(font, "Quit", rgb);
	message[5] = TTF_RenderText_Solid(font, "Quit", choice);
	while (continuer)
	{
		while (i != 3)
		{
			SDL_BlitSurface(message[i], NULL, sdl->screen, &pos[i]);
			i++;
		}
		i = 0;
		SDL_BlitSurface(message[what_choice + 3], NULL, sdl->screen, &pos[what_choice]);
		sdl_flip(sdl->screen);
		SDL_WaitEvent(&event);
		keystate = SDL_GetKeyState(NULL);
		if (event.type == SDL_QUIT)
			return (0);
		if (event.type == SDL_KEYDOWN)
		{
			if (keystate[SDLK_q])
				return (1);
			if (keystate[SDLK_ESCAPE])
				return (1);
			if (keystate[SDLK_LEFT] && what_choice > 0)
			{
				what_choice--;
			}
			if (keystate[SDLK_RIGHT] && what_choice < 2)
			{
				what_choice++;
			}
			if (keystate[SDLK_RETURN] || keystate[SDLK_KP_ENTER])
			{
				if (what_choice == 0)
					return (1);
				if (what_choice == 1)
					return (20);
				if (what_choice == 2)
					return (30);
			}
		}
	}
	return (0);
}

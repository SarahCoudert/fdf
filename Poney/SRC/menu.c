/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:35:47 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/17 18:29:26 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/game.h"

int			menu_sound(t_sdl *sdl, t_menu *menu)
{
	Uint8			*keystate;
	int				continuer;

	continuer = 1;
	menu->color.r = 255;
	menu->color.g = 255;
	menu->color.b = 255;
	menu->pos_menu.x = 0;
	menu->pos_menu.y = 0;
	while (continuer)
	{
		sdl_blit(menu->state[menu->what_choice], NULL, sdl->screen, &menu->pos_menu);
		sdl_flip(sdl->screen);
		SDL_WaitEvent(&menu->ev_cred);
		keystate = SDL_GetKeyState(NULL);
		if (menu->ev_cred.type == SDL_QUIT)
			return (3);
		else if (menu->ev_cred.type == SDL_KEYDOWN)
		{
			if (keystate[SDLK_LEFT] && menu->what_choice == 5)
				menu->what_choice = 6;
			if (keystate[SDLK_RIGHT] && menu->what_choice == 6)
				menu->what_choice = 5;
			if ((keystate[SDLK_RETURN] || keystate[SDLK_KP_ENTER]) && menu->what_choice == 6)
				return (42);
		}
	}
	return (1);
}

int			menu_credit(t_sdl *sdl, t_menu *menu)
{
	int				i;
	SDL_Event		event;
	Uint8			*keystate;
	int				continuer;
	SDL_Rect		mess;

	i = 4;
	mess.x = 0;
	mess.y = 0;
	continuer = 1;
	menu->pos_menu.x = 0;
	menu->pos_menu.y = 0;
	menu->what_choice = 7;
	while (continuer)
	{
		sdl_blit(menu->state[menu->what_choice], NULL, sdl->screen, &menu->pos_menu);
		sdl_blit(menu->message[i], NULL, sdl->screen, &mess);
		sdl_flip(sdl->screen);
		SDL_WaitEvent(&event);
		keystate = SDL_GetKeyState(NULL);
		if (event.type == SDL_QUIT)
			return (3);
		else if (event.type == SDL_KEYDOWN)
		{
			if (keystate[SDLK_q])
				return (3);
			if (keystate[SDLK_ESCAPE])
				return (3);
			if (keystate[SDLK_LEFT])
			{
				if (menu->what_choice == 7)
					i = 0;
				if (menu->what_choice == 8)
					i = 2;
			}
			if (keystate[SDLK_RIGHT])
			{
				if (menu->what_choice == 7)
					i = 1;
				if (menu->what_choice == 8)
					i = 3;
			}
			if (keystate[SDLK_RETURN] || keystate[SDLK_KP_ENTER])
			{
				if (i == 0 || i == 3)
					return (42);
				if (i == 1)
				{
					menu->what_choice = 8;
					i = 4;
				}
				if (i == 2)
				{
					menu->what_choice = 7;
					i = 4;
				}
			}
		}
	}
	return (3);
}

int			ft_menu(t_menu *menu, t_sdl *sdl)
{
	Uint8		*keystate;
	int			continuer;

	continuer = 1;
	menu->pos_menu.x = 0;
	menu->pos_menu.y = 0;
	menu->what_choice = 0;
	while (continuer)
	{
		menu->menu = menu->state[menu->what_choice];
		sdl_blit(menu->menu, NULL, sdl->screen, &menu->pos_menu);
		sdl_flip(sdl->screen);
		SDL_WaitEvent(&menu->ev_men);
		keystate = SDL_GetKeyState(NULL);
		if (menu->ev_men.type == SDL_QUIT)
			return (3);
		else if (menu->ev_men.type == SDL_KEYDOWN)
		{
			if (keystate[SDLK_ESCAPE])
				return (3);
			if (keystate[SDLK_q])
				return (3);
			if (keystate[SDLK_UP])
			{
				if (menu->what_choice > 1)
				{
					menu->what_choice--;
				}
			}
			if (keystate[SDLK_DOWN])
			{
				if (menu->what_choice < 4)
				{
					menu->what_choice++;
				}
			}
			if (keystate[SDLK_RETURN] || keystate[SDLK_KP_ENTER])
			{
				if (menu->what_choice - 1 == 0)
					return (menu->what_choice - 1);
				if (menu->what_choice - 1 == 1)
				{
					menu->what_choice = 5;
					return (1);
				}
				if (menu->what_choice - 1 == 2)
				{
					menu->what_choice = 7;
					return (2);
				}
				if (menu->what_choice - 1 == 3)
				{
					menu->what_choice = 0;
					return (3);
				}
			}
		}
	}
	return (42);
}

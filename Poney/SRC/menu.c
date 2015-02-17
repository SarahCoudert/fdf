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

int			ft_menu(t_menu *menu, t_sdl *sdl)
{
	Uint8		*keystate;

	keystate = SDL_GetKeyState(NULL);
	menu->pos_menu.x = 0;
	menu->pos_menu.y = 0;
	menu->what_choice = 0;
	menu->state[0] = img_load("../IMG_SRC/menu/menu.jpg");
	menu->state[1] = img_load("../IMG_SRC/menu/menuplay.jpg");
	menu->state[2] = img_load("../IMG_SRC/menu/menusound.jpg");
	menu->state[3] = img_load("../IMG_SRC/menu/menucredits.jpg");
	menu->state[4] = img_load("../IMG_SRC/menu/menuexit.jpg");
	if ((menu->menu = menu->state[0]) == NULL)
	{
		ft_putendl_fd("Error : Cannot load menu", 2);
		return (0);
	}
	sdl_blit(menu->menu, NULL, sdl->screen, &menu->pos_menu);
	sdl_flip(sdl->screen);
	if (sdl->event.type == SDL_QUIT)
		return (3);
	else if (menu->ev_men.type == SDL_KEYDOWN)
	{
		if (keystate[SDLK_q])
			return (3);
		if (keystate[SDLK_UP])
			if (menu->what_choice < 4)
				menu->what_choice++;
		if (keystate[SDLK_DOWN])
			if (menu->what_choice > 0)
				menu->what_choice--;
		menu->menu = menu->state[menu->what_choice];
	sdl_blit(menu->menu, NULL, sdl->screen, &menu->pos_menu);
	sdl_flip(sdl->screen);
	}
	return (42);
}

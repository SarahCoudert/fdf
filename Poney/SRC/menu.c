/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:35:47 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/17 17:34:56 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/game.h"

int			ft_menu(t_menu *menu, t_sdl *sdl)
{
	menu->pos_menu.x = 0;
	menu->pos_menu.y = 0;
	if ((menu->menu = img_load("../IMG_SRC/menu.jpg")) == NULL)
	{
		ft_putendl_fd("Error : Cannot load menu", 2);
		return (3);
	}
	sdl_blit(menu->menu, NULL, sdl->screen, &menu->pos_menu);
	sdl_flip(sdl->screen);
	if (menu->ev_men == )
	return (3);
}

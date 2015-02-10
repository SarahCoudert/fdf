/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/09 18:34:42 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "libft/includes/libft.h"
#include <unistd.h>

#define HEIGHT_SCREEN		640
#define WIDTH_SCREEN		480
#define COLOR				32

void		ft_pause(void)
{
	int		continuer;
	SDL_Event		event;

	continuer = 1;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		if (event.type)
			if (event.type == SDL_QUIT)
				continuer = 0;
	}
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	SDL_Surface *screen;
	SDL_Surface *bg;
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	bg = NULL;
	screen = NULL;
	if ((SDL_Init(SDL_INIT_VIDEO)) == (-1))
	{
		ft_putendl("SDL_Init error.");
		return (-1);
		}
	(SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL));
	screen = SDL_SetVideoMode(HEIGHT_SCREEN, WIDTH_SCREEN, COLOR, SDL_HWSURFACE);
	if (screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	SDL_WM_SetCaption("Horsemen of the Appocalypse", NULL);
	if ((bg = SDL_LoadBMP("HD-Grass-Wallpapers.bmp")) == NULL)
		ft_putendl_fd("Error : Cannot charge background image", 2);
	SDL_BlitSurface(bg, NULL, screen, &rect);
	SDL_Flip(screen);
	ft_pause();
	SDL_Quit();
	return (0);
}

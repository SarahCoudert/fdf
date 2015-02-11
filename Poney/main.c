/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/11 11:43:13 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "libft/includes/libft.h"
#include <unistd.h>

#define HEIGHT_SCREEN		480
#define WIDTH_SCREEN		1280
#define COLOR				32

int		main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	int				continuer;
	SDL_Surface		*screen;
	SDL_Surface		*bg;
	SDL_Surface		*poney;
	SDL_Rect		rect;
	SDL_Rect		pos_poney;
	SDL_Event		event;
	int				i;

	i = 0;
	continuer = 1;
	pos_poney.x = 30;
	pos_poney.y = 210;
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
	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Flip(screen);
	if (screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	SDL_WM_SetCaption("Horsemen of the Appocalypse", NULL);
	if ((bg = SDL_LoadBMP("HD-Grass-Wallpapers.bmp")) == NULL)
		ft_putendl_fd("Error : Cannot charge background image", 2);

	SDL_BlitSurface(bg, NULL, screen, &rect);
	if ((poney = SDL_LoadBMP("chevalbmp.bmp")) == NULL)
		ft_putendl_fd("Error : Cannot charge horse image", 2);

	SDL_SetColorKey(poney, SDL_SRCCOLORKEY, SDL_MapRGB(poney->format, 255, 255, 255));

	SDL_BlitSurface(poney, NULL, screen, &pos_poney);
	SDL_EnableKeyRepeat(10, 10);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		if (event.type)
		{
			if (event.type == SDL_QUIT)
			{
				continuer = 0;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)	// press escape quit the game
					continuer = 0;
				if (event.key.keysym.sym == SDLK_q)			// pressing q too
					continuer = 0;
				if (event.key.keysym.sym == SDLK_RIGHT)		// move poney to the right
					if (pos_poney.x + 80 <= WIDTH_SCREEN)
						pos_poney.x += 3;					//we move 3px by 3px to make it faster
				if (event.key.keysym.sym == SDLK_LEFT)		// to the left
					if (pos_poney.x - 3 >= 0)
						pos_poney.x -= 3;
				if (event.key.keysym.sym == SDLK_UP) 		//to the top
					if (pos_poney.y - 3 >= 0)
						pos_poney.y -= 3;
				if (event.key.keysym.sym == SDLK_DOWN)		//to the bottom
					if (pos_poney.y + 75 <= HEIGHT_SCREEN)
						pos_poney.y += 3;
				i++;
			}
			else
				continuer = 1;
		}
		if (i % 8 == 1)
			SDL_BlitSurface(bg, NULL, screen, &rect);
		SDL_BlitSurface(poney, NULL, screen, &pos_poney);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(bg);
	SDL_FreeSurface(poney);
	SDL_Quit();
	return (0);
}

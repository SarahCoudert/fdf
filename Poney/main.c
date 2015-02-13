/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/13 16:55:05 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	sprite_init		(t_sdl *sdl)
{
	sdl->sprite[0] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-00.png");
	sdl->sprite[1] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-01.png");
	sdl->sprite[2] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-02.png");
	sdl->sprite[3] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-03.png");
	sdl->sprite[4] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-04.png");
	sdl->sprite[5] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-05.png");
	sdl->sprite[6] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/horse-run-black-06.png");
	sdl->sprite[7] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/Black-horse-00.png");
	sdl->sprite[8] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-00.png");
	sdl->sprite[9] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-01.png");
	sdl->sprite[10] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-02.png");
	sdl->sprite[11] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-03.png");
	sdl->sprite[12] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-04.png");
	sdl->sprite[13] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-05.png");
	sdl->sprite[14] = img_load("IMG_SRC/HorseofSpringAssets/Sprite/Black Horse/B-H-J-06.png");
}

int		main(int ac, char **av)
{
	t_sdl			sdl;
	
	(void)ac;
	(void)**av;
	sdl.pos_poney.x = 50;
	sdl.pos_poney.y = 220;
	sdl.rect.x = 0;
	sdl.rect.y = 0;
	sdl.jumpstate = 0;
	sdl.plane = 0;
	sdl.n = 0;
	sdl.bg = NULL;
	sdl.screen = NULL;
	sprite_init(&sdl);
	if ((sdl_init(SDL_INIT_VIDEO)) == (-1))
	{
		ft_putendl_fd("SDL_Init error.", 2);
		return (-1);
	}
	(sdl_seticon(sdl_bmp("sdl_icone.bmp"), NULL));
	sdl.screen = sdl_videomode(WIDTH_SCREEN, HEIGHT_SCREEN,
			COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (sdl.screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	sdl_caption("Horsemen of the Appocalypse", NULL);
	if ((sdl.bg = img_load("arbres.jpg")) == NULL)
		ft_putendl_fd("Error : Cannot charge background image", 2);
	sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
	if ((sdl.poney = img_load("Black-horse-00.png")) == NULL)
		ft_putendl_fd("Error : Cannot charge horse image", 2);
	sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
	sdl_keyrepeat(10, 10);
	sdl_flip(sdl.screen);
	loop(sdl);
	sdl_freesurface(sdl.bg);
	sdl_freesurface(sdl.poney);
	sdl_quit();
	return (0);
}

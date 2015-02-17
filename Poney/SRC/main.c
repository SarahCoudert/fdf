/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/17 18:29:23 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/game.h"

void	sprite_init		(t_sdl *sdl)
{
	sdl->sprite[0] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-00.png");
	sdl->sprite[1] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-01.png");
	sdl->sprite[2] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-02.png");
	sdl->sprite[3] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-03.png");
	sdl->sprite[4] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-04.png");
	sdl->sprite[5] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-05.png");
	sdl->sprite[6] = img_load("../IMG_SRC/Sprite/Black Horse/horse-run-black-06.png");
	sdl->sprite[7] = img_load("../IMG_SRC/Sprite/Black Horse/Black-horse-00.png");
	sdl->sprite[8] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-00.png");
	sdl->sprite[9] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-01.png");
	sdl->sprite[10] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-02.png");
	sdl->sprite[11] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-03.png");
	sdl->sprite[12] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-04.png");
	sdl->sprite[13] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-05.png");
	sdl->sprite[14] = img_load("../IMG_SRC/Sprite/Black Horse/B-H-J-06.png");
}

int		main(int ac, char **av)
{
	t_sdl			sdl;
	t_menu			menu;
	int				choice;

	choice = 0;
	sdl.pos_poney.x = 50;
	sdl.pos_poney.y = 220;
	sdl.rect.x = 0;
	sdl.rect.y = 0;
	sdl.bgx = 0;
	sdl.jumpstate = 0;
	sdl.plane = 0;
	sdl.n = 0;
	sdl.bg = NULL;
	sdl.screen = NULL;
	sdl.tempbg1.y = 0;
	sdl.tempbg1.x = 0;
	sdl.time_since_begin = 0;
	sdl.prev_time = 0;
	menu.is_menu = 1;
	(void)ac;
	(void)**av;
	sprite_init(&sdl);
	if ((sdl_init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) == (-1))
	{
		ft_putendl_fd("SDL_Init error.", 2);
		return (-1);
	}
	(sdl_seticon(sdl_bmp("sdl_icone.bmp"), NULL));
	sdl.screen = sdl_videomode(WIDTH_SCREEN, HEIGHT_SCREEN,
			COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
		ft_putendl_fd("Error : Cannot load music", 2);
	sdl.music = Mix_LoadMUS("../SOUNDS_SRC/QueenOfTheNight.wav");
	if (sdl.music == NULL)
		ft_putendl_fd("Error : Cannot load music", 2);
	if (sdl.screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	sdl_caption("Horsemen of the Appocalypse", NULL);
	while (menu.is_menu)
	{
			choice = ft_menu(&menu, &sdl);
		SDL_WaitEvent(&menu.ev_men);
		{
			choice = ft_menu(&menu, &sdl);
			if (choice == 3)
				return (0);
			if (choice == 0)
			{
				menu.is_menu = 0;
				if ((sdl.bg = img_load("../IMG_SRC/arbres.png")) == NULL)
					ft_putendl_fd("Error : Cannot charge background image", 2);
				sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
				if ((sdl.poney = img_load("../IMG_SRC/Sprite/Black Horse/Black-horse-00.png")) == NULL)
					ft_putendl_fd("Error : Cannot charge horse image", 2);
				sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
				sdl_keyrepeat(10, 10);
				sdl_flip(sdl.screen);
				loop(sdl);
			}
			if (choice == 42)
				menu.is_menu = 1;
		}
	}
	Mix_CloseAudio();
	sdl_freesurface(sdl.bg);
	sdl_freesurface(sdl.poney);
	sdl_quit();
	return (0);
}

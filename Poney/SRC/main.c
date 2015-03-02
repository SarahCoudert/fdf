/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/02 12:11:43 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"

void		sprite_init(t_sdl *sdl, t_menu *menu, t_bad *bad)
{
	sdl->sprite[0] = img_load("../img_src/sprite/Black Horse/horse-run-black-00.png");
	sdl->sprite[1] = img_load("../img_src/sprite/Black Horse/horse-run-black-01.png");
	sdl->sprite[2] = img_load("../img_src/sprite/Black Horse/horse-run-black-02.png");
	sdl->sprite[3] = img_load("../img_src/sprite/Black Horse/horse-run-black-03.png");
	sdl->sprite[4] = img_load("../img_src/sprite/Black Horse/horse-run-black-04.png");
	sdl->sprite[5] = img_load("../img_src/sprite/Black Horse/horse-run-black-05.png");
	sdl->sprite[6] = img_load("../img_src/sprite/Black Horse/horse-run-black-06.png");
	sdl->sprite[7] = img_load("../img_src/sprite/Black Horse/Black-horse-00.png");
	sdl->sprite[8] = img_load("../img_src/sprite/Black Horse/B-H-J-00.png");
	sdl->sprite[9] = img_load("../img_src/sprite/Black Horse/B-H-J-01.png");
	sdl->sprite[10] = img_load("../img_src/sprite/Black Horse/B-H-J-02.png");
	sdl->sprite[11] = img_load("../img_src/sprite/Black Horse/B-H-J-03.png");
	sdl->sprite[12] = img_load("../img_src/sprite/Black Horse/B-H-J-04.png");
	sdl->sprite[13] = img_load("../img_src/sprite/Black Horse/B-H-J-05.png");
	sdl->sprite[14] = img_load("../img_src/sprite/Black Horse/B-H-J-06.png");
	menu->state[0] = img_load("../img_src/menu/menu.jpg");
	menu->state[1] = img_load("../img_src/menu/menuplay.jpg");
	menu->state[2] = img_load("../img_src/menu/menusound.jpg");
	menu->state[3] = img_load("../img_src/menu/menucredits.jpg");
	menu->state[4] = img_load("../img_src/menu/menuexit.jpg");
	menu->state[5] = img_load("../img_src/menu/sound-page.png");
	menu->state[6] = img_load("../img_src/menu/sound-page-choice.png");
	menu->state[7] = img_load("../img_src/menu/credit page.png");
	menu->state[8] = img_load("../img_src/menu/credit page-choice2.png");
	menu->size[0] = 19;
	menu->size[1] = 19;
	menu->size[2] = 20;
	menu->size[3] = 20;
	menu->size[4] = 17;
	menu->words[0] = "Return to menu";
	menu->words[1] = "Next";
	menu->words[2] = "Previous";
	menu->words[3] = "Menu";
	menu->words[4] = "   ";
	bad->sprite[0] = img_load("../img_src/sprite/ennemy/Box.png");
	bad->sprite[1] = img_load("../img_src/sprite/ennemy/box01.png");
	bad->sprite[2] = img_load("../img_src/sprite/ennemy/box02.png");
	bad->sprite[3] = img_load("../img_src/sprite/ennemy/box03.png");
	bad->sprite[4] = img_load("../img_src/sprite/ennemy/box04.png");
	bad->sprite[5] = img_load("../img_src/sprite/ennemy/box05.png");
	bad->sprite[6] = img_load("../img_src/sprite/ennemy/box06.png");
	bad->sprite[7] = img_load("../img_src/sprite/ennemy/box07.png");
	sdl->messages[0] = "GAME OVER";
	sdl->messages[1] = "Retry";
	sdl->messages[2] = "Menu";
	sdl->messages[2] = "Quit";
}

int		main(int ac, char **av)
{
	t_sdl			sdl;
	t_menu			menu;
	t_bad			bad;
	int				choice;
	int				i;
	SDL_Color		rgb;

	rgb.r = 225;
	rgb.g = 225;
	rgb.b = 225;
	sdl.pos_poney.x = 50;
	sdl.pos_poney.y = 220;
	bad.pos_bad.x = 1200;
	bad.pos_bad.y = 240;
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
	menu.what_choice = 0;
	menu.is_menu = 1;
	choice = 42;
	i = 0;
	(void)ac;
	(void)**av;
	sprite_init(&sdl, &menu, &bad);
	if ((sdl_init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) == (-1))
	{
		ft_putendl_fd("SDL_Init error.", 2);
		return (-1);
	}
	sdl.screen = sdl_videomode(WIDTH_SCREEN, HEIGHT_SCREEN,
			COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (TTF_Init() == -1)
		ft_putendl_fd("Error : Cannot load font", 2);
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
		ft_putendl_fd("Error : Cannot load music", 2);
	sdl.music = Mix_LoadMUS("../sounds_src/QueenOfTheNight.wav");
	if (sdl.music == NULL)
		ft_putendl_fd("Error : Cannot load music", 2);
	if (sdl.screen == NULL)
		ft_putendl_fd("Error : Cannot load video", 2);
	sdl_caption("Horsemen of the Appocalypse", NULL);
	while (i <= 4)
	{
	//	sdl.font[i] = TTF_OpenFont("../img_src/fonts/Quicksand-Bold.ttf", sdl.size[i]);
		menu.font[i] = TTF_OpenFont("../img_src/fonts/Quicksand-Bold.ttf", menu.size[i]);
	//	sdl.text[i] = TTF_RenderText_Solid(menu.font[i], sdl.messages[i] , rgb);
		menu.message[i] = TTF_RenderText_Solid(menu.font[i], menu.words[i], rgb);
		i++;
	}
	while (menu.is_menu)
	{
		if (choice == 42)
		{
			choice = ft_menu(&menu, &sdl);
		}
		if (choice == 3)
			return (0);
		if (choice == 0)
		{
			menu.is_menu = 0;
			if ((sdl.bg = img_load("../img_src/sprite/background/arbres.png")) == NULL)
				ft_putendl_fd("Error : Cannot charge background image", 2);
			sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
			if ((sdl.poney = img_load("../img_src/sprite/Black Horse/Black-horse-00.png")) == NULL)
				ft_putendl_fd("Error : Cannot charge horse image", 2);
			sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
			sdl_flip(sdl.screen);
			loop(sdl, bad);
			return (0);
		}
		if (choice == 1)
		{
			choice = menu_sound(&sdl, &menu);
		}
		if (choice == 2)
		{
			choice = menu_credit(&sdl, &menu);
		}
		if ((choice < 0 || choice > 3) && choice != 42)
			menu.is_menu = 0;
	}
	Mix_CloseAudio();
	i = 0;
	while (i < 3)
	{
	TTF_CloseFont(menu.font[i++]);
	}
	TTF_Quit();
	sdl_freesurface(sdl.bg);
	sdl_freesurface(sdl.poney);
	sdl_quit();
	return (0);
}

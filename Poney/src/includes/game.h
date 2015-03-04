/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:30:11 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/03 18:18:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdlib.h>
# include <../SDL/SDL.h>
# include <../SDL/SDL_mixer.h>
# include <../SDL/SDL_image.h>
# include <../SDL/SDL_ttf.h>
# include "libft.h"
# include <unistd.h>
# include "sdl_define.h"
# define HEIGHT_SCREEN	354
# define WIDTH_SCREEN	1000
# define WIDTH_BG		1900
# define PONEY_LAR		192
# define PONEY_HAU		144
# define COLOR			32
# define SQUARE_WIDTH	80
# define SQUARE_HEIGHT	80

typedef struct			s_sdl
{
	SDL_Surface			*screen;
	SDL_Surface			*bg;
	SDL_Surface			*poney;
	SDL_Rect			rect;
	SDL_Rect			pos_poney;
	SDL_Event			event;
	SDL_Surface			*sprite[20];
	int					jumpstate;
	int					plane;
	int					n;
	int					bgx;
	SDL_Rect			tempbg1;
	int					time_since_begin;
	int					prev_time;
	Mix_Music			*music;
	char				*messages[100];
	SDL_Surface			*text[100];
	int					size[5];
	TTF_Font			*font[5];
	int					life;
}						t_sdl;

typedef struct			s_menu
{
	SDL_Surface			*menu;
	SDL_Surface			*Choice;
	SDL_Color			color;
	SDL_Surface			*message[100];
	TTF_Font			*font[5];
	int					size[5];
	char				*words[5];
	SDL_Rect			pos_menu;
	int					what_choice;
	SDL_Event			ev_men;
	int					is_menu;
	SDL_Surface			*state[20];
	int					is_menu_choice;
	SDL_Event			ev_cred;
}						t_menu;

typedef struct			s_bad
{
	SDL_Surface			*sprite[10];
	SDL_Rect			pos_bad;
	SDL_Surface			*image;
	SDL_Rect			pos_message;
}						t_bad;

int						menu_sound(t_sdl *sdl, t_menu *menu);
int						menu_credit(t_sdl *sdl, t_menu *menu);
int						ft_menu(t_menu *menu, t_sdl *sdl);
int					loop(t_sdl sdl, t_bad bad);
int						ennemy(t_sdl *sdl, t_bad *bad);
int						gameover(t_sdl *sdl);
int						titlescreen(t_sdl *sdl);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:30:11 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/27 14:51:36 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <unistd.h>
# include "sdl_define.h"
# include <stdlib.h>
# include "../SDL/include/SDL/SDL_mixer.h"
# include "../SDL/include/SDL/SDL.h"
# include "../SDL/include/SDL/SDL_image.h"
# include "../SDL/include/SDL/SDL_ttf.h"
# include "libft.h"
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
	SDL_Surface			*bg[3];
	SDL_Surface			*poney;
	SDL_Rect			rect;
	SDL_Rect			pos_poney;
	SDL_Event			event;
	SDL_Surface			*sprite[30];
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
	int					vitesse;
	int					timer;
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
	int					is_dangerous;
	SDL_Surface			*heart[3];
	SDL_Rect			pos_heart[3];
	SDL_Rect			pos_score[3];
	SDL_Color			rgb;
	TTF_Font			*font;
	SDL_Surface			*message[3];
}						t_bad;

int						menu_sound(t_sdl *sdl, t_menu *menu);
int						menu_credit(t_sdl *sdl, t_menu *menu);
int						ft_menu(t_menu *menu, t_sdl *sdl);
int						loop(t_sdl sdl, t_bad bad);
int						ennemy(t_sdl *sdl, t_bad *bad);
int						gameover(t_sdl *sdl);
int						titlescreen(t_sdl *sdl);
void					sdl_show_score(t_sdl *sdl, t_bad *bad);

#endif

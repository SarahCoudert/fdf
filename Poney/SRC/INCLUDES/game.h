/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:30:11 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/17 18:13:49 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdlib.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_image.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include "sdl_define.h"
# define HEIGHT_SCREEN	354
# define WIDTH_SCREEN	1000
# define WIDTH_BG		1900
# define PONEY_LAR		192
# define PONEY_HAU		144
# define COLOR			32

typedef struct			s_sdl
{
	SDL_Surface			*screen;
	SDL_Surface			*bg;
	SDL_Surface			*poney;
	SDL_Rect			rect;
	SDL_Rect			pos_poney;
	SDL_Event			event;
	SDL_Surface			*sprite[15];
	int					jumpstate;
	int					plane;
	int					n;
	int					bgx;
	SDL_Rect			tempbg1;
	SDL_Rect			tempbg2;
	int					time_since_begin;
	int					prev_time;
	Mix_Music			*music;
}						t_sdl;

typedef struct			s_menu
{
	SDL_Surface			*menu;
	SDL_Surface			*Choice;
	SDL_Rect			pos_menu;
	int					what_choice;
	SDL_Event			ev_men;
	int					is_menu;
	SDL_Surface			*state[4];
}						t_menu;

int						ft_menu(t_menu *menu, t_sdl *sdl);
void					loop(t_sdl sdl);

#endif

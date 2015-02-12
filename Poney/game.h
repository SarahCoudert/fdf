/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:30:11 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/12 17:40:52 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdlib.h>
# include <SDL.h>
# include <SDL_image.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include "SDL_define.h"
# define HEIGHT_SCREEN		500
# define WIDTH_SCREEN		2250
# define PONEY_LAR			192
# define PONEY_HAU			144
# define COLOR				32

typedef struct				s_sdl
{
	SDL_Surface				*screen;
	SDL_Surface				*bg;
	SDL_Surface				*poney;
	SDL_Rect				rect;
	SDL_Rect				pos_poney;
	SDL_Event				event;
	SDL_Surface				*sprite[8];
}							t_sdl;

void						loop(t_sdl sdl);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:36:07 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/19 17:42:42 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/game.h"

int		check_collision(SDL_Rec)
{
	if( bottomA <= topB )
	{
		return -1;
	}

	if( topA >= bottomB )
	{
		return -1;
	}

	if( rightA <= leftB )
	{
		return -1;
	}

	if( leftA >= rightB )
	{
		return -1;
	}

	return 1;
}

void		ennemy(t_sdl *sdl, t_bad *bad)
{
	int leftW;
	int leftB;
	int rightW;
	int rightB;
	int topW;
	int topB;
	int bottomW;
	int bottomB;

	bad->pos_bad.y -= 2;
	leftB = bad->pos_bad.x;
	rightB = bad->pos_bad.x + bad->pos_bad.w;
	topB = bad->pos_bad.y;
	bottomB = bad->pos_bad.y + bad->pos_bad.h;

	leftW = sdl->pos_poney.x;
	rightW = sdl->pos_poney.x + sdl->pos_poney.w;
	topW = sdl->pos_poney.y;
	bottomW = sdl->pos_poney.y + sdl->pos_poney.h;

	if (( bad->pos_bad.x < 0 ))
	{
		bad->pos_bad.x = 0;
	}
	if ( bad->pos_bad.x + SQUARE_WIDTH > WIDTH_SCREEN ) {
		bad->pos_bad.x = WIDTH_SCREEN - SQUARE_WIDTH;
	}
	if( ( check_collision( bad->pos_bad sdl->pos_poney)) ) {
		if(bad->pos_bad.x + bad->pos_bad.w > sdl->pos_poney.x + sdl->pos_poney.w) {
			bad->pos_bad.x = sdl->pos_poney.x + sdl->pos_poney.w;
		}
		if(bad->pos_bad.x < sdl->pos_poney.x) {
			bad->pos_bad.x = sdl->pos_poney.x - bad->pos_bad.w;
		}
	}
	bad->pos_bad.y += yVel;
	if (( bad->pos_bad.y < 0 ) ) {
		bad->pos_bad.y = 0;
	}
	if ( bad->pos_bad.y + SQUARE_HEIGHT > HEIGHT_SCREEN ) {
		bad->pos_bad.y = HEIGHT_SCREEN - SQUARE_HEIGHT;
	}
	if( ( check_collision( bad->pos_bad. sdl->pos_poney.)) ) {
		if(bad->pos_bad.y < sdl->pos_poney.y){
			bad->pos_bad.y = sdl->pos_poney.y - bad->pos_bad.h;
		}

		if(bad->pos_bad.y + bad->pos_bad.h > sdl->pos_poney.y + sdl->pos_poney.h) {
			bad->pos_bad.y = sdl->pos_poney.y + sdl->pos_poney.h;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:36:07 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/20 15:38:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/game.h"

int		check_collision(SDL_Rect box, SDL_Rect poney)
{
	int		leftpon;
	int		leftbox;
	int		rightpon;
	int		rightbox;
	int		topbox;
	int		bottompon;

	leftpon = poney.x;
	rightpon = poney.x + poney.w;
	bottompon = poney.y + poney.h;
	leftbox = box.x;
	rightbox = box.x + box.w;
	topbox = box.y;
	if (leftbox > rightpon || (leftbox <= rightpon && bottompon < topbox + 20))
	{
		return (1);
	}
	if (rightbox < leftpon || (rightbox > leftpon && bottompon < topbox + 20))
	{
		return (1);
	}
	return (-1);
}

int		ennemy(t_sdl *sdl, t_bad *bad)
{
	static int			i = 0;

	bad->image = bad->sprite[0];
	if (bad->pos_bad.x == 0)
	{
		if (i <= 7)
		{
			bad->image = bad->sprite[i + 1];
			i++;
		}
		else
		{
			i = 0;
			bad->pos_bad.x = 1100;
		}
	}
	else
		bad->pos_bad.x -= 10;
	return (check_collision(bad->pos_bad, sdl->pos_poney));
	return (1);
}

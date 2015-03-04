/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 16:36:07 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/04 17:52:32 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"

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
	if (leftbox > rightpon || bottompon - 30 < topbox)
	{
		return (1);
	}
	if (rightbox < leftpon + 40)
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
		if (i != 7)
		{
			bad->image = bad->sprite[i];
			i++;
			bad->is_dangerous = 1;
		}
		else
		{
			i = 0;
			bad->pos_bad.x = 1090 + (rand() % 1000);
		}
	}
	else
		bad->pos_bad.x -= 10;
	if (((check_collision(bad->pos_bad, sdl->pos_poney)) == -1) && (bad->is_dangerous == 1))
			return (-1);
	else
		return (0);
	return (0);
}

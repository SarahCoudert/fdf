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

	if ((bad->image = bad->sprite[0]) == NULL)
		ft_putendl("Estas la mierdas");
	if (bad->pos_bad.x == 0)
	{
		if (i != 7)
		{
			bad->image = bad->sprite[i];
			i++;
		}
		else
		{
			i = 0;
			bad->pos_bad.x = 1010 + (rand() % 400);
		}
	}
	else
		bad->pos_bad.x -= 10;
	return (check_collision(bad->pos_bad, sdl->pos_poney));
}

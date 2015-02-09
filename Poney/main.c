/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:07:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/09 18:34:42 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "libft/includes/libft.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	if ((SDL_Init(SDL_INIT_VIDEO)) == (-1))
	{
		ft_putendl("SDL_Init error.");
		return (-1);
	}
	SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	sleep(4);
	SDL_Quit();
	return (0);
}

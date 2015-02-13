/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:22:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/13 17:21:27 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		jump(t_sdl *sdl)
{
	static int			i = 0;

	SDL_Delay(35);
	if (i < 7)
	{
		if (i < 3)
		{
			sdl->pos_poney.y -= 60;
//			sdl->pos_poney.x += 8;
			i++;
		}
		else
		{
			if (sdl->plane == 1 && i == 3)
			{
				sdl->n++;
				SDL_Delay(10);
			}
			else 
				sdl->pos_poney.y += 45;
//			sdl->pos_poney.x += 13;
			if (sdl->plane != 1)
				i++;
		}
		sdl->poney = sdl->sprite[8 + i];
		sdl->plane = 0;
		return (1);
	}
	else
	{
		sdl->jumpstate = 0;
		i = 0;
		return (0);
	}
}

static int		aux(t_sdl *sdl, Uint8 *keystate)
{
	if (keystate[SDLK_ESCAPE])// press escape quit the game
		return (0);
	if (keystate[SDLK_q])// pressing q too
		return (0);
	if (keystate[SDLK_UP]) //jump
	{
		if (sdl->jumpstate == 1)
			sdl->plane = 1;
		sdl->jumpstate = 1;
		if (sdl->n > 3)
		{
			sdl->plane = 0;
			sdl->n = 0;
		}
	}
	return (1);
}

void		loop(t_sdl sdl)
{
	int		continuer;
	Uint8	*keystate;
	int		debut;
	int		i;
	int		j;

	i = 0;
	j = 0;
	continuer = 1;
	keystate = SDL_GetKeyState(NULL);
	debut = 1;
	while (continuer)
	{
		while (SDL_PollEvent(&sdl.event)) // tant que Pollevent renvoie un truc
		{
			if (sdl.event.type) //on verifie si on a un event
			{
				if (sdl.event.type == SDL_QUIT) //si on clique sur la croix on ferme tout
					continuer = 0;
				else if (sdl.event.type == SDL_KEYDOWN)// si on appuye sur une touche on regarde ce qu'il se passe
				{
					continuer = aux(&sdl, keystate);//on regarde les touches
				}
			}
		}
		i++;
		if (i % 4 == 1)// si il n'y a pas d'event a gerer(saut), on affiche en boucle Micheline en train de courir
		{
			SDL_Delay(30);
			sdl.poney = sdl.sprite[j];
			if (j < 6)
				j++;
			else
				j = 0;
		}
		if (debut)//si on vient d'arriver, le poney se tient droit
		{
			sdl.poney = sdl.sprite[7];
			debut--;
		}
		if (sdl.jumpstate == 1)
		{
			jump(&sdl);
		}
		sdl_blit(sdl.bg, NULL, sdl.screen, &sdl.rect);
		sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
		sdl_flip(sdl.screen);
	}
}

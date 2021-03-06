/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:22:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/27 16:24:21 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"
#include <time.h>

static void			move_bg(t_sdl *sdl, int vit)
{
	sdl->bgx -= sdl->vitesse;
	if (sdl->bgx <= -sdl->bg[vit]->w + WIDTH_SCREEN)
		sdl->bgx = 0;
	sdl->tempbg1.x = sdl->bgx;
	sdl->tempbg1.y = 0;
}

static void		jump(t_sdl *sdl, Uint8 *keystate)
{
	static int			i = 0;
	if (i < 7)
	{
		if (i < 3)
		{
			sdl->pos_poney.y -= 60;
			i++;
		}
		else if (sdl->jumpstate == 1 && i == 3 && sdl->plane == 0 && keystate[SDLK_UP])
			sdl->plane = 1;
		else
		{
			if (sdl->plane == 1 && i == 3 && sdl->n <= 25)
			{
				sdl->n++; //on incremente n pour eviter que Micheline ne vole trop longtemps
			}
			else
			{
				sdl->pos_poney.y += 45;
				sdl->plane = 0;
				i++;
			}
		}
		if (i <= 6)
			sdl->poney = sdl->sprite[8 + i];
		return ;
	}
	if (sdl->n == 30)
	{
		sdl->plane = 0;
		sdl->n = 0;
	}
	else
	{
		sdl->jumpstate = 0;
		i = 0;
		return ;
	}
	return ;
}

static int		aux(t_sdl *sdl, Uint8 *keystate)
{
	if (sdl->event.type == SDL_QUIT) //si on clique sur la croix on ferme tout
		return (0);
	else if (sdl->event.type == SDL_KEYDOWN)// si on appuye sur une touche on regarde ce qu'il se passe
	{
		if (keystate[SDLK_ESCAPE] || keystate[SDLK_q])
		{
			return (titlescreen(sdl));
		}
		if (keystate[SDLK_UP]) //jump
		{
			sdl->jumpstate = 1; //on met jumpstate a 1 dans tous les cas
		}
	}
	if (sdl->event.type == SDL_KEYUP)
	{
		if (sdl->event.key.keysym.sym == SDLK_UP)
		{
			sdl->plane = 0;
			sdl->n = 0;
		}
		if (sdl->event.key.keysym.sym == SDLK_m)
		{
			if (Mix_PausedMusic() == 1)
				Mix_ResumeMusic();
			else if (Mix_PlayingMusic() == 1)
				Mix_PauseMusic();
		}
	}
	return (1);
}

int		loop(t_sdl sdl, t_bad bad)
{
	int			continuer;
	Uint8		*keystate;
	int			i;
	int			j;
	int			choice;
	int			collision;
	int			k;
	int 		vit;

	k = 0;
	collision = 0;
	choice = 1;
	i = 0;
	j = 0;
	continuer = 1;
	vit = 0;
	keystate = SDL_GetKeyState(NULL);
	Mix_PlayMusic(sdl.music, -1);
	while (continuer)
	{
		sdl.time_since_begin = SDL_GetTicks();
		if (sdl.time_since_begin - sdl.prev_time > 20)
		{
			sdl.prev_time = sdl.time_since_begin;
			while (SDL_PollEvent(&sdl.event))
			{
				continuer = aux(&sdl, keystate);//on regarde les touches
				if (continuer == 20)
				{
					if (Mix_PlayingMusic() == 1)
						Mix_PauseMusic();
					return (42);
				}
				if (continuer == 30)
					return (3);
			}
			i++;
			sdl.poney = sdl.sprite[j];
			if (sdl.jumpstate == 1) //si on est en train de sauter alors on saute
				jump(&sdl, keystate);
			collision = ennemy(&sdl, &bad);
			if (collision == -1)
			{
				sdl.timer -= 20 + (sdl.vitesse % 50);
				sdl.life--;
				bad.is_dangerous = 0;
				collision = 0;
				if (sdl.life == 0)
				{
					if (Mix_PlayingMusic() == 1)
						Mix_PauseMusic();
					choice = gameover(&sdl);
					return (choice);
				}
			}
			sdl.vitesse = 10 + (sdl.timer / 100);
			move_bg(&sdl, vit);
			SDL_BlitSurface(sdl.bg[vit], NULL, sdl.screen, &sdl.tempbg1);
			SDL_BlitSurface(bad.image, NULL, sdl.screen, &bad.pos_bad);
			if (bad.is_dangerous == 1)
			{
				sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
			}
			else
			{
				sdl.poney = sdl.sprite[j + 19];
				SDL_SetAlpha(sdl.poney, SDL_SRCALPHA, 128);
				sdl_blit(sdl.poney, NULL, sdl.screen, &sdl.pos_poney);
			}
			if (i % 6 == 1)//if no event, Micheline is running
			{
				sdl.timer++;
				if (j < 6)
					j++;
				else
					j = 0;
			}
			while (k < sdl.life)
			{
				SDL_BlitSurface(bad.heart[k], NULL, sdl.screen, &bad.pos_heart[k]);
				k++;
			}
			sdl_show_score(&sdl, &bad);
			k = 0;
			sdl_flip(sdl.screen);
		}
	}
	return (3);
}

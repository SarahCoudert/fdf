/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:32:21 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/12 14:46:06 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_DEFINE_H
# define SDL_DEFINE_H

# define sdl_seticon		SDL_WM_SetIcon
# define sdl_init			SDL_Init
# define sdl_blit			SDL_BlitSurface
# define sdl_keyrepeat		SDL_EnableKeyRepeat
# define sdl_freesurface	SDL_FreeSurface
# define sdl_videomode		SDL_SetVideoMode
# define sdl_caption		SDL_WM_SetCaption
# define sdl_quit			SDL_Quit
# define sdl_waitevent		SDL_WaitEvent
# define img_load			IMG_Load
# define sdl_bmp			SDL_LoadBMP
# define sdl_flip			SDL_Flip

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:30:50 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/20 18:33:38 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE		200
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(int const fd, char **line);

#endif

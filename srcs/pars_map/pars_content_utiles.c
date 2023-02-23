/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_content_utiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:55:50 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/23 06:15:47 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_line(t_data *d, int i)
{
	if (i == 0 || d->file.all[i - 1] == '\n')
		return (1);
	return (0);
}

void	ini_d_texture(t_data *d)
{
	d->txr.plan[F_].value = (void *) 0x00000000;
	d->txr.plan[C_].value = (void *) 0x00000000;
	d->txr.path[NO_] = NULL;
	d->txr.path[SO_] = NULL;
	d->txr.path[EA_] = NULL;
	d->txr.path[WE_] = NULL;
}

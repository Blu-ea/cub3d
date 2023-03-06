/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:52:42 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/06 07:52:00 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int key, t_data *d)
{
	if (key == K_W)
	{
		d->pc._x += cos(d->pc.face_rad) / 4;
		d->pc._y -= sin(d->pc.face_rad) / 4;
	}
	if (key == K_S)
	{
		d->pc._x -= cos(d->pc.face_rad) / 4;
		d->pc._y += sin(d->pc.face_rad) / 4;
	}
	if (key == K_A)
	{
		d->pc._x -= sin(d->pc.face_rad) / 4;
		d->pc._y -= cos(d->pc.face_rad) / 4;
	}
	if (key == K_D)
	{
		d->pc._x += sin(d->pc.face_rad) / 4;
		d->pc._y += cos(d->pc.face_rad) / 4;
	}
}

void	ft_rotate(int key, t_data *d)
{
	if (key == K_LEFT || key == K_Q)
		d->pc.face_deg += 2;
	if (key == K_RIGHT || key == K_E)
		d->pc.face_deg -= 2;
	if (d->pc.face_deg < 0)
		d->pc.face_deg += 360;
	if (d->pc.face_deg > 360)
		d->pc.face_deg -= 360;
	d->pc.face_rad = d->pc.face_deg * M_PI / 180;
	(void) key;
	(void) d;
}

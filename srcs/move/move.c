/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:52:42 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/09 05:37:15 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int key, t_data *d)
{
	if (key == K_W)
	{
		d->pc._x += d->pc.dir.x / 4;
		d->pc._y += d->pc.dir.y / 4;
	}
	if (key == K_S)
	{
		d->pc._x -= d->pc.dir.x / 4;
		d->pc._y -= d->pc.dir.y / 4;
	}
	if (key == K_A)
	{
		d->pc._x += d->pc.dir.y / 4;
		d->pc._y -= d->pc.dir.x / 4;
	}
	if (key == K_D)
	{
		d->pc._x -= d->pc.dir.y / 4;
		d->pc._y += d->pc.dir.x / 4;
	}
}

void	ft_rotate(int key, t_data *d)
{
	double	oldplanex;
	double	olddirx;
	double	rot;

	rot = ROT * M_PI / 180;
	if (key == K_LEFT || key == K_Q)
	{
		olddirx = d->pc.dir.x;
		d->pc.dir.x = d->pc.dir.x * cos(-rot) - d->pc.dir.y * sin(-rot);
		d->pc.dir.y = olddirx * sin(-rot) + d->pc.dir.y * cos(-rot);
		oldplanex = d->pc.plane.x;
		d->pc.plane.x = d->pc.plane.x * cos(-rot) - d->pc.plane.y * sin(-rot);
		d->pc.plane.y = oldplanex * sin(-rot) + d->pc.plane.y * cos(-rot);
	}
	if (key == K_RIGHT || key == K_E)
	{
		olddirx = d->pc.dir.x;
		d->pc.dir.x = d->pc.dir.x * cos(rot) - d->pc.dir.y * sin(rot);
		d->pc.dir.y = olddirx * sin(rot) + d->pc.dir.y * cos(rot);
		oldplanex = d->pc.plane.x;
		d->pc.plane.x = d->pc.plane.x * cos(rot) - d->pc.plane.y * sin(rot);
		d->pc.plane.y = oldplanex * sin(rot) + d->pc.plane.y * cos(rot);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:52:42 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/11 07:27:14 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int key, t_data *d)
{
	if (key == K_W || key == K_UP)
	{
		d->pc._x += d->pc.dir.x * MOVE_FACTOR;
		d->pc._y += d->pc.dir.y * MOVE_FACTOR;
	}
	if (key == K_S || key == K_DOWN)
	{
		d->pc._x -= d->pc.dir.x * MOVE_FACTOR;
		d->pc._y -= d->pc.dir.y * MOVE_FACTOR;
	}
	if (key == K_A)
	{
		d->pc._x += d->pc.dir.y * MOVE_FACTOR;
		d->pc._y -= d->pc.dir.x * MOVE_FACTOR;
	}
	if (key == K_D)
	{
		d->pc._x -= d->pc.dir.y * MOVE_FACTOR;
		d->pc._y += d->pc.dir.x * MOVE_FACTOR;
	}
}

void	ft_rotate(int key, t_data *d)
{
	double	oldplnx;
	double	olddirx;
	double	rot;

	rot = ROT * M_PI / 180;
	if (key == K_LEFT || key == K_Q)
	{
		olddirx = d->pc.dir.x;
		d->pc.dir.x = d->pc.dir.x * cos(-rot) - d->pc.dir.y * sin(-rot);
		d->pc.dir.y = olddirx * sin(-rot) + d->pc.dir.y * cos(-rot);
		oldplnx = d->pc.pln.x;
		d->pc.pln.x = d->pc.pln.x * cos(-rot) - d->pc.pln.y * sin(-rot);
		d->pc.pln.y = oldplnx * sin(-rot) + d->pc.pln.y * cos(-rot);
	}
	if (key == K_RIGHT || key == K_E)
	{
		olddirx = d->pc.dir.x;
		d->pc.dir.x = d->pc.dir.x * cos(rot) - d->pc.dir.y * sin(rot);
		d->pc.dir.y = olddirx * sin(rot) + d->pc.dir.y * cos(rot);
		oldplnx = d->pc.pln.x;
		d->pc.pln.x = d->pc.pln.x * cos(rot) - d->pc.pln.y * sin(rot);
		d->pc.pln.y = oldplnx * sin(rot) + d->pc.pln.y * cos(rot);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:52:42 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/13 08:34:46 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_bonus(int key, t_data *d);
static void	get_offset_rot(int key, t_data *d, t_dvect *off, double *rot);

void	ft_move(int key, t_data *d)
{
	if (BONUS && !d->ghost)
	{
		ft_move_bonus(key, d);
		return ;
	}
	if (key == K_W || key == K_UP)
	{
		d->pc._x += d->pc.dir.x * MV_F;
		d->pc._y += d->pc.dir.y * MV_F;
	}
	if (key == K_S || key == K_DOWN)
	{
		d->pc._x -= d->pc.dir.x * MV_F;
		d->pc._y -= d->pc.dir.y * MV_F;
	}
	if (key == K_A)
	{
		d->pc._x += d->pc.dir.y * MV_F;
		d->pc._y -= d->pc.dir.x * MV_F;
	}
	if (key == K_D)
	{
		d->pc._x -= d->pc.dir.y * MV_F;
		d->pc._y += d->pc.dir.x * MV_F;
	}
}

// collision check featured
static void	ft_move_bonus(int key, t_data *d)
{
	t_dvect	offset;
	double	rot;

	get_offset_rot(key, d, &offset, &rot);
	if (move_ray(d, rot))
	{
		d->pc._x += offset.x;
		d->pc._y += offset.y;
	}
}

static void	get_offset_rot(int key, t_data *d, t_dvect *off, double *rot)
{
	if (key == K_W || key == K_UP)
	{
		off->x = d->pc.dir.x * MV_F;
		off->y = d->pc.dir.y * MV_F;
		*rot = 0;
	}
	if (key == K_S || key == K_DOWN)
	{
		off->x = -d->pc.dir.x * MV_F;
		off->y = -d->pc.dir.y * MV_F;
		*rot = M_PI;
	}
	if (key == K_A)
	{
		off->x = d->pc.dir.y * MV_F;
		off->y = -d->pc.dir.x * MV_F;
		*rot = 3 * M_PI / 2;
	}
	if (key == K_D)
	{
		off->x = -d->pc.dir.y * MV_F;
		off->y = d->pc.dir.x * MV_F;
		*rot = M_PI / 2;
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

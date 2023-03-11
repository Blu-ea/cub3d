/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:52:42 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/11 08:43:20 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_bonus(int key, t_data *d);
static void	get_offset(int key, t_data *d, t_dvect *off);
static bool	is_valid_move(t_data *d, t_dvect off);

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

	get_offset(key, d, &offset);
	if (is_valid_move(d, offset))
	{
		d->pc._x += offset.x;
		d->pc._y += offset.y;
	}
	
}

static bool	is_valid_move(t_data *d, t_dvect off)
{
	char	tiletype;
	t_ivect		mapi;

	mapi.x = (int)(d->pc._x + off.x);
	mapi.y = (int)(d->pc._y + off.y);
	if (mapi.x < 0 || mapi.x > d->file.width || mapi.y < 0 || mapi.y > d->file.length)
		return (true);
	tiletype = d->file.map[mapi.y][mapi.x];
	if (tiletype == '0' || tiletype == 'O' || tiletype == ' ')
		return (true);
	else
		return (false);
}

static void	get_offset(int key, t_data *d, t_dvect *off)
{
	if (key == K_W || key == K_UP)
	{
		off->x = d->pc.dir.x * MV_F;
		off->y = d->pc.dir.y * MV_F;
	}
	if (key == K_S || key == K_DOWN)
	{
		off->x = -d->pc.dir.x * MV_F;
		off->y = -d->pc.dir.y * MV_F;
	}
	if (key == K_A)
	{
		off->x = d->pc.dir.y * MV_F;
		off->y = -d->pc.dir.x * MV_F;
	}
	if (key == K_D)
	{
		off->x = -d->pc.dir.y * MV_F;
		off->y = d->pc.dir.x * MV_F;
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

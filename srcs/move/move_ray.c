/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:33:20 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/13 08:41:49 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rayc(t_data *d, t_rayc *r, double rot);
static void	get_stockxy_step(t_rayc *r);
static void	perform_dda(t_data *d, t_rayc *r);
static void	catch_inter(t_rayc *r);

// return if the movement is allowed or not
bool	move_ray(t_data *d, double rot)
{
	t_rayc	rayc;

	init_rayc(d, &rayc, rot);
	get_stockxy_step(&rayc);
	perform_dda(d, &rayc);
	if (rayc.hit == true)
	{
		catch_inter(&rayc);
		if (rayc.length < MV_RANGE)
		{
			return (false);
		}
		else
			return (true);
	}
	return (true);
}

static void	init_rayc(t_data *d, t_rayc *r, double rot)
{
	r->start = init_dvect(d->pc._x, d->pc._y);
	r->map = init_ivect_d(d->pc._x, d->pc._y);
	r->cam = 0.0;
	r->dir = init_dvect(d->pc.dir.x, d->pc.dir.y);
	rotation_matrix(&r->dir, rot);
	get_unit_step(r);
	r->hit = false;
	r->side = false;
	r->length = 0.0;
}

// starting values -> get distance from player to x and y collision
// get step in direction + delta direction coordinates
static void	get_stockxy_step(t_rayc *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->stockxy.x = (r->start.x - r->map.x) * r->uss.x;
	}
	else
	{
		r->step.x = 1;
		r->stockxy.x = (r->map.x + 1.0 - r->start.x) * r->uss.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->stockxy.y = (r->start.y - r->map.y) * r->uss.y;
	}
	else
	{
		r->step.y = 1;
		r->stockxy.y = (r->map.y + 1.0 - r->start.y) * r->uss.y;
	}
}

// using the Digital Differential Analysis algorithm
// here the ray is shot
static void	perform_dda(t_data *d, t_rayc *r)
{
	while (ft_inf_wall(r, d))
	{
		if (r->stockxy.x < r->stockxy.y)
		{
			r->map.x += r->step.x;
			r->length = r->stockxy.x;
			r->stockxy.x += r->uss.x;
			r->side = true;
		}
		else
		{
			r->map.y += r->step.y;
			r->length = r->stockxy.y;
			r->stockxy.y += r->uss.y;
			r->side = false;
		}
		if (ft_is_wall(r->map.x, r->map.y, d))
		{
			r->hit = true;
		}
	}
}

static void	catch_inter(t_rayc *r)
{
	r->inter.x = r->start.x + (r->dir.x * r->length);
	r->inter.y = r->start.y + (r->dir.y * r->length);
}
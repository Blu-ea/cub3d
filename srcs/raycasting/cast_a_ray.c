/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:26:57 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/13 09:57:28 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rayc(t_data *d, t_rayc *r, int x);
static void	get_stockxy_step(t_rayc *r);
static void	perform_dda(t_data *d, t_rayc *r, bool action);
static void	catch_inter(t_data *d, t_rayc *r);

void	cast_a_ray(t_data *d, int x, bool action)
{
	t_rayc	rayc;

	init_rayc(d, &rayc, x);
	get_stockxy_step(&rayc);
	perform_dda(d, &rayc, action);
	if (action && rayc.hit == true)
	{
		catch_inter(d, &rayc);
		action_door(d, &rayc);
	}
	else if (!action && rayc.hit == true)
	{
		catch_inter(d, &rayc);
		wall_slice(d, &rayc, x);
	}
}

static void	init_rayc(t_data *d, t_rayc *r, int x)
{
	r->start = init_dvect(d->pc._x, d->pc._y);
	r->map = init_ivect_d(d->pc._x, d->pc._y);
	r->cam = 2 * x / (double)S_WIDTH - 1;
	r->dir = init_dvect(d->pc.dir.x, d->pc.dir.y);
	r->dir.x += d->pc.pln.x * r->cam;
	r->dir.y += d->pc.pln.y * r->cam;
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
static void	perform_dda(t_data *d, t_rayc *r, bool action)
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
		if (action && ft_what_tile(r->map.x, r->map.y, d) == O_DOOR)
			r->hit = true;
		if (ft_what_tile(r->map.x, r->map.y, d) != VOID \
		&& ft_what_tile(r->map.x, r->map.y, d) != O_DOOR)
		{
			r->hit = true;
		}
	}
}

static void	catch_inter(t_data *d, t_rayc *r)
{
	r->inter.x = r->start.x + (r->dir.x * r->length);
	r->inter.y = r->start.y + (r->dir.y * r->length);
	r->tile = ft_what_tile(r->map.x, r->map.y, d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:26:57 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/01 15:38:33 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rayc(t_data *d, t_rayc *r, int x);
static void	init_sside_ddist(t_data *d, t_rayc *r);
static void	perform_dda(t_data *d, t_rayc *r);

void	cast_a_ray(t_data *d, int x)
{
	t_rayc	rayc;

	init_rayc(d, &rayc, x);
	init_sside_ddist(d, &rayc);
	perform_dda(d, &rayc);
	set_draw_infos(d, &rayc);
}

static void	init_r(t_data *d, t_rayc *r, int x)
{
	// Ces variales a passer dans data [?]
	r->dir_x = get_dir_x(d->pc.face_rad);
	r->dir_y = get_dir_y(d->pc.face_rad);
	r->time = 0.0;
	r->old = 0.0;

	r->cam_x = 2 * x / (double)S_WIDTH - 1;
	r->ray_dir_x = r->dir_x + PLANE_X * r->cam_x;
	r->ray_dir_y = r->dir_x + PLANE_Y * r->cam_x;
	r->map_x = (int)d->pc._x;
	r->map_y = (int)d->pc._y;
	r->dd_x = get_delta_dist(r->ray_dir_x);
	r->dd_y = get_delta_dist(r->ray_dir_y);
	r->hit = 0;
}

// get step in direction + delta direction coordinates
static void	get_step_delta(t_data *d, t_rayc *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->sd_x = (d->pc._x - r->map_x) * r->dd_x;
	}
	else
	{
		r->step_x = 1;
		r->sd_x = (1.0 + r->map_x - d->pc._x) * r->dd_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->sd_y = (d->pc._y - r->map_y) * r->dd_y;
	}
	else
	{
		r->step_y = 1;
		r->sd_y = (1.0 + r->map_y - d->pc._y) * r->dd_y;
	}
}

// using the Digital Differential Analysis algorithm
static void	perform_dda(t_data *d, t_rayc *r)
{
	while (r->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (r->sd_x < r->sd_y)
		{
			r->sd_x += r->dd_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sd_y += r->dd_y;
			r->map_x += r->step_y;
			r->side = 1;
		}
	}
	//Check if ray has hit a wall
	// [?] map[x][y] ou map[y][x]
	if (d->file.map[r->map_x][r->map_y] == '1')
		r->hit = 1;
}

static void	set_draw_infos(t_data *d, t_rayc *r)
{
	r->color = BLUE4;
	// continuer ici
}

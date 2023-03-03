/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:26:57 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/03 12:34:46 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rayc(t_data *d, t_rayc *r, int x);
static void	get_stockxy_step(t_data *d, t_rayc *r);
static void	perform_dda(t_data *d, t_rayc *r);

void	cast_a_ray(t_data *d, int x)
{
	t_rayc	rayc;

	init_rayc(d, &rayc, x);
	get_stockxy_step(d, &rayc);
	perform_dda(d, &rayc);
	// set_draw_infos(d, &rayc);
}

static void	init_rayc(t_data *d, t_rayc *r, int x)
{
	(void)x; // besoin plus tard surement

	// Ces variales a passer dans data [?]
	r->start = init_dvect(d->pc._x, d->pc._y);
	r->map = init_ivect((int)d->pc._x, (int)d->pc._y);
	r->dir = init_dvect(get_dir_x(d->pc.face_rad), get_dir_y(d->pc.face_rad));
	get_unit_step(r);
	r->hit = false;
	r->side = false;
	r->length = 0.0;
	
	// checking values :
	/* *
	printf("r->start : (%f,%f)\n", r->start.x, r->start.y);
	printf("r->map : (%d,%d)\n", r->map.x, r->map.y);
	printf("r->dir : (%f,%f)\n", r->dir.x, r->dir.y);
	printf("r->uss : (%f,%f)\n", r->uss.x, r->uss.y);
	printf("hit = %d\n", r->hit);
	* */

	// r->cam_x = 2 * x / (double)S_WIDTH - 1;
	// r->ray_dir_x = r->dir_x + PLANE_X * r->cam_x;
	// r->ray_dir_y = r->dir_x + PLANE_Y * r->cam_x;
	// r->map_x = (int)d->pc._x;
	// r->map_y = (int)d->pc._y;
	// r->dd_x = get_delta_dist(r->ray_dir_x);
	// r->dd_y = get_delta_dist(r->ray_dir_y);
	
}

// get step in direction + delta direction coordinates
static void	get_stockxy_step(t_data *d, t_rayc *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->stockxy.x = ((r->start.x - (double)r->map.x)) * r->uss.x;
	}
	else
	{
		r->step.x = 1;
		r->stockxy.x = ((double)(r->map.x + 1) - r->start.x) * r->uss.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->stockxy.y = ((r->start.y - (double)r->map.y)) * r->uss.y;
	}
	else
	{
		r->step.y = 1;
		r->stockxy.y = ((double)(r->map.y + 1) - r->start.y) * r->uss.y;
	}
}

// using the Digital Differential Analysis algorithm
// here the ray is shot
static void	perform_dda(t_data *d, t_rayc *r)
{
	while (r->hit == false)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (r->stockxy.x < r->stockxy.y)
		{
			r->map.x += r->step.x;
			r->length = r->stockxy.x;
			r->stockxy.x += r->uss.x;
		}
		else
		{
			r->map.y += r->step.y;
			r->length = r->stockxy.y;
			r->stockxy.y += r->uss.y;
		}	
	//Check if ray has hit a wall
	// [?] map[x][y] ou map[y][x]
	// if (r->map.x >= 0 && r->map.x < S_WIDTH && r->map.y >= 0 && r->map.y < S_LENGTH) // dans le cas utilise distance
		if (d->file.map[r->map.x][r->map.y] == '1')
		{
			r->hit = true;
			printf("hit calculated with tile(%d, %d)\n", r->map.x, r->map.y);
		
		}
			
	}
}

//	printf("intersection (%f, %f)\n", r->inter.x, r->inter.y);

// static void	set_draw_infos(t_data *d, t_rayc *r)
// {
// 	r->color = BLUE4;
// 	// continuer ici
// }

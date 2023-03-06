/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:26:57 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/06 08:58:29 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rayc(t_data *d, t_rayc *r, int x);
static void	get_stockxy_step(t_rayc *r);
static void	perform_dda(t_data *d, t_rayc *r);
static void	catch_inter(t_rayc *r);

void	cast_a_ray(t_data *d, int x)
{
	t_rayc	rayc;

	init_rayc(d, &rayc, x);
	get_stockxy_step(&rayc);
	perform_dda(d, &rayc);
	if (rayc.hit == true) // voir aussi ici le cas inf ?
	{
		catch_inter(&rayc);
		wall_slice(d, &rayc, x);
	}
}

static void	init_rayc(t_data *d, t_rayc *r, int x)
{
	r->start = init_dvect(d->pc._x, d->pc._y);
	r->map = init_ivect((int)d->pc._x, (int)d->pc._y);
	r->cam =  2 * x / (double)S_WIDTH - 1;

	r->dir = init_dvect(get_dir_x(d->pc.face_rad), get_dir_y(d->pc.face_rad));
		// ensuite utiliser x ici pour deduire la direction du rayon
		//a partir de la direction du player
	r->dir.x += PLANE_X * r->cam;
	r->dir.y += PLANE_Y * r->cam;

	get_unit_step(r);
	r->hit = false;
	r->side = false;
	r->length = 0.0;
	
	// print_rayc1(r);	// checking values :
	
}

// starting values -> get distance from player to x and y collision
// get step in direction + delta direction coordinates
static void	get_stockxy_step(t_rayc *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->stockxy.x = (r->start.x - (double)r->map.x) * r->uss.x;
	}
	else
	{
		r->step.x = 1;
		r->stockxy.x = ((double)r->map.x + 1.0 - r->start.x) * r->uss.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->stockxy.y = (r->start.y - (double)r->map.y) * r->uss.y;
	}
	else
	{
		r->step.y = 1;
		r->stockxy.y = ((double)r->map.y + 1.0 - r->start.y) * r->uss.y;
	}
}

// using the Digital Differential Analysis algorithm
// here the ray is shot
static void	perform_dda(t_data *d, t_rayc *r)
{
	while (ft_inf_wall(r, d))
	{
		//jump to next map square, either in x-direction, or in y-direction
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
		// printf("map cheking current :  tile(%d, %d) ", r->map.x, r->map.y); //checking
		// if (map_in_bound(r->map.x, r->map.y, d)) // checking
			// printf("= '%c'\n", d->file.map[r->map.y][r->map.x]); // checking
	//Check if ray has hit a wall
	// if (r->map.x >= 0 && r->map.x < S_WIDTH && r->map.y >= 0 && r->map.y < S_LENGTH) // dans le cas utilise distance
		if (ft_is_wall(r->map.x, r->map.y, d))
		{
			r->hit = true;
			// printf("hit calculated with tile(%d, %d)\n", r->map.x, r->map.y); //checking
		}
	}
}

static void	catch_inter(t_rayc *r)
{
	r->inter.x = r->start.x + (r->dir.x * r->length);
	r->inter.y = r->start.y + (r->dir.y * r->length);
	// printf("inter : (%f, %f) -- ray length : %f -- side : %d\n", r->inter.x, r->inter.y, r->length, r->side); //checking
}
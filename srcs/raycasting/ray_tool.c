/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:40:53 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/03 10:58:48 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static double	uss_formula(double top, double bot);

// get vector direction x coordinate from an angle in radians
double get_dir_x(double angle)
{
	return (cos(angle));
}

// get vector direction y coordinate from an angle in radians
double get_dir_y(double angle)
{
	return (sin(angle));
}

/*
	get delta direction coordinates
	parameter is x or y value form ray_dir
	To avoid a division by 0, return a high number instead
*/
// double get_delta_dir(double ray_dir_xy)
// {
// 	if (ray_dir_xy == 0)
// 		return (1e30);
// 	else
// 	{
// 		return (abs(1 / ray_dir_xy));
// 	}
// }

// using Phytagore to calculate  Unit Step Size wich is 
// the scaling factor beetween hypotenuse and a 
// step unit direction to x or y axis
void	get_unit_step(t_rayc *r)
{
	r->uss.x = uss_formula(r->dir.y, r->dir.x);
	r->uss.y = uss_formula(r->dir.x, r->dir.y);
}

static double	uss_formula(double top, double bot)
{
	return(sqrt(1 + (top / bot) * (top / bot)));
}
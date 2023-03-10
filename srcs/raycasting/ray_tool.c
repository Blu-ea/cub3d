/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:40:53 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 14:48:34 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static double	uss_formula(double i);

// get vector direction x coordinate from an angle in radians
double	get_dir_x(double angle)
{
	return (cos(angle));
}

// get vector direction y coordinate from an angle in radians
// -1 * sinus because y axis is reverted in the pixel grid
double	get_dir_y(double angle)
{
	return (-sin(angle));
}

// using Phytagore to calculate  Unit Step Size wich is 
// the scaling factor beetween hypotenuse and a 
// step unit direction to x or y axis
void	get_unit_step(t_rayc *r)
{
	r->uss.x = uss_formula(r->dir.x);
	r->uss.y = uss_formula(r->dir.y);
}

static double	uss_formula(double i)
{
	if (i < 0)
		return (1 / -i);
	return (1 / i);
}

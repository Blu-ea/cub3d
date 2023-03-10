/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:38:20 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 10:37:59 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	toogle(t_data *d, t_rayc *r);

void	action_door(t_data *d, t_rayc *r)
{
	printf("Action intersection : (%f, %f)\n", r->inter.x, r->inter.y); //checking
	if (r->length > ACTION_RANGE)
		return ;
	
	printf("range_action is valid (raylength : %f)\n", r->length); //checking
	printf("tile hit is map(%d, %d) = \'%c\'\n", r->map.x, r->map.y, d->file.map[r->map.y][r->map.x]); //checking
	toogle(d, r);
}

static void	toogle(t_data *d, t_rayc *r)
{
	if (d->file.map[r->map.y][r->map.x] == 'O')
	{
		d->file.map[r->map.y][r->map.x] = 'C';
	}
	else if (d->file.map[r->map.y][r->map.x] == 'O')
	{
		d->file.map[r->map.y][r->map.x] = 'O';
	}
}
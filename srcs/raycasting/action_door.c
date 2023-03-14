/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:38:20 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/14 08:52:40 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	toogle(t_data *d, t_rayc *r);

void	action_door(t_data *d, t_rayc *r)
{
	if (r->length > ACTION_RANGE)
		return ;
	toogle(d, r);
}

static void	toogle(t_data *d, t_rayc *r)
{
	if (d->file.map[r->map.y][r->map.x] == 'O')
	{
		d->file.map[r->map.y][r->map.x] = 'C';
	}
	else if (d->file.map[r->map.y][r->map.x] == 'C')
	{
		d->file.map[r->map.y][r->map.x] = 'O';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_card.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:04:41 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 14:54:21 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_west_east(t_data *d, t_rayc *r);
static int	get_south_north(t_data *d, t_rayc *r);

// determine the cardinal orientation of the hit face
int	get_cardinal(t_data *d, t_rayc *r)
{
	if (r->side)
		return (get_west_east(d, r));
	else
		return (get_south_north(d, r));
}

static int	get_west_east(t_data *d, t_rayc *r)
{
	if (d->pc._x <= r->inter.x)
		return (EA_);
	else
		return (WE_);
}

static int	get_south_north(t_data *d, t_rayc *r)
{
	if (d->pc._y <= r->inter.y)
		return (SO_);
	else
		return (NO_);
}

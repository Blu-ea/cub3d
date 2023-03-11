/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:02:47 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/10 15:09:00 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_wall(int x, int y, t_data *d)
{
	if (map_in_bound(x, y, d) && d->file.map[y][x] == '1')
		return (1);
	return (0);
}

int	ft_inf_wall(t_rayc *r, t_data *d)
{
	if (r->hit == true)
		return (0);
	if (r->dir.y < 0 && r->map.y < 0)
		return (r->inf = true, 0);
	if (r->dir.x < 0 && r->map.x < 0)
		return (r->inf = true, 0);
	if (r->dir.y > 0 && r->map.y > d->file.length)
		return (r->inf = true, 0);
	if (r->dir.x > 0 && r->map.x > d->file.width)
		return (r->inf = true, 0);
	return (1);
}

void	toogle_bool(bool *boolean)
{
	if (*boolean == true)
		*boolean = false;
	else
		*boolean = true;
}
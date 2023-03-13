/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:14:48 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/13 07:27:24 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_mini_player(t_data *d);

void	ft_mini_map(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (d->file.map[++y / MAP_ZOOM])
	{
		x = -1;
		while (d->file.map[y / MAP_ZOOM][++x / MAP_ZOOM])
		{
			if (d->file.map[y / MAP_ZOOM][x / MAP_ZOOM] == '0')
				my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0xffffff);
			else if (d->file.map[y / MAP_ZOOM][x / MAP_ZOOM] == '1')
				my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0x000000);
			else if (d->file.map[y / MAP_ZOOM][x / MAP_ZOOM] == 'C')
				my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0xF00000);
			else if (d->file.map[y / MAP_ZOOM][x / MAP_ZOOM] == 'O')
				my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0x00F000);
		}
	}
	ft_mini_player(d);
}

void	ft_mini_player(t_data *d)
{
	int	x;
	int	y;

	y = d->pc._y * MAP_ZOOM - MAP_ZOOM / 5;
	while (++y < d->pc._y * MAP_ZOOM + MAP_ZOOM / 5)
	{
		x = d->pc._x * MAP_ZOOM - MAP_ZOOM / 5;
		while (++x < d->pc._x * MAP_ZOOM + MAP_ZOOM / 5)
			my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0xff0000);
	}
	y = (d->pc._y + (d->pc.dir.y / 1.5)) * MAP_ZOOM - MAP_ZOOM / 8;
	while (++y < (d->pc._y + (d->pc.dir.y / 1.5)) * MAP_ZOOM + MAP_ZOOM / 8)
	{
		x = (d->pc._x + (d->pc.dir.x / 1.5)) * MAP_ZOOM - MAP_ZOOM / 8;
		while (++x < (d->pc._x + (d->pc.dir.x / 1.5)) * MAP_ZOOM + MAP_ZOOM / 8)
			my_mlx_pixel_put(d, x + MAP_OFFSETX, y + MAP_OFFSETY, 0x00ff00);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:39:27 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/03 01:06:04 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mini_map(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (d->file.map[++y / 10])
	{
		x = -1;
		while (d->file.map[y / 10][++x / 10])
		{
			if (d->file.map[y / 10][x / 10] == '0')
				my_mlx_pixel_put(d, x, y, 0xffffff);
			else if (d->file.map[y / 10][x / 10] == '1')
				my_mlx_pixel_put(d, x, y, 0x000000);
			if ((x < (d->pc._x * 10) + 3 && x > (d->pc._x * 10) - 3) \
				&& y < (d->pc._y * 10) + 3 && y > (d->pc._y * 10) - 3)
				my_mlx_pixel_put(d, x, y, 0xff0000);
			if (x < (d->pc._x + cos(d->pc.face_rad)) * 10 + 2 \
				&& x > (d->pc._x + cos(d->pc.face_rad)) * 10 - 2 \
				&& y < (d->pc._y - sin(d->pc.face_rad)) * 10 + 2 \
				&& y > (d->pc._y - sin(d->pc.face_rad)) * 10 - 2)
				my_mlx_pixel_put(d, x, y, 0x00ff00);
		}
	}
}

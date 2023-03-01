/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:39:27 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/01 08:45:19 by amiguez          ###   ########.fr       */
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
			if (d->file.map[y / 10][x / 10] == '1')
				my_mlx_pixel_put(d, x, y, 0x000000);
		}
	}
	
}

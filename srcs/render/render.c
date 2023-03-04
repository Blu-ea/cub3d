/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:03:04 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/04 07:02:00 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putcrossair(t_data *d);

int	ft_render(t_data *data)
{
	t_data	*d;
	int		x;
	int		y;

	d = data;
	x = -1;
	while (++x < S_WIDTH)
	{
		y = -1;
		while (++y < S_LENGTH)
		{
			if (y < S_LENGTH / 2)
				my_mlx_pixel_put(d, x, y, (int)d->txr.plan[C_].i_v);
			else
				my_mlx_pixel_put(d, x, y, (int)d->txr.plan[F_].i_v);
		}
	}

	// Loup se greffe ici
	ft_putwall(d);

	x = 0;
	y = 0;
	ft_putcrossair(d);
	ft_mini_map(d);
	mlx_mouse_get_pos(d->mlx.ptr, d->mlx.win, &x, &y);
	if (!mlx_in_bound(x, y))
	{
		// printf ("mouse x,y = %d,%d\n", x, y);
		my_mlx_pixel_put(d, x, y, 0xffffff);
	}
	mlx_put_image_to_window(d->mlx.ptr, d->mlx.win, d->n_image.img, 0, 0);
	return (0);
}

void	ft_putcrossair(t_data *d)
{
	int	x;
	int	y;

	x = (S_WIDTH / 2) - 6;
	while (++x < (S_WIDTH / 2) + 5)
	{
		y = (S_LENGTH / 2) - 31;
		while (++y < (S_LENGTH / 2) + 30)
			my_mlx_pixel_put (d, x, y, 0x000000);
	}
	x = (S_WIDTH / 2) - 31;
	while (++x < (S_WIDTH / 2) + 30)
	{
		y = (S_LENGTH / 2) - 6;
		while (++y < (S_LENGTH / 2) + 5)
			my_mlx_pixel_put (d, x, y, 0x000000);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:39:03 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/08 10:58:26 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_xpm_img(t_data *d);
int	ft_create_image(t_data *d, int length, int width);

int	pars_mlx(t_data *d)
{
	d->mlx.ptr = mlx_init();
	if (!d->mlx.ptr)
		return (d->err_code = MLX_INIT_FAIL, EXIT_FAILURE);
	d->mlx.win = mlx_new_window(d->mlx.ptr, S_WIDTH, S_LENGTH, "Cub3D");
	if (!d->mlx.win)
		return (d->err_code = MLX_WIN_FAIL, EXIT_FAILURE);
	if (ft_create_image(d, S_WIDTH, S_LENGTH))
		return (EXIT_FAILURE);
	if (ft_xpm_img(d))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_xpm_img(t_data *d)
{
	int	width;
	int	height;
	int	i;

	i = -1;
	while (++i < 4)
	{
		d->txr.wall[i].img = mlx_xpm_file_to_image \
			(d->mlx.ptr, d->txr.path[i], &width, &height);
		if (!d->txr.wall[i].img)
			return (d->err_code = XPM_IMAGE_FAILED, EXIT_FAILURE);
		if (width != height)
			return (d->err_code = BAD_TEXTURE, EXIT_FAILURE);
		d->txr.wall[i].size = width;
		d->txr.wall[i].addr = mlx_get_data_addr(d->txr.wall[i].img, \
			&d->txr.wall[i].bit_per_pixel, \
			&d->txr.wall[i].line_length, &d->txr.wall[i].endian);
	}
	if (d->txr.wall[0].size != d->txr.wall[1].size || \
			d->txr.wall[0].size != d->txr.wall[2].size || \
			d->txr.wall[0].size != d->txr.wall[3].size)
		return (d->err_code = BAD_TEXTURE, EXIT_FAILURE);
	d->txr.size = d->txr.wall[0].size;
	return (EXIT_SUCCESS);
}

int	ft_create_image(t_data *d, int x, int y)
{
	d->n_image.img = mlx_new_image(d->mlx.ptr, x, y);
	if (!d->n_image.img)
		return (d->err_code = MLX_NEW_IMG_FAILED, EXIT_FAILURE);
	d->n_image.addr = mlx_get_data_addr(d->n_image.img, \
		&d->n_image.bit_per_pixel, \
		&d->n_image.line_length, &d->n_image.endian);
	return (EXIT_SUCCESS);
}

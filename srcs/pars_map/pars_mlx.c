/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:39:03 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/04 01:40:40 by amiguez          ###   ########.fr       */
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
		d->txr._face[i] = mlx_xpm_file_to_image \
			(d->mlx.ptr, d->txr.path[0], &width, &height);
		if (!d->txr._face[i])
			return (d->err_code = XPM_IMAGE_FAILED, EXIT_FAILURE);
		if (width != height && d->txr.size != width && d->txr.size != 0)
			return (d->err_code = BAD_TEXTURE, EXIT_FAILURE);
	}
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

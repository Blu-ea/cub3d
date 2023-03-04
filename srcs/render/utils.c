/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:24:14 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/04 08:47:03 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_in_bound(int x, int y)
{
	if (x < 0 || x > S_WIDTH)
		return (EXIT_FAILURE);
	if (y < 0 || y > S_LENGTH)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_in_bound(int x, int y, t_data *d)
{
	if (y > d->file.length || y < 0)
		return (0);
	if (x > ft_strlen(d->file.map[y]) || x < 0)
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (mlx_in_bound(x, y))
		return ;
	dst = d->n_image.addr + (y * d->n_image.line_length + x * \
		(d->n_image.bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

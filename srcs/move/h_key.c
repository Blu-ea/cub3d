/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:21 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/10 10:41:10 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key(int key, t_data *data)
{
	t_data		*d;

	d = data;
	if (key == K_ESC)
		mlx_loop_end (d->mlx.ptr);
	else if (key == K_W || key == K_S || key == K_A || key == K_D \
	|| key == K_UP || key == K_DOWN)
		ft_move(key, d);
	else if (key == K_LEFT || key == K_RIGHT || key == K_E || key == K_Q)
		ft_rotate(key, d);
	else if (key == K_SPACE)
		cast_a_ray(d, S_LENGTH / 2, true);
	return (0);
}

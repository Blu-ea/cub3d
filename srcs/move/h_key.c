/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:21 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/02 19:41:24 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key(int key, t_data *data)
{
	t_data		*d;

	d = data;
	if (key == K_ESC)
		mlx_loop_end (d->mlx.ptr);
	else if (key == K_W || key == K_S || key == K_A || key == K_D)
		ft_move(key, d);
	else if (key == K_LEFT || key == K_RIGHT)
		ft_rotate(key, d);
	return (0);
}

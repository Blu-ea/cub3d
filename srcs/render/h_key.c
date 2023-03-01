/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:21 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/01 06:47:12 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key(int key, void *data)
{
	t_data		*d;
	static int	hide;

	d = data;
	if (key == K_ESC)
		mlx_loop_end (d->mlx.ptr);
	else if (key == K_A || key == K_LEFT)
		ft_move(key, d);
	else if (key == K_H && hide == 0)
	{
		mlx_mouse_hide(d->mlx.ptr, d->mlx.win);
		hide = 1;
	}
	else if (key == K_H && hide == 1)
	{
		mlx_mouse_show(d->mlx.ptr, d->mlx.win);
		hide = 0;
	}
	return (0);
}

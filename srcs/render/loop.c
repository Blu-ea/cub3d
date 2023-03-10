/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:01 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/10 10:04:46 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_data *d)
{
	mlx_hook (d->mlx.win, ON_KEYDOWN, (1L << 0), ft_key, d);
	mlx_hook(d->mlx.win, ON_DESTROY, (1L << 0), &ft_exitgame, d);
	mlx_mouse_hook (d->mlx.win, ft_mouse, d);
	mlx_loop_hook (d->mlx.ptr, ft_render, d);
	mlx_loop(d->mlx.ptr);
}

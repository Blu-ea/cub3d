/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:01 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/27 21:24:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_data *d)
{
	// mlx_key_hook(d->mlx.win, ft_hook, d);
	mlx_hook (d->mlx.win, ON_KEYDOWN, (1L << 0), ft_hook, d);
	mlx_loop(d->mlx.ptr);
}

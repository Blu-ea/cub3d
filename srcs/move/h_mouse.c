/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:45:54 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/14 16:06:55 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int button, int x, int y, t_data *d)
{
	(void) x;
	(void) y;
	if (button == RMB && !d->mouse_hide)
	{
		mlx_mouse_hide(d->mlx.ptr, d->mlx.win);
		d->mouse_hide = 1;
	}
	else if (button == RMB && d->mouse_hide)
	{
		mlx_mouse_show(d->mlx.ptr, d->mlx.win);
		d->mouse_hide = 0;
	}
	printf ("x,y = %d,%d\n", x, y);
	printf ("mouse button == %d\n", button);
	return (0);
}

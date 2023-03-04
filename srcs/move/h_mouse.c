/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:45:54 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/02 18:02:33 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int button, int x, int y, t_data *d)
{
	static int	hide;

	(void) x;
	(void) y;
	if (button == RMB && !hide)
	{
		mlx_mouse_hide(d->mlx.ptr, d->mlx.win);
		hide = 1;
	}
	else if (button == RMB && hide)
	{
		mlx_mouse_show(d->mlx.ptr, d->mlx.win);
		hide = 0;
	}
	else if (button == LMB)
		printf ("x,y = %d,%d\n", x, y);
	return (0);
}

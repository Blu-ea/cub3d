/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:37:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/04 09:21:08 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	init_draw(t_rayc *r, t_draw *w);

// void	wall_slice(t_data *d, t_rayc *r)
// {
// 	t_draw	draw;

// 	(void)d; // je sais pas encore si besoin
// 	init_draw(r, &draw);
// }

// // Calculate the distance to the wall
// static void	init_draw(t_rayc *r, t_draw *w)
// {
// 	if (r->side == true)
// 		w->pwd = r->stockxy.x - r->uss.x;
// 	else
// 		w->pwd = r->stockxy.y - r->uss.y;
// 	w->sh = (int)(S_LENGTH / w->pwd);
// }
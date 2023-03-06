/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:37:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/06 06:49:15 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_draw(t_rayc *r, t_draw *w);
static void	draw_the_slice(t_data *d, t_draw *w, int x);

void	wall_slice(t_data *d, t_rayc *r, int x)
{
	t_draw	draw;

	init_draw(r, &draw);
	draw_the_slice(d, &draw, x);
}

// Calculate the perpendicular wall distance (pwd) to determine the slice height (sh)
// then get the two points to draw a line
static void	init_draw(t_rayc *r, t_draw *w)
{

	// calcul du pwd ici
	if (r->side == true)
		w->pwd = r->stockxy.x - r->uss.x;
	else
		w->pwd = r->stockxy.y - r->uss.y;
		
	printf("perp wall distance : %f ---> height : %d\n", w->pwd, w->sh);//checking


	w->sh = (int)(S_LENGTH / w->pwd);
	w->start = -w->sh / 2 + S_LENGTH / 2;
	if (w->start < 0)
		w->start = 0;
	w->end = w->sh / 2 + S_LENGTH / 2;
	if (w->end >= S_LENGTH)
		w->end = S_LENGTH - 1;
	
	printf("slice from %d to %d ( %d px)\n", w->start, w->end, w->end - w->start); // checking
}

static void	draw_the_slice(t_data *d, t_draw *w, int x)
{
	int y;

	y = w->start;
	while (y <= w->end)
	{
		my_mlx_pixel_put(d, x, y, BLUE4);
		y++;
	}
}
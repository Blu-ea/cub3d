/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:37:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 14:59:16 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_draw(t_rayc *r, t_draw *w);
static void	draw_the_slice(t_data *d, t_rayc *r, t_draw *w, int x);
static int	get_color(t_pixi *pixi);

void	wall_slice(t_data *d, t_rayc *r, int x)
{
	t_draw	draw;

	init_draw(r, &draw);
	if (d->ghost)
		draw_the_slice(d, r, &draw, x);
	else
		draw_the_text(d, r, &draw, x);
}

// Calculate the perpendicular wall distance (pwd)
// to determine the slice height (sh)
// then get the two points to draw a line
static void	init_draw(t_rayc *r, t_draw *w)
{
	if (r->side == true)
		w->pwd = r->stockxy.x - r->uss.x;
	else
		w->pwd = r->stockxy.y - r->uss.y;
	w->sh = (int)(S_LENGTH / w->pwd);
	w->start = -w->sh / 2 + S_LENGTH / 2;
	if (w->start < 0)
		w->start = 0;
	w->end = w->sh / 2 + S_LENGTH / 2;
	if (w->end >= S_LENGTH)
		w->end = S_LENGTH - 1;
}

static void	draw_the_slice(t_data *d, t_rayc *r, t_draw *w, int x)
{
	t_pixi	pixi;
	int		color;

	pixi.x = x;
	pixi.card = get_cardinal(d, r);
	pixi.y = w->start;
	color = get_color(&pixi);
	while (pixi.y <= w->end)
	{
		my_mlx_pixel_put(d, pixi.x, pixi.y, color);
		pixi.y++;
	}
}

static int	get_color(t_pixi *pixi)
{
	int	color;

	if (pixi->card == NO_)
		color = NO_COL_0;
	else if (pixi->card == SO_)
		color = SO_COL_0;
	else if (pixi->card == EA_)
		color = SO_COL_1;
	else
		color = NO_COL_1;
	return (color);
}

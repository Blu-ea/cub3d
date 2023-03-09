/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:37:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/09 10:06:41 by loumarti         ###   ########lyon.fr   */
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
	if (d->ghost) /*ghostmode*/ // ('!' si on veut switch en debug)
		draw_the_slice(d, r, &draw, x);
	else
		draw_the_text(d, r, &draw, x);
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
		


	w->sh = (int)(S_LENGTH / w->pwd);
	w->start = -w->sh / 2 + S_LENGTH / 2;
	if (w->start < 0)
		w->start = 0;
	w->end = w->sh / 2 + S_LENGTH / 2;
	if (w->end >= S_LENGTH)
		w->end = S_LENGTH - 1;
	

	// printf("perp wall distance : %f ---> height : %d\n", w->pwd, w->sh);//checking
	// printf("slice from %d to %d ( %d px)\n", w->start, w->end, w->end - w->start); // checking
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
		// [2] - recup l'info du pixel a copier depuis le buffer texture
		// deduire la position exacte en fonction de l'intersection ?

		my_mlx_pixel_put(d, pixi.x, pixi.y, color);
		// if (r->side)
		// 	my_mlx_pixel_put(d, x, y, NO_COL_0);
		// else
		// 	my_mlx_pixel_put(d, x, y, NO_COL_1);
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
	return color;
}
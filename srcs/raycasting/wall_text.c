/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:25:47 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/11 07:24:30 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_pixel_color(t_new_image img, t_ivect *pos);
static t_ivect	get_tile_index(t_data *d, t_rayc *r, t_draw *w, t_pixi *pixi);
static void		adjust_tile_y(t_data *d, t_draw *w, int pixiy, t_ivect *ti);

void	draw_the_text(t_data *d, t_rayc *r, t_draw *w, int x)
{
	t_ivect	ti;
	t_pixi	pixi;
	int		snip;
	int		offset;

	pixi.x = x;
	pixi.card = get_cardinal(d, r);
	offset = 0;
	if (w->sh > S_LENGTH)
		offset = (w->sh - S_LENGTH) / 2;
	pixi.y = w->start + offset;
	ti = get_tile_index(d, r, w, &pixi);
	while (pixi.y - offset <= w->end)
	{
		snip = get_pixel_color(d->txr.wall[pixi.card], &ti);
		my_mlx_pixel_put(d, pixi.x, pixi.y - offset, snip);
		pixi.y++;
		adjust_tile_y(d, w, pixi.y, &ti);
	}
}

// x : use floating value as percentage
// y : A basic proportion calcul beetween wall slice height and tile height
static t_ivect	get_tile_index(t_data *d, t_rayc *r, t_draw *w, t_pixi *pixi)
{
	double		wip;
	t_ivect		ti;
	int			height;

	height = w->sh;
	if (height == 0)
	{
		ti.x = 0;
		ti.y = 0;
		return (ti);
	}
	if (r->side == false)
		wip = fabs(fmod(r->inter.x, 1));
	else
		wip = fabs(fmod(r->inter.y, 1));
	ti.x = (int)((double)d->txr.size * wip);
	ti.y = ((pixi->y - w->start) * d->txr.size) / height;
	return (ti);
}

static void	adjust_tile_y(t_data *d, t_draw *w, int pixiy, t_ivect *ti)
{
	if (w->sh == 0)
		ti->y = 0;
	else
		ti->y = ((pixiy - w->start) * d->txr.size) / abs(w->sh);
}

static int	get_pixel_color(t_new_image img, t_ivect *pos)
{
	char	*char_color;
	int		*color;

	char_color = img.addr + (pos->y * img.line_length) \
	+ (pos->x * img.bit_per_pixel / 8);
	color = (int *)char_color;
	return (*color);
}

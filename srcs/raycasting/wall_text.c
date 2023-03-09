/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:25:47 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/09 14:11:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_pixel_color(t_new_image img, t_ivect *pos);
static t_ivect	get_tile_index(t_data *d, t_rayc *r, t_draw *w, t_pixi *pixi);
static void		adjust_tile_y(t_data *d, t_draw *w, int pixiy, t_ivect *ti);

void	draw_the_text(t_data *d, t_rayc *r, t_draw *w, int x)
{
	t_ivect	ti;	//texture tile index in x-axis
	t_pixi	pixi; //le pixel a print
	int		snip; //l'echantillon de couleur collecte dans le buffer de la tile

	pixi.x = x;
	pixi.card = get_cardinal(d, r);
	// printf("cardinal = %d -- %s\n", pixi.card, d->txr.path[pixi.card]); //checking
	pixi.y = w->start;

	ti = get_tile_index(d, r, w, &pixi);
	// printf("tile index : (%d , %d)\n", ti.x, ti.y); //checking

	while (pixi.y <= w->end)
	{
		// printf("snip at point(%d, %d)\n", ti.x, ti.y); //checking
		snip = get_pixel_color(d->txr.wall[pixi.card], &ti);
		my_mlx_pixel_put(d, pixi.x, pixi.y, snip);
		pixi.y++;
		adjust_tile_y(d, w, pixi.y, &ti);
	}
}

// x : use floating value as percentage
// y : A basic proportion calcul beetween wall slice height and tile height
static t_ivect	get_tile_index(t_data *d, t_rayc *r, t_draw *w, t_pixi *pixi)
{
	double	wip; //wall index percent
	t_ivect		ti; //tile index
	int		height; //slice height

	height =  w->sh; //w->end - w->start;
	if (r->side)
		wip = fmod(r->inter.x , 1);
	else
		wip = fmod(r->inter.y , 1);
	ti.x = (int)((double)d->txr.size * wip);
	// printf("pixi->y : %d  |  d->txr.size : %d  | height : %d\n", pixi->y, d->txr.size, w->sh);

	ti.y = ((pixi->y - w->start) * d->txr.size) / height;
	return (ti);
}

static void	adjust_tile_y(t_data *d, t_draw *w, int pixiy, t_ivect *ti)
{
	ti->y = ((pixiy - w->start) * d->txr.size) / abs(w->sh);
}

static int	get_pixel_color(t_new_image img, t_ivect *pos)
{
	char	*char_color;
	int		*color;

	char_color = img.addr + (pos->y * img.line_length) + (pos->x * img.bit_per_pixel / 8);
	color = (int *)char_color;

	return (*color);
}
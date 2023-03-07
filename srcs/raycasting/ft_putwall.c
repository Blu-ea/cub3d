/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:09:24 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/07 15:35:22 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	test_texture(t_data *d, t_ivect *here); // only for testing/learning
// static int	get_pixel_color(t_new_image *img, t_ivect *pos); // only for testing

void	ft_putwall(t_data *d)
{
	int	x;

	x = 0;
	while (x < S_WIDTH)
	{
		cast_a_ray(d, x);
		x++;
	}

	// test en lancant un seul rayon tout droit
	// cast_a_ray(d, S_WIDTH / 2);

	// test en lancant un rayon non droit (eucli != perp)
	// cast_a_ray(d, (S_WIDTH / 2) - 500);
	
	// Test pour comprendre comment utiliser les textures
	// t_ivect here = init_ivect(800, 1000);
	// test_texture(d, &here);
}

// // only for testing/learning
// static void	test_texture(t_data *d, t_ivect *here)
// {
// 	t_new_image	text0;
// 	t_ivect		point;
// 	int			color;

// 	text0.img = d->txr._face[0];
// 	text0.addr = mlx_get_data_addr(text0.img, &text0.bit_per_pixel, &text0.line_length, &text0.endian);
// 	point.x = 0;
// 	point.y = 0;

	
// 	// printf("Txr size = %d\n", d->txr.size);	//checking

// 	while (point.y < d->txr.size)
// 	{
// 		point.x = 0;
// 		while (point.x < d->txr.size)
// 		{
// 			color = get_pixel_color(&text0, &point);
// 			my_mlx_pixel_put(d, point.x + here->x, point.y + here->y, color);
// 			point.x++;
// 		}
// 		point.y++;
// 	}
// }

// static int	get_pixel_color(t_new_image *img, t_ivect *pos)
// {
// 	char	*char_color;
// 	int		*color;

// 	char_color = img->addr + (pos->y * img->line_length) + (pos->x * img->bit_per_pixel / 8);
// 	color = (int *)char_color;

// 	return (*color);
// }

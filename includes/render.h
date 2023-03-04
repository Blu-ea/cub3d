/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:38 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/04 09:02:42 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

void	game_loop(t_data *d);

int		ft_render(t_data *d);

void	ft_mini_map(t_data *d);
int		mlx_in_bound(int x, int y);
int		map_in_bound(int x, int y, t_data *d);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif

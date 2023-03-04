/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:39:05 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/02 19:41:20 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "cub3d.h"

void	ft_rotate(int key, t_data *d);

int		ft_key(int key, t_data *data);
int		ft_mouse(int button, int x, int y, t_data *d);

void	ft_move(int key, t_data *d);

#endif
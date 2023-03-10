/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:06:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 10:46:36 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exitgame(t_data *d)
{
	return (ft_key(K_ESC, d));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvect_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:26:43 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/14 08:51:49 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dvect	init_dvect(double x, double y)
{
	t_dvect	new;

	new.x = x;
	new.y = y;
	return (new);
}

void	rotation_matrix(t_dvect *dir, double rot)
{
	double	stamp;

	stamp = dir->x;
	dir->x = dir->x * cos(rot) - dir->y * sin(rot);
	dir->y = stamp * sin(rot) + dir->y * cos(rot);
}

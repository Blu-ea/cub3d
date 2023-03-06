/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:05:08 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/06 07:24:09 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_rayc1(t_rayc *r)
{
	printf("r->start : (%f,%f)\n", r->start.x, r->start.y);
	printf("r->map : (%d,%d)\n", r->map.x, r->map.y);
	printf("r->dir : (%f,%f)\n", r->dir.x, r->dir.y);
	printf("r->uss : (%f,%f)\n", r->uss.x, r->uss.y);
	printf("hit = %d -- cam : %f\n", r->hit, r->cam);
}
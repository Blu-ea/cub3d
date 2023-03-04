/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:05:08 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/04 11:39:42 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_rayc1(t_rayc *r)
{
	printf("r->start : (%f,%f)\n", r->start.x, r->start.y);
	printf("r->map : (%d,%d)\n", r->map.x, r->map.y);
	printf("r->dir : (%f,%f)\n", r->dir.x, r->dir.y);
	printf("r->uss : (%f,%f)\n", r->uss.x, r->uss.y);
	printf("hit = %d\n", r->hit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:55:45 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 10:10:52 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_data input)
{
	int	i;

	printf ("====== Debug ======\n");
	i = -1;
	while (input.file.map[++i])
		printf ("%s\n", input.file.map[i]);
	printf ("     =========\n");
	printf ("======  End  ======\n");
}

void	print_d(t_data d)
{
	printf ("====== Debug ======\n");
	printf ("Path txr[NO] = '%s'\n", d.txr.path[NO_]);
	printf ("Path txr[SO] = '%s'\n", d.txr.path[SO_]);
	printf ("Path txr[EA] = '%s'\n", d.txr.path[EA_]);
	printf ("Path txr[WE] = '%s'\n", d.txr.path[WE_]);
	printf ("       ====\n");
	printf ("Color F_.A = %d\n", d.txr.plan[F_].argb.a);
	printf ("Color F_.R = %d\n", d.txr.plan[F_].argb.r);
	printf ("Color F_.G = %d\n", d.txr.plan[F_].argb.g);
	printf ("Color F_.B = %d\n", d.txr.plan[F_].argb.b);
	printf ("Color F_.Value = %p\n", d.txr.plan[F_].value);
	printf ("       ====\n");
	printf ("Color C_.A = %d\n", d.txr.plan[C_].argb.a);
	printf ("Color C_.R = %d\n", d.txr.plan[C_].argb.r);
	printf ("Color C_.G = %d\n", d.txr.plan[C_].argb.g);
	printf ("Color C_.B = %d\n", d.txr.plan[C_].argb.b);
	printf ("Color C_.Value = %p\n", d.txr.plan[C_].value);
	printf ("       ====\n");
	printf ("Mlx_ptr = %p\n", d.mlx.ptr);
	printf ("======  End  ======\n");
}

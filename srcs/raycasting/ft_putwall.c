/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:09:24 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/06 16:21:37 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	
	

}

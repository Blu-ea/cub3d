/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivect_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:54:23 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/09 19:12:36 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "i_vector.h"

t_ivect	init_ivect(int x, int y)
{
	t_ivect	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_ivect	init_ivect_d(double x, double y)
{
	t_ivect	new;

	if (x < 0)
		x -= 1;
	if (y < 0)
		y -= 1;
	new.x = x;
	new.y = y;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvect_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:26:43 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/04 11:40:12 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_vector.h"

t_dvect	init_dvect(double x, double y)
{
	t_dvect	new;

	new.x = x;
	new.y = y;
	return (new);
}

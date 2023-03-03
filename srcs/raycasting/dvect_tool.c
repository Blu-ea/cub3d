/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvect_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:26:43 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/03 09:55:10 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "d_vector.h"

t_dvect	init_dvect(double x, double y)
{
	t_dvect	new;

	new.x = x;
	new.y = y;
	return (new);
}
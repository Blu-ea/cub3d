/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivect_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:54:23 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/03 10:56:46 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "i_vector.h"

t_ivect	init_ivect(int x, int y)
{
	t_ivect	new;

	new.x = x;
	new.y = y;
	return (new);
}
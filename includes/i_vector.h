/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:51:38 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/10 15:12:56 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_VECTOR_H
# define I_VECTOR_H

typedef struct s_ivect {
	int		x;
	int		y;

}			t_ivect;

t_ivect	init_ivect(int x, int y);
t_ivect	init_ivect_d(double x, double y);

#endif

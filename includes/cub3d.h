/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:46:29 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 09:58:35 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>

# include "pars_cub.h"
# include "debug.h"

# include "../libft/includes/libft.h"

typedef struct rgb
{
	char	a;
	char	r;
	char	g;
	char	b;
}	t_rgb;

typedef union color
{
	void	*value;
	t_rgb	argb;
}	t_color;

typedef struct data
{
	char	**map;

	int		_x;
	int		_y;

	t_color	floor;
	t_color	roof;

	void	*_so;
	void	*_no;
	void	*_we;
	void	*_ea;

}	t_data;

#endif
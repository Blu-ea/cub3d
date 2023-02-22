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
# include "limits.h"

# include "../libft/includes/libft.h"

typedef struct s_rgb
{
	char	a;
	char	r;
	char	g;
	char	b;
}	t_rgb;

typedef union s_color
{
	void	*value;
	t_rgb	argb;
}	t_color;

typedef struct s_textures
{
	t_color	floor;
	t_color	roof;

	void	*_so;
	char	*path_so;
	void	*_no;
	char	*path_no;
	void	*_we;
	char	*path_we;
	void	*_ea;
	char	*path_ea;

}	t_textures;


typedef struct s_player_info
{

	float	_x;
	float	_y;

	double	face_x;
	double	face_y;

}	t_player_data;

typedef struct s_data
{
	char	**map;

	char	*file_content;

}	t_data;

#endif
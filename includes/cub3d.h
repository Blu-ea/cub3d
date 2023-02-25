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

// # include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# include "pars_cub.h"
# include "debug.h"
# include "../mlx_linux/mlx.h"

# include "../libft/includes/libft.h"

# define NO_ 0
# define SO_ 1
# define EA_ 2
# define WE_ 3

# define F_ 0
# define C_ 1

typedef enum e_error_list
{
	SUCCES,
	WRONG_ARG,
	WRONG_FILE,
	ERROR_OPEN,
	ERROR_MALLOC,
	TROUBLE_READ,
	DOUBLE_DEF_TXR,
	DOUBLE_DEF_COLOR,
	NOT_VALID_TXR,
	NOT_VALID_COLOR,
	MISSING_COLLOR,
	MISSING_TXR,
	NOT_VALID_MAP,
	WRONG_INPUT_MAP,
	DOUBLE_STARTING_POINT,
}	t_error;

typedef struct s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_rgb;

typedef union s_color
{
	void	*value;
	t_rgb	argb;
}	t_color;

typedef struct s_textures
{
	t_color	plan[2];
	char	*path[4];
	void	*_face[4];

}	t_textures;

typedef struct s_player_info
{
	float	_x;
	float	_y;

	double	face_x;
	double	face_y;

	char	start_face;
}	t_player;

typedef struct s_file
{
	char	**map;
	int		fd;
	char	*all;
}	t_file;

typedef struct s_mlx_data
{
	void	*ptr;
}	t_mlx_d;

typedef struct s_data
{
	t_file		file;
	t_textures	txr;
	t_error		err_code;
	t_player	pc;
	t_mlx_d		mlx;
}	t_data;

#endif
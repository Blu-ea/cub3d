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
# include "render.h"
# include "raycasting.h"
# include "../mlx_linux/mlx.h"
# include "key.h"

# include "../libft/includes/libft.h"

# define NO_ 0
# define SO_ 1
# define EA_ 2
# define WE_ 3

# define F_ 0
# define C_ 1
	// WIDTH IS DEFINE FOR X
# define S_WIDTH 1900 
	// LENGTH IS DEFINE FOR Y
# define S_LENGTH 1700

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
	NO_STARTING_POINT,
	MLX_INIT_FAIL,
	MLX_WIN_FAIL,
	MLX_NEW_IMG_FAILED,
	MLX_MAP_FAILED,
	BAD_TEXTURE,
	XPM_IMAGE_FAILED,
}	t_error;

typedef struct s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_rgb;

typedef union u_color
{
	void	*value;
	t_rgb	argb;
	int		i_v;
}	t_color;

	/**** To free *****/
	/* path  0 to 4   */
	/* _face 0 to 4   */
	/******************/
typedef struct s_textures
{
	t_color	plan[2];
	char	*path[4];
	void	*_face[4];
	int		size;
}	t_textures;

typedef struct s_player_info
{
	double	_x;
	double	_y;

	double	face_rad;
	double	face_deg;

	char	start_face;
}	t_player;

	/**** To free ***********/
	/* Map (double pointer) */
	/* All                  */
	/************************/
typedef struct s_file
{
	char	**map;
	int		fd;
	char	*all;

	int		length;
	int		width;
}	t_file;

	/**** Need to destroy ***/
	/*		ptr & win		*/
	/************************/
typedef struct s_mlx_data
{
	void	*ptr;
	void	*win;
}	t_mlx_d;

	/**** Need to destroy ***/
	/*			img			*/
	/************************/
typedef struct s_new_image
{
	void	*img;
	char	*addr;
	int		endian;
	int		bit_per_pixel;
	int		line_length;
}	t_new_image;

typedef struct s_data
{
	t_file		file;
	t_textures	txr;
	t_error		err_code;
	t_player	pc;
	t_mlx_d		mlx;
	t_new_image	n_image;
}	t_data;

#endif
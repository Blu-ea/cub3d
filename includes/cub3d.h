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
# include "key.h"
# include "move.h"
# include "../mlx_linux/mlx.h"

// includes from loumarti
# include "raycasting.h"
# include "d_vector.h"
# include "i_vector.h"
# include <stdbool.h>

# include "../libft/includes/libft.h"

# ifndef MAP_ZOOM
#  define MAP_ZOOM 15 // size of 1x1 block on the minimap
# endif

# ifndef MAP_OFFSETX
#  define MAP_OFFSETX 100 //offset in pixel
# endif

# ifndef MAP_OFFSETY
#  define MAP_OFFSETY 100 //offset in pixel
# endif

# ifndef ROT
#  define ROT 2 // rotation speed
# endif

# ifndef MV_F
#  define MV_F 0.15 // mouvement speed : default was 0.25
# endif

# ifndef MV_RANGE
#  define MV_RANGE 0.20 // distance to keep player away from wall
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# define NO_ 0
# define SO_ 1
# define EA_ 2
# define WE_ 3
# define DO_ 4

# define F_ 0
# define C_ 1
	// WIDTH IS DEFINE FOR X
# define S_WIDTH 1900
	// LENGTH IS DEFINE FOR Y
# define S_LENGTH 1500

# define SUCCES_T "Nothing wrong"
# define WRONG_ARG_T "Wrong number of arg"
# define WRONG_FILE_T "Need a .cub file"
# define ERROR_OPEN_T "File not found"
# define ERROR_MALLOC_T "Malloc failled"
# define TROUBLE_READ_T "Read failed"
# define DOUBLE_DEF_TXR_T "Double Textures definition"
# define DOUBLE_DEF_COLOR_T "Double Color definition"
# define NOT_VALID_TXR_T "Need a .XPM file"
# define NOT_VALID_COLOR_T "Need a RRR,GGG,BBB Color"
# define MISSING_COLLOR_T "Missing a Color definition"
# define MISSING_TXR_T "Missing a Texture definition"
# define NOT_VALID_MAP_T "Map isn't valid"
# define WRONG_INPUT_MAP_T "Map need to contain only \
'01SEW' or space (and D in bonus cases)"
# define DOUBLE_STARTING_POINT_T "Double starting point in map"
# define NO_STARTING_POINT_T "Missing starting point"
# define MLX_INIT_FAIL_T "MLX initialisation Failed"
# define MLX_WIN_FAIL_T "MLX window creation failed"
# define MLX_NEW_IMG_FAILED_T "MLX image creation failed"
# define BAD_TEXTURE_T "MLX texture not valid"
# define XPM_IMAGE_FAILED_T "Creation of image failed"

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
	BAD_TEXTURE,
	XPM_IMAGE_FAILED,
	LST_ERRO_SIZE
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
	int		size;
}	t_new_image;

	/**** To free *****/
	/* path  0 to 4   */
	/* _face 0 to 4   */
	/******************/
typedef struct s_textures
{
	t_color		plan[2];
	char		*path[5];
	t_new_image	wall[5];
	int			size;
}	t_textures;

typedef struct s_player_info
{
	double	_x;
	double	_y;

	t_dvect	pln;
	t_dvect	dir;

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

typedef struct s_data
{
	t_file		file;
	t_textures	txr;
	t_error		err_code;
	t_player	pc;
	t_mlx_d		mlx;
	t_new_image	n_image;
	bool		ghost;
	bool		mouse_hide;
}	t_data;

#endif
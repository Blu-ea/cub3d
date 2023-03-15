/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:52:40 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/15 11:50:51 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include "d_vector.h"
# include "i_vector.h"
# include <stdbool.h>

//the range an action can be done, like open a door
# define ACTION_RANGE 1.5

// default background color to walls
# define NO_COL_0 0x67E6D4
# define NO_COL_1 0x5CB5A8
# define SO_COL_0 0x2a89a3
# define SO_COL_1 0x2b7d94
# define EA_COL_0 0x66eda5
# define EA_COL_1 0x51c989
# define WE_COL_0 0xffa754
# define WE_COL_1 0xde9149

typedef enum e_tile
{
	VOID,
	WALL,
	C_DOOR,
	O_DOOR
}			t_tile;

// pixel info needed to put on walls
typedef struct s_pixi
{
	int	x;
	int	y;
	int	card;

}				t_pixi;

// datas to draw each slice of wall
typedef struct s_draw
{
	double	pwd;
	int		sh;
	int		start;
	int		end;

}				t_draw;

typedef struct s_rayc
{
	t_dvect		start;
	t_ivect		map;
	t_dvect		dir;
	double		cam;
	t_dvect		uss;
	bool		hit;
	bool		inf;
	bool		side;
	double		length;
	t_dvect		inter;
	t_tile		tile;
	t_dvect		step;
	t_dvect		stockxy;

}				t_rayc;

// raycasting
void	ft_putwall(t_data *d);
void	cast_a_ray(t_data *d, int x, bool action);

// raycasting utilitaries
double	get_dir_x(double angle);
double	get_dir_y(double angle);
void	get_unit_step(t_rayc *r);
t_tile	ft_what_tile(int x, int y, t_data *d);
int		ft_inf_wall(t_rayc *r, t_data *d);

// draw wall
void	wall_slice(t_data *d, t_rayc *r, int x);
void	draw_the_text(t_data *d, t_rayc *r, t_draw *w, int x);
int		get_cardinal(t_data *d, t_rayc *r);

// actions
void	action_door(t_data *d, t_rayc *r);

// debug tools
void	print_rayc1(t_rayc *r);
void	toogle_bool(bool *boolean);

#endif
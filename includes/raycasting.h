/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:52:40 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/09 15:31:06 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include "d_vector.h"
# include "i_vector.h"
# include <stdbool.h>

//the 2d raycaster version of camera plane
# define PLANE_X 0
# define PLANE_Y 0.25

// default background color to walls
# define NO_COL_0 0x67E6D4
# define NO_COL_1 0x5CB5A8
# define SO_COL_0 0x2a89a3
# define SO_COL_1 0x2b7d94
# define EA_COL_0 0x66eda5
# define EA_COL_1 0x51c989
# define WE_COL_0 0xffa754
# define WE_COL_1 0xde9149



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
	double	pwd; // perp wall distance
	int		sh; // slice wall height
	int		start;
	int		end;

}				t_draw;

typedef struct s_rayc
{
	// Ray start (set equal to player position)
	t_dvect		start;
	t_ivect		map; // the current tile coordinate INT vector

	//initial direction vector -> ray direction
	t_dvect		dir;// [?] a passer direct dans data ?  non mais pour cam c peut etre bien
	// => en dir du rayon
	
	// camera 
	double		cam; // [?] avec lui ? (camera ne change que dans une direction, double suffit ici)

	// scaling factor beetween hypotenuse
	// and a step unit direction to x or y axis
	// Unit Step Size
	t_dvect		uss;

	bool		hit; // was there a wall hit?
	bool		inf; // does the player looking outside of map
	bool		side; // was it a SN(false) or EW(true) wall
	double		length; // length or ray, maybe not usefull (we don't need a maxlength yet in perform_dda)
	t_dvect		inter; // intersection position : (maybe not needed) 

	//what direction to step in x or y-direction (either +1 or -1)
	t_dvect		step;

	// stocking the x length of ray and y length of ray
	// needed by the DDA algorithm wich will chose the shorter
	t_dvect		stockxy;

} t_rayc;

//raycasting
void	ft_putwall(t_data *d);
void	cast_a_ray(t_data *d, int x);

// raycasting utilitaries
double	get_dir_x(double angle);
double	get_dir_y(double angle);
void	get_unit_step(t_rayc *r);
int		ft_is_wall(int x, int y, t_data *d);
int		ft_inf_wall(t_rayc *r, t_data *d);

// draw wall
void	wall_slice(t_data *d, t_rayc *r, int x);
void	draw_the_text(t_data *d, t_rayc *r, t_draw *w, int x);
int		get_cardinal(t_data *d, t_rayc *r);

// debug
void	print_rayc1(t_rayc *r);

#endif
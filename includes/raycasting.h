/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:52:40 by loumarti          #+#    #+#             */
/*   Updated: 2023/03/03 12:23:57 by loumarti         ###   ########lyon.fr   */
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
# define PLANE_Y 0.66

// default background color to walls
# define BLUE4 0x67E6D4





typedef struct s_rayc {
	// Ray start (set equal to player position)
	t_dvect		start;
	t_ivect		map; // the current tile coordinate INT vector

	//initial direction vector
	t_dvect		dir;// [?] a passer direct dans data ?

	// scaling factor beetween hypotenuse
	// and a step unit direction to x or y axis
	// Unit Step Size
	t_dvect		uss;

	bool		hit; //was there a wall hit?
	bool		side; // was it a East or West wall
	double		length; // length or ray, maybe not usefull (we don't need a maxlength yet in perform_dda)
	t_dvect		inter; // intersection position : (maybe not needed) 

	//what direction to step in x or y-direction (either +1 or -1)
	t_dvect		step;

	// stocking the x length of ray and y length of ray
	// needed by the DDA algorithm wich will chose the shorter
	t_dvect		stockxy;

	


		// [?] a passer dans Data ? ou inutile pour notre loop ?
	// double	time; //time of current frame
	// double	old; //time of previous frame

	//calculate ray position and direction
	// double	cam_x;	//x-coordinate in camera space
	// double	ray_dir_x;
	// double	ray_dir_y;

	//which box of the map we're in // remplacer par start
	// t_ivect		map;
	
	// //length of ray from current position to next x or y-side
	// double	sd_x;
	// double	sd_y;
	// // sd stand for "side dist"

	// //length of ray from one x or y-side to next x or y-side
	// double	dd_x;
	// double	dd_y;
	// // dd stand for "delta dist"
	// double	perp_dist_wall;
	

	

	// int		side; //was a NS or a EW wall hit?

	// //infos to draw a line
	// int		l_h;
	// int		start;
	// int		end;
	// int		color;

} t_rayc;


void	ft_putwall(t_data *d);
void	cast_a_ray(t_data *d, int x);

// raycasting utilitaries functions
double	get_dir_x(double angle);
double	get_dir_y(double angle);
// double	get_delta_dir(double ray_dir_xy);
void	get_unit_step(t_rayc *r);

#endif
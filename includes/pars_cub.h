/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:14:45 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 11:03:42 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_CUB_H
# define PARS_CUB_H

# include "cub3d.h"

typedef struct s_data		t_data ;
typedef enum e_error_list	t_error ;

int		cub_pars(t_data *d, char **argv, int argc);

/*=====================*/

int		pars_infile(char *file, t_data *data);
int		ft_cub(char *file);
int		read_file(int fd, char **file);

int		pars_content(t_data *d);

void	ini_d_texture(t_data *d);
int		start_line(t_data *d, int i);

int		pars_map(t_data *d, char **file);
int		pars_xpm(t_data *d);
int		pars_mlx(t_data *d);

int		pars_map_start_l(char *line);

/*=====================*/

t_error	pars_error(t_data *d);

/*=====================*/

#endif
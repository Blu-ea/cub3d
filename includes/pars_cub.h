/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:14:45 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 08:27:52 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_CUB_H
# define PARS_CUB_H

# include "cub3d.h"
# include <fcntl.h>

/*=====================*/

t_data	pars_infile(char *file);

/*=====================*/

int		pars_error(char *promt, int err);

/*=====================*/

#endif
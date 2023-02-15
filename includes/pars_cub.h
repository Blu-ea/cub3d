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

# include <fcntl.h>

typedef struct data	t_data ;

/*=====================*/

t_data	pars_infile(char *file);
int		ft_cub(char *file);
t_data	fill_data(int fd);

/*=====================*/

void	pars_error(char *promt, int err);

/*=====================*/

#endif
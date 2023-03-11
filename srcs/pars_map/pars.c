/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:44:03 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/22 17:44:03 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_pars(t_data *d, char **argv, int argc)
{
	if (argc != 2)
		return (d->err_code = WRONG_ARG, pars_error(d));
	else if (pars_infile(argv[1], d))
		return (pars_error(d));
	else if (pars_content(d))
		return (pars_error(d));
	else if (pars_map(d, ft_split(d->file.all, '\n')))
		return (pars_error(d));
	else if (pars_mlx(d))
		return (pars_error(d));
	return (EXIT_SUCCESS);
}

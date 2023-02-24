/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:25:50 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 09:52:17 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_error	pars_error(t_data *d)
{
	printf ("path NO = '%s'\n", d->txr.path[0]);
	printf ("path SO = '%s'\n", d->txr.path[1]);
	printf ("path EA = '%s'\n", d->txr.path[2]);
	printf ("path WE = '%s'\n", d->txr.path[3]);
	printf ("=============\n");
	printf ("color = '%p'\n", d->txr.plan[0].value);
	printf ("color = '%p'\n", d->txr.plan[1].value);
	free(d->file.all);
	ft_free_2d_array(d->file.map);
	free(d->txr.path[0]);
	free(d->txr.path[1]);
	free(d->txr.path[2]);
	free(d->txr.path[3]);
	return (d->err_code);
}

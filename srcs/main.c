/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:22:05 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 10:09:08 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (cub_pars(&data, argv, argc))
		return (printf ("Failed\n"), 1);
	print_d(data);
	free(data.file.all);
	ft_free_2d_array(data.file.map);
	free(data.txr.path[0]);
	free(data.txr.path[1]);
	free(data.txr.path[2]);
	free(data.txr.path[3]);
}

void	init_data(t_data *data)
{
	data->file.all = NULL;
	data->file.fd = 0;
	data->file.map = NULL;
	data->pc._x = 0;
	data->pc._y = 0;
	data->pc.start_face = '0';
	data->pc.face_x = 0;
	data->pc.face_y = 0;
	data->txr.plan[0].value = 0x00000000;
	data->txr.plan[1].value = 0x00000000;
	data->txr.path[0] = NULL;
	data->txr.path[1] = NULL;
	data->txr.path[2] = NULL;
	data->txr.path[3] = NULL;
}

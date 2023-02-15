/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:19:30 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 08:51:09 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_cub.h"

t_data	pars_infile(char *file)
{
	int	fd;

	if (ft_cub(file) == EXIT_FAILURE)
		pars_error("Wrong file type (Need a .cub)", 1);
	fd = open(file, O_RDONLY);
	if (!fd)
		pars_error("Open failed", 2);
	return (fill_data(fd));
}

t_data	fill_data(int fd)
{
	t_data	data;
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
	}
}

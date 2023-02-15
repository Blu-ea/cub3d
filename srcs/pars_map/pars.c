/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:19:30 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 11:21:35 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_cub(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

t_data	fill_data(int fd)
{
	t_data	data;
	char	*temp;
	char	*input;

	input = get_next_line(fd);
	temp = get_next_line(fd);
	printf("%p %d\n", input, fd);
	while (temp)
	{
		input = ft_strjoin_free(input, temp, FREE_BOTH);
		temp = get_next_line(fd);
	}
	printf("%s\n", input);
	data.roof.value = (void *) 5;
	return (data);
}

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

int	pars_infile(char *file, t_data *d)
{
	int		fd;
	char	*file_content;

	(void) d;
	if (ft_cub(file) == EXIT_FAILURE)
		pars_error("Wrong file type (Need a .cub)", 1);
	fd = open(file, O_RDONLY);
	if (!fd)
		pars_error("Open failed", 2);
	if (read_file(fd, &d->file_content) || !d->file_content)
		return (printf ("failled read"), EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
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

int	read_file(int fd, char **file)
{
	char	*temp;

	*file = get_next_line(fd);
	temp = get_next_line(fd);
	*file = ft_strjoin_free(*file, temp, FREE_S1);
	while (temp != 0)
	{
		free(temp);
		temp = get_next_line(fd);
		*file = ft_strjoin_free(*file, temp, FREE_S1);
	}
	if (!file)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

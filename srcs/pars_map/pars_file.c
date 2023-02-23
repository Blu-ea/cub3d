/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:19:30 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/23 02:17:26 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_double_free(char **s1, char **s2);

int	pars_infile(char *file, t_data *d)
{
	int		fd;

	if (ft_cub(file) == EXIT_FAILURE)
		return (1);
	fd = open(file, O_RDONLY);
	if (!fd)
		return (1);
	if (read_file(fd, &d->file.all))
		return (d->err_code = ERROR_READ, 1);
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
	if (!*file || !temp)
		return (ft_double_free(file, &temp), ERROR_MALLOC);
	while (temp && *file)
	{
		free(temp);
		temp = get_next_line(fd);
		*file = ft_strjoin_free(*file, temp, FREE_S1);
	}
	if (!*file)
		return (ft_double_free(file, &temp), ERROR_MALLOC);
	return (EXIT_SUCCESS);
}

void	ft_double_free(char **s1, char **s2)
{
	if (*s1)
		free(*s1);
	if (*s2)
		free(*s2);
	*s1 = NULL;
	*s2 = NULL;
}

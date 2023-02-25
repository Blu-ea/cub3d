/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:09:08 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/24 19:28:22 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pars_map_fill(t_data *d, char **file);
int	pars_map_start_l(char *line);
int	pars_map_input(t_data *d, char **map);
int	pars_map_border(char **map, int i, int j, t_data *d);

int	pars_map(t_data *d, char **file)
{
	if (pars_map_fill(d, file))
		return (EXIT_FAILURE);
	if (pars_map_input(d, d->file.map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_map_fill(t_data *d, char **file)
{
	int	line;
	int	i;

	i = -1;
	if (!file)
		return (d->err_code = ERROR_MALLOC, EXIT_FAILURE);
	line = -1;
	while (file[++line] && pars_map_start_l(file[line]))
		free(file[line]);
	while (file[line + ++i])
		;
	d->file.map = malloc(sizeof(char *) * (i + 1));
	if (!d->file.map)
		return (d->err_code = ERROR_MALLOC, EXIT_FAILURE);
	d->file.map[i] = 0;
	while (i--)
		d->file.map[i] = file[line + i];
	free(file);
	return (EXIT_SUCCESS);
}

int	pars_map_start_l(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	pars_map_input(t_data *d, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (pars_map_border(map, i, j, d))
					return (EXIT_FAILURE);
			}
			else if (map[i][j] != ' ' && map[i][j] != '1')
				return (d->err_code = WRONG_INPUT_MAP, EXIT_FAILURE);
		}
	}
	if (d->pc._x == 0 || d->pc._y == 0)
		return (printf ("No starting position\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pars_map_border(char **map, int i, int j, t_data *d)
{
	if (i == 0 || j == 0)
		return (d->err_code = NOT_VALID_MAP, EXIT_FAILURE);
	if (i == ft_tablen(map) - 1 || j == ft_strlen(map[i]) - 1)
		return (d->err_code = NOT_VALID_MAP, EXIT_FAILURE);
	if (j > ft_strlen(map[i + 1]) - 1 || j > ft_strlen(map[i - 1]) - 1)
		return (d->err_code = NOT_VALID_MAP, EXIT_FAILURE);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (d->err_code = NOT_VALID_MAP, EXIT_FAILURE);
	if (map[i][j] != '0')
	{
		if (d->pc.start_face != '0')
			return (d->err_code = DOUBLE_STARTING_POINT, EXIT_FAILURE);
		d->pc.start_face = map[i][j];
		d->pc._y = i;
		d->pc._x = j;
	}
	return (EXIT_SUCCESS);
}

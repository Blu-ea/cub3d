/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:09:08 by amiguez           #+#    #+#             */
/*   Updated: 2023/03/11 16:07:10 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pars_map_fill(t_data *d, char **file);
int		pars_map_input(t_data *d, char **map);
int		pars_map_border(char **map, int i, int j, t_data *d);
void	pars_set_rotation(t_data *d);

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

int	pars_map_input(t_data *d, char **map)
{
	int	j;

	while (map[++d->file.length])
	{
		j = -1;
		while (map[d->file.length][++j])
		{
			if (ft_is_charset(map[d->file.length][j], "0NSEW"))
			{
				if (pars_map_border(map, d->file.length, j, d))
					return (EXIT_FAILURE);
			}
			else if (map[d->file.length][j] != ' ' \
					&& map[d->file.length][j] != '1')
				if (BONUS == 0 || map[d->file.length][j] != 'D')
					return (d->err_code = WRONG_INPUT_MAP, EXIT_FAILURE);
		}
		if (j > d->file.width)
			d->file.width = j;
	}
	if (d->pc._x == 0 || d->pc._y == 0)
		return (d->err_code = NO_STARTING_POINT, EXIT_FAILURE);
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
		d->pc._y = i + .5;
		d->pc._x = j + .5;
		pars_set_rotation(d);
		map[i][j] = '0';
	}
	return (EXIT_SUCCESS);
}

void	pars_set_rotation(t_data *d)
{
	double	rad;

	rad = M_PI;
	if (d->pc.start_face == 'N')
		rad = M_PI / 2;
	if (d->pc.start_face == 'S')
		rad = 3 * M_PI / 2;
	if (d->pc.start_face == 'E')
		rad = 0;
	d->pc.dir.x = cos(rad);
	d->pc.dir.y = -sin(rad);
	d->pc.pln.x = 0;
	d->pc.pln.y = 0;
	if (d->pc.start_face == 'N' || d->pc.start_face == 'S')
		d->pc.pln.x = .66;
	if (d->pc.start_face == 'W' || d->pc.start_face == 'E')
		d->pc.pln.y = .66;
	if (d->pc.start_face == 'W' || d->pc.start_face == 'S')
	{
		d->pc.pln.x *= -1;
		d->pc.pln.y *= -1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:55:50 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/23 07:23:16 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		add_texture(t_data *d, int face, int i);
int		pars_texture_f(t_data *d);
int		add_color(t_data *d, int plan, int i);
int		pars_color_f(t_data *d, char **src, int ret);

int	pars_content(t_data *d)
{
	int	i;

	ini_d_texture(d);
	i = -1;
	while (d->file.all[++i] != '\0')
	{
		if (!ft_strncmp(&d->file.all[i], "NO ", 3) && start_line(d, i))
				i = add_texture(d, NO_, i + 3);
		else if (!ft_strncmp(&d->file.all[i], "SO ", 3) && start_line(d, i))
				i = add_texture(d, SO_, i + 3);
		else if (!ft_strncmp(&d->file.all[i], "EA ", 3) && start_line(d, i))
				i = add_texture(d, EA_, i + 3);
		else if (!ft_strncmp(&d->file.all[i], "WE ", 3) && start_line(d, i))
				i = add_texture(d, WE_, i + 3);
		else if (!ft_strncmp(&d->file.all[i], "F ", 2) && start_line(d, i))
				i = add_color(d, F_, i + 2);
		else if (!ft_strncmp(&d->file.all[i], "C ", 2) && start_line(d, i))
				i = add_color(d, C_, i + 2);
		if (i == -1)
			return (printf ("i = -1\n"), EXIT_FAILURE);
	}
	if (pars_texture_f(d))
		return (EXIT_FAILURE);
	int j = -1;
	while (++j<2)
		printf ("color = %lu\n", (long unsigned int) d->txr.plan[j].value);
	return (EXIT_SUCCESS);
}

int	add_texture(t_data *d, int face, int i)
{
	int	j;

	j = i;
	if (d->txr.path[face])
		return (-1);
	while (d->file.all[j] != '\n' && d->file.all[j])
		j++;
	d->txr.path[face] = ft_strndup(&d->file.all[i], j - i);
	if (!d->txr.path[face])
		return (-1);
	return (j);
}

int	pars_texture_f(t_data *d)
{
	int	f;
	int	i;

	f = 0;
	while (f < 4)
	{
		i = ft_strlen(d->txr.path[f]);
		if (i < 4)
			return (printf ("no file %d\n",f),EXIT_FAILURE);
		if (d->txr.path[f][i - 1] != 'm' || d->txr.path[f][i - 2] != 'p' \
			|| d->txr.path[f][i - 3] != 'x' || d->txr.path[f][i - 4] != '.')
			return (printf ("not xpm %d\n",f),EXIT_FAILURE);
		f++;
	}
	return (EXIT_SUCCESS);
}

int	add_color(t_data *d, int plan, int i)
{
	int		j;
	char	*temp;
	char	**temp_split;

	j = i;
	if (d->txr.plan[plan].argb.a == 255)
		return (-1);
	while (d->file.all[j] != '\n' && d->file.all[j])
		j++;
	temp = ft_strndup(&d->file.all[i], j - i);
	if (!temp)
		return (-1);
	temp_split = ft_split(temp, ',');
	free(temp);
	if (!temp_split)
		return (-1);
	if (ft_tablen(temp_split) != 3)
		return (ft_free_2d_array(temp_split), -1);
	d->txr.plan[plan].argb.r = ft_atoi(temp_split[0]);
	d->txr.plan[plan].argb.g = ft_atoi(temp_split[1]);
	d->txr.plan[plan].argb.b = ft_atoi(temp_split[2]);
	d->txr.plan[plan].argb.a = 255;
	return (pars_color_f(d, temp_split, j));
}

int	pars_color_f(t_data *d, char **src, int ret)
{
	int				color;
	unsigned char	i;
	char			*cmp;

	(void) d;
	color = -1;
	while (++color < 3)
	{
		i = ft_atoi(src[color]);
		cmp = ft_itoa(i);
		if (!cmp)
			return (ft_free_2d_array(src), -1);
		if (strncmp(src[color], cmp, strlen(cmp)) || strncmp(src[color], cmp, strlen(src[color])))
			return (ft_free_2d_array(src), free(cmp), -1);
		free(cmp);
	}
	return (ft_free_2d_array(src), ret);
}

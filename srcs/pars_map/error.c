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

void	ft_error_print(int err_code);
char	**ft_error_init(char *lst[LST_ERRO_SIZE]);

t_error	pars_error(t_data *d)
{
	free(d->file.all);
	ft_free_2d_array(d->file.map);
	free(d->txr.path[0]);
	free(d->txr.path[1]);
	free(d->txr.path[2]);
	free(d->txr.path[3]);
	free(d->txr.path[4]);
	if (d->txr.wall[0].img)
		mlx_destroy_image(d->mlx.ptr, d->txr.wall[0].img);
	if (d->txr.wall[1].img)
		mlx_destroy_image(d->mlx.ptr, d->txr.wall[1].img);
	if (d->txr.wall[2].img)
		mlx_destroy_image(d->mlx.ptr, d->txr.wall[2].img);
	if (d->txr.wall[3].img)
		mlx_destroy_image(d->mlx.ptr, d->txr.wall[3].img);
	if (d->txr.wall[4].img)
		mlx_destroy_image(d->mlx.ptr, d->txr.wall[4].img);
	if (d->n_image.img)
		mlx_destroy_image(d->mlx.ptr, d->n_image.img);
	if (d->mlx.win)
		mlx_destroy_window(d->mlx.ptr, d->mlx.win);
	if (d->mlx.ptr)
		mlx_destroy_display(d->mlx.ptr);
	free(d->mlx.ptr);
	ft_error_print(d->err_code);
	return (d->err_code);
}

char	**ft_error_init(char *lst[LST_ERRO_SIZE])
{
	lst[0] = SUCCES_T;
	lst[1] = WRONG_ARG_T;
	lst[2] = WRONG_FILE_T;
	lst[3] = ERROR_OPEN_T;
	lst[4] = ERROR_MALLOC_T;
	lst[5] = TROUBLE_READ_T;
	lst[6] = DOUBLE_DEF_TXR_T;
	lst[7] = DOUBLE_DEF_COLOR_T;
	lst[8] = NOT_VALID_TXR_T;
	lst[9] = NOT_VALID_COLOR_T;
	lst[10] = MISSING_COLLOR_T;
	lst[11] = MISSING_TXR_T;
	lst[12] = NOT_VALID_MAP_T;
	lst[13] = WRONG_INPUT_MAP_T;
	lst[14] = DOUBLE_STARTING_POINT_T;
	lst[15] = NO_STARTING_POINT_T;
	lst[16] = MLX_INIT_FAIL_T;
	lst[17] = MLX_WIN_FAIL_T;
	lst[18] = MLX_NEW_IMG_FAILED_T;
	lst[19] = BAD_TEXTURE_T;
	lst[20] = XPM_IMAGE_FAILED_T;
	return (lst);
}

void	ft_error_print(int err_code)
{
	char	*err_lst[LST_ERRO_SIZE];

	printf ("err = %d\n", err_code);
	(void)err_code;
	ft_error_init(err_lst);
	printf ("Error : %s", err_lst[err_code]);
}

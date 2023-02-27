/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:38:21 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/27 21:21:50 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Better exit needed

int	ft_hook(int key, void *data)
{
	(void) data;
	printf ("%d\n", key);
	if (key == K_ESC)
		exit (0);
	return (0);
}

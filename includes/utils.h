/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:47:16 by amiguez           #+#    #+#             */
/*   Updated: 2023/02/15 08:50:45 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifned UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 160
# endif

# include <stddef.h>

char	*get_next_line(int fd);

#endif
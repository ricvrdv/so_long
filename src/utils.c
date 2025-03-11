/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:16:53 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 17:17:04 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_close(char *message, int fd)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	close(fd);
	exit(EXIT_FAILURE);
}

int	ft_open(char *file, int flags)
{
	int	fd;

	fd = open(file, flags);
	if (fd == -1)
	{
		ft_error("Error: Failed to open map file.\n");
	}
	return (fd);
}

void	set_position(t_point *position, int x, int y)
{
	position->x = x;
	position->y = y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:08 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 17:34:10 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	are_borders_valid(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < map->height)
	{
		if (row == 0 || row == map->height - 1)
		{
			col = 0;
			while (col < map->width)
			{
				if (map->grid[row][col] != '1')
					return (0);
				col++;
			}
		}
		else
		{
			if (map->grid[row][0] != '1'
				|| map->grid[row][map->width - 1] != '1')
				return (0);
		}
		row++;
	}
	return (1);
}

void	validate_borders(t_map *map, int fd)
{
	if (!are_borders_valid(map))
	{
		free_map(map);
		ft_error_close("Map is not surrounded by walls.\n", fd);
	}
	close(fd);
}

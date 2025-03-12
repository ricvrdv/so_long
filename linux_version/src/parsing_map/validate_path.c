/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:15 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 17:35:18 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(t_map *map, char **map_copy, size_t height, int flag);
static void	flood_fill(char **map_copy, t_map *map, size_t x, size_t y);

void	validate_path(t_map *map)
{
	char	**map_copy;
	size_t	i;

	map_copy = (char **)calloc(map->height, sizeof(char *));
	if (!map_copy)
		ft_error("Error: Failed to allocate memory for map copy.\n");
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->grid[i]);
		if (!map_copy[i])
		{
			free_map_copy(map, map_copy, i, 1);
			ft_error("Error: Failed to allocate memory for map row copy.\n");
		}
		i++;
	}
	flood_fill(map_copy, map, map->player_position.x, map->player_position.y);
	if (map->collectibles != map->collected || map->exit_check != 1)
	{
		free_map_copy(map, map_copy, map->height, 1);
		ft_error("Error: No valid path.\n");
	}
	free_map_copy(map, map_copy, map->height, 0);
}

static void	free_map_copy(t_map *map, char **map_copy, size_t height, int flag)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (flag == 1)
		free_map(map);
}

static void	flood_fill(char **map_copy, t_map *map, size_t x, size_t y)
{
	char	current;

	if (x >= map->width || y >= map->height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	current = map_copy[y][x];
	map_copy[y][x] = 'F';
	if (current == 'C')
		map->collected++;
	else if (current == 'E')
	{
		map->exit_check = 1;
	}
	flood_fill(map_copy, map, x + 1, y);
	flood_fill(map_copy, map, x, y + 1);
	flood_fill(map_copy, map, x - 1, y);
	flood_fill(map_copy, map, x, y - 1);
}

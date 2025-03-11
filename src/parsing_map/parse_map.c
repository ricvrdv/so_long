/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:01 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 17:25:37 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		validate_characters(t_map *map, char *line, size_t row, int fd);
static void		validate_requirements(t_map *map, int fd);

void	parse_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error_close("Empty map file.\n", fd);
	while (line)
	{
		validate_characters(map, line, map->height, fd);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	validate_requirements(map, fd);
}

static void	validate_characters(t_map *map, char *line, size_t row, int fd)
{
	size_t	col;

	col = 0;
	while (line[col] != '\n' && line[col] != '\r' && line[col] != '\0')
	{
		if (line[col] == 'P')
		{
			map->player_count++;
			set_position(&map->player_position, (int)col, (int)row);
		}
		else if (line[col] == 'E')
		{
			map->exit_count++;
			set_position(&map->exit_position, (int)col, (int)row);
		}
		else if (line[col] == 'C')
			map->collectibles++;
		else if (line[col] != '0' && line[col] != '1')
		{
			free(line);
			ft_error_close("Invalid character in map.\n", fd);
		}
		col++;
	}
}

static void	validate_requirements(t_map *map, int fd)
{
	if (map->player_count != 1)
	{
		ft_error_close("Map must have exactly one player (P).\n", fd);
	}
	if (map->exit_count != 1)
	{
		ft_error_close("Map must have exactly one exit (E).\n", fd);
	}
	if (map->collectibles < 1)
	{
		ft_error_close("Map must have at least one collectible (C).\n", fd);
	}
	close(fd);
}

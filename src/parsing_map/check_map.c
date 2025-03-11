/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:33:56 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 17:45:24 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*extract_filename(char *path)
{
	char	*filename;

	filename = ft_strrchr(path, '/');
	if (filename)
		return (filename + 1);
	return (path);
}

void	check_map(t_map *map, char *map_file)
{
	size_t	len;
	int		fd;
	char	*filename;

	filename = extract_filename(map_file);
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_error("Error: File extension must be .ber\n");
	}
	fd = ft_open(map_file, O_RDONLY);
	init_struct(map);
	parse_map(fd, map);
	fd = ft_open(map_file, O_RDONLY);
	store_map(map, fd, 0);
	validate_borders(map, fd);
	validate_path(map);
}

size_t	calculate_width(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\r' && line[len] != '\0')
		len++;
	return (len);
}

static void	check_form(t_map *map, int fd)
{
	size_t	row;

	if (map->height == 0 || map->grid == NULL)
	{
		free_map(map);
		ft_error_close("Map is empty or grid is not allocated.\n", fd);
	}
	row = 0;
	map->width = calculate_width(map->grid[row]);
	while (row < map->height)
	{
		if (calculate_width(map->grid[row]) != map->width)
		{
			free_map(map);
			ft_error_close("Map is not rectangular.\n", fd);
		}
		row++;
	}
}

void	store_map(t_map *map, int fd, size_t row)
{
	char	*line;

	map->grid = (char **)malloc(sizeof(char *) * map->height);
	if (!map->grid)
		ft_error_close("Failed to allocate memory for map grid.\n", fd);
	line = get_next_line(fd);
	while (line)
	{
		map->grid[row] = ft_strdup(line);
		if (!map->grid[row])
		{
			while (row > 0)
				free(map->grid[--row]);
			free(map->grid);
			free(line);
			ft_error_close("Failed to allocate memory for map row.\n", fd);
		}
		free(line);
		row++;
		line = get_next_line(fd);
	}
	check_form(map, fd);
}

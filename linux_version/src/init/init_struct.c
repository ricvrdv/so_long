/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:18:36 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 17:18:45 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_counts(t_map *map);
static void	init_map_ptrs(t_map *map);
static void	init_positions(t_map *map);
static void	init_mlx_image(t_map *map);

void	init_struct(t_map *map)
{
	init_map_counts(map);
	init_map_ptrs(map);
	init_positions(map);
	init_mlx_image(map);
}

static void	init_map_counts(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->collectibles = 0;
	map->collected = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->moves = 0;
	map->exit_check = 0;
}

static void	init_map_ptrs(t_map *map)
{
	map->grid = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	map->player = NULL;
	map->exit = NULL;
	map->chest_closed = NULL;
	map->chest_open = NULL;
	map->wall = NULL;
	map->floor = NULL;
	map->collectible_states = NULL;
}

static void	init_positions(t_map *map)
{
	map->player_position.x = 0;
	map->player_position.y = 0;
	map->exit_position.x = 0;
	map->exit_position.y = 0;
}

static void	init_mlx_image(t_map *map)
{
	map->image.img = NULL;
	map->image.addr = NULL;
	map->image.bits_per_pixel = 0;
	map->image.line_length = 0;
	map->image.endian = 0;
}

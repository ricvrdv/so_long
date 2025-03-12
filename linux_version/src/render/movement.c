/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:28:15 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 11:20:53 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		(*new_y)--;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		(*new_y)++;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		(*new_x)--;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		(*new_x)++;
}

void	update_player_image(t_map *game, int keycode)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		game->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/frog_left.xpm", &tile_size, &tile_size);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		game->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/frog_right.xpm", &tile_size, &tile_size);
	}
	else
	{
		game->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/frog_right.xpm", &tile_size, &tile_size);
	}
	if (!game->player)
	{
		free_all(game);
		ft_error("Error: Failed to load player texture.\n");
	}
}

int	validate_movement(t_map *game, int x, int y)
{
	if (x < 0 || x >= (int)game->width || y < 0 || y >= (int)game->height)
		return (0);
	if (game->grid[y][x] == '1')
		return (0);
	return (1);
}

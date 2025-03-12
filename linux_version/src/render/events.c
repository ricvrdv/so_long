/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:26:49 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 11:30:36 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_key_press(int keycode, t_map *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_position.x;
	new_y = game->player_position.y;
	update_player_position(keycode, &new_x, &new_y);
	update_player_image(game, keycode);
	if (validate_movement(game, new_x, new_y))
	{
		game->player_position.x = new_x;
		game->player_position.y = new_y;
		game->moves++;
		ft_printf("Movements: %d\n", game->moves);
		handle_collectibles(game);
		handle_exit(game);
		render_game(game);
	}
}

int	key_press(int keycode, t_map *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else
		handle_key_press(keycode, game);
	return (0);
}

void	handle_collectibles(t_map *game)
{
	int	x;
	int	y;

	x = game->player_position.x;
	y = game->player_position.y;
	if (game->grid[y][x] == 'C' && game->collectible_states[y][x] == 0)
	{
		game->collected++;
		game->collectible_states[y][x] = 1;
		render_game(game);
	}
}

static void	update_exit_wall(t_map *game)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit_open.xpm",
			&tile_size, &tile_size);
	if (!game->exit)
	{
		free_all(game);
		ft_error("Error: Failed to load updated exit texture.\n");
	}
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/water.xpm",
			&tile_size, &tile_size);
	if (!game->wall)
	{
		free_all(game);
		ft_error("Error: Failed to load updated wall texture.\n");
	}
}

void	handle_exit(t_map *game)
{
	if (game->collected == game->collectibles)
	{
		update_exit_wall(game);
		render_game(game);
	}
	if (game->grid[game->player_position.y][game->player_position.x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("Congrats! You're ready to code!\n");
			exit_game(game);
		}
		else
			ft_printf("Open all chests to unlock your machine!\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:23:46 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 17:54:26 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_minilibx(t_map *game);
static void	load_textures(t_map *game);
static void	load_file(t_map *game, void **texture, char *file_path);

void	game_init(t_map *game)
{
	if (!game)
		ft_error("Error: Failed to initialize game.\n");
	game->collected = 0;
	init_collectible_states(game);
	set_minilibx(game);
	load_textures(game);
	render_game(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win_ptr, 17, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
}

static void	set_minilibx(t_map *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error("Error: Failed to initialize MiniLibX.\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_error("Error: Failed to create window for the game.\n");
	}
	game->image.img = mlx_new_image(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE);
	game->image.addr = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
}

static void	load_textures(t_map *game)
{
	load_file(game, &game->player, "textures/frog_right.xpm");
	load_file(game, &game->exit, "textures/exit_closed.xpm");
	load_file(game, &game->chest_closed, "textures/chest_closed.xpm");
	load_file(game, &game->chest_open, "textures/chest_open.xpm");
	load_file(game, &game->wall, "textures/magma.xpm");
	load_file(game, &game->floor, "textures/floor.xpm");
}

static void	load_file(t_map *game, void **texture, char *file_path)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	*texture = mlx_xpm_file_to_image(game->mlx_ptr, file_path,
			&tile_size, &tile_size);
	if (!*texture)
	{
		free_all(game);
		ft_error("Error: Failed to load texture.\n");
	}
}

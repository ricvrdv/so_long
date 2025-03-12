/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:29:44 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 17:33:27 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_map *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_collectible(t_map *game, size_t x, size_t y)
{
	if (game->collectible_states[y][x] == 0)
	{
		put_image(game, game->chest_closed, x, y);
	}
	else
	{
		put_image(game, game->chest_open, x, y);
	}
}

void	render_game(t_map *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_image(game, game->floor, x, y);
			if (game->grid[y][x] == '1')
				put_image(game, game->wall, x, y);
			else if (game->grid[y][x] == 'C')
				render_collectible(game, x, y);
			else if (game->grid[y][x] == 'E')
				put_image(game, game->exit, x, y);
			x++;
		}
		y++;
	}
	put_image(game, game->player,
		game->player_position.x, game->player_position.y);
}

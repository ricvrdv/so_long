/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:16 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/05 22:40:55 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *game)
{
	size_t	y;

	if (!game || !game->grid)
		return ;
	y = 0;
	while (y < game->height)
	{
		if (game->grid[y])
			free(game->grid[y]);
		y++;
	}
	free(game->grid);
	game->grid = NULL;
}

void	free_collectible_states(t_map *game)
{
	size_t	y;

	if (!game->collectible_states)
		return ;
	y = 0;
	while (y < game->height)
	{
		free(game->collectible_states[y]);
		y++;
	}
	free(game->collectible_states);
	game->collectible_states = NULL;
}

void	destroy_images(t_map *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->chest_open)
		mlx_destroy_image(game->mlx_ptr, game->chest_open);
	if (game->chest_closed)
		mlx_destroy_image(game->mlx_ptr, game->chest_closed);
}

void	free_all(t_map *game)
{
	if (!game)
		return ;
	if (game->grid)
		free_map(game);
	free_collectible_states(game);
	destroy_images(game);
	if (game->image.img)
		mlx_destroy_image(game->mlx_ptr, game->image.img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	return ;
}

int	exit_game(t_map *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
}

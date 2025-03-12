#include "so_long.h"

static int	**allocate_memory(size_t height, size_t width)
{
	int		**collectible_states;
	size_t	y;

	collectible_states = (int **)malloc(sizeof(int *) * height);
	if (!collectible_states)
		return (NULL);
	y = 0;
	while (y < height)
	{
		collectible_states[y] = (int *)malloc(sizeof(int) * width);
		if (!collectible_states[y])
		{
			while (y > 0)
				free(collectible_states[--y]);
			free(collectible_states);
			return (NULL);
		}
		y++;
	}
	return (collectible_states);
}

void	init_collectible_states(t_map *game)
{
	int	x;
	int	y;

	game->collectible_states = allocate_memory(game->height, game->width);
	if (!game->collectible_states)
		ft_error("Failed to allocate memory for collectible states.\n");
	y = 0;
	while (y < (int)game->height)
	{
		x = 0;
		while (x < (int)game->width)
		{
			if (game->grid[y][x] == 'C')
				game->collectible_states[y][x] = 0;
			else
				game->collectible_states[y][x] = -1;
			x++;
		}
		y++;
	}
}

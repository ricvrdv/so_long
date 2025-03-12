#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
	{
		ft_error("Usage: ./so_long <map_file.ber>\n");
	}
	check_map(&game, argv[1]);
	game_init(&game);
	return (0);
}

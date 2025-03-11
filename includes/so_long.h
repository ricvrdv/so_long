/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:14:19 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/10 17:46:01 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_W 119
# define KEY_DOWN 65364
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_A 97
# define KEY_RIGHT 65363
# define KEY_D 100

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h" 
# include <fcntl.h>
# include <stdio.h>

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	char		**grid;
	size_t		width;
	size_t		height;
	size_t		collectibles;
	size_t		collected;
	t_point		player_position;
	size_t		player_count;
	t_point		exit_position;
	size_t		exit_count;
	int			moves;
	int			exit_check;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	void		*player;
	void		*exit;
	void		*chest_open;
	void		*chest_closed;
	void		*wall;
	void		*floor;
	int			**collectible_states;
}				t_map;

// PARSING MAP
void	check_map(t_map *map, char *map_file);
void	parse_map(int fd, t_map *map);
void	store_map(t_map *map, int fd, size_t row);
void	validate_borders(t_map *map, int fd);
void	validate_path(t_map *map);

// INITIALISE DATA STRUCTURES
void	init_struct(t_map *map);

// INITIALISE GAME
void	game_init(t_map *game);
void	init_collectible_states(t_map *game);

// RENDER GAME
void	render_game(t_map *game);
int		key_press(int keycode, t_map *game);
void	update_player_position(int keycode, int *new_x, int *new_y);
void	update_player_image(t_map *game, int keycode);
int		validate_movement(t_map *game, int x, int y);
void	handle_collectibles(t_map *game);
void	handle_exit(t_map *game);

// FREE
int		exit_game(t_map *game);
void	free_all(t_map *game);
void	destroy_images(t_map *game);
void	free_map(t_map *game);
void	free_collectible_states(t_map *game);

// UTILS
void	ft_error(char *message);
void	ft_error_close(char *message, int fd);
int		ft_open(char *file, int flags);
void	set_position(t_point *position, int x, int y);

#endif

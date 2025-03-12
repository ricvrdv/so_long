NAME = so_long

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Iminilibx

SRC = src/main.c \
	src/utils.c \
	src/free.c \
	src/parsing_map/check_map.c \
	src/parsing_map/parse_map.c \
	src/parsing_map/validate_borders.c \
	src/parsing_map/validate_path.c \
	src/init/init_game.c \
	src/init/init_struct.c \
	src/init/collectible_states.c \
	src/render/render.c \
	src/render/events.c \
	src/render/movement.c

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./includes/minilibx

MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

all: $(MLX) $(LIBFT) $(NAME)
	

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./includes

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\n\tCompilation completed successfully!\n"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

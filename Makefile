NAME = so_long

SRCS =  main.c errors.c $(GNL_SRC) $(GAME_SRC) $(MAP_SRC)
OBJS = $(SRCS:.c=.o)

libft = libft
printf = ft_printf
libs = libft/libft.a ft_printf/libftprintf.a
GAME_SRC = game/game_init.c game/end_program.c game/open_image.c
MAP_SRC = map/map_checker.c  map/map_checker_utils.c  map/map_reader.c  map/tilemap_generator.c map/enemy_generator.c
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=gnu17

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11

INCLUDES = -Iincludes

all: make_libs $(NAME)

make_libs:
	$(MAKE) -C $(libft)
	$(MAKE) -C $(printf)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(libs) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(libft) clean
	$(MAKE) -C $(printf) clean
	rm $(OBJS)


fclean: clean
	$(MAKE) -C $(libft) fclean
	$(MAKE) -C $(printf) fclean
	rm $(NAME)
re: fclean all

.PHONY: all clean fclean re

NAME = so_long

SRCS =  *.c $(GNL_SRC) $(GAME_SRC) $(MAP_SRC) $(PRINTF_SRC)
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
PRINTF_SRC = ft_printf/*.c
GAME_SRC = game/*.c
MAP_SRC = map/*.c
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11

INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRCS = srcs/check_characters.c srcs/check_errors.c srcs/check_map.c srcs/draw_map.c\
srcs/flood_fill.c srcs/free_utils.c srcs/is_it_reachable.c srcs/press_key.c srcs/map_read.c srcs/main.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

SRCS = animate.c check_characters.c check_errors.c check_map.c draw_map.c flood_fill.c free_utils.c is_it_reachable.c\
load_player_frames.c main.c map_read.c move_counter.c move_enemy.c mv_en_to_pl.c press_key.c release_key.c\
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L./libft -lft -L./printf -lftprintf

clean:
	rm -f $(OBJS)
	make -C ./libft clean
	make -C ./printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)
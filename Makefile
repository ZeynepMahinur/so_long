CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

MLX_FLAGS = -L../so_long_folder/minilibx-linux -lmlx -lXext -lX11 -lm
LIBFT = ../so_long_folder/libft/libft.a
PRINTF = ../so_long_folder/printf/libftprintf.a

SRCS = animate.c check_characters.c check_errors.c check_map.c draw_map.c flood_fill.c free_utils.c is_it_reachable.c\
load_player_frames.c main.c map_read.c move_counter.c move_enemy.c mv_en_to_pl.c press_key.c release_key.c\
../so_long_folder/get_next_line/get_next_line.c ../so_long_folder/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(LIBFT):
	make -C ../so_long_folder/libft

$(PRINTF):
	make -C ../so_long_folder/printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L../so_long_folder/libft -lft -L../so_long_folder/printf -lftprintf

clean:
	rm -f $(OBJS)
	make -C ../so_long_folder/libft clean
	make -C ../so_long_folder/printf clean

fclean: clean
	rm -f $(NAME)
	make -C ../so_long_folder/libft fclean
	make -C ../so_long_folder/printf fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)
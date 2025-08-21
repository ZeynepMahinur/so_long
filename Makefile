CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I.

MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS = srcs/check_characters.c srcs/check_errors.c srcs/check_map.c srcs/draw_map.c\
srcs/flood_fill.c srcs/free_utils.c srcs/is_it_reachable.c srcs/press_key.c srcs/map_read.c srcs/main.c

SRCS_BONUS = animate_bonus.c check_characters_bonus.c check_map_bonus.c draw_map_bonus.c check_errors_bonus.c flood_fill_bonus.c \
free_utils_bonus.c is_it_reachable_bonus.c map_read_bonus.c press_key_bonus.c main_bonus.c 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = so_long

NAME_BONUS = so_long_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
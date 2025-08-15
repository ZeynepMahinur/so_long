#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_game
{
    char    **map;
    int     height;
    int     width;

}              t_game;



#endif
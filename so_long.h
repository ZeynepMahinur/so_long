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
    int     player_x;
    int     player_y;
    int     collectible;
}              t_game;

typedef struct s_count
{
    int     player;
    int     collectible;
    int     exit;
}              t_count;

typedef struct s_reach
{
    char    **map_copy;
    int     collect;
    int     found_exit;
}              t_reach;

int     map_read(char *filename, t_game *data);
void    free_map(t_game *data);
void    map_error(char *err);
void    check_map(t_game *data);
void    check_characters(t_game *data);
void    flood_fill(t_reach *r, int x, int y);
int     is_it_reachable(t_game *data);


size_t  ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *get_next_line(int fd);
int     ft_printf(const char *f, ...);

#endif
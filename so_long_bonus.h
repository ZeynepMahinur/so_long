#ifndef SO_LONG_H_BONUS
# define SO_LONG_H_BONUS

#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_images
{
    void    *player_img;
    void    *wall_img;
    void    *floor_img;
    void    *collectible_img;
    void    *exit_img;
    void    *player_frames[3];
    void    *player_up[3];
    void    *player_down[3];
    void    *player_left[3];
    void    *player_right[3];
}              t_images;

typedef struct s_game
{
    char    **map;
    int     height;
    int     width;
    int     player_x;
    int     player_y;
    int     collectible;
    void    *mlx;
    void    *window;
    int     frame;
    t_images img;
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
    int     height;
}              t_reach;

void    free_map_bonus(t_game *data);
int     map_read_bonus(char *filename, t_game *data);
void    check_map_bonus(t_game *data);
void    check_characters_bonus(t_game *data);
void    flood_fill_bonus(t_reach *r, int x, int y);
int     is_it_reachable_bonus(t_game *data);
void    draw_map_bonus(t_game *data);
void     images_bonus(t_game *data);
int     press_key_bonus(int key_code, t_game *data);
int     close_game_bonus(t_game *data);
void    if_error_exit_bonus(char *err, t_game *data);
int     animate_bonus(t_game *data);
void    free_animation_bonus(t_game *data);

size_t  ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *get_next_line(int fd);
int     ft_printf(const char *f, ...);

#endif
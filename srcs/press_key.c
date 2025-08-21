#include "so_long.h"

int  close_game(t_game *data)
{
    mlx_destroy_image(data->mlx, data->img.collectible_img);
    mlx_destroy_image(data->mlx, data->img.player_img);
    mlx_destroy_image(data->mlx, data->img.wall_img);
    mlx_destroy_image(data->mlx, data->img.floor_img);
    mlx_destroy_image(data->mlx, data->img.exit_img);
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    free_map(data);
    free(data->mlx);
    exit (0);
    return (0);
}

static int      exit_door(t_game *data, int x, int y)
{
    if (data->map[y][x] == 'E')
    {
        if (data->collectible > 0)
        {
            ft_printf("You must collect all the leeks!\n");
            return (0);
        }
        else
        {
            ft_printf("Congratulations! You won!");
            close_game(data);
        }
    }
    return (1);
}

static void    move_player(t_game *data, int px, int py)
{
    int     x;
    int     y;

    x = data->player_x + px;
    y = data->player_y + py;
    if (data->map[y][x] == '1')
        return ;
    if (data->map[y][x] == 'C')
    {
        data->collectible--;
        data->map[y][x] = '0';
    }
    if (!exit_door(data, x, y))
        return ;
    data->map[data->player_y][data->player_x] = '0';
    data->map[y][x] = 'P';
    data->player_x = x;
    data->player_y = y;
}

int     press_key(int key_code, t_game *data)
{
    if (key_code == 65307)
        close_game(data);
    else if (key_code == 119)
        move_player(data, 0, -1);
    else if (key_code == 115)
        move_player(data, 0, 1);
    else if (key_code == 97)
        move_player(data, -1, 0);
    else if (key_code == 100)
        move_player(data, 1, 0);
    mlx_clear_window(data->mlx, data->window);
    draw_map(data);
    return (0);
}

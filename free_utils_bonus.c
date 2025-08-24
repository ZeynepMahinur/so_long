#include "so_long_bonus.h"

void    free_map_bonus(t_game *data)
{
    int     i;

    i = 0;
    if (!data->map)
        return ;
    while (i < data->height)
    {
        if (data->map[i])
            free (data->map[i]);
        i++;
    }
    free (data->map);
    data->map = NULL;
}

void    free_animation_bonus(t_game *data)
{
    int     i;

    i = 0;
    while (i < 4)
    {
        if (data->img.player_frames[i])
            mlx_destroy_image(data->mlx, data->img.player_frames[i]);
        if (data->img.player_up[i])
            mlx_destroy_image(data->mlx, data->img.player_up[i]);
        if (data->img.player_down[i])
            mlx_destroy_image(data->mlx, data->img.player_down[i]);
        if (data->img.player_right[i])
            mlx_destroy_image(data->mlx, data->img.player_right[i]);
        if (data->img.player_left[i])
            mlx_destroy_image(data->mlx, data->img.player_left[i]);
        i++;
    }
}

int  close_game_bonus(t_game *data)
{
    free_animation_bonus(data);
    mlx_destroy_image(data->mlx, data->img.collectible_img);
    mlx_destroy_image(data->mlx, data->img.player_img);
    mlx_destroy_image(data->mlx, data->img.wall_img);
    mlx_destroy_image(data->mlx, data->img.floor_img);
    mlx_destroy_image(data->mlx, data->img.exit_img);
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    free_map_bonus(data);
    free(data->mlx);
    exit (0);
    return (0);
}
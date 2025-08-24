#include "so_long_bonus.h"

static void    load_player_frames(t_game *data)
{
    int     wid;
    int     hei;

    data->img.player_frames[0] = mlx_xpm_file_to_image(data->mlx, "textures/charidle_1.xpm", &wid, &hei);
    data->img.player_frames[1] = mlx_xpm_file_to_image(data->mlx, "textures/deneme.xpm", &wid, &hei);
    data->img.player_frames[2] = mlx_xpm_file_to_image(data->mlx, "textures/charidle_3.xpm", &wid, &hei);
    data->img.player_frames[3] = mlx_xpm_file_to_image(data->mlx, "textures/charidle_4.xpm", &wid, &hei);
    data->img.player_right[0] = mlx_xpm_file_to_image(data->mlx, "textures/charright1.xpm", &wid, &hei);
    data->img.player_right[1] = mlx_xpm_file_to_image(data->mlx, "textures/charright2.xpm", &wid, &hei);
    data->img.player_right[2] = mlx_xpm_file_to_image(data->mlx, "textures/charright3.xpm", &wid, &hei);
    data->img.player_right[3] = mlx_xpm_file_to_image(data->mlx, "textures/charright4.xpm", &wid, &hei);
    data->img.player_left[0] = mlx_xpm_file_to_image(data->mlx, "textures/charleft1.xpm", &wid, &hei);
    data->img.player_left[1] = mlx_xpm_file_to_image(data->mlx, "textures/charleft2.xpm", &wid, &hei);
    data->img.player_left[2] = mlx_xpm_file_to_image(data->mlx, "textures/charleft3.xpm", &wid, &hei);
    data->img.player_left[3] = mlx_xpm_file_to_image(data->mlx, "textures/charleft4.xpm", &wid, &hei);
    data->img.player_down[0] = mlx_xpm_file_to_image(data->mlx, "textures/chardown1.xpm", &wid, &hei);
    data->img.player_down[1] = mlx_xpm_file_to_image(data->mlx, "textures/chardown2.xpm", &wid, &hei);
    data->img.player_down[2] = mlx_xpm_file_to_image(data->mlx, "textures/chardown3.xpm", &wid, &hei);
    data->img.player_down[3] = mlx_xpm_file_to_image(data->mlx, "textures/chardown4.xpm", &wid, &hei);
    data->img.player_up[0] = mlx_xpm_file_to_image(data->mlx, "textures/charup1.xpm", &wid, &hei);
    data->img.player_up[1] = mlx_xpm_file_to_image(data->mlx, "textures/charup2.xpm", &wid, &hei);
    data->img.player_up[2] = mlx_xpm_file_to_image(data->mlx, "textures/charup3.xpm", &wid, &hei);
    data->img.player_up[3] = mlx_xpm_file_to_image(data->mlx, "textures/charup4.xpm", &wid, &hei);
}

void     images_bonus(t_game *data)
{
    int     wid;
    int     hei;

    data->img.collectible_img = mlx_xpm_file_to_image(data->mlx, "textures/collectible.xpm", &wid, &hei);
    data->img.exit_img = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &wid, &hei);
    data->img.floor_img = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &wid, &hei);
    data->img.player_img = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &wid, &hei);
    data->img.wall_img = mlx_xpm_file_to_image(data->mlx, "textures/wallb.xpm", &wid, &hei);
    load_player_frames(data);
}

static void    draw_player_bonus(t_game *data, int i, int j)
{
    if (data->direction == 0)
        mlx_put_image_to_window(data->mlx, data->window, data->img.player_frames[data->frame], j * 64, i * 64);
    else if (data->direction == 4)
        mlx_put_image_to_window(data->mlx, data->window, data->img.player_right[data->frame], j * 64, i * 64);
    else if (data->direction == 3)
        mlx_put_image_to_window(data->mlx, data->window, data->img.player_left[data->frame], j * 64, i * 64);
    else if (data->direction == 2)
        mlx_put_image_to_window(data->mlx, data->window, data->img.player_down[data->frame], j * 64, i * 64);
    else if (data->direction == 1)
        mlx_put_image_to_window(data->mlx, data->window, data->img.player_up[data->frame], j * 64, i * 64);
}

void    draw_map_bonus(t_game *data)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->window, data->img.wall_img, j * 64, i * 64);
            else if (data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->window, data->img.floor_img, j * 64, i * 64);
            else if (data->map[i][j] == 'P')
                draw_player_bonus(data, i, j);
            else if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->img.collectible_img, j * 64, i * 64);
            else if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->window, data->img.exit_img, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

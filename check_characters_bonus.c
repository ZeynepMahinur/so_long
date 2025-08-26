#include "so_long_bonus.h"

void    check_enemies(t_game *data)
{
    int     i;

    i = 0;
    while (i < data->enemy_count)
    {
        data->enemies[i].path_x = 1;
        data->enemies[i].path_y = 1;
        i++;
    }
}

static void     count_characters_bonus(char c, t_count *count, t_game *data, int i, int j, int *enemy_index, int write_enemies)
{
    if (c == 'P')
    {
        if (!write_enemies)
        {
            count->player++;
            data->player_x = j;
            data->player_y = i;
        }
    }
    else if (c == 'C')
    {
        if (!write_enemies)
        {
            count->collectible++;
        }
    }
    else if (c == 'E')
    {
        if (!write_enemies)
        {
            count->exit++;
        }
    }
    else if (c == 'X')
    {
        count->enemy++;
        if (write_enemies)
        {
            data->enemies[*enemy_index].x = j;
            data->enemies[*enemy_index].y = i;
            data->enemies[*enemy_index].path_x = 1;
            data->enemies[*enemy_index].path_y = 1;
            (*enemy_index)++;
        }
    }
    else if (c != '1' && c != '0')
        if_error_exit_bonus("Invalid character in the map.", data);
}

static void     scan_map_bonus(t_game *data, t_count *count, int *enemy_index, int write_enemies)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            count_characters_bonus(data->map[i][j], count, data, i, j, enemy_index, write_enemies);
            j++;
        }
        i++;
    }
}

void    check_characters_bonus(t_game *data)
{
    t_count     count;
    int     enemy_index;

    count.player = 0;
    count.collectible = 0;
    count.exit = 0;
    count.enemy = 0;
    enemy_index = 0;
    scan_map_bonus(data, &count, &enemy_index, 0);
    if (count.enemy > 0)
        data->enemies = malloc(sizeof(t_enemy) * count.enemy);
    data->enemy_count = count.enemy;
    enemy_index = 0;
    scan_map_bonus(data, &count, &enemy_index, 1);
    data->collectible = count.collectible;
    if (count.player != 1)
        if_error_exit_bonus("There must be a character.", data);
    if (count.collectible < 1)
        if_error_exit_bonus("There must be atleast 1 collectible.", data);
    if (count.exit != 1)
        if_error_exit_bonus("There must be an exit.", data);
}

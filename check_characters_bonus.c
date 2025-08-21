#include "so_long_bonus.h"

static void     count_characters_bonus(char c, t_count *count, t_game *data, int i, int j)
{
    if (c == 'P')
    {
        count->player++;
        data->player_x = j;
        data->player_y = i;
    }
    else if (c == 'C')
        count->collectible++;
    else if (c == 'E')
        count->exit++;
    else if (c != '1' && c != '0')
        if_error_exit_bonus("Invalid character in the map.", data);
}

static void     scan_map_bonus(t_game *data, t_count *count)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            count_characters_bonus(data->map[i][j], count, data, i, j);
            j++;
        }
        i++;
    }
}

void    check_characters_bonus(t_game *data)
{
    t_count     count;

    count.player = 0;
    count.collectible = 0;
    count.exit = 0;
    scan_map_bonus(data, &count);
    data->collectible = count.collectible;

    if (count.player != 1)
        if_error_exit_bonus("There must be a character.", data);
    if (count.collectible < 1)
        if_error_exit_bonus("There must be atleast 1 collectible.", data);
    if (count.exit != 1)
        if_error_exit_bonus("There must be an exit.", data);
}
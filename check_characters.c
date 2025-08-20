#include "so_long.h"

static void     count_characters(char c, t_count *count, t_game *data, int i, int j)
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
        map_error("Invalid character in the map.");
}

static void     scan_map(t_game *data, t_count *count)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            count_characters(data->map[i][j], count, data, i, j);
            j++;
        }
        i++;
    }
}

void    check_characters(t_game *data)
{
    t_count     count;

    count.player = 0;
    count.collectible = 0;
    count.exit = 0;
    scan_map(data, &count);
    data->collectible = count.collectible;

    if (count.player != 1)
        map_error("There must be a character.");
    if (count.collectible < 1)
        map_error("There must be atleast 1 collectible.");
    if (count.exit != 1)
        map_error("There must be an exit.");
}
#include "so_long.h"

static char     **map_copy(t_game *data)
{
    char    **copy;
    int     i;

    copy = malloc(sizeof (char *) * data->height);
    if (!copy)
        if_error_exit("Map allocation failed for the copy of the map.", data);
    i = 0;
    while (i < data->height)
    {
        copy[i] = ft_strdup(data->map[i]);
        if (!copy[i])
            if_error_exit("Memory allocation failed for copying", data);
        i++;
    }
    return (copy);
}

static void     free_map_copy(char **copy, int height)
{
    int     i;

    i = 0;
    while (i < height)
    {
        free (copy[i]);
        i++;
    }
    free (copy);
}

static void     find_player_start(t_game *data, int *start_x, int *start_y)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[i][j] == 'P')
            {
                *start_x = j;
                *start_y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

int     is_it_reachable(t_game *data)
{
    t_reach     r;
    int         x_start;
    int         y_start;

    r.map_copy = map_copy(data);
    r.height = data->height;
    r.collect = 0;
    r.found_exit = 0;
    find_player_start(data, &x_start, &y_start);
    flood_fill(&r, x_start, y_start);
    free_map_copy(r.map_copy, data->height);
    return (r.found_exit && r.collect == data->collectible);
}
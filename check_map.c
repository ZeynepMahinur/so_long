#include "so_long.h"

static void    check_rectangle(t_game *data)
{
    int     len;
    int     i;

    i = 0;
    while (i < data->height)
    {
        len = ft_strlen(data->map[i]);
        if (data->map[i][len - 1] == '\n')
            len--;
        if (len != data->width)
            map_error("Map isn't rectangular.");
        i++;
    }
}

static void    check_wall_limit(t_game *data)
{
    int     i;

    i = 0;
    while (i < data->width)
    {
        if (data->map[0][i] != '1')
            map_error("First wall isn't closed.");
        if (data->map[data->height - 1][i] != '1')
            map_error("Last wall isn't closed.");
        i++;
    }

    i = 0;
    while (i < data->height)
    {
        if (data->map[i][0] != '1')
            map_error("Left wall isn't closed properly.");
        if (data->map[i][data->width - 1] != '1')
            map_error("Right wall isn't closed properly.");
        i++;
    }
}

void    check_map(t_game *data)
{
    check_rectangle(data);
    check_wall_limit(data);
    check_characters(data);
}

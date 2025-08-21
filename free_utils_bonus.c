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
#include "so_long.h"

void    free_map(t_game *data)
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
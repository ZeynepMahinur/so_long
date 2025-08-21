#include "so_long_bonus.h"

int     animate_bonus(t_game *data)
{
    static int  count;

    count++;
    if (count >= 65)
    {
        data->frame = (data->frame + 1) % 3;
        count = 0;
    }
    draw_map_bonus(data);
    return (0);
}
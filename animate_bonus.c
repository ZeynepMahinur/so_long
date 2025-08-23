#include "so_long_bonus.h"

int     animate_bonus(t_game *data)
{
    static int  count;
    int    reference_map_size = 333;
    int    current_map_size = (data->height * data->width);
    double  speed_factor;
    int     threshold;

    count++;
    speed_factor = (double)reference_map_size / (double)current_map_size;
    threshold = (int)(100 * speed_factor);
    if (threshold < 1)
        threshold = 1;
    if (count >= threshold )
    {
        data->frame = (data->frame + 1) % 3;
        count = 0;
    }
    draw_map_bonus(data);
    return (0);
}

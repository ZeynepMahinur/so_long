#include "so_long_bonus.h"

int move_towards(int current, int target)
{
    if (target > current)
        return (current + 1);
    else
        return (current - 1);
}

int if_enemy_present(t_game *data, int x, int y)
{
    int     i;

    i = 0;
    while (i < data->enemy_count)
    {
        if (data->enemies[i].x == x && data->enemies[i].y == y)
            return (1);
        i++;
    }
    return (0);
}

int my_abs(int n)
{
    if (n < 0)
        return -n;
    return n;
}

void      move_all_enemy(t_game *data)
{
    int     i;
    
    i = 0;
    while (i < data->enemy_count)
    {
        mv_en_to_pl(data, &data->enemies[i]);
        i++;
    }
}

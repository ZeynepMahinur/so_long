#include "so_long_bonus.h"

static int      absolute_number(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

void    move_enemy(t_game *data, t_enemy *enemy)
{
    int     x;
    int     y;
    int     path;
    
    x = enemy->x;
    y = enemy->y;
    path = 
}
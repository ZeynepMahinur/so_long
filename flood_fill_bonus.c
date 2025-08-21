#include "so_long_bonus.h"

void    flood_fill_bonus(t_reach *r, int x, int y)
{
    char    c;

    if (x < 0 || y < 0)
        return ;
    if (x < 0 || y < 0 || y >= r->height || x >= (int)ft_strlen(r->map_copy[y]))
        return ;
    c = r->map_copy[y][x];
    if (c == '1' || c == 'V')
        return ;
    if (c == 'C')
        r->collect++;
    if (c == 'E')
        r->found_exit = 1;
    r->map_copy[y][x] = 'V';

    flood_fill_bonus(r, x + 1, y);
    flood_fill_bonus(r, x - 1, y);
    flood_fill_bonus(r, x, y + 1);
    flood_fill_bonus(r, x, y - 1);
}
#include "so_long.h"

void    flood_fill(t_reach *r, int x, int y)
{
    char    c;

    if (x < 0 || y < 0)
        return ;
    if (x < 0 || y < 0 || !r->map_copy[x] || y >= ft_strlen(r->map_copy[x]))
        return ;
    c = r->map_copy[x][y];
    if (c == '1' || c == 'V')
        return ;
    if (c == 'C')
        r->collect++;
    if (c == 'E')
        r->found_exit = 1;

    r->map_copy[x][y] = 'V';

    flood_fill(r, x + 1, y);
    flood_fill(r, x - 1, y);
    flood_fill(r, x, y + 1);
    flood_fill(r, x, y - 1);
}
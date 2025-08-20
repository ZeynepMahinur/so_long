#include "so_long.h"

static void    map_error(char *err)
{
    ft_printf("Error! %s\n", err);
}

void    if_error_exit(char *err, t_game *data)
{
    map_error(err);
    free_map(data);
    exit (1);
}

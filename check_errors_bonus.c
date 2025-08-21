#include "so_long_bonus.h"

static void    map_error_bonus(char *err)
{
    ft_printf("Error! %s\n", err);
}

void    if_error_exit_bonus(char *err, t_game *data)
{
    map_error_bonus(err);
    free_map_bonus(data);
    exit (1);
}
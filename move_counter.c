#include "so_long_bonus.h"

int    move_counter(t_game *data)
{
    static int  moves;

    moves++;
    ft_printf("Moves: %d\n", moves);
    return (moves);
}

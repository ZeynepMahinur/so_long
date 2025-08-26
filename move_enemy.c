#include "so_long_bonus.h"

static int move_towards(int current, int target)
{
    if (target > current)
        return (current + 1);
    else
        return (current - 1);
}

static int if_enemy_present(t_game *data, int x, int y)
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

static int my_abs(int n)
{
    if (n < 0)
        return -n;
    return n;
}

static void mv_en_to_pl(t_game *data, t_enemy *enemy)
{
    int     next_x;
    int     next_y;

    next_x = enemy->x;
    next_y = enemy->y;
    if (my_abs(data->player_x - enemy->x) > my_abs(data->player_y - enemy->y))
        next_x = move_towards(enemy->x, data->player_x);
    else
        next_y = move_towards(enemy->y, data->player_y);
    if (data->map[next_y][next_x] == '1' || data->map[next_y][next_x] == 'E')
        return ;
    if (if_enemy_present(data, next_x, next_y))
        return ;
    if (enemy->x == data->player_x && enemy->y == data->player_y)
    {
        ft_printf("Game over! You got caught by Teto 〣( ºΔº )〣.\n");
        close_game_bonus(data);
    }
    data->map[enemy->y][enemy->x] = '0';
    enemy->x = next_x;
    enemy->y = next_y;
    data->map[enemy->y][enemy->x] = 'X';
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




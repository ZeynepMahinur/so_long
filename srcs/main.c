#include "so_long.h"

int     main(int argc, char **argv)
{
    t_game data;

    if (argc != 2)
        return (1);
    map_read(argv[1], &data);
    check_map(&data);
    if (!is_it_reachable(&data))
        if_error_exit("Map is not solvable!", &data);
    
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "so_long");
    images(&data);
    draw_map(&data);
    mlx_key_hook(data.window, press_key, &data);
    mlx_hook(data.window, 17, 0, close_game, &data);
    mlx_loop(data.mlx);
}

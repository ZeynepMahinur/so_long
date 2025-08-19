#include "so_long.h"

/*int main(int argc, char **argv)
{
    t_game data;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    // Map'i oku
    if (map_read(argv[1], &data) == -1)
        map_error("Map couldn't be read.");

    // Kontrolleri yap
    check_map(&data);

    // Ulaşılabilirlik kontrolü
    if (!is_it_reachable(&data))
        map_error("Map is not solvable!");

    ft_printf("Map is valid and reachable!\n");
    for (int i = 0; i < data.height; i++)
        ft_printf("%s\n", data.map[i]);

    // Map'i temizle
    free_map(&data);

    return (0);
}*/

int     main(int argc, char **argv)
{
    t_game data;

    if (argc != 2)
        return (1);
    map_read(argv[1], &data);
    check_map(&data);
    if (!is_it_reachable(&data))
        map_error("Map is not solvable!");
    
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "so_long");
    images(&data);
    draw_map(&data);
    mlx_key_hook(data.window, press_key, &data);
    mlx_hook(data.window, 17, 0, close_game, &data);
    free_map(&data);
    mlx_loop(data.mlx);
}
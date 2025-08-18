/*#include "so_long.h"

int main(int argc, char **argv)
{
    t_game data;

    if (argc != 2)
        ft_printf("Usage: ./so_long <map_file.ber>");

    ft_memset(&data, 0, sizeof(t_game));

    map_read(argv[1], &data);

    ft_printf("DEBUG: Map height = %d, width = %d\n", data.height, data.width);

    for (int i = 0; i < data.height; i++)
        ft_printf("Map[%d]: %s", i, data.map[i]);

    free_map(&data);
    return 0;
}*/

#include "so_long.h"

/*int main(int argc, char **argv)
{
    t_game data;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    // map'i oku
    if (map_read(argv[1], &data) == -1)
        map_error("Map couldn't be read.");

    // kontrolleri yap
    check_map(&data);

    ft_printf("Map is valid!\n");

    // map'i temizle
    free_map(&data);

    return (0);
}*/

int main(int argc, char **argv)
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

    // Map'i temizle
    free_map(&data);

    return (0);
}




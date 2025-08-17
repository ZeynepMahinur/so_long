#include "so_long.h"

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
}


#include "so_long.h"

void    error(char *err)
{
    ft_printf("%s\n", err);
    exit (1);
}
int     map_read(char *filename, t_game *data)
{
    int     fd;
    int     i;
    int     len;
    char    *line;
    i = 0;

    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
        error("Error! Non-existant .ber file.");
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error("Error! Non-existant file.");
    
    data->height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        data->height++;
        free (line);
    }
    close(fd);

    //harita yer ayırma malloc
    data->map = malloc((sizeof(char *)) * (data->height + 1));
    if (!data->map)
        error("Error! Allocation failed.");
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error("Error! Non-existant file.");
    //width ayarı
    while ((line = get_next_line(fd)) != NULL)
    {
        data->map[i] = line;
        i++; 
    }
    data->map[i] = NULL;
    data->width = ft_strlen(data->map[0]);
    close (fd);
    return (0);
}

void    free_map(t_game *data)
{
    int     i;
    i = 0;
    while (i < data->height)
    {
        free (data->map[i]);
        i++;
    }
    free (data->map);
}

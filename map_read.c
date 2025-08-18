#include "so_long.h"

static void     check_ber(char *filename)
{
    int     len;

    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
        map_error("Invalid file extension. Expected .ber");

}

static void     height_count(int fd, t_game *data)
{
    char    *line;

    data->height = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        data->height++;
        free (line);
    }
}

static void     read_maplines(int fd, t_game *data)
{
    char    *line;
    int     i;

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        data->map[i++] = line;
    }
    data->map[i] = NULL;
    if (i == 0)
        map_error("Map is unreadable.");
}

int map_read(char *filename, t_game *data)
{
    int     fd;

    check_ber(filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        map_error("File could not be opened.");
    height_count(fd, data);
    close (fd);
    data->map = malloc(sizeof(char *) * (data->height + 1));
    if (!data->map)
        map_error("Memory allocation failed for map.");
    fd = open(filename, O_RDONLY);
    read_maplines(fd, data);
    close (fd);
    if (fd < 0)
        map_error("File couldn't be reopened");
    data->width = ft_strlen(data->map[0]);
    return (0);
}



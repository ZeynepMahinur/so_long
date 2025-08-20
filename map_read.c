#include "so_long.h"

static void     check_ber(char *filename)
{
    int     len;

    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    {
        ft_printf("Error! Invalid file extension. Expected .ber");
        exit (1);
    }
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
        if_error_exit("Map is unreadable.", data);
}

int map_read(char *filename, t_game *data)
{
    int     fd;

    check_ber(filename);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        if_error_exit("File could not be opened.", data);
    height_count(fd, data);
    close (fd);
    data->map = malloc(sizeof(char *) * (data->height + 1));
    if (!data->map)
        if_error_exit("Memory allocation failed for map.", data);
    fd = open(filename, O_RDONLY);
    read_maplines(fd, data);
    close (fd);
    if (fd < 0)
        if_error_exit("File couldn't be reopened", data);
    data->width = ft_strlen(data->map[0]);
    return (0);
}


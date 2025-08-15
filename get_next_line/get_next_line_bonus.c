/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:14:44 by zarikan           #+#    #+#             */
/*   Updated: 2025/07/10 14:14:50 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_join(int fd, char *saved)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= -1)
	{
		free (buffer);
		free (saved);
		return (NULL);
	}
	if (bytes <= 0)
	{
		free (buffer);
		return (saved);
	}
	buffer[bytes] = '\0';
	temp = saved;
	saved = ft_strjoin(saved, buffer);
	free (temp);
	free (buffer);
	return (saved);
}

static char	*read_save(int fd, char *saved)
{
	char	*old_saved;
	ssize_t	i;

	i = 1;
	while ((saved == NULL || !ft_strchr(saved, '\n')) && i != 0)
	{
		old_saved = saved;
		saved = read_join(fd, saved);
		if (saved == old_saved)
			break ;
		if (!saved)
			return (NULL);
	}
	return (saved);
}

static char	*get_line(char *saved)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!saved || saved[0] == '\0')
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] && saved[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*save_remain(char *saved)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free (saved);
		return (NULL);
	}
	i++;
	new_save = malloc(ft_strlen(saved + i) + 1);
	if (!new_save)
		return (NULL);
	while (saved[i])
		new_save[j++] = saved[i++];
	new_save[j] = '\0';
	free (saved);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	saved[fd] = read_save(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = get_line(saved[fd]);
	saved[fd] = save_remain(saved[fd]);
	return (line);
}

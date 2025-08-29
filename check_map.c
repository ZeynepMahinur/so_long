/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:49:28 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 14:52:16 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_rectangle_bonus(t_game *data)
{
	int	len;
	int	i;

	i = 0;
	while (i < data->height)
	{
		len = ft_strlen(data->map[i]);
		if (data->map[i][len - 1] == '\n')
			len--;
		if (len != data->width)
		{
			if_error_exit("Map isn't rectangular.", data);
		}
		i++;
	}
}

static void	check_wall_limit_bonus(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1')
			if_error_exit("First wall isn't closed properly.", data);
		if (data->map[data->height - 1][i] != '1')
			if_error_exit("Last wall isn't closed properly.", data);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1')
			if_error_exit("Left wall isn't closed properly.", data);
		if (data->map[i][data->width - 1] != '1')
			if_error_exit("Right wall isn't closed properly.", data);
		i++;
	}
}

void	check_map_bonus(t_game *data)
{
	check_rectangle_bonus(data);
	check_wall_limit_bonus(data);
	check_characters_bonus(data);
}

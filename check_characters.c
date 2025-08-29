/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:59:10 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 14:48:02 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemies(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		data->enemies[i].path_x = 1;
		data->enemies[i].path_y = 1;
		i++;
	}
}

static void	cnt_chars2(char c, t_count *count, t_game *data, t_args *args)
{
	if (c == 'P')
	{
		if (!args->wr_en)
		{
			count->player++;
			data->player_x = args->j;
			data->player_y = args->i;
		}
	}
	else if (c == 'X')
	{
		count->enemy++;
		if (args->wr_en)
		{
			data->enemies[*(args->enemy_i)].x = args->j;
			data->enemies[*(args->enemy_i)].y = args->i;
			data->enemies[*(args->enemy_i)].path_x = 1;
			data->enemies[*(args->enemy_i)].path_y = 1;
			data->enemies[*(args->enemy_i)].frame = 0;
			(*(args->enemy_i))++;
		}
	}
}

static void	cnt_chars(char c, t_count *count, t_game *data, t_args *args)
{
	if (c == 'C')
	{
		if (!args->wr_en)
		{
			count->collectible++;
		}
	}
	else if (c == 'E')
	{
		if (!args->wr_en)
		{
			count->exit++;
		}
	}
	else if (c != '1' && c != '0' && c != 'E'
		&& c != 'C' && c != 'P' && c != 'X')
		if_error_exit("Invalid character in the map.", data);
}

static void	scan_map(t_game *data, t_count *count, int *enemy_i, int wr_en)
{
	int		i;
	int		j;
	t_args	args;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			args.i = i;
			args.j = j;
			args.enemy_i = enemy_i;
			args.wr_en = wr_en;
			cnt_chars(data->map[i][j], count, data, &args);
			cnt_chars2(data->map[i][j], count, data, &args);
			j++;
		}
		i++;
	}
}

void	check_characters(t_game *data)
{
	t_count	count;
	int		enemy_index;

	count.player = 0;
	count.collectible = 0;
	count.exit = 0;
	count.enemy = 0;
	enemy_index = 0;
	scan_map(data, &count, &enemy_index, 0);
	if (count.enemy > 0)
		data->enemies = ft_calloc(count.enemy, sizeof(t_enemy));
	data->enemy_count = count.enemy;
	enemy_index = 0;
	scan_map(data, &count, &enemy_index, 1);
	data->collectible = count.collectible;
	if (count.player != 1)
		if_error_exit("There must be a character.", data);
	if (count.collectible < 1)
		if_error_exit("There must be atleast 1 collectible.", data);
	if (count.exit != 1)
		if_error_exit("There must be an exit.", data);
}

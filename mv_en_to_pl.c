/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_en_to_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:23:45 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 16:26:30 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	next_pos(t_game *data, t_enemy *enemy, int *next_x, int *next_y)
{
	*next_x = enemy->x;
	*next_y = enemy->y;
	if (my_abs(data->player_x - enemy->x) > my_abs(data->player_y - enemy->y))
		*next_x = move_towards(enemy->x, data->player_x);
	else
		*next_y = move_towards(enemy->y, data->player_y);
}

static int	move_to(t_game *data, t_enemy *enemy, int next_x, int next_y)
{
	int	i;

	i = 0;
	if (data->map[next_y][next_x] == '1' || data->map[next_y][next_x] == 'E')
		return (0);
	while (i < data->enemy_count)
	{
		if (&data->enemies[i] != enemy && data->enemies[i].x == next_x)
		{
			if (data->enemies[i].y == next_y)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	en_hit_pl(t_game *data, int x, int y)
{
	return (x == data->player_x && y == data->player_y);
}

static void	updt_map (t_game *data, t_enemy *enemy, int next_x, int next_y)
{
	if (data->map[enemy->y][enemy->x] != 'C')
		data->map[enemy->y][enemy->x] = '0';
	enemy->x = next_x;
	enemy->y = next_y;
}

void	mv_en_to_pl(t_game *data, t_enemy *enemy)
{
	int	next_x;
	int	next_y;

	if (data->ded)
		return ;
	next_pos(data, enemy, &next_x, &next_y);
	if (!move_to(data, enemy, next_x, next_y))
		return ;
	if (en_hit_pl(data, next_x, next_y))
	{
		ft_printf("Game over! You got caught by Teto 〣( ºΔº )〣.\n");
		data->ded = 1;
		close_game(data);
	}
	updt_map(data, enemy, next_x, next_y);
}

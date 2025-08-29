/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:31:17 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 17:14:38 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_door(t_game *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		if (data->collectible > 0)
		{
			ft_printf("You must collect all the leeks!\n");
			return (0);
		}
		else
		{
			ft_printf("Congratulations! You won!");
			close_game(data);
		}
	}
	return (1);
}

static int	move_conditions(t_game *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C')
	{
		data->collectible--;
		data->map[y][x] = '0';
	}
	if (data->map[y][x] == 'X')
	{
		ft_printf("Game over! You got caught by Teto 〣( ºΔº )〣.\n");
		close_game(data);
	}
	if (!exit_door(data, x, y))
		return (0);
	return (1);
}

static void	move_player(t_game *data, int px, int py)
{
	int	x;
	int	y;
	int	result;

	x = data->player_x + px;
	y = data->player_y + py;
	result = move_conditions(data, x, y);
	if (result == 0)
		return ;
	if (result == -1)
		return ;
	data->map[data->player_y][data->player_x] = '0';
	data->map[y][x] = 'P';
	move_counter(data);
	data->player_x = x;
	data->player_y = y;
	if (data->ded)
		return ;
}

static int	press_key_sd(int key_cd, t_game *data)
{
	if (key_cd == 97)
	{
		move_player(data, -1, 0);
		data->direction = 3;
	}
	else if (key_cd == 100)
	{
		move_player(data, 1, 0);
		data->direction = 4;
	}
	return (0);
}

int	press_key(int key_cd, t_game *data)
{
	if (key_cd == 65307)
		close_game(data);
	else if (key_cd == 119)
	{
		move_player(data, 0, -1);
		data->direction = 1;
	}
	else if (key_cd == 115)
	{
		move_player(data, 0, 1);
		data->direction = 2;
	}
	press_key_sd(key_cd, data);
	move_all_enemy(data);
	mlx_clear_window(data->mlx, data->window);
	draw_map(data);
	return (0);
}

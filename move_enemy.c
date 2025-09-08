/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:21:14 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 16:23:10 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_towards(int current, int target)
{
	if (target > current)
		return (current + 1);
	else if (target < current)
		return (current - 1);
	return (current);
}

int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	move_all_enemy(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		mv_en_to_pl(data, &data->enemies[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:53:35 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 13:58:19 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int animate_enemy(t_game *data)
{
	int			i;

	i = 0;
	while (i < data->enemy_count)
	{
		data->enemies[i].frame++;
		if (data->enemies[i].frame >= 4)
			data->enemies[i].frame = 0;
		i++;
	}
	return (0);
}

int	animate_bonus(t_game *data)
{
	static int	count;
	int			reference_map_size;
	int			current_map_size;
	double		speed_factor;
	int			threshold;

	reference_map_size = 256;
	current_map_size = (data->height * data->width);
	count++;
	speed_factor = (double)reference_map_size / (double)current_map_size;
	threshold = (int)(100 * speed_factor);
	if (threshold < 1)
		threshold = 1;
	if (count >= threshold)
	{
		data->frame = (data->frame + 1) % 4;
		animate_enemy(data);
		count = 0;
	}
	draw_map_bonus(data);
	return (0);
}


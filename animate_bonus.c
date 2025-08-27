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
		count = 0;
	}
	draw_map_bonus(data);
	return (0);
}

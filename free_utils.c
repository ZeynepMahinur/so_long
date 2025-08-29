/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:21:57 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 15:25:52 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	while (i < data->height)
	{
		if (data->map[i])
			free (data->map[i]);
		i++;
	}
	free (data->map);
	data->map = NULL;
}

void	free_animation(t_game *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->img.enemy_frames[i])
			mlx_destroy_image(data->mlx, data->img.enemy_frames[i]);
		if (data->img.player_frames[i])
			mlx_destroy_image(data->mlx, data->img.player_frames[i]);
		if (data->img.player_up[i])
			mlx_destroy_image(data->mlx, data->img.player_up[i]);
		if (data->img.player_down[i])
			mlx_destroy_image(data->mlx, data->img.player_down[i]);
		if (data->img.player_right[i])
			mlx_destroy_image(data->mlx, data->img.player_right[i]);
		if (data->img.player_left[i])
			mlx_destroy_image(data->mlx, data->img.player_left[i]);
		i++;
	}
}

int	close_game(t_game *data)
{
	free_animation(data);
	mlx_destroy_image(data->mlx, data->img.collectible_img);
	mlx_destroy_image(data->mlx, data->img.player_img);
	mlx_destroy_image(data->mlx, data->img.wall_img);
	mlx_destroy_image(data->mlx, data->img.floor_img);
	mlx_destroy_image(data->mlx, data->img.exit_img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free_map(data);
	free(data->enemies);
	free(data->mlx);
	exit (0);
	return (0);
}

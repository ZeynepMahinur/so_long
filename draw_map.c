/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:52:35 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/03 12:23:53 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_game *data)
{
	int	wid;
	int	hei;

	data->img.collectible_img = mlx_xpm_file_to_image(data->mlx,
			"textures/collectible.xpm", &wid, &hei);
	data->img.exit_img = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &wid, &hei);
	data->img.floor_img = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &wid, &hei);
	data->img.player_img = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &wid, &hei);
	data->img.wall_img = mlx_xpm_file_to_image(data->mlx,
			"textures/wallb.xpm", &wid, &hei);
	load_player_frames(data);
	load_player_frames2(data);
	load_enemy_frames(data);
}

static void	draw_player(t_game *data, int i, int j)
{
	if (data->direction == 0)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.player_frames[data->frame], j * 64, i * 64);
	else if (data->direction == 4)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.player_right[data->frame], j * 64, i * 64);
	else if (data->direction == 3)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.player_left[data->frame], j * 64, i * 64);
	else if (data->direction == 2)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.player_down[data->frame], j * 64, i * 64);
	else if (data->direction == 1)
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.player_up[data->frame], j * 64, i * 64);
}

static void	draw_enemies(t_game *data)
{
	t_enemy	*ene;
	int		i;

	i = 0;
	while (i < data->enemy_count)
	{
		ene = &data->enemies[i];
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.enemy_frames[ene->frame], ene->x * 64, ene->y * 64);
		i++;
	}
}

static void	draw_map2(t_game *data, int i, int j)
{
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.collectible_img, j * 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.exit_img, j * 64, i * 64);
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->window,
					data->img.floor_img, j * 64, i * 64);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window,
					data->img.wall_img, j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				draw_player(data, i, j);
			draw_map2(data, i, j);
			draw_enemies(data);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_frames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:34:15 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/03 12:24:38 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy_frames(t_game*data)
{
	int	wid;
	int	hei;

	data->img.enemy_frames[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy_idle1.xpm", &wid, &hei);
	data->img.enemy_frames[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy_idle2.xpm", &wid, &hei);
	data->img.enemy_frames[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy_idle3.xpm", &wid, &hei);
	data->img.enemy_frames[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy_idle4.xpm", &wid, &hei);
}

void	load_player_frames2(t_game *data)
{
	int	wid;
	int	hei;

	data->img.player_left[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/charleft3.xpm", &wid, &hei);
	data->img.player_left[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/charleft4.xpm", &wid, &hei);
	data->img.player_down[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/chardown1.xpm", &wid, &hei);
	data->img.player_down[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/chardown2.xpm", &wid, &hei);
	data->img.player_down[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/chardown3.xpm", &wid, &hei);
	data->img.player_down[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/chardown4.xpm", &wid, &hei);
	data->img.player_up[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/charup1.xpm", &wid, &hei);
	data->img.player_up[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/charup2.xpm", &wid, &hei);
	data->img.player_up[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/charup3.xpm", &wid, &hei);
	data->img.player_up[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/charup4.xpm", &wid, &hei);
}

void	load_player_frames(t_game *data)
{
	int	wid;
	int	hei;

	data->img.player_frames[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/charidle_1.xpm", &wid, &hei);
	data->img.player_frames[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/charidle_2.xpm", &wid, &hei);
	data->img.player_frames[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/charidle_3.xpm", &wid, &hei);
	data->img.player_frames[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/charidle_4.xpm", &wid, &hei);
	data->img.player_right[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/charright1.xpm", &wid, &hei);
	data->img.player_right[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/charright2.xpm", &wid, &hei);
	data->img.player_right[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/charright3.xpm", &wid, &hei);
	data->img.player_right[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/charright4.xpm", &wid, &hei);
	data->img.player_left[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/charleft1.xpm", &wid, &hei);
	data->img.player_left[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/charleft2.xpm", &wid, &hei);
}

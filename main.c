/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:37:10 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 16:02:09 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	data;

	ft_memset(&data, 0, sizeof(data));
	data.frame = 0;
	if (argc != 2)
		return (1);
	map_read_bonus(argv[1], &data);
	check_map_bonus(&data);
	if (!is_it_reachable_bonus(&data))
		if_error_exit("Map is not solvable!", &data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx,
			data.width * 64, data.height * 64, "so_long");
	images_bonus(&data);
	draw_map_bonus(&data);
	mlx_hook(data.window, 2, 1L << 0, press_key_bonus, &data);
	mlx_hook(data.window, 3, 1L << 1, release_key_bonus, &data);
	mlx_loop_hook(data.mlx, animate_bonus, &data);
	mlx_hook(data.window, 17, 0, close_game_bonus, &data);
	mlx_loop(data.mlx);
}

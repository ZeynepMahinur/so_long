/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:40:50 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 18:07:32 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../so_long_folder/minilibx-linux/mlx.h"
# include "../so_long_folder/get_next_line/get_next_line.h"
# include "../so_long_folder/libft/libft.h"
# include "../so_long_folder/printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_image
{
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_frames[4];
	void	*player_up[4];
	void	*player_down[4];
	void	*player_left[4];
	void	*player_right[4];
	void	*enemy_frames[4];
	void	*enemy_img;
}		t_image;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	path_x;
	int	path_y;
	int	frame;
}		t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_image	img;
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		enemy_count;
	t_enemy	*enemies;
	int		collectible;
	int		frame;
	int		direction;
	int		ded;
}		t_game;

typedef struct s_count
{
	int	player;
	int	collectible;
	int	exit;
	int	enemy;
}		t_count;

typedef struct s_reach
{
	char	**map_copy;
	int		collect;
	int		found_exit;
	int		height;
}	t_reach;

typedef struct s_args
{
	int	i;
	int	j;
	int	*enemy_i;
	int	wr_en;
}		t_args;

void	free_map(t_game *data);
int		map_read(char *filename, t_game *data);
void	check_map(t_game *data);
void	check_characters(t_game *data);
void	flood_fill(t_reach *r, int x, int y);
int		is_it_reachable(t_game *data);
void	draw_map(t_game *data);
void	images(t_game *data);
int		press_key(int key_code, t_game *data);
int		release_key(int key_code, t_game *data);
int		close_game(t_game *data);
void	if_error_exit(char *err, t_game *data);
int		animate(t_game *data);
void	free_animation(t_game *data);
int		move_counter(t_game *data);
void	move_all_enemy(t_game *data);
void	check_enemies(t_game *data);
int		my_abs(int n);
int		move_towards(int current, int target);
void	mv_en_to_pl(t_game *data, t_enemy *enemy);
void	load_player_frames(t_game *data);
void	load_player_frames2(t_game *data);
void	load_enemy_frames(t_game *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:19:50 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 15:21:33 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_reach *r, int x, int y)
{
	char	c;

	if (x < 0 || y < 0)
		return ;
	if (x < 0 || y < 0 || y >= r->height || x >= (int)ft_strlen(r->map_copy[y]))
		return ;
	c = r->map_copy[y][x];
	if (c == '1' || c == 'V')
		return ;
	if (c == 'C')
		r->collect++;
	if (c == 'E')
		r->found_exit = 1;
	r->map_copy[y][x] = 'V';
	flood_fill(r, x + 1, y);
	flood_fill(r, x - 1, y);
	flood_fill(r, x, y + 1);
	flood_fill(r, x, y - 1);
}

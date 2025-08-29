/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:20:29 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 16:21:02 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_counter(t_game *data)
{
	static int	moves;

	(void)data;
	moves++;
	ft_printf("Moves: %d\n", moves);
	return (moves);
}

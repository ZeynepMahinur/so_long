/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:48:29 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 14:49:08 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_error_bonus(char *err)
{
	ft_printf("Error! %s\n", err);
}

void	if_error_exit(char *err, t_game *data)
{
	map_error_bonus(err);
	free_map_bonus(data);
	exit (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:26:32 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/03 12:26:43 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	release_key(int key_cd, t_game *data)
{
	if (key_cd == 119 || key_cd == 115 || key_cd == 97 || key_cd == 100)
		data->direction = 0;
	return (0);
}

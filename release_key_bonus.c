#include "so_long_bonus.h"

int	release_key_bonus(int key_cd, t_game *data)
{
	if (key_cd == 119 || key_cd == 115 || key_cd == 97 || key_cd == 100)
		data->direction = 0;
	return (0);
}
#include "so_long.h"

int	release_key(int key_cd, t_game *data)
{
	if (key_cd == 119 || key_cd == 115 || key_cd == 97 || key_cd == 100)
		data->direction = 0;
	return (0);
}
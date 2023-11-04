#include "fdf.h"

//This file will contain all the functions
//that are responsible for different keys to be pressef
int	close_window(int keycode, t_vars	*vars)
{
	printf("*Clossing the window*\n");
	mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

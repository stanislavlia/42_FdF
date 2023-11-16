#include "fdf.h"

//This file will contain all the functions
//that are responsible for different keys to be pressed
int	close_window(int keycode, t_env	*env)
{
	if (keycode == ESCAPE)
		printf("*Clossing the window*\n");
		mlx_destroy_window(env->mlx, env->mlx_window);
	return (1);
}

void	set_new_image(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	mlx_clear_window(env->mlx, env->mlx_window);
	env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img.addr = mlx_get_data_addr(env->img.img,
					&env->img.bits_per_pixel,
					&env->img.line_length,
					&env->img.endian);

	display_static_matrix(env);
}



int	shift_picture(int keycode, t_env *env)
{
	if (keycode == ARROW_RIGHT)
	{
		shift_matrix_x(env, 40);
		
		
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == ARROW_LEFT)
	{
		shift_matrix_x(env, -40);
		
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == ARROW_UP)
	{
		shift_matrix_y(env, -40);
		

		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == ARROW_DOWN)
	{
		shift_matrix_y(env, 40);

		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}	

void	hook_all_funcs(t_env	*env)
{
	mlx_key_hook(env->mlx_window, close_window, env);
	mlx_key_hook(env->mlx_window, shift_picture, env);
}

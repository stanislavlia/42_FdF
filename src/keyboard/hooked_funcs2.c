#include "fdf.h"

int	reset_to_isom(int keycode, t_env *env)
{
	if (keycode == KEY_R)
	{
		env->map = env->init_isom_map;
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}

int	rotate_pic_z(int keycode, t_env *env)
{
	if (keycode == MOUSE_CLICK_LEFT)
	{
		rotate_matrix_x(&env->map, M_PI / 16);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == MOUSE_CLICK_RIGHT)
	{
		rotate_matrix_z(&env->map, - M_PI / 16);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}

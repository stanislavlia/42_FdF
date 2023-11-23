/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooked_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:45:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/23 14:45:27 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	mlx_destroy_window(env->mlx, env->mlx_window);
	free_matrix(&env->map);
	free_matrix(&env->init_isom_map);
	free(env->mlx);
	exit(0);
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
		shift_matrix_x(env, -40);
	if (keycode == ARROW_LEFT)
		shift_matrix_x(env, 40);
	if (keycode == ARROW_UP)
		shift_matrix_y(env, 40);
	if (keycode == ARROW_DOWN)
		shift_matrix_y(env, -40);
	if (keycode == KEY_R)
		reset_to_isom(keycode, env);
	set_new_image(env);
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	return (1);
}

int	scale_picture(int keycode, t_env *env)
{
	if (keycode == PLUS)
	{
		scale_matrix(env, 1.2);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == MINUS)
	{
		scale_matrix(env, 0.8);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}

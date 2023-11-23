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

int	reset_to_isom(int keycode, t_env *env)
{
	if (keycode == KEY_R)
	{
		copy_matrix(&env->init_isom_map, &env->map);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}

int	rotate_pic_z(int keycode, t_env *env)
{
	if (keycode == MOUSE_CLICK_LEFT)
	{
		rotate_matrix_x(&env->map, M_PI / 32);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	if (keycode == MOUSE_CLICK_RIGHT)
	{
		rotate_matrix_z(&env->map, -M_PI / 32);
		set_new_image(env);
		mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
	}
	return (1);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
		ft_close_window(env);
	if (keycode == PLUS || keycode == MINUS)
		scale_picture(keycode, env);
	else
		shift_picture(keycode, env);
	return (1);
}

void	hook_all_funcs(t_env	*env)
{
	mlx_key_hook(env->mlx_window, key_hook, env);
	mlx_hook(env->mlx_window, MOUSE_CLICK_LEFT, 0, rotate_pic_z, env);
	mlx_hook(env->mlx_window, MOUSE_CLICK_RIGHT, 0, rotate_pic_z, env);
	mlx_hook(env->mlx_window, 17, 0, ft_close_window, env);
}

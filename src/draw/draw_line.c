/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:53:11 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/23 11:53:14 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_steep(t_vector p1, t_vector p2)
{
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
		return (1);
	return (0);
}

void	draw_linelow(t_vector p1, t_vector p2, t_env *env)
{
	double	d;
	int		y_step;
	int		x;
	int		y;

	x = p1.x;
	y = p1.y;
	y_step = 1;
	if ((p2.y - p1.y) < 0)
		y_step = -1;
	d = (2 * (p2.y - p1.y) * y_step) - (p2.x - p1.x);
	while (x < p2.x)
	{
		if (abs(p2.z - p1.z) > 0)
			my_mlx_pixel_put(&(env->img), x, y,
				interpolate_color(p1.color,
					create_trgb(0, 200, 50, 100),
					calculate_gradient(x, y, p1, p2)));
		else
			my_mlx_pixel_put(&(env->img), x, y, p1.color);
		y = y + y_step * (d > 0);
		d = d + (2 * ((p2.y - p1.y) * y_step - (p2.x - p1.x) * (d > 0)));
		x++;
	}
}

void	draw_linehigh(t_vector p1, t_vector p2, t_env *env)
{
	double	d;
	int		x_step;
	int		x;
	int		y;

	x = p1.x;
	y = p1.y;
	x_step = 1;
	if ((p2.x - p1.x) < 0)
		x_step = -1;
	d = (2 * (p2.x - p1.x) * x_step) - (p2.y - p1.y);
	while (y < p2.y)
	{
		if (abs(p2.z - p1.z) > 0)
			my_mlx_pixel_put(&(env->img), x, y,
				interpolate_color(p1.color,
					create_trgb(0, 200, 50, 100),
					calculate_gradient(x, y, p1, p2)));
		else
			my_mlx_pixel_put(&(env->img), x, y, p1.color);
		x = x + x_step * (d > 0);
		d += 2 * ((p2.x - p1.x) * x_step) + (2 * (-(p2.y - p1.y))) * (d > 0);
		y++;
	}
}

void	draw_line(t_vector p1, t_vector p2, t_env *env)
{
	if (is_steep(p1, p2))
	{
		if (p2.y > p1.y)
			draw_linehigh(p1, p2, env);
		else
			draw_linehigh(p2, p1, env);
	}
	else
	{
		if (p2.x > p1.x)
			draw_linelow(p1, p2, env);
		else
			draw_linelow(p2, p1, env);
	}
}

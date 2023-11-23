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

int	interpolate_color(int color1, int color2, double gradient)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((color1 >> 16) & 0xFF) + (((color2 >> 16) & 0xFF)
				- ((color1 >> 16) & 0xFF)) * gradient);
	g = (int)(((color1 >> 8) & 0xFF) + (((color2 >> 8) & 0xFF)
				- ((color1 >> 8) & 0xFF)) * gradient);
	b = (int)((color1 & 0xFF) + ((color2 & 0xFF) - (color1 & 0xFF)) * gradient);
	return ((r << 16) | (g << 8) | b);
}

double	calculate_gradient(int x, int y, t_vector p1, t_vector p2)
{
	int	dx;
	int	dy;
	int	distance;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	distance = sqrt(dx * dx + dy * dy);
	return (sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y)) / distance);
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

// void draw_linehigh(t_vector p1, t_vector p2, t_env *env)
// {
//     double dx, dy, D;
//     int x_step, x, y;
//     double gradient, distance, currentDistance;

//     x = p1.x;
//     y = p1.y;
//     x_step = 1;
//     dx = p2.x - p1.x;
//     dy = p2.y - p1.y;
//     distance = sqrt(dx * dx + dy * dy); // Total distance between p1 and p2

//     if (dx < 0) {
//         x_step = -1;
//         dx = -dx;
//     }
//     D = (2 * dx) - dy;

//     while (y < p2.y) {
//         currentDistance = sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y));
//         gradient = currentDistance / distance; // Calculate the gradient at the current point

//         // Interpolate the color based on the gradient and the z values
//         int interpolatedColor = interpolate_color(p1.color, p2.color, gradient);

// 		if (abs(p2.z - p1.z) > 0)
//        		my_mlx_pixel_put(&(env->img), floor((double)x), floor((double)y), interpolatedColor);
// 		else
// 			my_mlx_pixel_put(&(env->img), floor((double)x), floor((double)y), p1.color);

//         if (D > 0) {
//             x = x + x_step;
//             D = D + (2 * (dx - dy));
//         } else {
//             D = D + 2 * dx;
//         }
//         y++;
//     }
// }

void	draw_line(t_vector p1, t_vector p2, t_env *env)
{
	// if (abs(p2.x) >= WIDTH / 2 || abs(p2.y) >= HEIGHT / 2)
	// 	return ;
	// if (abs(p1.x) >= WIDTH / 2 || abs(p1.y) >= HEIGHT / 2)
	// 	return ;
	if	(is_steep(p1, p2))
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


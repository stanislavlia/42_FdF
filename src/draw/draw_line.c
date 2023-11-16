
#include "fdf.h"


int	is_steep(t_vector p1, t_vector p2)
{
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
		return (1);
	return (0);
}

//Implementation of Bresenham's algorithm

//Plots line with small steep (x changes faster than y)
// Reduce num of vars
void	draw_linelow(t_vector p1, t_vector p2, t_env *env)
{
	int	dx;
	int	dy;
	int	y_step;
	int	x;
	int y;
	int D;


	x = p1.x;
	y = p1.y;
	y_step = 1;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dy < 0)
	{
		y_step = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	while (x < p2.x)
	{
		//printf("plot x = %d; y = %d\n", x, y);
		//my_mlx_pixel_put(&(env->img.img), x, y, DEFAULT_COLOR);
		if ((p2.z > 0))
			my_mlx_pixel_put(&(env->img), x, y, create_trgb(0, 255, 100, 100));
		else
			my_mlx_pixel_put(&(env->img), x, y, p2.color);
		if (D > 0)
		{
			y = y + y_step;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		x++;
	}
}

//Basically swaps x and y axises
// replace x with y in func for low steep
void	draw_linehigh(t_vector p1, t_vector p2, t_env *env)
{
	int	dx;
	int	dy;
	int	x_step;
	int	x;
	int y;
	int D;


	x = p1.x;
	y = p1.y;
	x_step = 1;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx < 0)
	{
		x_step = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	while (y < p2.y)
	{
		if ((p2.z > 0))
			my_mlx_pixel_put(&(env->img), x, y, create_trgb(0, 255, 100, 100));
		else
			my_mlx_pixel_put(&(env->img), x, y, p2.color);
		if (D > 0)
		{
			x = x + x_step;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
		y++;
	}
}

void	draw_line(t_vector p1, t_vector p2, t_env *env)
{
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

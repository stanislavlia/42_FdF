
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
		printf("plot x = %d; y = %d\n", x, y);
		//my_mlx_pixel_put(env->img.img, x, y, DEFAULT_COLOR);
		my_mlx_pixel_put(&env->img.img, x, y, DEFAULT_COLOR);
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
		printf("plot x = %d; y = %d\n", x, y); //replace with put_pixel
		//my_mlx_pixel_put(env->img.img, x, y, DEFAULT_COLOR);
		my_mlx_pixel_put(&env->img.img, x, y, DEFAULT_COLOR);
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


// int	main()
// {
// 	t_vector	p1;
// 	t_vector	p2;
// 	t_env		env;

// 	p1.x = 0; p1.y = -4;
// 	p2.x = 0; p2.y = -10;
// 	draw_line(p1, p2, &env);
// }

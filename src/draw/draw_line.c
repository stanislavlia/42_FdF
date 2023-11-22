
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
// void	draw_linelow(t_vector p1, t_vector p2, t_env *env)
// {
// 	double	dx;
// 	double	dy;
// 	int	y_step;
// 	int	x;
// 	int y;
// 	double D;

// 	x = p1.x;
// 	y = p1.y;
// 	y_step = 1;
// 	dx = p2.x_fl - p1.x_fl;
// 	dy = p2.y_fl - p1.y_fl;
// 	if (dy < 0)
// 	{
// 		y_step = -1;
// 		dy = -dy;
// 	}
// 	D = (2 * dy) - dx;
// 	while (x < p2.x)
// 	{
// 		//printf("plot x = %d; y = %d\n", x, y);
// 		//my_mlx_pixel_put(&(env->img.img), x, y, DEFAULT_COLOR);
// 		if (p2.z_fl > p1.z_fl || (p1.z_fl > 0) && p2.z_fl > 0)
// 		{
// 			p2.color = create_trgb(0, 200, 50, 100);

// 			my_mlx_pixel_put(&(env->img), x , y , p2.color);
// 		}
// 		else
// 			my_mlx_pixel_put(&(env->img), x,  y , p2.color);
// 		if (D > 0)
// 		{
// 			y = y + y_step;
// 			D = D + (2 * (dy - dx));
// 		}
// 		else
// 			D = D + 2 * dy;
// 		x++;
// 	}
// }


// void	draw_linehigh(t_vector p1, t_vector p2, t_env *env)
// {
// 	double	dx;
// 	double	dy;
// 	int	x_step;
// 	int	x;
// 	int y;
// 	double D;

// 	x = p1.x;
// 	y = p1.y;
// 	x_step = 1;
// 	dx = p2.x - p1.x;
// 	dy = p2.y - p1.y;

// 	if (dx < 0)
// 	{
// 		x_step = -1;
// 		dx = -dx;
// 	}
// 	D = (2 * dx) - dy;
// 	while (y < p2.y)
// 	{
// 		//if ((p2.z > 0 || p1.z > 0))
// 		if (p1.z > p2.z || (p1.z_fl > 0) && p2.z_fl > 0)
// 		{	
// 			p2.color = (int) create_trgb(0, 200, 50, 100);
// 			my_mlx_pixel_put(&(env->img), floor((double)x) , floor((double)y) , p2.color);
// 		}
// 		else
// 			my_mlx_pixel_put(&(env->img), floor((double)x), floor((double)y), p2.color);
// 		if (D > 0)
// 		{
// 			x = x + x_step;
// 			D = D + (2 * (dx - dy));
// 		}
// 		else
// 			D = D + 2 * dx;
// 		y++;
// 	}
// }
int interpolate_color(int color1, int color2, double gradient) 
{
    // Extract RGB components from color1
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    // Extract RGB components from color2
    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    // Interpolate each component
    int r = (int)(r1 + (r2 - r1) * gradient);
    int g = (int)(g1 + (g2 - g1) * gradient);
    int b = (int)(b1 + (b2 - b1) * gradient);

    // Combine components back into a single color
    return (r << 16) | (g << 8) | b;
}



void draw_linelow(t_vector p1, t_vector p2, t_env *env) {
    double dx, dy, D;
    int y_step, x, y;
    double gradient, distance, currentDistance;

    x = p1.x;
    y = p1.y;
    y_step = 1;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    distance = sqrt(dx * dx + dy * dy); // Total distance between p1 and p2

    if (dy < 0) {
        y_step = -1;
        dy = -dy;
    }
    D = (2 * dy) - dx;

    while (x < p2.x) {
        currentDistance = sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y));
        gradient = currentDistance / distance; // Calculate the gradient at the current point

        // Interpolate the color based on the gradient
        int interpolatedColor = interpolate_color(p1.color, create_trgb(0, 200, 50, 100), gradient);
		if (abs(p2.z - p1.z) > 0 )
        	my_mlx_pixel_put(&(env->img), x, y, interpolatedColor);
		else
			my_mlx_pixel_put(&(env->img), x, y, p1.color);

        if (D > 0) {
            y = y + y_step;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2 * dy;
        }
        x++;
    }
}




void draw_linehigh(t_vector p1, t_vector p2, t_env *env) {
    double dx, dy, D;
    int x_step, x, y;
    double gradient, distance, currentDistance;

    x = p1.x;
    y = p1.y;
    x_step = 1;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    distance = sqrt(dx * dx + dy * dy); // Total distance between p1 and p2

    if (dx < 0) {
        x_step = -1;
        dx = -dx;
    }
    D = (2 * dx) - dy;

    while (y < p2.y) {
        currentDistance = sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y));
        gradient = currentDistance / distance; // Calculate the gradient at the current point

        // Interpolate the color based on the gradient and the z values
        int interpolatedColor = interpolate_color(p1.color, p2.color, gradient);

		if (abs(p2.z - p1.z) > 0)
       		my_mlx_pixel_put(&(env->img), floor((double)x), floor((double)y), interpolatedColor);
		else
			my_mlx_pixel_put(&(env->img), floor((double)x), floor((double)y), p1.color);

        if (D > 0) {
            x = x + x_step;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2 * dx;
        }
        y++;
    }
}



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

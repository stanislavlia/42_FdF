
#include "fdf.h"

//Implementation of Bresenham's algorithm

//For now, 
//		   I assume x2 > x1
//				and y2 > y1
// 			For now func doesnt work with great slope + some edge cases
void	draw_line(t_vector	point1, t_vector point2, int color, t_env env)
{
	int	deltaY;
	int	deltaX;
	int	x;
	int	y;
	int	D;

	
	deltaY = point2.y - point1.y;
	deltaX = point2.x - point1.x;
	x = point1.x;
	y = point1.y;
	D = 2*deltaY - deltaX;

	printf("point1: x = %d y = %d\n", point1.x, point1.y);
	printf("point2: x = %d y = %d\n", point2.x, point2.y);
	printf("Dx = %d; Dy = %d\n", deltaX, deltaY);


	while (x < point2.x)
	{
		printf("plot x=%d; y=%d\n", x, y);
		if (D > 0)
		{
			y++;
			D = D - 2 * deltaX;
		}
		D = D + 2 * deltaY;
		x++;
	}
}

int	main()
{
	t_vector	p1;
	t_vector	p2;
	t_env		env;


	p1.x = 0; p1.y = 1;
	p2.x = 2; p2.y = 5;
	draw_line(p1, p2, 100, env);
	
}

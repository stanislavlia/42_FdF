#include "fdf.h"

//MLX drawing

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	fill_topleft_square(void	*img, int	square_size, int	color)
{
	int	default_color = create_trgb(0, 200, 100, 0);
	int	i = 0;
	int	j = 0;

	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			my_mlx_pixel_put(img, i, j, default_color);
			printf("i = %d; j = %d\n", i, j);
			j++;
		}
		i++;
	}
}


// void	display_matrix(void		*img, t_matrix matrix)
// {
// 	int	default_color = create_trgb(0, 200, 100, 0);
// 	int	highval_color = create_trgb(0, 255, 50, 255);
// 	int	i = 0;
// 	int	j = 0;
// 	int	z_val;

// 	while (i < matrix.m)
// 	{
// 		j = 0;
// 		while (j < matrix.n)
// 		{	
// 			z_val = matrix.rows[i].values[j].z;
// 			if (z_val > 5)
// 				my_mlx_pixel_put(img, j, i, highval_color);
// 			else
// 				my_mlx_pixel_put(img, j, i, default_color);
// 			printf("i = %d; j = %d\n", i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	display_static_matrix(t_env *env, int x_margin, int y_margin)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->map.m)
	{
		j = 0;
		while (j < env->map.n)
		{
			my_mlx_pixel_put(&env->img.img, i * y_margin, j * x_margin, DEFAULT_COLOR);
			j++;
		}
		i++;
	}	
}

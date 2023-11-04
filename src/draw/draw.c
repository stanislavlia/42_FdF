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
	int	i = 0;
	int	j = 0;

	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			my_mlx_pixel_put(img, i, j, color);
			printf("i = %d; j = %d\n", i, j);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:27:06 by sliashko          #+#    #+#             */
/*   Updated: 2023/10/31 18:27:09 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//Counts number of numbers in row 
int	count_els_row(char *row)
{
	int	n_els;

	n_els = 0;
	while (*row != '\0')
	{
		if (*row == ' ')
			n_els++;
		row++;
	}
	return (n_els);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}


//NOTE: create func to free the row
t_row	extract_row(char *row, int y, int row_size)
{
	char	**array_row;
	int		x_coord;
	t_vector *row_extracted;
	t_row	row_ret;
	
	row_extracted = (t_vector *) malloc(sizeof(t_vector) * row_size);
	array_row = ft_split(row, ' ');
	// if (array_row == NULL || row == NULL)
	// 	Make up some way to report about mistake
	x_coord = 0;
	while (x_coord < row_size)
	{
		row_extracted[x_coord].x = x_coord;
		row_extracted[x_coord].y = y;
		row_extracted[x_coord].z_color_pair = array_row[x_coord];
		set_z_and_color(&(row_extracted[x_coord]), DEFAULT_COLOR);
		printf("x = %d; y = %d; z = %d; color = %d\n", x_coord, y, row_extracted[x_coord].z, row_extracted[x_coord].color);

		x_coord++;
	}
	row_ret.values = row_extracted;
	row_ret.y = y;
	free_2d_array(array_row);
	return (row_ret);
}

t_matrix	read_matrix(int fd, int m, int n) //TODO: Create a function that will free the matrix
{
	char	*curr_line;
	int		y_coord;
	t_matrix	matrix;

	matrix.m = m;
	matrix.n = n;
	y_coord = 0;
	matrix.rows = (t_row *) malloc(sizeof(t_row) * m);
	while (y_coord < m)
	{	
		curr_line = get_next_line(fd);
		printf("Line: %s", curr_line);
		matrix.rows[y_coord] = extract_row(curr_line, y_coord, n);
		y_coord++;
	}
	return matrix;
}

//it separates (z_val, color) pair if there is color in this vector
// otherwise just write value to vec.z 
void	set_z_and_color(t_vector	*vec, int	default_color)
{
	int	i;

	i = 0;
	vec->z = ft_atoi(vec->z_color_pair);
	while (vec->z_color_pair[i] != '\0')
	{
		if (vec->z_color_pair[i] == ',')
		{
			vec->color = ft_atoi_base((vec->z_color_pair) + i + 3, "0123456789ABCDEF");
			return ;
		}
		i++;
	}
	vec->color = default_color;
}


// int	main()
// {
// 	//t_row row = extract_row("132   1   -132   435   -1  -2          ", 2, 6);
	
// 	int	fd = open("/Users/sliashko/Desktop/FdF/test_maps/elem-col.fdf", O_RDONLY);
// 	printf("FD = %d\n", fd);

// 	void	*mlx = mlx_init();
// 	void	*mlx_window = mlx_new_window(mlx, 1000, 1000, "My FDF window");
// 	t_data	img;
// 	t_vars  vars;
// 	vars.win = mlx_window;
// 	vars.mlx = mlx;

// 	//printf("Atoi base result = %d \n", ft_atoi_base("1A", "0123456789ABCDEF"));
// 	img.img = mlx_new_image(mlx, 100, 100);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 						&img.endian);

// 	t_matrix matrix = read_matrix(fd, 10, 10);
// 	printf("M = %d\nN = %d\n", matrix.m, matrix.n);

// 	// mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
// 	// display_matrix(&(img.img), matrix);
// 	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
// 	// mlx_loop(mlx);

// }


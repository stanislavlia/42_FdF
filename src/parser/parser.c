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
		free(curr_line);
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

int	main()
{
	t_env	env;
	setup_environment(&env);

	t_vector	p1;
	t_vector	p2;

	p1.x = 0; p1.y = 0;
	p2.x = 500; p2.y = 334;


	draw_line(p1, p2, &env);
	// my_mlx_pixel_put(env.img.img, 51,51, DEFAULT_COLOR);
	// my_mlx_pixel_put(env.img.img, 52, 52, DEFAULT_COLOR);
	// my_mlx_pixel_put(env.img.img, 53, 53, DEFAULT_COLOR);
	// my_mlx_pixel_put(env.img.img, 100, 100, DEFAULT_COLOR);
	//fill_topleft_square(&env.img.img, 100, DEFAULT_COLOR);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 50, 50);
	
	mlx_loop(env.mlx);
}

// int	main()
// {
	
// 	int	fd = open("/Users/sliashko/Desktop/FdF/test_maps/elem-col.fdf", O_RDONLY);
// 	printf("FD = %d\n", fd);

// 	t_env	env;
	

// 	setup_environment(&env);
// 	env.map = read_matrix(fd, 10, 10);
// 	printf("M = %d\nN = %d\n", env.map.m, env.map.n);

// 	mlx_hook(env.mlx_window, 2, 1L<<0, close_window, &env);
// 	display_matrix(&(env.img.img), env.map);

// 	mlx_loop(env.mlx);
// 	//free_matrix(&env.map);
	
// }


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
		row_extracted[x_coord].z = ft_atoi(array_row[x_coord]); //TODO: adress case of (num,color) BONUS part
		//printf("X = %d; Y = %d; Z = %d \n", x_coord, y, ft_atoi(array_row[x_coord]));

		x_coord++;
	}
	//DONT FORGET TO FREE array_row
	row_ret.values = row_extracted;
	row_ret.y = y;
	free_2d_array(array_row);
	return (row_ret);
}


t_matrix	read_matrix(int fd, int m, int n)
{
	char	*curr_line;
	int		y_coord;
	t_matrix	matrix;

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


int	main()
{
	//t_row row = extract_row("132   1   -132   435   -1  -2          ", 2, 6);

	
	int	fd = open("/Users/sliashko/Desktop/FdF/test_maps/10-2.fdf", O_RDONLY);
	printf("FD = %d\n", fd);

	void	*mlx = mlx_init();
	void	*mlx_window = mlx_new_window(mlx, 1000, 1000, "My FDF window");
	t_data	img;

	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
						&img.endian);

	fill_topleft_square(&(img.img), 300, 0x00FFFFAC);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);

	mlx_loop(mlx);
	// t_matrix matrix = read_matrix(fd, 10, 10);
	// printf("some el there %d\n", matrix.rows[0].values[3].z);


}

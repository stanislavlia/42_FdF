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

t_row	extract_row(char *row, int y, int row_size, t_matrix matrix)
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
		row_extracted[x_coord].x = (x_coord - row_size / 2) * matrix.x_margin ;
		row_extracted[x_coord].y = (y - matrix.m / 2) * matrix.y_margin;
		row_extracted[x_coord].x_fl = (double) row_extracted[x_coord].x;
		row_extracted[x_coord].y_fl = (double) row_extracted[x_coord].y;
		row_extracted[x_coord].z_color_pair = array_row[x_coord];
		set_z_and_color(&(row_extracted[x_coord]), DEFAULT_COLOR);
		row_extracted[x_coord].z_fl = (double) row_extracted[x_coord].z;
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
	matrix.x_margin = (WIDTH / n) / 1.8;
	matrix.y_margin = (HEIGHT / m) / 1.5;
	y_coord = 0;
	matrix.rows = (t_row *) malloc(sizeof(t_row) * m);
	while (y_coord < m)
	{	
		curr_line = get_next_line(fd);
		matrix.rows[y_coord] = extract_row(curr_line, y_coord, n, matrix);
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
	if (vec->z > 0)
		vec->color = create_trgb(0, 120, 40, 120);
	else
		vec->color = default_color;
	while (vec->z_color_pair[i] != '\0')
	{
		if (vec->z_color_pair[i] == ',')
		{
			vec->color = ft_atoi_base((vec->z_color_pair) + i + 3, "0123456789ABCDEF");
			return ;
		}
		i++;
	}
	
}



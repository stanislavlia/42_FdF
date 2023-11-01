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
t_vector	*extract_row(char *row, int y, int row_size)
{
	char	**array_row;
	int		x_coord;
	t_vector *row_extracted;
	
	row_extracted = (t_vector *) malloc(sizeof(t_vector) * row_size);
	array_row = ft_split(row, ' ');
	if (array_row == NULL || row == NULL)
		return (NULL);
	x_coord = 0;
	while (array_row[x_coord] != NULL)
	{
		row_extracted[x_coord].x = x_coord;
		row_extracted[x_coord].y = y;
		row_extracted[x_coord].z = ft_atoi(array_row[x_coord]);
		printf("X = %d; Y = %d; Z = %d \n", x_coord, y, ft_atoi(array_row[x_coord]));

		x_coord++;
	}
	//DONT FORGET TO FREE array_row
	free_2d_array(array_row);
	return (row_extracted);
}


int	main()
{
	t_vector *row1 = extract_row("132 1 -13232 435 -1 -2 ", 2, 6);

	printf("\n-----el----- \nx = %d\ny = %d\nz = %d\n", row1[0].x, row1[0].y, row1[0].z);
	printf("\n-----el----- \nx = %d\ny = %d\nz = %d\n", row1[1].x, row1[1].y, row1[1].z);
	printf("\n-----el----- \nx = %d\ny = %d\nz = %d\n", row1[2].x, row1[2].y, row1[2].z);


}

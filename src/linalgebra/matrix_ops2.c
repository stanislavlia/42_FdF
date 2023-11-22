#include "fdf.h"


void	rotate_matrix_z(t_matrix *matrix, double angle)
{
	int	i;
	int j;

	i = 0;
	while (i < matrix->m)
	{
		j = 0;
		while (j < matrix->n)
		{
			matrix->rows[i].values[j].x_fl = matrix->rows[i].values[j].x_fl * cos(angle) - matrix->rows[i].values[j].y_fl * sin(angle);
			matrix->rows[i].values[j].y_fl = matrix->rows[i].values[j].x_fl * sin(angle) + matrix->rows[i].values[j].y_fl * cos(angle);
			matrix->rows[i].values[j].x = (int) matrix->rows[i].values[j].x_fl;
			matrix->rows[i].values[j].y = (int) matrix->rows[i].values[j].y_fl;
			j++;
		}
		i++;
	}
}


void	rotate_matrix_x(t_matrix *matrix, double angle)
{
	int	i;
	int j;

	
	i = 0;
	while (i < matrix->m)
	{
		j = 0;
		while (j < matrix->n)
		{
		
			matrix->rows[i].values[j].y_fl = matrix->rows[i].values[j].y_fl * cos(angle) - matrix->rows[i].values[j].z_fl * sin(angle);
			matrix->rows[i].values[j].z_fl = matrix->rows[i].values[j].y_fl * sin(angle) + matrix->rows[i].values[j].z_fl * cos(angle);
			matrix->rows[i].values[j].z = (int) (matrix->rows[i].values[j].z_fl) + 1;
			matrix->rows[i].values[j].y = (int) (matrix->rows[i].values[j].y_fl) + 1;
			j++;
		}
		i++;
	}
}

//Assumes matrices has the same shape
void	copy_matrix(t_matrix *src, t_matrix *dest)
{
	int i;
	int j;
	
	i = 0;
	while (i < src->m)
	{
		j = 0;
		while (j < src->n)
		{
			dest->rows[i].values[j].x_fl = src->rows[i].values[j].x_fl;
			dest->rows[i].values[j].y_fl = src->rows[i].values[j].y_fl;
			dest->rows[i].values[j].z_fl = src->rows[i].values[j].z_fl;
			dest->rows[i].values[j].x = src->rows[i].values[j].x;
			dest->rows[i].values[j].y = src->rows[i].values[j].y;
			dest->rows[i].values[j].z= src->rows[i].values[j].z;
			j++;
		}
		i++;
	}
}

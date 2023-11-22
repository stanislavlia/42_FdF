#include	"fdf.h"


void	free_matrix(t_matrix	*matrix_ptr)
{
	int	i;

	i = 0;
	while (i < (*matrix_ptr).m)
	{

		free((*matrix_ptr).rows[i].values);
		i++;
	}
	free((*matrix_ptr).rows);
}

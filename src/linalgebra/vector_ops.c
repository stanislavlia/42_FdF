
#include "fdf.h"

void	addto_x_vec(t_vector	*vec, int val)
{
	vec->x = vec->x + val;
}

void	addto_y_vec(t_vector	*vec, int val)
{
	vec->y = vec->y + val;
}

void	addto_z_vec(t_vector	*vec, int val)
{
	vec->z = vec->z + val;
}


void	vec_add_vec(t_vector *vec1, t_vector *vec2)
{
	vec1->x = vec1->x + vec2->x;
	vec1->y = vec1->y + vec2->y;
	vec1->z = vec1->z + vec2->z;
}


int	dot_product(t_vector *vec1, t_vector *vec2)
{
	int	result;

	result = vec1->x * vec2->x;
	result += vec1->y * vec2->y;
	result += vec1->z * vec2->z;
	return (result);
}

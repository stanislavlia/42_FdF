
#include "fdf.h"

void	addto_x_vec(t_vector	*vec, int val)
{
	vec->x_fl = vec->x_fl + val;
	vec->x = (int) round(vec->x_fl);
}

void	addto_y_vec(t_vector	*vec, int val)
{
	vec->y_fl = vec->y_fl + val;
	vec->y = (int) round(vec->y_fl);
}

void	addto_z_vec(t_vector	*vec, int val)
{
	vec->z_fl = vec->z_fl + val;
	vec->z = (int)round(vec->z_fl);
}


void	vec_add_vec(t_vector *vec1, t_vector *vec2)
{
	vec1->x_fl = vec1->x_fl + vec2->x_fl;
	vec1->y_fl = vec1->y_fl + vec2->y_fl;;
	vec1->z_fl = vec1->z_fl + vec2->z_fl;
	vec1->x = (int) round(vec1->x_fl);
	vec1->y = (int) round(vec1->y_fl);
	vec1->z = (int) round(vec1->z_fl);

}


int	dot_product(t_vector *vec1, t_vector *vec2)
{
	int	result;

	result = vec1->x * vec2->x;
	result += vec1->y * vec2->y;
	result += vec1->z * vec2->z;
	return (result);
}

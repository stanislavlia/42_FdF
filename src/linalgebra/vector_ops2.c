#include "fdf.h"

void	scale_x_vec(t_vector	*vec, float scalar)
{
	vec->x_fl = vec->x_fl * scalar;
	vec->x = (int) round(vec->x_fl);
}

void	scale_y_vec(t_vector	*vec, float scalar)
{
	vec->y_fl = vec->y_fl * scalar;
	vec->y = (int) round(vec->y_fl);
}

void	scale_z_vec(t_vector	*vec, float scalar)
{
	vec->z_fl = vec->z_fl * scalar;
	vec->z = (int) round(vec->z_fl);
}

void	isometric_proj_vec(t_vector *vec)
{
	// correct formula:
	// vec->x = (sqrt(3) / 2) * vec->x - (sqrt(3) / 2) * vec->y;
	// vec->y = (vec->x / 2) + vec->y / 2 - vec->z;
	//my modified formula:
	vec->x_fl = (sqrt(3) / 2) * vec->x_fl  - (sqrt(3) / 2) * vec->y_fl;
	vec->y_fl = (vec->x_fl / 2.3) + vec->y_fl / 1 -  1.3 * vec->z_fl;

	vec->x = (int) round(vec->x_fl);
	vec->y = (int) round(vec->y_fl);
	vec->z = (int) round(vec->z_fl);
}

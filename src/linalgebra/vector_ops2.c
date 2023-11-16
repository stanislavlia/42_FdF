#include "fdf.h"

void	scale_x_vec(t_vector	*vec, float scalar)
{
	vec->x = vec->x * scalar;
}

void	scale_y_vec(t_vector	*vec, float scalar)
{
	vec->y = vec->y * scalar;
}

void	scale_z_vec(t_vector	*vec, float scalar)
{
	vec->z = vec->z * scalar;
}

void	isometric_proj_vec(t_vector *vec)
{
	// vec->x = (sqrt(3) / 2) * vec->x - (sqrt(3) / 2) * vec->y;
	// vec->y = (vec->x / 2) + vec->y / 2 - vec->z;
	vec->x = (sqrt(3) / 2) * vec->x  - (sqrt(3) / 2) * vec->y;
	vec->y = (vec->x / 2) + vec->y / 2 - vec->z;
}

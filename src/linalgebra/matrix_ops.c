#include "fdf.h"

void	shift_matrix_x(t_env *env, int shift_step)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < env->map.m)
	{	
		j = 0;
		while (j < env->map.n)
		{
			addto_x_vec(&env->map.rows[i].values[j], shift_step);
			j++;
		}
		i++;
	}
}

void	shift_matrix_y(t_env *env, int shift_step)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < env->map.m)
	{	
		j = 0;
		while (j < env->map.n)
		{
			addto_y_vec(&env->map.rows[i].values[j], shift_step);
			j++;
		}
		i++;
	}
}



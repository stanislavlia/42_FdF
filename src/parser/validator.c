#include	"fdf.h"

//it separates (z_val, color) pair if there is color in this vector
// otherwise just write value to vec.z 
void	set_z_and_color(t_vector	*vec, int	default_color)
{
	int	i;

	i = 0;
	vec->z = ft_atoi(vec->z_color_pair);
	while (vec->z_color_pair[i] != '\0')
	{
		if (vec->z_color_pair[i] == ',')
		{
			vec->color = ft_atoi_base((vec->z_color_pair) + i + 3, "0123456789ABCDEF");
			return ;
		}
		i++;
	}
	vec->color = default_color;
}

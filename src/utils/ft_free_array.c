#include "fdf.h"

void	ft_free_array(char	***array_of_str)
{
	int	i;

	i = 0;
	while ((*array_of_str)[i] != NULL)
	{
		free((*array_of_str)[i]);
		i++;
	}
	free(*array_of_str);
}

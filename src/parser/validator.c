#include	"fdf.h"

int		len_of_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL )
	{
		i++;
	}
	return (i);
}


int		is_map_valid(char	*path_to_map)
{
	int	fd;
	int	els_in_row;
	char	*line;
	char	**array;

	fd = open(path_to_map, O_RDONLY);
	if	(fd == -1)
		return (0);
	els_in_row = -11;
	line = get_next_line(fd);
	while (line != NULL)
	{
		array = ft_split(line, ' ');
		//printf("The last element in array is %s\n", array[10]);
		printf("Num elements in a row = %d\n", len_of_array(array));
		if	(len_of_array(array) == els_in_row || els_in_row == -11)
			els_in_row = len_of_array(array);
		else
		{
			printf("Map validation failed\n");
			ft_free_array(&array);
			return (0);
		}
		free(line);
		ft_free_array(&array);
		line = get_next_line(fd);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooked_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:45:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/23 14:45:27 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	len_of_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL )
	{
		i++;
	}
	return (i);
}

int	get_m_rows(char *path_to_map)
{
	int	fd;
	int	m_rows;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (0);
	m_rows = 0;
	while (get_next_line(fd) != NULL)
	{
		m_rows++;
	}
	printf("M_rows = %d\n\n\n", m_rows);
	return (m_rows);
}

int	get_n_columns(char *path_to_map)
{
	int		fd;
	int		n_cols;
	char	*line;
	char	**array;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	array = ft_split(line, ' ');
	n_cols = len_of_array(array);
	return (n_cols);
}

int	is_map_valid(char *path_to_map)
{
	int		fd;
	int		els_in_row;
	char	*line;
	char	**array;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (0);
	els_in_row = -11;
	line = get_next_line(fd);
	while (line != NULL)
	{
		array = ft_split(line, ' ');
		if (len_of_array(array) == els_in_row || els_in_row == -11)
			els_in_row = len_of_array(array);
		else
		{
			ft_free_array(&array);
			return (0);
		}
		free(line);
		ft_free_array(&array);
		line = get_next_line(fd);
	}
	return (1);
}

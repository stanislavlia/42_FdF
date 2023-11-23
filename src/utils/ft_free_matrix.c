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

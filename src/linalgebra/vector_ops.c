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

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
	vec->x_fl = (1 / sqrt(2)) * vec->x_fl - (1 / sqrt(2)) * vec->y_fl;
	vec->y_fl = (vec->x_fl / 2) + vec->y_fl / 2 - vec->z_fl;
	vec->x = (int) round(vec->x_fl);
	vec->y = (int) round(vec->y_fl);
	vec->z = (int) round(vec->z_fl);
}

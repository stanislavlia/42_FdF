/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:39:45 by sliashko          #+#    #+#             */
/*   Updated: 2023/11/11 15:39:49 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO

// Create rotation around 3 axes


// Add colors and gradients
// Add parallel projections
// Bind keys
// Norminette




int	main(int argc, char **argv)
{	
	char	*path;
	t_env	env;
	int		fd;
	// int		m = get_m_rows(path);
	// int		n = get_n_rows(path);

	if (argc != 2)
	{
		printf("Please, provide the path to the map as argument!\n");
		return (0);
	}
	path = argv[1];
	fd = open(path, O_RDONLY);
	setup_environment(&env);
	env.map = read_matrix(fd, get_m_rows(path), get_n_columns(path));
	env.init_isom_map = read_matrix(open(path, O_RDONLY), get_m_rows(path), get_n_columns(path));

	scale_z_matrix(&env, 8);
	isometric_projection(&env.map);
	isometric_projection(&env.init_isom_map);
	hook_all_funcs(&env);
	display_static_matrix(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
}


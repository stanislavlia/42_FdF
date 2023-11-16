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
// - Ask how to redraw the matrix again after pressing a key: DONE
// - Change x, y, z from into to float or double to make picture smoother 

// - Create matmul, search for rotation, projection, scale, shift matrices: shift is DONE
// - read about paralled and isometric projections

// - Bind some keys to test operations
// - Adjust code with Norminette


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
	printf("M = %d\nN = %d\n", env.map.m, env.map.n);
	hook_all_funcs(&env);
	scale_z_matrix(&env, 10);
	isometric_projection(&env);
	display_static_matrix(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
}


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

// int	main()
// {
	
// 	int	fd = open("/Users/sliashko/Desktop/FdF/test_maps/42.fdf", O_RDONLY);
// 	printf("FD = %d\n", fd);

// 	t_env	env;
	

// 	setup_environment(&env);
// 	env.map = read_matrix(fd, 11, 19);
// 	env.map.x_margin *= 2;
// 	env.map.y_margin *= 4;
// 	printf("M = %d\nN = %d\n", env.map.m, env.map.n);

// 	mlx_hook(env.mlx_window, 2, 1L<<0, close_window, &env);
// 	display_static_matrix(&env);
// 	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 50, 50);

// 	mlx_loop(env.mlx);
// 	//free_matrix(&env.map);
	
// }
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
	display_static_matrix(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 50, 50);
	mlx_loop(env.mlx);

}

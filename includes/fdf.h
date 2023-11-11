/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:52 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/18 12:04:06 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


#define DEFAULT_COLOR 0xFFFFFF
#define WIDTH 1000
#define HEIGHT 1000


# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	int		x;
	int		y;
	int		z;
	char	*z_color_pair;
	int		color;

}	t_vector;

typedef struct s_row
{
	int			y;
	t_vector	*values;


}	t_row;



typedef struct s_matrix
{
	t_row	*rows;
	int		m;
	int		n; //shape of the matrix

}				t_matrix;


//STRUCT FOR MLX
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


typedef	struct s_env
{
	void		*mlx;
	void		*mlx_window;
	t_data		img;
	t_matrix	map;

}			t_env;



//Utils
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi_base(char *str, char *base);
void	setup_environment(t_env *env_ptr);

//MLX drawing
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_topleft_square(void	*img, int	square_size, int	color);
void	display_static_matrix(t_env *env, int x_margin, int y_margin);
int	close_window(int keycode, t_vars	*vars);
void	draw_line(t_vector p1, t_vector p2, t_env *env);

//Linear Algebra functions
void	addto_x_vec(t_vector	*vec, int val);
void	addto_y_vec(t_vector	*vec, int val);
void	addto_z_vec(t_vector	*vec, int val)
void	vec_add_vec(t_vector *vec1, t_vector *vec2);
int		dot_product(t_vector *vec1, t_vector *vec2);


//Colors
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

//Validation and parsing
void	set_z_and_color(t_vector	*vec, int	default_color);
int		is_map_valid(char	*path_to_map);

//Cleaning functions
void	ft_free_array(char	***array_of_str);
void	free_matrix(t_matrix	*matrix_ptr);

//GNL
t_list		*get_last_node(t_list *lst);
int			search_for_newline(t_list *list);
void		append_node(t_list **list, char *buffer_batch);
int			create_list(t_list **list, int fd);
size_t		len_till_nl(t_list	*start_node);
char		*get_next_line(int fd);
void		keep_rest(t_list **list);
void		free_list(t_list **list, t_list *clean_node, char *buffer);
char		*retrive_line(t_list	*list);
int			fill_line_from_content(char *line, int *i, char *content);

#endif

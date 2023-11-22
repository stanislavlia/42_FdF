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
#define WIDTH 1920
#define HEIGHT 1080
#define W_MARGIN 1
#define H_MARGIN 1

//X11 events
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 53

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
	double	x_fl;
	double	y_fl;
	double	z_fl;

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
	int		x_margin;
	int		y_margin;

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
	t_matrix	init_isom_map;
	t_matrix	init_map;

}			t_env;



//Utils
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi_base(char *str, char *base);
void	setup_environment(t_env *env_ptr);

//MLX drawing
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_topleft_square(void	*img, int	square_size, int	color);
void	display_static_matrix(t_env *env);
void	draw_line(t_vector p1, t_vector p2, t_env *env);
void	set_new_image(t_env *env);

//Linear Algebra functions
void	addto_x_vec(t_vector	*vec, int val);
void	addto_y_vec(t_vector	*vec, int val);
void	addto_z_vec(t_vector	*vec, int val);
void	vec_add_vec(t_vector *vec1, t_vector *vec2);
int		dot_product(t_vector *vec1, t_vector *vec2);
void	shift_matrix_x(t_env *env, int shift_step);
void	shift_matrix_y(t_env *env, int shift_step);
void	scale_x_vec(t_vector	*vec, float scalar);
void	scale_y_vec(t_vector	*vec, float scalar);
void	scale_z_vec(t_vector	*vec, float scalar);
void	scale_matrix(t_env *env, float scalar);
void	isometric_proj_vec(t_vector *vec);
void	isometric_projection(t_matrix *map);
void	scale_z_matrix(t_env *env, float scalar);
void	rotate_matrix_z(t_matrix *matrix, double angle);
void	rotate_matrix_x(t_matrix *matrix, double angle);
void	copy_matrix(t_matrix *src, t_matrix *dest);

//Colors
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

//Validation and parsing
void		set_z_and_color(t_vector	*vec, int	default_color);
int			is_map_valid(char	*path_to_map);
int			get_m_rows(char *path_to_map);
int			get_n_columns(char *path_to_map);
t_matrix	read_matrix(int fd, int m, int n);

//Keybord events
void	hook_all_funcs(t_env	*env);
int	reset_to_isom(int keycode, t_env *env);
int	rotate_pic_z(int keycode, t_env *env);
int	ft_close_window(t_env *env);

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

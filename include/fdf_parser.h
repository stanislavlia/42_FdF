/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:28:33 by sliashko          #+#    #+#             */
/*   Updated: 2023/10/31 18:28:35 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_H
# define FDF_PARSER_H

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;

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

}	t_matrix;


int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif

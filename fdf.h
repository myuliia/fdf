/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:33:28 by myuliia           #+#    #+#             */
/*   Updated: 2018/12/03 15:40:09 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>

# define LENGHT 1200
# define WIDTH 800
# define PINK 133397388
# define WHITE 16777215
# define STRNG1 "Press 'Space' to show hints"
# define STRNG2 "Press 'Enter' to update picture"
# define STRNG3 "left arrow   '<'"
# define STRNG4 "right arrow  '>'"
# define STRNG5 "up arrow     '^'"
# define STRNG6 "down arrow   'v'"
# define STRNG7 "View from above:     '0'"
# define STRNG8 "Change projection:   '5'"
# define STRNG9 "Change color:"
# define STRNG10 "Blue       'B'"
# define STRNG11 "Yellow     'Y'"
# define STRNG12 "Green      'G'"
# define STRNG13 "Red        'R'"
# define STRNG14 "Random     'Q'"
# define STRNG15 "Add color of top:    '7'"
# define STRNG16 "Remove color of top: '8'"

typedef struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}				t_mlx;

typedef struct	s_read
{
	int **res;
	int height;
	int width;
	int sy;
	int fd;
	int tmp_color;
	int indicator_color;
}				t_read;

typedef struct	s_xyz
{
	double	start_y;
	double	start_x;
	double	step_y;
	double	step_x;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	double	shift;
	double	updown;
	int		color;
	int		indic;
}				t_xyz;

typedef struct	s_fdf
{
	t_xyz	*varb;
	t_mlx	*w;
	t_read	*save;
}				t_fdf;

t_read			*ft_read(char *argv);
char			*read_two(t_read *save, char *buf, char *tmp, char *line);
void			map_in_int(char **map, t_read *save);
void			ft_valid_symbol(char *s);
void			ft_error(int nb);
int				destroy(void);
void			fill(t_fdf fdf);
t_mlx			*initialize(void);
void			draw_algorithm(t_fdf f);
void			draw_helper_two(t_fdf f, int x, int y);
void			draw_helper_two(t_fdf f, int x, int y);
void			line(t_fdf f);
void			line_x(int dx, int dy, int sx, t_fdf f);
void			line_y(int dx, int dy, int sx, t_fdf f);
int				ft_key_hook(int key, t_fdf *fdf);
void			moving(t_fdf fdf, int key);
void			title(t_fdf fdf, int k);
void			ft_string_put(t_fdf f);
void			zoom(t_fdf fdf, int key);
void			change_z(t_fdf fdf, int key);
void			change_color(t_fdf fdf, int key);
void			change_projection(t_fdf fdf, int key);
//void	color_of_top(int nb, int x, int y, t_fdf);

#endif

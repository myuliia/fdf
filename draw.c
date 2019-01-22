/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:06:51 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/15 16:49:13 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill(t_fdf fdf)
{
	if (fdf.save->height >= 50)
	{
		fdf.varb->shift = 2;
		fdf.varb->step_x = 6;
		fdf.varb->step_y = 4;
		fdf.varb->updown = 2;
		fdf.varb->start_x = 100;
		fdf.varb->start_y = 100;
		fdf.save->tmp_color = 133397388;
		fdf.varb->indic = 1;
	}
	else
	{
		fdf.varb->shift = 10;
		fdf.varb->step_x = 30;
		fdf.varb->step_y = 20;
		fdf.varb->updown = 5;
		fdf.varb->start_x = 400;
		fdf.varb->start_y = 200;
		fdf.save->tmp_color = 133397388;
		fdf.varb->indic = 1;
	}
}

void	color_of_top(int nb, int x, int y, t_fdf f)
{
	if (f.save->indicator_color == 1)
	{
		if ((nb != 0) || f.save->res[y][x] != 0)
			f.varb->color = 16777215;
		else
			f.varb->color = f.save->tmp_color;
	}
	else
		f.varb->color = f.save->tmp_color;
}

void	draw_helper_one(t_fdf f, int x, int y)
{
	if (x < f.save->width - 1)
	{
		f.varb->x0 = f.varb->start_x + (x * f.varb->step_x)
			- (y * f.varb->shift);
		f.varb->y0 = f.varb->start_y + (y * f.varb->step_y)
			- f.save->res[y][x] * f.varb->updown;
		f.varb->x1 = f.varb->start_x + ((x + 1) * f.varb->step_x)
			- (y * f.varb->shift);
		f.varb->y1 = f.varb->start_y + (y * f.varb->step_y)
			- f.save->res[y][x + 1] * f.varb->updown;
		color_of_top(f.save->res[y][x + 1], x, y, f);
		line(f);
	}
}

void	draw_helper_two(t_fdf f, int x, int y)
{
	if (y < f.save->height - 1)
	{
		f.varb->x0 = f.varb->start_x + (x * f.varb->step_x)
			- (y * f.varb->shift);
		f.varb->y0 = f.varb->start_y + (y * f.varb->step_y)
			- f.save->res[y][x] * f.varb->updown;
		f.varb->x1 = f.varb->start_x + (x * f.varb->step_x)
			- ((y + 1) * f.varb->shift);
		f.varb->y1 = f.varb->start_y + ((y + 1) * f.varb->step_y)
			- f.save->res[y + 1][x] * f.varb->updown;
		color_of_top(f.save->res[y][x], x, y, f);
		line(f);
	}
}

void	draw_algorithm(t_fdf f)
{
	int x;
	int y;

	y = -1;
	if (f.varb->indic != 1)
		fill(f);
	while (++y < f.save->height)
	{
		x = -1;
		while (++x < f.save->width)
		{
			draw_helper_one(f, x, y);
			draw_helper_two(f, x, y);
		}
	}
}

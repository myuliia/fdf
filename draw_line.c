/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:09:08 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/11 14:09:09 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_fdf f)
{
	int sx;
	int dy;
	int dx;

	dx = abs(f.varb->x1 - f.varb->x0);
	sx = f.varb->x1 >= f.varb->x0 ? 1 : -1;
	dy = abs(f.varb->y1 - f.varb->y0);
	f.save->sy = f.varb->y1 >= f.varb->y0 ? 1 : -1;
	mlx_pixel_put(f.w->mlx_ptr, f.w->win_ptr, f.varb->x0,
		f.varb->y0, f.varb->color);
	if (dy <= dx)
		line_x(dx, dy, sx, f);
	else
		line_y(dx, dy, sx, f);
}

void	line_x(int dx, int dy, int sx, t_fdf f)
{
	int err;

	err = -dx;
	while (f.varb->x0 != f.varb->x1 || f.varb->y0 != f.varb->y1)
	{
		mlx_pixel_put(f.w->mlx_ptr, f.w->win_ptr, f.varb->x0,
			f.varb->y0, f.varb->color);
		f.varb->x0 += sx;
		err += 2 * dy;
		if (err > 0)
		{
			err -= 2 * dx;
			f.varb->y0 += f.save->sy;
		}
	}
}

void	line_y(int dx, int dy, int sx, t_fdf f)
{
	int err;

	err = -dy;
	while (f.varb->x0 != f.varb->x1 || f.varb->y0 != f.varb->y1)
	{
		mlx_pixel_put(f.w->mlx_ptr, f.w->win_ptr, f.varb->x0,
			f.varb->y0, f.varb->color);
		f.varb->y0 += f.save->sy;
		err += 2 * dx;
		if (err > 0)
		{
			err -= 2 * dy;
			f.varb->x0 += sx;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:22:18 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/12 15:22:19 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moving(t_fdf fdf, int key)
{
	if (key == 123)
		fdf.varb->start_x = fdf.varb->start_x + 10;
	if (key == 124)
		fdf.varb->start_x = fdf.varb->start_x - 10;
	if (key == 125)
		fdf.varb->start_y = fdf.varb->start_y - 10;
	if (key == 126)
		fdf.varb->start_y = fdf.varb->start_y + 10;
	draw_algorithm(fdf);
}

void	change_color(t_fdf fdf, int key)
{
	if (key == 15)
		fdf.save->tmp_color = 16711680;
	if (key == 16)
		fdf.save->tmp_color = 15924992;
	if (key == 5)
		fdf.save->tmp_color = 65280;
	if (key == 11)
		fdf.save->tmp_color = 255;
	if (key == 12)
	{
		fdf.save->tmp_color = fdf.save->tmp_color * 10;
		if (fdf.save->tmp_color <= 5)
			fdf.save->tmp_color = fdf.save->tmp_color + 10;
	}
	if (key == 89)
		fdf.save->indicator_color = 1;
	if (key == 91)
		fdf.save->indicator_color = 0;
	draw_algorithm(fdf);
}

void	change_z(t_fdf fdf, int key)
{
	if (key == 92)
		fdf.varb->updown = fdf.varb->updown + 1;
	if (key == 85)
		fdf.varb->updown = fdf.varb->updown - 1;
	if (key == 36)
	{
		fill(fdf);
	}
	draw_algorithm(fdf);
}

void	change_projection(t_fdf fdf, int key)
{
	if (key == 87)
		fdf.varb->shift = fdf.varb->shift * -1;
	if (key == 82)
	{
		fdf.varb->shift = 0;
		fdf.varb->updown = 1.2;
	}
	draw_algorithm(fdf);
}

void	zoom(t_fdf fdf, int key)
{
	if (key == 69)
	{
		fdf.varb->shift = fdf.varb->shift * 1.1;
		fdf.varb->step_x = fdf.varb->step_x * 1.1;
		fdf.varb->step_y = fdf.varb->step_y * 1.1;
		fdf.varb->updown = fdf.varb->updown + 0.1;
	}
	if (key == 78)
	{
		fdf.varb->shift = fdf.varb->shift * 0.9;
		fdf.varb->step_x = fdf.varb->step_x * 0.9;
		fdf.varb->step_y = fdf.varb->step_y * 0.9;
		fdf.varb->updown = fdf.varb->updown - 0.1;
	}
	draw_algorithm(fdf);
}

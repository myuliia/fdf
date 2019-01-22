/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   titles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:34:51 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/12 17:34:52 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	title(t_fdf fdf, int k)
{
	int i;
	int j;
	int p;

	j = 25;
	p = 875;
	mlx_clear_window(fdf.w->mlx_ptr, fdf.w->win_ptr);
	while (j-- != 0 && p++ < 901)
	{
		i = 1200;
		while (i-- != 0)
		{
			mlx_pixel_put(fdf.w->mlx_ptr, fdf.w->win_ptr, i, j, PINK);
			mlx_pixel_put(fdf.w->mlx_ptr, fdf.w->win_ptr, i, p, PINK);
		}
	}
	if (k == 1)
		mlx_string_put(fdf.w->mlx_ptr, fdf.w->win_ptr, 5, 850, PINK, STRNG1);
}

void	ft_string_put(t_fdf f)
{
	title(f, 2);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 5, 850, 0, STRNG1);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 5, 28, WHITE, STRNG2);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 8, 760, WHITE, "Move:");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 7, 780, WHITE, STRNG3);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 7, 800, WHITE, STRNG4);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 7, 820, WHITE, STRNG5);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 7, 840, WHITE, STRNG6);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 220, 760, WHITE, "Zoom:");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 222, 780, WHITE, "bigger  '+'");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 222, 800, WHITE, "smaller '-'");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 380, 760, WHITE, "Change Z:");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 380, 780, WHITE, "upper   '9'");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 380, 800, WHITE, "lower   '3'");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 520, 760, WHITE, STRNG7);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 520, 780, WHITE, STRNG8);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 790, 750, WHITE, STRNG9);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 792, 770, WHITE, STRNG10);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 792, 790, WHITE, STRNG11);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 792, 810, WHITE, STRNG12);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 792, 830, WHITE, STRNG13);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 792, 850, WHITE, STRNG14);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 520, 800, WHITE, STRNG15);
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 520, 820, WHITE, STRNG16);
}

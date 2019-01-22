/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:04:59 by myuliia           #+#    #+#             */
/*   Updated: 2018/12/07 18:05:18 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_key_hook(int key, t_fdf *fdf)
{
	title(*fdf, 1);
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		moving(*fdf, key);
	if (key == 69 || key == 78)
		zoom(*fdf, key);
	if (key == 92 || key == 85 || key == 36)
		change_z(*fdf, key);
	if (key == 49)
		ft_string_put(*fdf);
	if (key == 15 || key == 16 || key == 5 || key == 11 || key == 12
			|| key == 89 || key == 91)
		change_color(*fdf, key);
	if (key == 87 || key == 82)
		change_projection(*fdf, key);
	else
		draw_algorithm(*fdf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:07:56 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/13 16:10:04 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*initialize(void)
{
	t_mlx	*w;

	w = (t_mlx *)malloc(sizeof(t_mlx));
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, 1200, 900, "FDF");
	return (w);
}

int		main(int argc, char **argv)
{
	t_xyz	varb;
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_error(5);
	}
	fdf.save = ft_read(argv[1]);
	fdf.w = initialize();
	title(fdf, 1);
	draw_algorithm(fdf);
	mlx_hook(fdf.w->win_ptr, 17, 0, destroy, NULL);
	mlx_hook(fdf.w->win_ptr, 2, 0, ft_key_hook, &fdf);
	mlx_loop(fdf.w->mlx_ptr);
	return (0);
}

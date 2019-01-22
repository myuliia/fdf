/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:23:06 by myuliia           #+#    #+#             */
/*   Updated: 2018/12/07 15:25:00 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int nb)
{
	if (nb == 1)
		write(1, "The map isn't valid\n", 20);
	if (nb == 2)
		write(1, "The map is empty\n", 17);
	if (nb == 3)
		write(1, "Invalid symbol\n", 15);
	if (nb == 4)
		write(1, "File doesn't open \n", 19);
	if (nb == 5)
		write(1, "usage: ./fdf source_file\n", 25);
	exit(0);
}

int		destroy(void)
{
	exit(1);
}

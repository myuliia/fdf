/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:56:13 by myuliia           #+#    #+#             */
/*   Updated: 2018/12/07 17:58:42 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_valid_symbol(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' || s[i] <= 'z')
			|| s[i] == ',' || s[i] == 'x'
			|| s[i] == ' ' || s[i] == '\n'
			|| s[i] == '-')
			i++;
		else
			ft_error(3);
	}
}

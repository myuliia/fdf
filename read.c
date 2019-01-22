/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:00:18 by myuliia           #+#    #+#             */
/*   Updated: 2018/12/11 14:00:49 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_two(t_read *save, char *buf, char *tmp, char *line)
{
	ft_valid_symbol(line);
	if (save->width == ft_count_words(line, ' ') || save->height == 1)
		save->width = ft_count_words(line, ' ');
	else
		ft_error(1);
	tmp = ft_strjoin(buf, line);
	free(buf);
	free(line);
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	return (buf);
}

t_read	*ft_read(char *argv)
{
	char	*line;
	char	*buf;
	char	**map;
	char	*tmp;
	t_read	*save;

	save = (t_read *)malloc(sizeof(t_read));
	save->height = 0;
	save->width = 0;
	buf = ft_strdup("\0");
	if ((save->fd = open(argv, O_RDONLY)) < 0)
		ft_error(4);
	while ((get_next_line(save->fd, &line)) == 1 && ++save->height)
	{
		buf = read_two(save, buf, tmp, line);
	}
	if (!save->width)
		ft_error(2);
	close(save->fd);
	map = ft_strsplit(buf, '\n');
	free(buf);
	map_in_int(map, save);
	close(save->fd);
	return (save);
}

void	map_in_int(char **map, t_read *save)
{
	char	**tmp;
	int		y;
	int		x;

	y = 0;
	save->res = (int**)malloc(sizeof(int*) * save->height);
	while (y < save->height)
	{
		save->res[y] = (int*)malloc(sizeof(int) * save->width);
		tmp = ft_strsplit(map[y], ' ');
		free(map[y]);
		x = 0;
		while (x < save->width)
		{
			save->res[y][x] = atoi(tmp[x]);
			free(tmp[x]);
			x++;
		}
		free(tmp);
		y++;
	}
	free(map);
}

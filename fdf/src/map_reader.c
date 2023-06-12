/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:50:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/12 20:01:29 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void print_map(t_node *map, t_2d_point size)
{
	int	i;
	int j;
	
	j = 0;
	while(map && j++ < size.y)
	{
		i = 0;
		while (map && i++ < size.x)
		{
			ft_printf("%d | ", map->pos.z);
			map = map->next;
		}
		ft_printf("\n");
	}
}

t_node	*make_map(int fd)
{
	t_node		*map;
	t_3d_point	pos;
	char		*line;
	int			check;
	int i;

	map = NULL;
	pos.z = 1;
	pos.y = 1;
	check = 1;
	while ((line = get_next_line(fd)))
	{
		i = 0;
		pos.x = 1;
		
		while (ft_isdigit(line[i]) || ft_isspace(line[i]))
		{
			if (ft_isdigit(line[i]))
			{
				pos.z = line[i] - '0';
				node_addback(&map, node_new(pos));
				pos.x++;
			}
			if (line[i] == '\n')
				pos.y++;
			i++;
		}
	}
	free(line);
	t_node *banana = node_find(&map, (t_2d_point){8, 3});
	printf("%p", banana);
	//printf("\nx%d y%d z%d\n", banana->pos.x, banana->pos.y, banana->pos.z);
	print_map(map, (t_2d_point){8, 4});
	return (map);
}
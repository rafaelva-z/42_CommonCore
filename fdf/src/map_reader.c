/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:50:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/22 17:48:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	print_map(t_map map)
{
	t_node	*node;
	int		i;
	int		j;

	j = 0;
	node = map.first_node;
	while (node)
	{
		i = 0;
		while (node && i++ < node->pos.x)
		{
			ft_printf("%d |", node->pos.z);
			node = node->next;
		}
		ft_printf("\n");
	}
}

// static void	vertical_ptr(t_map **map, t_2d_point size,)
// {

// }

t_map	*make_map(int fd)
{
	t_map		*map;
	char		*line;
	int			i;

	map = malloc(sizeof(t_map));
	map->first_node = NULL;

	//Node assign and adding
	t_3d_point	pos;

	pos = (t_3d_point){1, 1, 1};
	while ((line = get_next_line(fd)))
	{
		i = 0;
		pos.x = 1;
		while (ft_isdigit(line[i]) || ft_isspace(line[i]))
		{
			if (ft_isdigit(line[i]))
			{
				pos.z = ft_atoi(&line[i]);
				node_addback(&(map->first_node), node_new(pos));
				pos.x++;
				while (ft_isdigit(line[i]))
					i++;
			}
			if (line[i] == '\n')
				pos.y++;
			i++;
		}
		map->size = (t_2d_point){pos.x - 1, pos.y};
	}
	printf("%d %d<<<<", map->size.x, map->size.y);
	free(line);
	print_map(*map);
	return (map);
}
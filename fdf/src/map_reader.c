/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:50:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/03 15:40:31 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* static void	print_map(t_map map)
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
			printf("0%f |", node->pos.z);
			node = node->next;
		}
		ft_printf("\n");
	}
} */

static void	map_addline(t_map **map, char *line, int y)
{
	int			i;
	t_3d_point	pos;
	int			eol;

	i = 0;
	pos = (t_3d_point){1, y, -1};
	while (ft_isdigit(line[i]) || ft_issignal(line[i]) || ft_isspace(line[i]))
	{
		while (ft_isspace(line[i]))
		{
			if (line[i++] == '\n' && (*map)->first_node)
			{
				node_last((*map)->first_node)->end_of_line.x = 1;
				pos.y++;
			}
		}
		if (ft_isdigit(line[i]) || ft_issignal(line[i]))
		{
			pos.z = ft_atoi(&line[i]);
			node_addback(&((*map)->first_node), node_new(*map, pos));
			pos.x++;
			while (ft_issignal(line[i]) || ft_isdigit(line[i]))
				i++;
		}
	}
}

static t_2d_point	get_map_size(t_map *map)
{
	t_2d_point	map_size;
	t_node		*tmp;
	int			x_size;

	if (!map)
		return ((t_2d_point){-1, -1});
	map_size = (t_2d_point){0, 0};
	x_size = 0;
	tmp = map->first_node;
	while (tmp)
	{
		while (tmp && !tmp->end_of_line.x)
		{
			if (!map_size.x)
				x_size++;
			tmp = tmp->next;
		}
		if (!map_size.x)
			map_size.x = x_size + 1;
		map_size.y++;
		if (tmp)
			tmp = tmp->next;
	}
	return (map_size);
}

static void	below_ptr_assign(t_map **map, t_2d_point size)
{
	t_2d_point	pos;

	pos.x = 1;
	while (pos.x <= size.x)
	{
		pos.y = 1;
		if (pos.x == 1)
			pos.y++;
		while (pos.y <= size.y)
		{
			node_addbelow(&((*map)->first_node),
				node_find(*map, (t_2d_point){pos.x, pos.y}));
			pos.y++;
		}
		node_find(*map, (t_2d_point){pos.x, pos.y - 1})->end_of_line.y = 1;
		pos.x++;
	}
}

//	Relocates the points so that the closest point to the center is {0,0}	
void	center_map(t_map *map)
{
	t_node	*node;

	node = map->first_node;
	while (node)
	{
		node->pos.x -= map->size.x / 2;
		node->pos.y -= map->size.y / 2; 
		node = node->next;
	}
}

t_map	*make_map(int fd)
{
	t_map		*map;
	char		*line;
	int			y;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->first_node = NULL;
	map->scale = 10;
	map->offset = (t_2d_point){WIN_WIDTH / 2, WIN_HEIGHT / 2};
	map->rotation = (t_3d_point){0, 0, 0};
	map->angle_z = (t_2d_point){cos(map->rotation.z), sin(map->rotation.z)};
	line = get_next_line(fd);
	y = 1;
	while (line)
	{
		map_addline(&map, line, y++);
		line = get_next_line(fd);
	}
	map->size = get_map_size(map);
	below_ptr_assign(&map, map->size);
	center_map(map);
	free(line);
	return (map);
}

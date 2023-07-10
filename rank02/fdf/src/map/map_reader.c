/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:50:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/10 19:55:16 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
static void	map_center(t_map *map)
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

static t_map	*start_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->first_node = NULL;
	map->scale = 25;
	map->offset = (t_2d_point){WIN_WIDTH / 2, WIN_HEIGHT / 2};
	map->rotation = (t_3d_point){0, 0, 0};
	map->angle_x = (t_2d_point){cos(map->rotation.x), sin(map->rotation.x)};
	map->angle_y = (t_2d_point){cos(map->rotation.y), sin(map->rotation.y)};
	map->angle_z = (t_2d_point){cos(map->rotation.z), sin(map->rotation.z)};
	return (map);
}

static int	read_mapfile(t_map *map, int fd)
{
	char		*line;
	int			y;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	y = 1;
	while (line)
	{
		if (!map_addline(&map, line, y++))
		{
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			free(line);
			return (-1);
		}
	}
	map->size = map_getsize(map);
	return (0);
}

t_map	*make_map(int fd)
{
	t_map		*map;

	map = NULL;
	map = start_map(map);
	if (!map)
		return (NULL);
	if (read_mapfile(map, fd))
	{
		map_free(map);
		return (NULL);
	}
	if (map->size.y > 1)
		below_ptr_assign(&map, map->size);
	map_center(map);
	return (map);
}

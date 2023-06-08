/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:50:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 18:06:39 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_node	**make_map(int fd)
{
	t_node		*map;
	t_3d_point	pos;
	char		*line;
	int			check;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	check = 1;
	while ((line = get_next_line(fd)))
	{
		pos.z = line[0];
		node_addback(&map, node_new(pos));
		pos.x++;
		if (line[1] == '\n')
			pos.y++;
	}

	free(line);
	return (map);
}
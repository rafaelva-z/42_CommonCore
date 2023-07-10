/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:40:21 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/07 18:40:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_2d_point	map_getsize(t_map *map)
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

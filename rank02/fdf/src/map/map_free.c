/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:15:45 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/07 18:36:01 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	map_free(t_map *map)
{
	t_node	*tmp;

	while (map->first_node)
	{
		tmp = map->first_node;
		map->first_node = map->first_node->next;
		free(tmp);
	}
	free(map);
}

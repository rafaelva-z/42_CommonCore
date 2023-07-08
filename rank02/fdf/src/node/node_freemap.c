/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_freemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:15:45 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/06 15:23:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	node_freemap(t_map *map)
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

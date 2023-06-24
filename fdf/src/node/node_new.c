/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:45:25 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/24 15:15:40 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_node	*node_new(t_map *map, t_3d_point point)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->pos = point;
	node->map = map;
	node->next = NULL;
	node->below = NULL;
	node->end_of_line = (t_2d_point){0, 0};
	return (node);
}

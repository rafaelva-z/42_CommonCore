/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:03:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/06 15:19:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_node	*node_find(t_map *map, t_2d_point pos)
{
	t_node	*tmp;

	tmp = map->first_node;
	while (((tmp->pos.x != pos.x) || (tmp->pos.y != pos.y)))
	{
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	if (((tmp->pos.x == pos.x) && (tmp->pos.y == pos.y)))
		return (tmp);
	return (NULL);
}

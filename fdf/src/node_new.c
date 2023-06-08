/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:45:25 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 17:34:47 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_node	*node_new(t_3d_point point)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->pos = point;
	node->next = NULL;
	node->next_line = NULL;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:50:06 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 18:01:30 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	node_addback(t_node **node, t_node *new_node)
{
	t_node	*last;

	if (!*node)
		*node = new_node;
	else
	{
		last = node_last(*node);
		last->next = new_node;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_addbelow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:50:06 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/24 16:29:56 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	node_addbelow(t_node **node, t_node *new_node)
{
	t_node	*last;

	if (!*node)
		*node = new_node;
	else
	{
		last = node_lastbelow(*node);
		last->below = new_node;
	}
}

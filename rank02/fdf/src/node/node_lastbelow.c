/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_lastbelow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:57:49 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/03 15:38:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_node	*node_lastbelow(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->below)
		node = node->below;
	return (node);
}

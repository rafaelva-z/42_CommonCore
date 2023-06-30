/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:47 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/30 20:15:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_fdf(t_map map, t_img *img)
{
	t_node	*node;
	int		i;
	int		multiply;

	node = map.first_node;
	i = 0;
	multiply = 100;
	//printf("%d, %d / %d, %d", map.first_node->pos.x, node->pos.y, node->next->pos.x, node->next->pos.y);
	while (node->next)
	{
		if (node->end_of_line.x == 0)
			draw_line((t_2d_point){node->pos.x * multiply, node->pos.y * multiply}, (t_2d_point){node->next->pos.x * multiply, node->next->pos.y * multiply}, img);
		node = node->next;
	}
	node = map.first_node;
	while (node->below)
	{
		if (node->end_of_line.y == 0)
			draw_line((t_2d_point){node->pos.x * multiply, node->pos.y * multiply}, (t_2d_point){node->below->pos.x * multiply, node->below->pos.y * multiply}, img);
		node = node->below;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:47 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 13:59:08 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_fdf(t_mlx *mlx)
{
	t_node	*node;

	node = mlx->map->first_node;
	calc_node_pos(mlx->map);
	while (node->next)
	{
		if (node->end_of_line.x == 0)
			draw_line((t_2d_line){(t_2d_point){node->calc_pos.x,
				node->calc_pos.y},
				(t_2d_point){node->next->calc_pos.x,
				node->next->calc_pos.y}},
				mlx->img);
		node = node->next;
	}
	node = mlx->map->first_node;
	while (node->below)
	{
		if (node->end_of_line.y == 0)
			draw_line((t_2d_line){(t_2d_point){node->calc_pos.x,
				node->calc_pos.y},
				(t_2d_point){node->below->calc_pos.x, node->below->calc_pos.y}},
				mlx->img);
		node = node->below;
	}
}

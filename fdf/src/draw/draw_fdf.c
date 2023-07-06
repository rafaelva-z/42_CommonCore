/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:47 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/06 15:29:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	calc_2d_pos(t_map *map)
{
	t_node	*node;

	node = map->first_node;
	while (1)
	{
		node->calc_pos.x = roundf((node->pos.x * map->angle_z.x - node->pos.y
					* map->angle_z.y) * map->scale + map->offset.x);
		node->calc_pos.y = roundf((node->pos.z + node->pos.x
					* map->angle_z.y + node->pos.y * map->angle_z.x)
				* map->scale + map->offset.y);
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

void	draw_fdf(t_mlx *mlx)
{
	t_node	*node;

	node = mlx->map->first_node;
	calc_2d_pos(mlx->map);
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

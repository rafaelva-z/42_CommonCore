/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:47 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/10 22:06:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	calc_2d_pos(t_map *map)
{
	t_node	*node;

	float rotated_x;
	float rotated_y;

	node = map->first_node;
	// rotated_z = node->pos.x * sin(map->rotation.x) + node->pos.z * cos(map->rotation.x);
	// rotated_x = node->pos.x * cos(map->rotation.x) - node->pos.z * sin(map->rotation.x);

	while (1)
	{
		rotated_x = node->pos.x ;
		rotated_y = node->pos.y * map->angle_y.x + node->pos.z * map->angle_y.x;
		node->calc_pos.x = roundf((rotated_x * map->angle_z.x - rotated_y * map->angle_z.y) * map->scale + map->offset.x);
		node->calc_pos.y = roundf((map->pos.z + rotated_x * map->angle_z.y + rotated_y * map->angle_z.x) * map->scale + map->offset.y);
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

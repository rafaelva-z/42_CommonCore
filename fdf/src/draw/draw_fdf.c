/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:41:47 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/01 18:29:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	calc_2d_pos(t_map *map)
{
	t_node	*node;
	
	node = map->first_node;
	while (1)
	{
		node->calc_pos.x = (node->pos.x /* * cos(0.523599) */ - node->pos.y /* * cos(0.523599) */)* map->scale + map->offset.x;
		node->calc_pos.y = (node->pos.z + node->pos.x /* * sin(0.523599) */ + node->pos.y /* * sin(0.523599) */)* map->scale + map->offset.y;
		if (node->next)
			node = node->next;
		else
			break;
	}
}

//node->calc_pos.x = node->pos.x * cos(0.523599) - node->pos.y * cos(0.523599);
//node->calc_pos.y = node->pos.z + node->pos.x * sin(0.523599) + node->pos.y * sin(0.523599);

void	draw_fdf(t_mlx *mlx)
{
	t_node	*node;
	int		i;

	node = mlx->map->first_node;
	calc_2d_pos(mlx->map);
	while (node->next)
	{
		if(node->end_of_line.x == 0)
			draw_line((t_2d_point){node->calc_pos.x, node->calc_pos.y},
					(t_2d_point){node->next->calc_pos.x, node->next->calc_pos.y}, mlx->img);
		node = node->next;
	}
	node = mlx->map->first_node;
	while (node->below)
	{
		if (node->end_of_line.y == 0)
			draw_line((t_2d_point){node->calc_pos.x, node->calc_pos.y},
					(t_2d_point){node->below->calc_pos.x, node->below->calc_pos.y}, mlx->img);
		node = node->below;
	}
}
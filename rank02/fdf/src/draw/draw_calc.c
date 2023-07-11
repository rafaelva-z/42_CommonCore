/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:42:13 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 17:59:10 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/* 		
        Formula used below:
        angle = how much to rotate
        x, y, z = position before rotation
        rotated.x,y,z = position after rotation
        
        X axis rotation
		rotated.y = y * cos(angle) + z * sin(angle);
		rot_z = -y * sin(angle) + z * cos(angle);
		Y axis rotation
		rot_x = x * cos(angle) + z * sin(angle);
		rot_z = -x * sin(angle) + z * cos(angle);
        Z axis rotation
        rot_x = x * cos(angle) + y * sin(angle);
		rot_y = -x * sin(angle) + y * cos(angle);
        
        The calculations have to be done in this order! (x, y, z)
 */

static void	calc_rot_x(t_map *map, t_node *node, t_3d_point *rotated)
{
	rotated->y = node->pos.y * map->angle_x.x + node->pos.z * map->angle_x.y;
	rotated->z = -node->pos.y * map->angle_x.y 
		+ node->pos.z * map->angle_x.x;
}

static void	calc_rot_y(t_map *map, t_node *node, t_3d_point *rotated)
{
	rotated->x = node->pos.x * map->angle_y.x + rotated->z * map->angle_y.y;
	rotated->z = -node->pos.x * map->angle_y.y + rotated->z * map->angle_y.x;
}

static void	calc_rot_z(t_map *map, t_3d_point *rotated)
{
	double	rotated_x;

	rotated_x = rotated->x;
	rotated->x = rotated_x * map->angle_z.x + rotated->y * map->angle_z.y;
	rotated->y = -rotated_x * map->angle_z.y
		+ rotated->y * map->angle_z.x;
}

static void	calc_2d_pos(t_map *map, t_node *node, t_3d_point rotated)
{
	node->calc_pos.x = roundf((rotated.x - rotated.y)
			* map->scale + map->offset.x);
	node->calc_pos.y = roundf((rotated.z + rotated.x + rotated.y)
			* map->scale + map->offset.y);
}

void	calc_node_pos(t_map *map)
{
	t_node		*node;
	t_3d_point	rotated;

	node = map->first_node;
	while (node)
	{
		calc_rot_x(map, node, &rotated);
		calc_rot_y(map, node, &rotated);
		calc_rot_z(map, &rotated);
		calc_2d_pos(map, node, rotated);
		node = node->next;
	}
}

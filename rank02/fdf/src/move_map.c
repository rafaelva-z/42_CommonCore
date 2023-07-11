/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:08:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 17:44:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_x(t_map *map, int keycode, float angle)
{
	if (keycode == ROT_X)
		map->rotation.x -= angle;
	else if (keycode == RROT_X)
		map->rotation.x += angle;
	map->angle_x.x = cos(map->rotation.x);
	map->angle_x.y = sin(map->rotation.x);
}

static void	rotate_y(t_map *map, int keycode, float angle)
{
	if (keycode == ROT_Y)
		map->rotation.y -= angle;
	else if (keycode == RROT_Y)
		map->rotation.y += angle;
	map->angle_y.x = cos(map->rotation.y);
	map->angle_y.y = sin(map->rotation.y);
}

static void	rotate_z(t_map *map, int keycode, float angle)
{
	if (keycode == ROT_Z)
		map->rotation.z -= angle;
	else if (keycode == RROT_Z)
		map->rotation.z += angle;
	map->angle_z.x = cos(map->rotation.z);
	map->angle_z.y = sin(map->rotation.z); 
}

void	rotate(t_map *map, int keycode)
{
	float	rot_amount;

	rot_amount = 0.15;
	if (keycode == ROT_X || keycode == RROT_X)
		rotate_x(map, keycode, rot_amount);
	else if (keycode == ROT_Y || keycode == RROT_Y)
		rotate_y(map, keycode, rot_amount);
	else if (keycode == ROT_Z || keycode == RROT_Z)
		rotate_z(map, keycode, rot_amount);
}

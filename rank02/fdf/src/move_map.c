/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:08:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/03 15:42:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	offset(t_map *map, int keycode)
{
	int	offset;

	offset = 10;
	if (keycode == KEY_UP || keycode == KEY_W)
		map->offset.y -= offset;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		map->offset.y += offset;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		map->offset.x -= offset;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		map->offset.x += offset;
}

void	zoom(t_map *map, int keycode)
{
	int	zoom;

	zoom = 1;
	if (keycode == KEY_MINUS)
		map->scale -= zoom;
	else if (keycode == KEY_PLUS)
		map->scale += zoom;
}

void	rotate(t_map *map, int keycode)
{
	float	angle;

	angle = 0.1;
	if (keycode == KEY_Q)
		map->rotation.z -= angle;
	else if (keycode == KEY_E)
		map->rotation.z += angle;
	map->angle_z.x = cos(map->rotation.z);
	map->angle_z.y = sin(map->rotation.z); 
}

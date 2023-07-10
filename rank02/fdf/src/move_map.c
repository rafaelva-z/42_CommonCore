/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:08:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/10 22:08:25 by rvaz             ###   ########.fr       */
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
	if (keycode == KEY_MINUS && map->scale > 0)
	{
		if ((map->scale - zoom) < 0)
			map->scale = 0;
		else
			map->scale -= zoom;
	}
	else if (keycode == KEY_PLUS)
		map->scale += zoom;
}

/* static void	rotate_x(t_map *map, int keycode)
{
	float	angle;

	angle = 0.1;
	if (keycode == KEY_Z)
		map->rotation.y -= angle;
	else if (keycode == KEY_X)
		map->rotation.y += angle;
	map->angle_y.x = cos(map->rotation.y);
	map->angle_y.y = sin(map->rotation.y);
} */

static void	rotate_y(t_map *map, int keycode)
{
	float	angle;

	angle = 10;
	if (keycode == KEY_R)
		map->rotation.y -= angle;
	else if (keycode == KEY_F)
		map->rotation.y += angle;
	map->angle_y.x = map->rotation.y;
	map->angle_y.y = map->rotation.y;
}

static void	rotate_z(t_map *map, int keycode)
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

void	rotate(t_map *map, int keycode)
{
	if (keycode == KEY_Q || keycode == KEY_E)
		rotate_z(map, keycode);
	else if (keycode == KEY_R || keycode == KEY_F)
		rotate_y(map, keycode);
}



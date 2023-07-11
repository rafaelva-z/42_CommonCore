/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:48:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 17:45:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	reset_view(t_map *map, int keycode)
{
	if (keycode == CENTER)
		map->offset = (t_2d_point){WIN_WIDTH / 2, WIN_HEIGHT / 2};
	if (keycode == FRONT)
	{
		map->rotation = (t_3d_point){-0.63, 0, 0.79};
		map->angle_x = (t_2d_point){0.81, -0.585};
		map->angle_y = (t_2d_point){1, 0};
		map->angle_z = (t_2d_point){0.7, 0.7};
	}
}

void	offset(t_map *map, int keycode)
{
	int	offset;

	offset = 10;
	if (keycode == UP)
		map->offset.y -= offset;
	else if (keycode == DOWN)
		map->offset.y += offset;
	else if (keycode == LEFT)
		map->offset.x -= offset;
	else if (keycode == RIGHT)
		map->offset.x += offset;
}

void	zoom(t_map *map, int keycode)
{
	int	zoom;

	zoom = 1;
	if (keycode == ZOOM_OUT && map->scale > 0)
	{
		if ((map->scale - zoom) < 0)
			map->scale = 0;
		else
			map->scale -= zoom;
	}
	else if (keycode == ZOOM_IN)
		map->scale += zoom;
}

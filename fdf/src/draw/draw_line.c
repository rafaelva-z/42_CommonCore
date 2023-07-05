/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:45:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/05 19:05:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	calculate_next_point(t_2d_line *line,
	t_2d_point diff, t_2d_point *err)
{
	t_2d_point	s;

	s.x = (line->point_a.x < line->point_b.x);
	if (!s.x)
		s.x = -1;
	s.y = (line->point_a.y < line->point_b.y);
	if (!s.y)
		s.y = -1;
	err->y = err->x * 2;
	if (err->y > diff.y)
	{
		err->x += diff.y;
		line->point_a.x += s.x;
	}
	if (err->y < diff.x)
	{
		err->x += diff.x;
		line->point_a.y += s.y;
	}
}

void	draw_line(t_2d_line line, t_img *img)
{
	t_2d_point	diff;
	t_2d_point	err;

	diff = (t_2d_point){abs(line.point_b.x - line.point_a.x), -abs(line.point_b.y - line.point_a.y)};
	err.x = diff.x + diff.y;
	while (line.point_a.x != line.point_b.x || line.point_a.y != line.point_b.y)
	{
		if (line.point_a.x >= 0 && line.point_a.y >= 0 && line.point_a.x < WIN_WIDTH && line.point_a.y < WIN_HEIGHT)
			draw_pixel(img, line.point_a.x, line.point_a.y, 0x00FFaa00);
		calculate_next_point(&line, diff, &err);
	}
}

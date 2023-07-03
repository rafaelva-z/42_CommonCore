/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:45:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/03 15:37:39 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	calculate_next_point(t_2d_point *pa, t_2d_point pb,
	t_2d_point diff, t_2d_point *err)
{
	t_2d_point	s;

	s.x = (pa->x < pb.x);
	if (!s.x)
		s.x = -1;
	s.y = (pa->y < pb.y);
	if (!s.y)
		s.y = -1;
	err->y = err->x * 2;
	if (err->y > diff.y)
	{
		err->x += diff.y;
		pa->x += s.x;
	}
	if (err->y < diff.x)
	{
		err->x += diff.x;
		pa->y += s.y;
	}
}

void	draw_line(t_2d_point pa, t_2d_point pb, t_img *img)
{
	t_2d_point	diff;
	t_2d_point	err;

	diff = (t_2d_point){abs(pb.x - pa.x), -abs(pb.y - pa.y)};
	err.x = diff.x + diff.y;
	while (pa.x != pb.x || pa.y != pb.y)
	{
		if (pa.x >= 0 && pa.x < WIN_WIDTH && pa.y >= 0 && pa.y < WIN_HEIGHT)
			draw_pixel(img, pa.x, pa.y, 0x00FFaa00);
		calculate_next_point(&pa, pb, diff, &err);
	}
}

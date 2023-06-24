/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:45:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/24 19:08:47 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	calculate_next_point(t_2d_point *pa, t_2d_point pb,
	t_2d_point diff, int *err, int *err2)
{
	t_2d_point	s;

	s.x = (pa->x < pb.x);
	if (!s.x)
		s.x = -1;
	s.y = (pa->y < pb.y);
	if (!s.y)
		s.y = -1;
	*err2 = *err * 2;
	if (*err2 > diff.y)
	{
		*err += diff.y;
		pa->x += s.x;
	}
	if (*err2 < diff.x)
	{
		*err += diff.x;
		pa->y += s.y;
	}
}

void	draw_line(t_2d_point pa, t_2d_point pb, t_img *img)
{
	t_2d_point	diff;
	int			err;
	int			err2;

	diff = (t_2d_point){abs(pb.x - pa.x), -abs(pb.y - pa.y)};
	err = diff.x + diff.y;
	while (pa.x != pb.x || pa.y != pb.y)
	{
		draw_pixel(img, pa.x, pa.y, 0x00FFaa00);
		calculate_next_point(&pa, pb, diff, &err, &err2);
	}
}

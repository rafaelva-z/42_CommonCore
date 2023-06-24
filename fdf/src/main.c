/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:52 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/24 15:23:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	update(void)
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	int		i;
	int		j;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF - by rvaz");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	j = 200;
	while (j < 400)
	{
		i = 50;
		while (i < 850)
		{
			if (((i + j) % 15) == 0)
				my_mlx_pixel_put(&img, i, j, 0x00FFaa00);
			i++;
		}
		j++;
	}
	j = 20;
	while (j < 500)
	{
		i = 300;
		while (i < 500)
		{
			if (((i - j) % 15) == 0)
				my_mlx_pixel_put(&img, i, j, 0x00FFaa00);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, close_win, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_pgm, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(void)
{
	int		fd;
	t_map	*map;

	fd = open("maps/rvaz/firstmap.fdf", O_RDONLY);
	map = make_map(fd);
	update();
}

static int	absolute(int n)
{
	if(n < 0)
		n = -n;
	return (n);
}

void	draw_line(t_2d_point point_a, t_2d_point point_b, t_img img)
{
	t_2d_point	diff;
	t_2d_point	s;
	t_2d_point	err;

	diff.x = absolute(point_b.x - point_a.x);
	diff.y = -absolute(point_b.y - point_a.y);
	err.x = diff.x + diff.y;
	if (point_a.x < point_b.x)
		s.x = 1;
	else
		s.x = 0;
	if (point_a.y < point_b.y)
		s.y = 1;
	else
		s.y =-1;	
	while (1)
	{
		my_mlx_pixel_put(&img, point_a.x, point_a.y, 0x00FFaa00);
		if (point_a.x == point_b.x && point_a.y == point_b.y)
			break ;
		err.y = 2 * err.x;
		if (err.y > diff.y) 
		{
			err.x += diff.y;
			point_a.x += s.x;
		}
		if (err.y < diff.x)
		{
			err.x += diff.x;
			point_a.y += s.y;
		}
	}
}

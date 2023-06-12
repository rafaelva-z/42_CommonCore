/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:52 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/12 16:14:43 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void update()
{
	t_mlx	mlx;
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
	t_node	*map;

	fd = open("maps/rvaz/firstmap.fdf", O_RDONLY);
	map = make_map(fd);
	update();
}

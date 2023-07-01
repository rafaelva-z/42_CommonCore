/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:52 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/01 18:29:23 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	start(t_map map)
{
	t_mlx	mlx;

	mlx.map = &map;
	mlx.mlx = mlx_init();
	mlx.img = malloc(sizeof(t_img));
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF - by rvaz");
	mlx.img->img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img->addr = mlx_get_data_addr(mlx.img->img, &(mlx.img->bits_per_pixel),
			&(mlx.img->line_length), &(mlx.img->endian));
	draw_fdf(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img->img, 0, 0);
	mlx_key_hook(mlx.win, key_reader, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_pgm, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(void)
{
	int		fd;
	t_map	*map;

	fd = open("maps/rvaz/firstmap.fdf", O_RDONLY);
	map = make_map(fd);
	start(*map);
}

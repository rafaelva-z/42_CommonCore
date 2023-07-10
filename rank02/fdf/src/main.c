/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:52 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/10 17:59:10 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	mlx_start(t_mlx *mlx, t_map *map)
{
	mlx->map = map;
	mlx->mlx = mlx_init();
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF - by rvaz");
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, 
			&(mlx->img->bits_per_pixel), &(mlx->img->line_length),
			&(mlx->img->endian));
}

static void	print_instructions(void)
{
	ft_printf("┌─────────────────────────────────┐\n");
	ft_printf("│          Fdf - by rvaz          │\n");
	ft_printf("├──────┬──────────────────────────┤\n");
	ft_printf("│'ESC' │ exit                     │\n");
	ft_printf("│'+'   │ zoom in                  │\n");
	ft_printf("│'-'   │ zoom out                 │\n");
	ft_printf("│'w'   │ move up                  │\n");
	ft_printf("│'s'   │ move down                │\n");
	ft_printf("│'a'   │ move left                │\n");
	ft_printf("│'d'   │ move right               │\n");
	ft_printf("│'q'   │ rotate counterclockwise  │\n");
	ft_printf("│'e'   │ rotate clockwise         │\n");
	ft_printf("└──────┴──────────────────────────┘\n");
}

void	start(t_map *map)
{
	t_mlx	mlx;

	mlx_start(&mlx, map);
	draw_fdf(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img->img, 0, 0);
	mlx_key_hook(mlx.win, key_reader, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_pgm, &mlx);
	print_instructions();
	mlx_loop(mlx.mlx);
}

static void	arg_check(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_printf("[fdf] ERROR - Too many arguments | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
	else if (argc == 1)
	{
		ft_printf("[fdf] ERROR - No arguments | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".fdf", 4))
	{
		ft_printf("[fdf] ERROR - Invalid file extension | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	arg_check(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		map = make_map(fd);
		if (map)
			start(map);
		else
			ft_printf("[fdf] ERROR - Invalid map\n");
	}
	else
		ft_printf("[fdf] ERROR - Invalid map or map path\n");
}

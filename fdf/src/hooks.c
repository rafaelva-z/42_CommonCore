/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/01 18:43:35 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../lib/libft/ft_printf/ft_printf.h"

int	key_reader(int keycode, t_mlx *mlx)
{
	printf("Keycode %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (close_pgm(mlx));
	}
	else if (keycode == KEY_UP)
		mlx->map->offset.y -= 10;
	else if (keycode == KEY_DOWN)
		mlx->map->offset.y += 10;
	else if (keycode == KEY_LEFT)
		mlx->map->offset.x -= 10;
	else if (keycode == KEY_RIGHT)
		mlx->map->offset.x += 10;
	else if (keycode == KEY_MINUS)
		mlx->map->scale -= 1;
	else if (keycode == KEY_PLUS)
		mlx->map->scale += 1;
	else if (keycode == KEY_F1)
	printf("OffsetX %f, OffsetY%f\n", mlx->map->offset.x, mlx->map->offset.y);
	ft_bzero(mlx->img->addr, WIN_WIDTH * WIN_HEIGHT * sizeof(mlx->img->bits_per_pixel));
	draw_fdf(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

int	close_pgm(t_mlx *mlx)
{
	exit(0);
	return (1);
}
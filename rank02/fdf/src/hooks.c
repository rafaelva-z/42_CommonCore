/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/10 22:00:51 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../lib/libft/ft_printf/ft_printf.h"

int	key_reader(int keycode, t_mlx *mlx)
{
	printf(">>>%d<<<\n", keycode);
	if (keycode == KEY_ESC)
	{
		return (close_pgm(mlx));
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT 
		|| keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		offset(mlx->map, keycode);
	else if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		zoom(mlx->map, keycode);
	else if (keycode == KEY_Q || keycode == KEY_E || keycode == KEY_R || keycode == KEY_F)
		rotate(mlx->map, keycode);
	ft_bzero(mlx->img->addr, (WIN_WIDTH * WIN_HEIGHT)
		* sizeof(mlx->img->bits_per_pixel));
	draw_fdf(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

int	close_pgm(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->img);
	map_free(mlx->map);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
	return (1);
}

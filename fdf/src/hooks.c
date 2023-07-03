/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/03 15:39:44 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../lib/libft/ft_printf/ft_printf.h"

int	key_reader(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (close_pgm(mlx));
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT 
		|| keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		offset(mlx->map, keycode);
	else if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		zoom(mlx->map, keycode);
	else if (keycode == KEY_Q || keycode == KEY_E)
		rotate(mlx->map, keycode);
	ft_bzero(mlx->img->addr, (WIN_WIDTH * WIN_HEIGHT)
		* sizeof(mlx->img->bits_per_pixel));
	draw_fdf(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

int	close_pgm(t_mlx *mlx)
{
	exit(0);
	return (1);
}

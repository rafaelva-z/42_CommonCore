/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/12 12:23:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_reader(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		close_pgm(mlx);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT 
		|| keycode == RIGHT)
		offset(mlx->map, keycode);
	else if (keycode == ZOOM_OUT || keycode == ZOOM_IN)
		zoom(mlx->map, keycode);
	else if (keycode == ROT_X || keycode == RROT_X || keycode == ROT_Y 
		|| keycode == RROT_Y || keycode == ROT_Z || keycode == RROT_Z)
		rotate(mlx->map, keycode);
	else if (keycode == CENTER || keycode == FRONT)
		reset_view(mlx->map, keycode);
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
}

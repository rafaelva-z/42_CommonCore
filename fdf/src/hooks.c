/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/30 20:12:18 by rvaz             ###   ########.fr       */
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
	// else if (keycode == KEY_UP)
	// 	move.y--;
	// else if (keycode == KEY_DOWN)
	// 	move.y++;
	// else if (keycode == KEY_LEFT)
	// 	move.x--;
	// else if (keycode == KEY_RIGHT)
	// 	move.x++;
	return (0);
}

int	close_pgm(t_mlx *mlx)
{
	exit(0);
	return (1);
}
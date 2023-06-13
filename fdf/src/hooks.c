/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/13 18:44:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../lib/libft/ft_printf/ft_printf.h"

int	close_win(int keycode, t_mlx *mlx)
{
	ft_printf("Keypressed >%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (close_pgm(mlx));
	}
	return (0);
}

int	close_pgm(t_mlx *mlx)
{
	exit(0);
	return (1);
}
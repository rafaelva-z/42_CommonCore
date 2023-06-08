/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 13:11:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../lib/libft/ft_printf/ft_printf.h"

void	close_win(int keycode, t_mlx *mlx)
{
	ft_printf("Keypressed >%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		close_pgm(mlx);
	}
}

void	close_pgm(t_mlx *mlx)
{

	exit(0);
}
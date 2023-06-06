/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/06 20:46:59 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <limits.h>
# include <stdint.h>
# include <sys/stat.h>

//To delete

# include <stdio.h>

# include "minilibx-linux/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

//Image
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	close_win(int keycode, t_mlx *mlx);
void	close_pgm(t_mlx *mlx);

#endif
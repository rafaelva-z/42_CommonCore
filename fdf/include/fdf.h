/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 12:43:24 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <limits.h>
# include <stdint.h>
# include <sys/stat.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"


//DELETE THIS************************
# include <stdio.h>

//STRUCTS
//	Store MLX and window pointers
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

//	Image
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//FUNCTIONS
//	Program Management
void	close_win(int keycode, t_mlx *mlx);
void	close_pgm(t_mlx *mlx);

#endif
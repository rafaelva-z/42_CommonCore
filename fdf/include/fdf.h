/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/08 18:03:57 by rvaz             ###   ########.fr       */
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

//Screen Resolution
# define WIN_WIDTH 960
# define WIN_HEIGHT 480

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

typedef struct s_2d_point
{
	int	x;
	int	y;
}	t_2d_point;

typedef struct s_3d_point
{
	int	x;
	int	y;
	int	z;
}	t_3d_point;

typedef struct s_node
{
	t_3d_point		pos;
	struct s_node	*next;
	struct s_node	*next_line;
}	t_node;

//FUNCTIONS
//	Program Management
void	close_win(int keycode, t_mlx *mlx);
void	close_pgm(t_mlx *mlx);

//	Structs and Node functions
t_node	**make_map(int fd);
t_node	*node_new(t_3d_point point);
void	node_addback(t_node **node, t_node *new_node);
t_node	*node_last(t_node *node);

#endif 
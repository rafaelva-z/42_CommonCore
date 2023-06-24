/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/24 18:19:58 by rvaz             ###   ########.fr       */
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

//Keyboard
# define KEY_ESC 65307
# define KEY_TAB 65289
# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472
# define KEY_F4 65473
# define KEY_F5 65474
# define KEY_F6 65475
# define KEY_F7 65476
# define KEY_F8 65477
# define KEY_F9 65478
# define KEY_F10 65479
# define KEY_F11 65480
# define KEY_F12 65481
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

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

//MAP and NODEs
struct	s_map;

typedef struct s_node
{
	t_3d_point		pos;
	struct s_map	*map;
	struct s_node	*next;
	struct s_node	*below;
	t_2d_point		end_of_line;
}	t_node;

typedef struct s_line
{
	t_2d_point	point_a;
	t_2d_point	point_b;
}	t_line;

typedef struct s_map
{
	t_3d_point		pos;
	t_node			*first_node;
	t_2d_point		size;
	t_img			img;
}	t_map;

//FUNCTIONS
//	Program Management
int		close_win(int keycode, t_mlx *mlx);
int		close_pgm(t_mlx *mlx);

//	Drawing
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_2d_point pa, t_2d_point pb, t_img *img);

//	Structs and Node functions
t_map	*make_map(int fd);
t_node	*node_new(t_map *map, t_3d_point point);
void	node_addback(t_node **node, t_node *new_node);
void	node_addbelow(t_node **node, t_node *new_node);
t_node	*node_last(t_node *node);
t_node	*node_find(t_map *map, t_2d_point pos);
t_node	*node_lastbelow(t_node *node);


int		ft_issignal(char c);

#endif 
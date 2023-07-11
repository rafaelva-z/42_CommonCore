/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 17:42:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <limits.h>
# include <stdint.h>
# include <sys/stat.h>
# include <math.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"

//	Screen Resolution
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

//	Keyboard
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_PLUS	65451
# define KEY_MINUS	65453
# define KEY_A		97
# define KEY_C		99
# define KEY_D		100
# define KEY_E		101
# define KEY_F		102
# define KEY_Q		113
# define KEY_R		114
# define KEY_S		115
# define KEY_V		118
# define KEY_W		119
# define KEY_X		120
# define KEY_Z		122

//	Controls
# define UP			KEY_W
# define LEFT		KEY_A
# define DOWN		KEY_S
# define RIGHT		KEY_D
# define ZOOM_IN	KEY_PLUS
# define ZOOM_OUT	KEY_MINUS
# define ROT_X		KEY_F
# define RROT_X		KEY_R
# define ROT_Y		KEY_Z
# define RROT_Y		KEY_X
# define ROT_Z		KEY_Q
# define RROT_Z		KEY_E
# define CENTER		KEY_C
# define FRONT		KEY_V

//STRUCTS
struct	s_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	struct s_map	*map;
}				t_mlx;

typedef struct s_2d_point
{
	double	x;
	double	y;
}	t_2d_point;

typedef struct s_3d_point
{
	double	x;
	double	y;
	double	z;
}	t_3d_point;

typedef struct s_2d_line
{
	t_2d_point	point_a;
	t_2d_point	point_b;
}	t_2d_line;

typedef struct s_node
{
	t_3d_point		pos;
	t_2d_point		calc_pos;
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
	double			scale;
	t_2d_point		offset;
	t_3d_point		rotation;
	t_2d_point		angle_x;
	t_2d_point		angle_y;
	t_2d_point		angle_z;
}	t_map;

//FUNCTIONS
//	Program Management
int			key_reader(int keycode, t_mlx *mlx);
int			close_pgm(t_mlx *mlx);
void		calc_node_pos(t_map *map);

//	Drawing
void		draw_pixel(t_img *img, int x, int y, int color);
void		draw_line(t_2d_line line, t_img *img);
void		draw_fdf(t_mlx *mlx);

// Map Movement
void		offset(t_map *map, int keycode);
void		zoom(t_map *map, int keycode);
void		rotate(t_map *map, int keycode);
void		reset_view(t_map *map, int keycode);

//	Struct and Node functions
t_map		*make_map(int fd);
int			map_addline(t_map **map, char *line, int y);
t_2d_point	map_getsize(t_map *map);
void		map_free(t_map *map);
t_node		*node_new(t_map *map, t_3d_point point);
void		node_addback(t_node **node, t_node *new_node);
void		node_addbelow(t_node **node, t_node *new_node);
t_node		*node_find(t_map *map, t_2d_point pos);
t_node		*node_last(t_node *node);
t_node		*node_lastbelow(t_node *node);

int			ft_issignal(char c);

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_addline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:33:03 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/11 17:53:03 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	map_charcheck(char *str)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(str) - 1;
	while (str[i])
	{
		if (i == strlen && str[i] == '\n')
			return (1);
		if (!ft_isdigit(str[i]) && (str[i] != ' ') && !ft_issignal(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Check if it's the last number in the line
static void	map_linespace(t_map **map, char *line, t_3d_point *pos, int *i)
{
	while (ft_isspace(line[*i]))
	{
		if (line[(*i)++] == '\n' && (*map)->first_node)
		{
			node_last((*map)->first_node)->end_of_line.x = 1;
			pos->y++;
		}
	}
}

static void	map_addnumber(t_map **map, char *line, t_3d_point *pos, int *i)
{
	if (ft_isdigit(line[*i]) || ft_issignal(line[*i]))
	{
		pos->z = -ft_atoi(&line[*i]);
		if (pos->z > 10000)
			pos->z = 10000;
		else if (pos->z < -10000)
			pos->z = -10000;
		node_addback(&((*map)->first_node), node_new(*map, *pos));
		pos->x++;
		while (ft_issignal(line[*i]) || ft_isdigit(line[*i]))
			(*i)++;
	}
}

int	map_addline(t_map **map, char *line, int y)
{
	int			i;
	t_3d_point	pos;

	i = 0;
	pos = (t_3d_point){1, y, -1};
	if (map_charcheck(line) == 0)
		return (-1);
	while (line[i])
	{
		map_linespace(map, line, &pos, &i);
		map_addnumber(map, line, &pos, &i);
	}
	return (0);
}

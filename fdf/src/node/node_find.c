/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:03:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/22 16:12:20 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_node  *node_find(t_node **map, t_2d_point pos)
{
    t_node  *tmp;
    int     count;

    tmp = *map;
    while (((tmp->pos.x != pos.x) || (tmp->pos.y != pos.y)))
    {
        if (!tmp->next)
            break;
        tmp = tmp->next;
        printf("tmp %d %d %d,\n", tmp->pos.x, tmp->pos.y, tmp->pos.z);
        if (((tmp->pos.x == pos.x) && (tmp->pos.y == pos.y)))
            return (tmp);
    }
    return (NULL);
}

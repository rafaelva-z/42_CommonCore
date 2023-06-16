/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:28:13 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/16 17:18:48 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ps_newsort_moves(t_list **lst, int nb, int *moves)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->nb != nb)
	{
		(*moves)++;
		tmp = tmp->next;
	}
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_bestnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:05 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/05 16:34:25 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_bestnum_above(t_list stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		bestnum;

	tmp = stack_b;
	bestnum = INT_MIN;
	while (tmp)
	{
		if (tmp->nb >= bestnum && tmp->nb < stack_a.nb)
			bestnum = tmp->nb;
		tmp = tmp->next;
	}
	return (bestnum);
}

static int	find_bestnum_below(t_list stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		bestnum;

	tmp = stack_b;
	bestnum = INT_MAX;
	while (tmp)
	{
		if (tmp->nb < bestnum && tmp->nb > stack_a.nb)
			bestnum = tmp->nb;
		tmp = tmp->next;
	}
	return (bestnum);
}

int	find_bestnum(t_list stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		flag;
	int		bestnum;

	flag = 0;
	tmp = stack_b;
	bestnum = find_bestnum_above(stack_a, stack_b);
	if (bestnum == INT_MIN)
		bestnum = find_bestnum_below(stack_a, stack_b);
	return (bestnum);
}

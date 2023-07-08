/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:35:54 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/16 13:05:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	push(stack_b, stack_a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}

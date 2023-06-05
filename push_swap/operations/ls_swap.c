/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:05 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/05 15:28:02 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next)
	{
		tmp = (*stack)->next->next;
		ft_lstadd_front(stack, (*stack)->next);
		(*stack)->next->next = tmp;
	}
	return ;
}

void	sa(t_list **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
